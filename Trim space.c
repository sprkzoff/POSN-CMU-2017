#include<stdio.h>

int main()
{
    char x[100],y[100];
    gets(x);
    int k=0;
    int i;
    for(i=0;x[i] != 0;i++)
    {
        if(x[i]!= ' ')
        {
            y[k]=x[i];
            k++;
        }
        else
        {
            if(x[i+1] != ' ')
            {
                y[k]=x[i];
                k++;
            }
            else
            {
                continue;
            }
        }
    }
    y[k]=0;
    printf("%s",y);
    return 0;
}
