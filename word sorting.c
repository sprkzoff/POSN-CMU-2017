#include<stdio.h>
#include<string.h>

int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    char x[3][50],z[50];
    for(i=0;i<n;i++)
    {
        scanf("%s %s %s",&x[0],&x[1],&x[2]);
        for(j=0;j<3;j++)
        {
            for(k=0;k<2;k++)
            {
                if(strcmp(x[k],x[k+1])>0)
                {
                    strcpy(z,x[k]);
                    strcpy(x[k],x[k+1]);
                    strcpy(x[k+1],z);
                }
            }
        }
        printf("%s %s %s\n",x[0],x[1],x[2]);
    }
    return 0;
}
