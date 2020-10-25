#include<stdio.h>
#include<string.h>
int main()
{
    char x[51];
    gets(x);
    printf("%s",strrev(x));
    return 0;
}
