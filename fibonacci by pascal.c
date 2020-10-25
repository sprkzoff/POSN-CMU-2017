#include<stdio.h>

long long x[30][30];

int main()
{
    int n;
    printf("Enter N : ");
    scanf("%d",&n);
    long long sum=0;
    int i,j;
    x[0][0]=1;
    for(i=0;i<30;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(j==0 || j==i)
            {
                x[i][j]=1;
            }
            else
            {
                x[i][j]=x[i-1][j]+x[i-1][j-1];
            }
        }
    }
    int k;
    if(n%2==0)
    {
        k=0;
        for(i=n-1;i>=n/2;i--)
        {
            sum=sum+x[i][k];
            k++;
        }
    }
    else if(n%2==1)
    {
        k=0;
        for(i=n-1;i>=(n/2);i--)
        {
            sum=sum+x[i][k];
            k++;
        }
    }
    printf("%lld",sum);
    return 0;
}
