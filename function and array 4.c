#include<stdio.h>

void readdata(int n,int *x)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",x+i);
    }
}

void printdata(int n,int *x)
{
    int i,k=0,j;
    for(i=0;i<100;i++)
    {
        for(j=0;j<i;j++)
        {
            if(k==n)
            {
                return;
            }
            else
            {
                printf("%d ",*(x+k));
                k++;
            }
        }
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int x[n];
    readdata(n,x);
    printdata(n,x);
    return 0;
}
