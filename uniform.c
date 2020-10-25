#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int upper=0,lower=0;
    printf("Enter word : ");
    char x[51];
    gets(x);
    int i;
    for(i=0;i<strlen(x);i++)
    {
        if(x[i]>='A' && x[i]<='Z')
        {
            upper++;
        }
        else if(x[i]>='a' && x[i]<='z')
        {
            lower++;
        }
    }
    if(lower==upper)
    {
        if(x[0]>='A' && x[0]<='Z')
        {
            for(i=0;i<strlen(x);i++)
                printf("%c",toupper(x[i]));
        }
        else
        {
            for(i=0;i<strlen(x);i++)
                printf("%c",tolower(x[i]));
        }
    }
    else if(lower > upper)
    {
        for(i=0;i<strlen(x);i++)
            printf("%c",tolower(x[i]));
    }
    else
    {
        for(i=0;i<strlen(x);i++)
            printf("%c",toupper(x[i]));
    }
    return 0;
}
