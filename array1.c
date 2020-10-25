#include<stdio.h>

int main()
{
    int n,sum=0;
    printf("Input N : ");
    scanf("%d",&n);
    int x[n];
    printf("Input all number : ");
    int i,a;
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    printf("Input i and j : ");
    int j;
    scanf("%d %d",&i,&j);
    if(i<0 || j<0)
    {
        printf("ERROR");
    }
    else
    {
        for(a=i;a<=j;a++)
        {
            sum=sum+x[a];
        }
        printf("The sum of numbers from index %d to %d is %d",i,j,sum);
    }
    return 0;
}
