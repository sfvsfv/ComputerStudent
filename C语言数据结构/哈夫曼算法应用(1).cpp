//
// Created by andyzhong on 2021/7/1.
//
#include<iostream>

#include<cstdio>

#include<cstring>

#include<cstdlib>



using namespace std;



char filenamemi[100];

char filefile[100];

char filebian[100];



typedef struct

{
    int weight;

    char flag;

    int parent, lchild, rchild;

} HTNode, *HuffmanTree;

typedef struct ASCII

{
    char flag;

    int c;

    struct ASCII *next;

} ASCII, *LinkList;

typedef struct txt

{
    char flag;

    char huffman[5000];

} txtNode;



LinkList L;

typedef char **HuffmanCode;



bool InitList(LinkList &L)//初始化链表

{
    L = new ASCII;

    L->c  = 1;

    L->next = NULL;

    return true;

}



void Show(LinkList L)//显示链表

{
    LinkList p;

    p = L->next;

    while(p)

    {
        printf("  %c, %d\n", p->flag, p->c);

        p = p->next;

    }

    cout<<endl;

}



int Choice() //选择文件以及创建权重值

{
    FILE *fp;

    char a;

    int num = 0, key = 0;

    int instance = 0;

    LinkList  p, s, m;

    InitList(L);

    s = L;

    m = L;

    getchar();

    //char filefile[100] ;

    while(!key)

    {
        printf("请输入你要打开的文件名及路径，如c:\\users\\lenovo\\desktop\\7\\1.txt\n");

        gets(filefile);

        if ((fp=fopen(filefile,"r"))==NULL)

        {
            printf("打开文件%s出现错误\n",filefile);

            key = 0;

            return 0;

        }

        key = 1;

    }



    while((a = fgetc(fp)) != EOF)

    {
        s = L->next;

        printf("%c ", a);

        while(s)

        {
            if(s->flag == a)//如果在文本中出现了, 当前字符, 那么当前字符的权重值++

            {
                s->c++;

                instance = 1;

                break;

            }

            s = s->next;

        }

        if(instance == 0)//如果当前文本没有该字符, 那么, 创建该字符,插入到文本当中

        {
            p = new ASCII;

            p->flag = a;

            p->c = 1;

            m->next = p;

            p->next = NULL;

            m = p;

            num++;//文本中多少结点

        }

        instance = 0;

    }

    cout<<endl;

    Show(L);

    fclose(fp);

    return num;

}



void Select(HuffmanTree &HT, int num, int *s1, int *s2) //寻找两个最小的且双亲为0的最小节点

{
    int i, sec = 0, fir = 0;//a是次小, b是最小

    int second = -1, first = -1;

    HTNode L1, L2;//L1次小, L2最小

    for(i = num; i >= 1; i--)//选择两个双亲部不为0的结点

    {
        if(HT[i].parent == 0 && second == -1) second = i;

        else if(HT[i].parent == 0 && first == -1) first = i;



        if(first!=-1 && second!=-1) break;

    }

    //cout<<second<<" "<<first<<endl;

    if(HT[second].weight > HT[first].weight)

    {
        L1 = HT[second];

        L2 = HT[first];

        sec = second;

        fir = first;

    }

    else

    {
        L1 = HT[first];

        L2 = HT[second];

        sec = first;

        fir = second;

    }



    for(i = num; i >= 1; i--)//从剩下的节点中找到两个最小的节点

    {
        if( (HT[i].weight < L2.weight) &&(HT[i].parent == 0) && i!=second && i!=first)

        {
            L1 = L2;

            L2 = HT[i];

            sec = fir;

            fir = i;

        }

        else if( (HT[i].weight < L1.weight) && (HT[i].parent == 0) && i!=second && i!=first)

        {
            L1 = HT[i];

            sec = i;

        }

    }

    *s1 = fir;

    *s2 = sec;

}



bool CreatHuffmanaTree(HuffmanTree &HT, int num) //创建哈夫曼树

