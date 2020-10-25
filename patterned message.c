#include<stdio.h>
#include<string.h>
char trash[1000];

int main()
{
    int i=0;
    char c,y[500]={};
    char x[51],z[51]={};
    gets(x);
    int k=0;
    for(i=0;x[i]!=0;i++)
    {
        if(x[i]!=' ')
        {
            z[k]=x[i];
            k++;
        }
    }
    int m,n;
    scanf("%d %d",&m,&n);
    char a[m][n+1];
    int count=0,j;
    k=0;
    i=0;
    gets(trash);
    for(j=0;j<m;j++)
    {
        gets(a[j]);
    }
    int l=strlen(z);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]==' ')
            {
                printf(" ");
            }
            else
            {
                //printf("*");
                printf("%c",z[count%l]);
                count++;
            }
        }
        printf("\n");
    }
    return 0;
}
