#include<cstdio>
#include<climits>
#include<vector>
#include<queue>
 
using namespace std;
 
int v;
 
struct Edge
{
    int weight;
    int to;
    bool operator<(const Edge &a)const
    {
        return a.weight < weight;
    }
};
 
priority_queue<Edge> q;
 
int path[100000+1];
 
vector<Edge> graph[100000+1];
 
int main()
{
    int i,e,from,start,finish;
    for(i=0;i<100000+1;i++) //init path
        path[i]=INT_MAX;
    printf("Input >> Node Edge Start_node Finish_node : ");
    scanf("%d %d %d %d",&v,&e,&start,&finish);
    for(i=0;i<e;i++)
    {
        int a,b;
        Edge edge;
        scanf("%d %d %d",&a,&b,&edge.weight);
        edge.to=b;
        graph[a].push_back(edge);
        edge.to=a;
        graph[b].push_back(edge);
    }
    path[start]=0;
    Edge c;
    c.to=start;
    c.weight=0;
    q.push(c);
    while(!q.empty())
    {
        Edge d=q.top();
        int temp=d.to;
        q.pop();
        for(i=0;i<graph[temp].size();i++)
        {
            if(path[graph[temp][i].to] > path[temp]+graph[temp][i].weight)
            {
                q.push(graph[temp][i]);
                path[graph[temp][i].to] = path[temp]+graph[temp][i].weight;
            }
        }
    }
    printf("Shortest path from Node#%d to Node#%d = %d\n",start,finish,path[finish]);
    return 0;
}