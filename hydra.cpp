#include<cstdio>
#include<algorithm>

using namespace std;

int hydra[20000],knight[20000];

int main()
{
    int n,m,i,j,temp;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",&hydra[i]);
    for(i=0;i<m;i++)
        scanf("%d",&knight[i]);
    sort(hydra,hydra+n,greater<int>());
    sort(knight,knight+m);
    int sum=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(knight[j] >= hydra[i] && hydra[i] != -1 && knight[j] != -1)
            {
                hydra[i] = -1;
                sum+=knight[j];
                knight[j] = -1;
                break;
            }
        }
    }
    bool check=true;
    for(i=0;i<n;i++)
    {
        if(hydra[i] != -1)
        {
            check=false;
            break;
        }
    }
    if(check==false)
        printf("Boom");
    else printf("%d",sum);
    return 0;
}
