#include<stdio.h>
#include<string.h>

int main()
{
    char x[100];
    int y[10];
    scanf("%s",&x);
    int i;
    for(i=0;i<10;i++)
    {
        y[i]=0;
    }
    for(i=0;i<strlen(x);i++)
    {
        if(x[i]=='-')
        {
            continue;
        }
        else
        {
            y[x[i]-48]++;
        }
    }
    char a='0';
    int max=y[0];
    for(i=0;i<10;i++)
    {
        if(y[i]>max)
        {
            max=y[i];
            a=i-48;
        }
    }
    printf("%c",a);
    return 0;
}
