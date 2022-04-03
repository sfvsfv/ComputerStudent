#include<stdio.h>
int isprime(int n)
{
    int i=2;
    for(i;i<n;i++)
    {
        if(n%i==0)
        break;            
    }
    if(i==n)
    return 1;
    else
    return 0;
}
 
int main()
{
    int m,n,count=0;
    int sum=0;
    scanf("%d %d",&m,&n);
    for(int i=m ;i<=n;i++)
    {
        if(isprime(i)==1)
        {
        count++;
        sum+=i;
		}
    }
    printf("count=%d,sum=%d",count,sum);
    return 0;
}
