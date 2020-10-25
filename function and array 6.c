#include<stdio.h>

void encode(int n,int x[],char y[])
{
    int i,j,k=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<x[i];j++)
        {
            printf("%c",y[k]-3);
            k++;
        }
        printf(" ");
    }
}

int main()
{
    int n;
    char y[100];
    scanf("%s",y);
    scanf("%d",&n);
    int x[n];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    encode(n,x,y);
    return 0;
}
