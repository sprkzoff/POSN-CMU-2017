#include<stdio.h>
#include<string.h>
#include<ctype.h>
char trash[1000];

int main()
{
    int n;
    scanf("%d",&n);
    gets(trash);
    int i,j,k;
    char x[100],y[100],z[100];
    for(i=0;i<n;i++)
    {
        gets(x);
        k=0;
        for(j=0;x[j] != NULL;j++)
        {
            if(x[j]==' ' ||  !isalpha(x[j]))
            {
                continue;
            }
            else
            {
                y[k]=x[j];
                y[k]=tolower(y[k]);
                k++;
            }
        }
        y[k]=0;
        strcpy(z,y);
        strrev(z);
        if(strcmp(y,z)==0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
