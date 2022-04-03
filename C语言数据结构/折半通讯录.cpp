#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;

/*  person类
	包含人的姓名，城市，电话
*/
class Person 
{
private:	
	string name;
	string city;
	string phone;
public: 
	Person(){}
	Person(string name, string city, string phone) 
	{
		this->name = name;
		this->city = city;
		this->phone = phone;
	}
	string getCity() 
	{
		return this->city;
	}
	void setCity(string city) 
	{
		this->city = city;
	}
	string getPhone() 
	{
		return this->phone;
	}
	void setPhone(string phone)
	{
		this->phone = phone;
	}
	string getName() 
	{
		return this->name;
	}
	void setName(string name) 
	{
		this->name = name;
	}	
	void update(string name, string city, string phone)
	{
		this->name = name;
		this->city = city;
		this->phone = phone;
	}
};


typedef Person ElemType;
typedef int Status;
const int SUCCESS = 1;
const int ERROR = -2;

//定义节点类型
typedef struct DulNode
{
	ElemType data[100];
	int length;
}DulNode;

//排序
void nodeSort(DulNode &list,int local,string oldName,string newName)
{	
	int low = 0;
	int high = 0;
	int mid = 0;
	int temp = 0;
	if(newName.compare(oldName) <= 0)
	{
		low = 0;
		high = local - 1;
		temp = 1;	//向左查找
	}else
	{
		low = local + 1;
		high = list.length-1;
		temp = 0;	//向右查找
	}		
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(newName.compare(list.data[mid].getName()) < 0)
		{
			high = mid - 1;
		}else
		{
			low = mid + 1;
		}
	}
	Person tempPerson = list.data[local];
	if(temp == 1)	//向右移动
	{
		for(int j = local - 1 ;j >= high + 1;--j)
		{
			list.data[j + 1] = list.data[j];
		}
		list.data[(high + 1)] = tempPerson;	
	}else			
	{
		for(int j = local + 1 ;j <= high; j++)
		{
			list.data[j - 1] = list.data[j];
		}
		list.data[(high)] = tempPerson;	
	}
}

//插入节点,折半插入
Status nodeInsert(DulNode &list, Person person) 
{		
	int len = list.length-1;
	if(len >= 0)
	{
		int low = 0; int high = len;
		int mid = 0;
		while(low <= high)
		{
			mid = (low + high) / 2;				
			if(person.getName().compare(list.data[mid].getName()) < 0)
			{
				high = mid - 1;
			}else
			{
				low = mid + 1;
			}
		}
		for(int j = len;j >= high + 1;--j)
		{
			list.data[j + 1] = list.data[j];
		}
		list.data[(high + 1)] = person;		
	}
	else
	{		
		list.data[0] = person;		
	}
	list.length++;
	return SUCCESS;
}

//删除节点 
Status nodeDelete(DulNode &list, string name) 
{
	if(list.length > 0)
	{
		int low = 0;
		int high = list.length-1;
		int mid = (low + high) / 2;		
		while(low <= high)
		{
			mid = (low + high) / 2;
			if(name.compare(list.data[mid].getName()) < 0)
			{
				high = mid - 1;
			}else if(name.compare(list.data[mid].getName()) > 0)
			{
				low = mid + 1;
			}		
			else
			{
				for(int i = mid + 1;i <= list.length - 1;i ++)
				{
					list.data[i - 1] = list.data[i];
				}
				list.length --;
				return SUCCESS;
			}
		}
		return ERROR;
	}
	return ERROR;
}

//判断用户是否存在并获取该节点的数据(修改)
Status isNode(DulNode &list, string name, Person** person)
 {
	if(list.length > 0)
	{
		int low = 0;
		int high = list.length-1;
		int mid = (low + high) / 2;
		while(low <= high)
		{
			mid = (low + high) / 2;
			if(name.compare(list.data[mid].getName()) < 0)
			{
				high = mid - 1;
			}else 
			{
				low = mid + 1;
			}		
		}	
		if(name.compare(list.data[high].getName()) == 0)
		{
			*person = &(list.data[high]);		
			return high;
		}
	}
	return ERROR;	
}

//根据姓名判断用户是否存在并获取该节点的数据（查找用户） 
Status selectNode(DulNode &list, string name, Person** person) 
{
	if(list.length > 0)
	{
		int low = 0;
		int high = list.length-1;
		int mid = (low + high) / 2;		
		while(low <= high)
		{
			mid = (low + high) / 2;
			if(name.compare(list.data[mid].getName()) < 0)
			{
				high = mid - 1;
			}else if(name.compare(list.data[mid].getName()) > 0)
			{
				low = mid + 1;
			}else
			{
				*person = &(list.data[mid]);		
				return SUCCESS;
			}
		}			
	}
	return ERROR;	
}

