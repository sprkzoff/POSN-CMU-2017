#include<cstdio>
#include<queue>
 
using namespace std;
 
queue<int> q;
 
int n,m;
 
int visit[100+1],graph[100+1][100+1];
 
int main()
{
    int from,to;
    scanf("%d %d", &n,&m);
    while(m--)
    {
        scanf("%d %d",&to,&from);
        graph[from][to]=1;
        graph[to][from]=-1;
    }
    int i,j,temp,cnt;
    for(i=1;i<=n;i++)
    {
        cnt=0;
        for(j=0;j<=n;j++)
            visit[j]=0;
        q.push(i);
        visit[i]=1;
        while(!q.empty())
        {
            from=q.front();
            q.pop();
            for(j=1;j<=n;j++)
            {
                if(graph[from][j] == 1 && visit[j]==0)
                {
                    visit[j]=1;
                    q.push(j);
                }
            }
        }
        q.push(i);
        while(!q.empty())
        {
            from=q.front();
            q.pop();
            for(j=1;j<=n;j++)
            {
                if(graph[from][j] == -1 && visit[j]==0)
                {
                    visit[j]=1;
                    q.push(j);
                }
            }
        }
        for(j=1;j<=n;j++)
        {
            if(visit[j]==0)
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}