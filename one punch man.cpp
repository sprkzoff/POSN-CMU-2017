#include<cstdio>

using namespace std;

bool plate[5000+1][4000+1];

int main()
{
    int n,w,h;
    //printf("check\n");
    scanf("%d %d %d",&n,&w,&h);
    int i,j,k,x1,x2,y1,y2;
    while(n--)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for(i=y1;i<=y2;i++)
        {
            for(j=x1;j<=x2;j++)
            {
                plate[i][j]=1;
            }
        }
    }
    int cnt=0;
    for(i=1;i<=h;i++)
    {
        for(j=1;j<=w;j++)
        {
            cnt+=plate[i][j];
        }
    }
    printf("%d",cnt);
    return 0;
}
