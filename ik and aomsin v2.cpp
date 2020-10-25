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
    if(visited1[n]==0 || visited2[n]==0)
        return true;
    else return false;
}

void ikbfs(int found)
{
    if(found==1)
    {
        while(!q.empty())
            q.pop();
    }
    if(!q.empty())
    {
        int temp=q.front();
        //printf("%d->",temp);
        q.pop();
        int i;
        if(graph1[temp][n]==1)
        {
            visited1[n]=visited1[temp]+1;
            ikbfs(1);
        }
        for(i=1;i<=n;i++)
        {
            if(visited1[i]!=0 && visited1[i] > visited1[temp]+1 && graph1[temp][i]==1)
            {
                visited1[i]=visited1[temp]+1;
                q.push(i);
            }
            else if(visited1[i]==0 && graph1[temp][i]==1)
            {
                visited1[i]=visited1[temp]+1;
                q.push(i);
            }
        }
        ikbfs(0);
    }
}

void aomsinbfs(int found)
{
    if(found==1)
    {
        while(!q.empty())
            q.pop();
    }
    if(!q.empty())
    {
        int temp=q.front();
        //printf("%d->",temp);
        q.pop();
        int i;
        if(graph2[temp][n]==1)
        {
            visited2[n]=visited2[temp]+1;
            aomsinbfs(1);
        }
        for(i=1;i<=n;i++)
        {
            if(visited2[i]!=0 && visited2[i] > visited2[temp]+1 && graph2[temp][i]==1)
            {
                visited2[i]=visited2[temp]+1;
                q.push(i);
            }
            else if(visited2[i]==0 && graph2[temp][i]==1)
            {
                visited2[i]=visited2[temp]+1;
                q.push(i);
            }
        }
        aomsinbfs(0);
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
    visited1[1]=0;
    visited2[1]=0;
    q.push(1);
    ikbfs(0);
    //printf("\n");
    q.push(1);
    aomsinbfs(0);
    //printf("\n");
    printf("ik=%d aomsin=%d\n",visited1[n],visited2[n]);
    if(impossible())
        printf("Impossible");
    else printf("%d",max(visited1[n],visited2[n]));
    return 0;
}
