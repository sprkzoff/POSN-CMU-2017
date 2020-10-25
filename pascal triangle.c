#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    int x[n][n];
    x[0][0]=1;
    x[1][0]=1,x[1][1]=1;
    for(i=2;i<=n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(j==0)
            {
                x[i][j]=1;
            }
            else if(j==i-1)
            {
                x[i][j]=1;
            }
            else
            {
                x[i][j]=x[i-1][j]+x[i-1][j-1];
            }
        }
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<i;j++)
        {
            printf("%d ",x[i][j]);
        }
        printf("\n");
    }
    return 0;
}
