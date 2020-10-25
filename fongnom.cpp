#include<cstdio>
#include<algorithm>

using namespace std;

int parent[100000+1];

int findparent(int x)
{
    if(x == parent[x])
        return x;
    else
    {
        parent[x] = findparent(parent[x]);
        return findparent(parent[x]);
    }
}

int main()
{
    char comd;
    int n,m,i,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        parent[i]=i;
    while(m--)
    {
        scanf(" %c ",&comd);
        scanf("%d %d",&a,&b);
        if(comd == 'c')
        {
            if(a>b)
                swap(a,b);
            int u=findparent(a),v=findparent(b);
            parent[u]=v;
        }
        else
        {
            int u=findparent(a),v=findparent(b);
            if(v==u)
                printf("yes\n");
            else printf("no\n");
        }
        /*
        for(i=1;i<=n;i++)
            printf("%d ",parent[i]);
        printf("\n");
        */
    }
    return 0;
}