{
    int m, i;

    LinkList p;

    p = L->next;

    if(num <= 1) return false;

    m = 2*num-1;

    HT = new HTNode[m+1];

    for(i = 1; i <= m; i++)

    {
        HT[i].parent = 0;

        HT[i].lchild = 0;

        HT[i].rchild = 0;

    }

    for(i = 1; i <= num; i++)

    {
        HT[i].weight = p->c;

        HT[i].flag = p->flag;

        p = p->next;

    }



    int s1=0, s2=0;

    for(i = num+1; i <= m; i++)

    {
        Select(HT, i-1, &s1, &s2);

        //cout<<s1<<" "<<s2<<endl;

        HT[s1].parent = i;

        HT[s2].parent = i;

        HT[i].lchild = s1;

        HT[i].rchild = s2;

        HT[i].weight = HT[s1].weight + HT[s2].weight;

    }

    return true;

}



bool CreatHuffmanaCode(HuffmanTree HT, int num) //创建哈夫曼编码

{
    char  *cd;

    int i, c, f, start, key = 0;

    FILE *fp;

    char flag;

    getchar();

    while(!key)

    {
        printf("请输入你要保存密码本的文件名及路径，如c:\\users\\lenovo\\desktop\\7\\密码本.txt\n");

        gets(filenamemi);

        if ((fp=fopen(filenamemi,"w"))==NULL)

        {
            printf("保存文件%s出现错误, 请重新输入\n",filenamemi);

            key = 0;

        }

        key = 1;

    }

    cd = new char[num];

    cd[num-1] = '\0';

    for(i = 1; i <= num; i++)

    {
        start = num-1;

        c = i;

        f = HT[i].parent;

        flag = HT[i].flag;

        while(f != 0)

        {
            --start;

            if(HT[f].lchild == c) cd[start] = '0';

            else cd[start] = '1';

            c = f;

            f = HT[f].parent;

        }

        printf("%c %s\n", flag, &cd[start]);

        fprintf(fp,"%c %s\n", flag, &cd[start]);

    }

    delete cd;

    fclose(fp);

}

bool CreatTxtCode(int num)//创建文本编码

{
    FILE *fp, *fp1, *fp2;

    int key = 0;

    //char filename[100];

    txtNode txt[257];

    char a;

    getchar();

    while(!key)

    {
        printf("请输入你要保存编码的文件名及路径，如c:\\users\\lenovo\\desktop\\7\\1.cod\n");

        gets(filebian);

        if ((fp=fopen(filebian,"w"))==NULL)

        {
            printf("保存文件%s出现错误, 请重新输入\n",filebian);

            key = 0;

        }

        key = 1;



    }

    int i = 0, nu = 1, j;

    fp1 = fopen(filenamemi,"r");

    fp2 = fopen(filefile,"r");

    char interim[1000];

    fgets(interim, 100, fp1);

    while(!feof(fp1))

    {
        txt[nu-1].flag = interim[0];

        i = strlen(interim);

        for(j = 2; j < i-1; j++)

        {
            txt[nu-1].huffman[j-2] = interim[j];

        }

        fgets(interim, 100, fp1);

        nu++;

    }

    for(i = 0; i <= nu; i++)

    {
        cout<<txt[i].flag<<"  "<<txt[i].huffman<<endl;

    }

    while((a = fgetc(fp2)) != EOF)

    {
        for(i = 0; i <= nu; i++)

        {
            if(a == txt[i].flag)

            {
                fprintf(fp,"%s",txt[i].huffman);

            }

        }

    }

    fclose(fp);

    fclose(fp1);

    fclose(fp2);

    return true;

}

bool ReductionTxt(HuffmanTree HT, int num)//创建文本节点

