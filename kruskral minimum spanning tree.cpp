#include<cstdio>
#include<algorithm>
#include<functional>

using namespace std;

struct Edge
{
    int from;
    int to;
    int weight;
    bool operator <(const Edge &a)const
    {
        return weight < a.weight;
    }
};

int node_union(int x,int parent[])
{
    if(x!=parent[x])
        parent[x] = node_union(parent[x],parent);
    return parent[x];
}

int main()
{
    int V,E;
    scanf("%d %d",&V,&E);
    int i,parent[E];
    struct Edge edge[E];
    for(i=0;i<E;i++)
    {
        parent[i]=i;
        scanf("%d %d %d",&edge[i].from,&edge[i].to,&edge[i].weight);
        edge[i].from--;
        edge[i].to--;
    }
    sort(edge,edge+E);
    /*
    for(i=0;i<E;i++)
    {
        printf("%d ",edge[i].weight);
    }
    */
    int row=0;
    for(i=0;i<E;i++)
    {
        if(node_union(edge[i].from,parent) != node_union(edge[i].to,parent))
        {
            printf("node%d to node%d = %d\n",edge[i].from+1,edge[i].to+1,edge[i].weight);
            parent[edge[i].from]=parent[edge[i].to];
            row++;
        }
        if(row==V-1)
        {
            break;
        }
    }
    return 0;
}