//主菜单 
void showMenu()
{
	printf("\n");
	printf("********************** 欢迎使用通讯录管理系统 ********************\n");
	printf("*                                                                *\n");
	printf("* 　            　1、添加通讯录　");
	printf(" 　 　   2、查询　　          　*\n");
	printf("* 　　　　　　　　3、修改        ");
	printf(" 　　　  4、删除记录　　　　    *\n");
	printf("* 　　　　　　　　5、显示全部    "); 
	printf(" 　　　  6、退出程序 　         *\n");
	printf("*                                                                *\n");
	printf("******************************************************************\n");
}
//添加新成员 
int addPerson(DulNode &list) 
{
	char name[20];
	char city[20];
	char phone[20];
	printf("请输入姓名【可输入q回到初始界面操作】：");
	scanf("%s", name);
	fflush(stdin);
	string sName = (string)name;
	if(sName == "q")
	{
		printf("\n");
		return 0;
	}	
	printf("\n请输入城市：");
	scanf("%s", city);
	printf("\n请输入电话：");
	scanf("%s", phone);
	Person *person = new Person(sName, city, phone);	
	nodeInsert(list, *person);
	printf("\n添加成功！\n\n");	
	return 1;
}
//显示所有成员 
void showAllPerson(DulNode &list)
 {	
	printf("\n=========================== 通讯录列表 ===========================\n\n");
	int len = list.length;
	for(int j = 0;j <= list.length - 1; j ++)
	{
		string name = list.data[j].getName();
		string city = list.data[j].getCity();
		string phone = list.data[j].getPhone();			
		printf("*   编号：%d    姓名：%s     城市：%s     电话：%s\n\n",j + 1, name.c_str(), city.c_str(),phone.c_str());		
	}	
	if(len == 0)
	{
		printf("                     数据为空，请添加数据\n\n");
	}
	printf("==================================================================\n\n");
}
//修改用户信息
void updatePerson(DulNode &list) 
{	
	char inName[20];
	printf("请输入需要修改用户的姓名 【可输入q回到初始界面操作】：");
	scanf("%s", &inName);
	fflush(stdin);
	string sName = (string)inName; 
	if(sName == "q")
	{
		printf("\n");
		return;
	} 
	Person* person = new Person();
	int high = isNode(list, sName, &person);
	while(high == -2) 
	{
		printf("用户名不存在！ \n\n");
		printf("请输入需要修改用户的姓名 【可输入q回到初始界面操作】：");		
		char temp[20];    //临时变量 
		scanf("%s", &temp);
		fflush(stdin);
		sName = (string)temp; 
		if(sName == "q")
		{
			printf("\n");
			return;
		} 
		high = isNode(list, sName, &person);
	}	
	string oldName = list.data[high].getName();
	char name[20];
	char city[20];
	char phone[20];
	printf("请输入新的用户信息\n\n");
	printf("请输入姓名：");
	scanf("%s", &name);
	printf("\n请输入城市：");
	scanf("%s", &city);
	printf("\n请输入电话：");
	scanf("%s", &phone);
	person->update(name, city, phone);
	printf("\n修改成功\n\n");
	string newName = (string)name;
	nodeSort(list,high,oldName,newName);
 	showAllPerson(list); 
}
//查询成员信息 
void selectPerson(DulNode &list)
 {	
	char inName[20];
	printf("请输入需要查询用户的姓名 【可输入q回到初始界面操作】：");
	scanf("%s", &inName);
    fflush(stdin);
	string sName = (string)inName; 
	if(sName == "q")
	{
		printf("\n");
		return;
	} 
	Person *person = new Person();
	while(selectNode(list, sName, &person) == -2)
	{
		printf("用户名不存在！\n\n");
		printf("请再次输入要查询用户的姓名【可输入q回到初始界面】：");
		char temp[20];    //临时变量 
		scanf("%s", &temp);
		fflush(stdin);
		sName = (string)temp;
		if(sName == "q")
		{
			printf("\n");
			return;
		} 
	}
	string name = person->getName();
	string city = person->getCity();
	string phone = person->getPhone();
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("*                                                                *\n");
	printf("* 　            　姓名：%s　　          　\n\n",name.c_str());
	printf("* 　            　城市：%s   ",city.c_str());
	printf("    电话：%s　　          　\n",phone.c_str());
	printf("*                                                                *\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
} 
//删除成员信息 
void deletePerson(DulNode &list) 
{
	char inName[20];
	printf("请输入需要删除用户的姓名【可输入q放弃删除操作】：");
	scanf("%s", &inName);
	fflush(stdin);
	string sName = (string)inName; 
	if(sName == "q") 
	{
		printf("\n");
		return;
	} 	
	while(nodeDelete(list, sName) == -2)
	{
		printf("用户姓名不正确\n\n");
		printf("请再次输入需要删除用户的姓名【可输入q放弃删除操作】：");
		char temp[20];    //临时变量 
		scanf("%s", &temp);
		fflush(stdin);
		sName = (string)temp;
		if(sName == "q")
		{
			printf("\n");
			return;
		} 
	}
	printf("删除成功！\n\n");
}
//主函数 
int main()
 {
	DulNode L;
	L.length = 0;
	int mainChance;
	showMenu();
	printf("请输入:");
 	scanf("%d", &mainChance);
	fflush(stdin);
	int temp = 0;
	while(mainChance!=6) 
	{
		switch(mainChance) 
		{ 
			case 1:
				temp = addPerson(L);
				if(temp == 1)
				{
					showAllPerson(L); 
				}				
				break;
			case 2:
				selectPerson(L);
				break;
			case 3:
				updatePerson(L);				
				break;
			case 4:
				deletePerson(L);
				break;
			case 5:
				showAllPerson(L);
				break;
			default:
				printf("\n请输入 1 ~ 6 之间的整数 \n\n");
				break;
		}
		mainChance = 0;
		showMenu();
		printf("请输入:");
		scanf("%d", &mainChance);
		fflush(stdin);
	}
	return 0;
}


