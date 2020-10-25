#include<cstdio>
#include<algorithm>

using  namespace std;

int n;

int dynamic[10000+1];

int boss,x[1000+1];

int main()
{
    int i,j;
    scanf("%d %d",&boss,&n);
    for(i=1;i<=10000;i++)
        dynamic[i]=999999;
    dynamic[1]=1;
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
        dynamic[x[i]]=1;
    }
    for(i=1;i<=10000;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i-x[j] >= 0)
                dynamic[i]=min(dynamic[i-x[j]]+1,dynamic[i]);
            dynamic[i]=min(dynamic[i-1]+1,dynamic[i]);
        }
    }
    /*
    for(i=1;i<=boss;i++)
        printf("%d ",dynamic[i]);
    */
    printf("%d",dynamic[boss]);
    return 0;
}
