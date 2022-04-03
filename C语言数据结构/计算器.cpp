#include<stdio.h>
#include<stdlib.h>


/*数据栈*/
struct shuju   //struct结构体构建栈 
{
	int data[100];
	int top;
};


/*符号栈*/ 
struct fuhao
 {
	char symbol[100];
	int top;
};


void InitOperateNum(struct shuju *StackNum)    //数据栈非空 
{
    StackNum->top = -1;
}


void InitOperateSymbol(struct fuhao *StackSymbol)    //符号栈非空 
{  
    StackSymbol->top = -1; 
}


/*存入数据栈*/
void Inshuju(struct shuju *StackNum, int num)
{
	StackNum->top ++;
	StackNum->data[StackNum->top] = num;
}


/*存入符号栈*/ 
void Infuhao(struct fuhao *StackSymbol, char ch)
{
	StackSymbol->top ++;
	StackSymbol->symbol[StackSymbol->top] = ch;
}


/*读取数据栈*/
int Randshuju(struct shuju *StackNum)
{
	return StackNum->data[StackNum->top];
}


/*读取符号栈*/
char Randfuhao(struct fuhao *StackSymbol)
{
	return StackSymbol->symbol[StackSymbol->top];
}


/*从数据栈取出数据*/
int Putshuju(struct shuju *StackNum)
{
	int x;
	x = StackNum->data[StackNum->top];
	StackNum->top --;
	return x;
}


/*从符号栈取出符号*/
char Putfuhao(struct fuhao *StackSymbol)
{
	char c;
	c = StackSymbol->symbol[StackSymbol->top];
	StackSymbol->top --;
	return c;
}


/*符号优先级判断*/
int judge(char ch) {
	if(ch == '(')
	 {
		return 1; 
  	}
	if(ch == '+' || ch == '-') {
		return 2;
	}
	else if(ch == '*' || ch == '/') {
		return 3;
	}
	else if(ch == ')') {
		return 4;
	}
}


/*四则运算*/
int Math(int v1, int v2, char c)
{
	int sum;
	switch(c) {
		case '+' : {
			sum = v1 + v2;
			break;
		}
		case '-' : {
			sum = v1 - v2;
			break;
		}
		case '*' : {
			sum = v1 * v2;
			break;
		} 
		case '/' : {
			sum = v1 / v2;
			break;
		}
	}
	return sum;
}


int main()
{
	struct shuju data;
	struct fuhao symbol;
	InitOperateNum(&data);   //调用数据 
	InitOperateSymbol(&symbol);  //调用符号 
	int i, t, sum, v1, v2;
	char c;
	i = t = sum = 0;
	char v[100] = {0};
	char *str = (char *)malloc(sizeof(char)*200);
	while((c = getchar()) != '\n')  //非空字符 
	 {
		str[i] = c;
		i ++;
	}
	str[i] = '\0';
	for(i = 0; str[i] != '\0'; i ++) {
		if(i == 0 && str[i] == '-') {
			v[t++] = str[i];
		}
		else if(str[i] == '(' && str[i+1] == '-') {
			i ++;
			v[t++] = str[i++];
			while(str[i] >= '0' && str[i] <= '9') {
				v[t] = str[i];
				t ++;
				i ++;
			}
			Inshuju(&data, atoi(v));
			while(t > 0) {
				v[t] = 0;
				t --;
			}
			if(str[i] != ')') {
				i --;
				Infuhao(&symbol, '(');
			}
		}
		else if(str[i] >= '0' && str[i] <= '9') {
			while(str[i] >= '0' && str[i] <= '9') {
				v[t] = str[i];
				t ++;
				i ++;
			}
			Inshuju(&data, atoi(v));
			while(t > 0) {
				v[t] = 0;
				t --;
			}
			i --;
		}
		else {
			if(symbol.top == -1) 
			{        //如果符号栈没有元素，直接把符号放入符号栈 
				Infuhao(&symbol, str[i]);
			}
			else if(judge(str[i]) == 1) { //如果此符号是'('，直接放入符号栈 
				Infuhao(&symbol, str[i]);
			}
			else if(judge(str[i]) == 2) { //如果此符号是'+'或'-'，判断与栈顶符号是优先级 
				if(judge(Randfuhao(&symbol)) == 1) { //如果栈顶符号是'('，放入符号栈 
					Infuhao(&symbol, str[i]);
				}
				else if(judge(Randfuhao(&symbol)) == 2) { //如果栈顶符号是'+'或'-'，则出栈运算 
					while(symbol.top >= 0 && data.top >= 1) { //循环出栈
						v2 = Putshuju(&data);
						v1 = Putshuju(&data);
						sum = Math(v1, v2, Putfuhao(&symbol));
						Inshuju(&data, sum); //将运算结果压入数据栈 
					}
					Infuhao(&symbol, str[i]); //新符号进栈 
				}
				else if(judge(Randfuhao(&symbol)) == 3) { //如果栈顶符号是'*'或'/'，则进符号栈 
					while(symbol.top >= 0 && data.top >= 1) { //循环出栈
						v2 = Putshuju(&data);
						v1 = Putshuju(&data);
						sum = Math(v1, v2, Putfuhao(&symbol));
						Inshuju(&data, sum); //将运算结果压入数据栈 
					}
					Infuhao(&symbol, str[i]); //新符号进栈 
				}
				/*栈顶符号不可能是')'，故不做判断*/ 
			}
			else if(judge(str[i]) == 3) { //如果此符号是'*'或'/'，则判断与栈顶符号是优先级
				if(judge(Randfuhao(&symbol)) == 1) { //如果栈顶符号是'('，放入符号栈 
					Infuhao(&symbol, str[i]);
				}
				else if(judge(Randfuhao(&symbol)) == 2) { //如果栈顶符号是'+'或'-'，则进符号栈
					Infuhao(&symbol, str[i]); //新符号进栈
				}
				else if(judge(Randfuhao(&symbol)) == 3) { //如果栈顶符号是'*'或'/'，则出栈运算 
					while(symbol.top >= 0 && data.top >= 1) { //循环出栈
						v2 = Putshuju(&data);
						v1 = Putshuju(&data);
						sum = Math(v1, v2, Putfuhao(&symbol));
						Inshuju(&data, sum); //将运算结果压入数据栈 
					}
					Infuhao(&symbol, str[i]); //新符号进栈
				}
			}
			else if(judge(str[i]) == 4) { // 如果此符号是')'，则出栈运算直到遇到'('
				do { //循环出栈直到遇到'('
					v2 = Putshuju(&data);
					v1 = Putshuju(&data);
					sum = Math(v1, v2, Putfuhao(&symbol));
					Inshuju(&data, sum); //将运算结果压入数据栈 
				}while(judge(Randfuhao(&symbol)) != 1);
				Putfuhao(&symbol); //括号内运算结束后使'('出栈 
			} 		
		}
	}
	free(str); //释放内存空间
	while(symbol.top != -1) {
		v2 = Putshuju(&data);
		v1 = Putshuju(&data);
		sum = Math(v1, v2, Putfuhao(&symbol));
		Inshuju(&data, sum);	
	}
	printf("%d", data.data[0]);
	
	return 0;
}
