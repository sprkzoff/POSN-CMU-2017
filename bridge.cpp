#include<cstdio>
#include<algorithm>

using namespace std;

int dynamic[10000+1][10000+1],x[10000+1],y[10000+1];

int main()
{
    int i,n,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&x[i]);
    for(i=0;i<n;i++)
        scanf("%d",&y[i]);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
                dynamic[i][j]=dynamic[i-1][j-1]+1;
            else dynamic[i][j]=max(dynamic[i-1][j],dynamic[i][j-1]);
        }
    }
    /*
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            printf("%d ",dynamic[i][j]);
        }
        printf("\n");
    }
    */
    printf("%d",dynamic[n][n]);
    return 0;
}
