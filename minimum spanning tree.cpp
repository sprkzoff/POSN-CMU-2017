#include<cstdio>
#include<climits>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int graph[n][n],parent[n],path[n],inmst[n];
    int i,j,temp,index;
    for(i=0;i<n;i++)
    {
        parent[i]=999;
        inmst[i]=false;
        path[i]=INT_MAX;
        for(j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    path[0]=0;
    parent[0]=0;
    for(i=0;i<n;i++)
    {
        temp=graph[i][1];
        index=1;
        for(j=0;j<n;j++)
        {
            if(graph[i][j]!=0 && graph[i][j]<temp)
            {
                index=j;
                temp=graph[i][j];
            }
        }
        //path[index]=INT_MAX;
        inmst[index]=true;
        for(j=0;j<n;j++)
        {
            if(graph[index][j]!=0 && graph[index][j]<path[j])
            {
                path[j]=graph[index][j];
                parent[j]=index;
            }
        }
    }
    int sum=0;
    for(i=0;i<n;i++)
    {
        printf("%d ",path[i]);
        sum+=path[i];
    }
    printf("%d",sum);
    return 0;
}
