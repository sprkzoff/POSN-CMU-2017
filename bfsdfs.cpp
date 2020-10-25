#include<cstdio>
#include<stack>
#include<queue>

using namespace std;

queue<int> q;

stack<int> s;

int graph[1000+1][1000+1],visited1[1000+1],visited2[1000+1];

int V;

void dfs()
{
    if(!s.empty())
    {
        int temp=s.top(),i;
        s.pop();
        printf("%d ",temp);
        for(i=1;i<=V;i++)
        {
            if(graph[temp][i] == 1 && visited2[i]==0)
            {
                visited2[i]=1;
                s.push(i);
                dfs();
            }
        }
    }
}

void bfs()
{
    if(!q.empty())
    {
        int temp=q.front(),i;
        q.pop();
        printf("%d ",temp);
        for(i=1;i<=V;i++)
        {
            if(graph[temp][i] == 1 && visited1[i]==0)
            {
                visited1[i]=1;
                q.push(i);
            }
        }
        bfs();
    }
}

int main()
{
    int E;
    scanf("%d %d",&V,&E);
    int i,a,b;
    for(i=0;i<E;i++)
    {
        scanf("%d %d",&a,&b);
        graph[a][b]=1;
        graph[b][a]=1;
    }
    int start;
    scanf("%d",&start);
    s.push(start);
    q.push(start);
    visited1[start]=1;
    visited2[start]=1;
    bfs();
    printf("\n");
    dfs();
    return 0;
}
