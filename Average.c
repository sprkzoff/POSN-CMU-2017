#include<stdio.h>

int main()
{
    int m,i,n,j,x[100];
    double sum;
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&n);
        sum=0;
        for(j=0;j<n;j++)
        {
            scanf("%d",&x[j]);
            sum=sum+x[j];
        }
        sum=sum/(double)n;
        printf("%.2lf\n",sum);
    }
    return 0;
}
