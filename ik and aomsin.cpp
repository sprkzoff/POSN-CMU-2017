#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

queue<int> q;

int n,m,ik=99999,aomsin=99999;

int graph1[400+1][400+1],graph2[400+1][400+1],visited1[400+1],visited2[400+1];

//graph1 = ik
//graph2 = aomsin

bool impossible()
{
    if(ik==99999 || aomsin==99999)
        return true;
    else return false;
}

void ikbfs(int cnt)
{
    if(!q.empty())
    {
        int temp=q.front();
        printf("%d->",temp);
        if(temp == n)
        {
            if(ik > cnt) //find minimum way
                ik=cnt;
        }
        q.pop();
        int i;
        for(i=1;i<=n;i++)
        {
            if(visited1[i]==0 && graph1[temp][i]==1)
            {
                visited1[i]=1;
                q.push(i);
            }
        }
        ikbfs(cnt+1);
    }
}

void aomsinbfs(int cnt)
{
    if(!q.empty())
    {
        int temp=q.front();
        printf("%d->",temp);
        if(temp == n)
        {
            if(aomsin > cnt) //find minimum way
                aomsin=cnt;
        }
        q.pop();
        int i;
        for(i=1;i<=n;i++)
        {
            if(visited2[i]==0 && graph2[temp][i]==1)
            {
                visited2[i]=1;
                q.push(i);
            }
        }
        aomsinbfs(cnt+1);
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    int i,j;
    for(i=1;i<=n;i++) //create complete graph2
    {
        for(j=1;j<=n;j++)
        {
            if(i != j)
                graph2[i][j]=1;
        }
    }
    int a,b;
    for(i=0;i<m;i++) // create graph1 and init graph2
    {
        scanf("%d %d",&a,&b);
        graph1[a][b]=1;
        graph1[b][a]=1;
        graph2[a][b]=0;
        graph2[b][a]=0;
    }
    visited1[1]=1;
    visited2[1]=1;
    q.push(1);
    ikbfs(0);
    printf("\n");
    q.push(1);
    aomsinbfs(0);
    printf("\n");
    printf("ik=%d aomsin=%d\n",ik,aomsin);
    if(impossible())
        printf("Impossible");
    else printf("%d",max(ik,aomsin));
    return 0;
}
