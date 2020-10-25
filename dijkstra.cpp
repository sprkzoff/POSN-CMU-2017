#include<cstdio>
#include<climits>
#include<queue>

using namespace std;

struct Edge
{
    int weight;
    int from;
    int to;
    bool operator<(Edge a)const
    {
        return weight < a.weight;
    }
};

priority_queue<Edge> pq;

int main()
{
    int V,E,i;
    scanf("%d %d",&V,&E);
    Edge edge[E];
    int path[V+1];
    int source;
    for(i=0;i<E;i++)
    {
        scanf("%d %d %d",&edge[i].from,&edge[i].to,&edge[i].weight);
    }
    scanf("%d",&source);
    for(i=0;i<V+1;i++)
    {
        path[i]=INT_MAX;
    }
    path[source]=0;
    pq.push(...........);
    while(!pq.empty())
    {

    }
    return 0;
}
