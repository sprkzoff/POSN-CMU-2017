#include<cstdio>
 
using namespace std;
 
int x[1000+1][1000+1],num[2][1000000+1];
 
int main()
{
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    int cnt=1,left=0,right=m-1,up=0,down=n-1;
    while(cnt <= n*m)
    {
        for(i=left;i<=right;i++)
        {
            x[up][i]=cnt;
            num[0][cnt]=up;
            num[1][cnt]=i;
            cnt++;
        }
        up++;
        for(i=up;i<=down;i++)
        {
            x[i][right]=cnt;
            num[0][cnt]=i;
            num[1][cnt]=right;
            cnt++;
        }
        right--;
        for(i=right;i>=left;i--)
        {
            x[down][i]=cnt;
            num[0][cnt]=down;
            num[1][cnt]=i;
            cnt++;
        }
        down--;
        for(i=down;i>=up;i--)
        {
            x[i][left]=cnt;
            num[0][cnt]=i;
            num[1][cnt]=left;
            cnt++;
        }
        left++;
    }
    /*
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%3d ",x[i][j]);
        }
        printf("\n");
    }
    for(i=1;i<=n*m;i++)
        printf("cnt=%d i=%d j=%d\n",i,num[0][i],num[1][i]);
    */
    int ask;
    scanf("%d",&ask);
    if(ask > n*m)
        printf("0");
    else printf("%d %d",num[0][ask]+1,num[1][ask]+1);
    return 0;
}