{
    FILE *fp, *fp1;//fp----编码文件    fp1------还原之后的文件

    int key = 0;

    char filename[100],  filename1[100];

    char a;

    getchar();

    if ((fp=fopen(filebian,"r"))==NULL)

    {
        printf("打开文件%s出现错误\n",filebian);

        key = 0;

        return false;

    }

    while(!key)

    {
        printf("请输入你要保存的文件名及路径，如c:\\users\\lenovo\\desktop\\7\\2.txt\n");

        gets(filename1);

        if ((fp1=fopen(filename1,"w"))==NULL)

        {
            printf("打开文件%s出现错误\n",filename1);

            key = 0;

            return false;

        }

        key = 1;

    }



    int kk = 2*num-1;

    while((a = fgetc(fp)) != EOF)

    {
        if(a == '0')

        {
            kk = HT[kk].lchild;

        }

        else

        {
            kk = HT[kk].rchild;

        }



        if( (HT[kk].lchild == 0)  && (HT[kk].rchild == 0) )

        {
            fprintf(fp1,"%c", HT[kk].flag);

            kk = 2*num-1;

        }

    }

    fclose(fp);

    fclose(fp1);

    return true;

}



void zip()//压缩文件

{
    int fpnumber=0,fp1number=0;

    FILE *fp, *fp1;//fp----编码文件    fp1------压缩文件

    int key = 0, in, i;

    char filename[100],  filename1[100];

    char a;

    int twopower[11] = {1,2,4,8,16,32,64,128,256,512,1024};

    getchar();

    if ((fp=fopen(filebian,"r"))==NULL)

    {
        printf("打开文件%s出现错误\n",filebian);

        key = 0;

        return;

    }

    key = 0;

    while(!key)

    {
        printf("请输入保存的文件名及路径，如C:\\users\\lenovo\\desktop\\7\\2.cod\n");

        gets(filename1);

        if ((fp1=fopen(filename1,"w"))==NULL)

        {
            printf("打开文件%s出现错误\n",filename1);

            key = 0;

            return ;

        }

        key = 1;

    }

    //fp1=fopen("C:\\users\\lenovo\\desktop\\7\\2.cod","w");

    in = 0;

    int sum = 0, fla = 2;

    a = fgetc(fp);

    while(!feof(fp))

    {
        sum = sum + int(a-'0')*twopower[7-in];

        //cout<<int(a-'0')<<" "<<twopower[in]<<" "<<sum<<endl;

        in++;

        a = fgetc(fp);

        if(in == 8 || feof(fp))

        {
            in = 0;

            fprintf(fp1, "%d ", sum);

            sum = 0;

        }

    }

    fseek(fp,0L,SEEK_END);   /*利用fseek函数将指针定位在文件结尾的位置*/

    fpnumber=ftell(fp);   /*利用ftell函数返回指针相对于文件开头的位置，以字节计算*/

    printf("原文件所占的字节数为%ld个\n",fpnumber);   /*进行输出*/

    fseek(fp1,0L,SEEK_END);   /*利   用fseek函数将指针定位在文件结尾的位置*/

    fp1number=ftell(fp1);   /*利用ftell函数返回指针相对于文件开头的位置，以字节计算*/

    printf("压缩后所占的字节数为%ld个\n",fp1number);   /*进行输出*/

    printf("压缩比为%d/%d",fp1number,fpnumber);

    fclose(fp);

    fclose(fp1);

}





int main()

{
    int num;

    HuffmanTree L;

    start:

    printf("******************************************************************\n\n");

    printf("哈夫曼编码译码器\n\n");

    printf("*\t1、选择需要进行编码的文件\t\t*\n\n");

    printf("*\t2、建立哈夫曼树\t\t\t\t*\n\n");

    printf("*\t3、建立密码本并对文件编码\t\t*\n\n");

    printf("*\t4、选择需要进行解码的文件并解码\t\t*\n\n");

    printf("*\t5、按位压缩方式对文件进行压缩\t\t*\n\n\n");

    printf("******************************************************************\n\n");

    int option = 0;

    cin>>option;

    while(1)

    {
        switch(option)

        {
            case 1:

                num = Choice();

                break;

            case 2:

                if(CreatHuffmanaTree(L, num))cout<<"成功"<<endl;

                break;

            case 3:

                CreatHuffmanaCode(L, num);

                if(CreatTxtCode(num)) cout<<"成功"<<endl;

                break;

            case 4:

                if(ReductionTxt(L, num)) cout<<"成功"<<endl;

                break;

            case 5:

                zip();

                cout<<"压缩成功";

                break;

        }

        goto start;

    }

    return 0;

}
