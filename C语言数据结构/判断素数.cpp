#include <stdio.h>
int isprime(int n)
{
int i;
for (i=2; i<=n-1; i++) { if (n %i==0) return 0;}
return 1;
}
int main()
{
int x,y;
printf("请输λ一个整数: ");
scanf("%d",&x);
y= isprime(x);
if(y==0)
printf( "NO\n");
else
printf( "YES\n");
}

