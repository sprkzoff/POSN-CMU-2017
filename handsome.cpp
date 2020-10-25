#include<cstdio>
#include<queue>
 
using namespace std;
 
queue<int> x;
 
int v,e;
int graph[100+1][100+1],mor[100+1];
 
int main()
{
    scanf("%d %d",&v,&e);
    int i,a,b;
    for(i=0;i<e;i++)
    {
        scanf("%d %d",&a,&b);
        graph[a][b]=1;
        graph[b][a]=1;
    }
    x.push(0);
    int temp;
    while(!x.empty())
    {
        temp=x.front();
        x.pop();
        for(i=1;i<v;i++)
        {
            if(graph[temp][i]==1 && mor[i]==0)
            {
                mor[i]=mor[temp]+1;
                x.push(i);
            }
        }
    }
    for(i=1;i<v;i++)
        printf("%d\n",mor[i]);
    return 0;
}