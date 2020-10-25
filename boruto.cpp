#include<cstdio>
#include<queue>
 
using namespace std;
 
queue<int> a,b;
 
int m,n,ans=1,cnt,loop1,loop2;
 
char x[50][50];
int dynamic[50][50];
 
void init_dynamic()
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            dynamic[i][j]=0;
}
 
int main()
{
    scanf("%d %d",&n,&m);
    int i,j;
    m+=1;
    for(i=0;i<n;i++)
        scanf("%s",&x[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(x[i][j] == 'W')
            {
                cnt=1;
                a.push(i);
                b.push(j);
                dynamic[i][j]=1;
                while(!a.empty())
                {
                    int verti=a.front(),hori=b.front();
                    a.pop(),b.pop();
                    if(verti-1 >= 0 && dynamic[verti][hori]+1 <= m && dynamic[verti-1][hori]==0 && x[verti-1][hori]=='W') //up
                    {
                        dynamic[verti-1][hori]=dynamic[verti][hori]+1;
                        cnt++;
                        a.push(verti-1);
                        b.push(hori);
                    }
                    if(verti+1 < n && dynamic[verti][hori]+1 <= m && dynamic[verti+1][hori]==0  && x[verti+1][hori]=='W') //down
                    {
                        dynamic[verti+1][hori]=dynamic[verti][hori]+1;
                        cnt++;
                        a.push(verti+1);
                        b.push(hori);
                    }
                    if(hori+1 < n && dynamic[verti][hori]+1 <= m && dynamic[verti][hori+1]==0  && x[verti][hori+1]=='W') //right
                    {
                        dynamic[verti][hori+1]=dynamic[verti][hori]+1;
                        cnt++;
                        a.push(verti);
                        b.push(hori+1);
                    }
                    if(hori-1 >= 0 && dynamic[verti][hori]+1 <= m && dynamic[verti][hori-1]==0  && x[verti][hori-1]=='W') //left
                    {
                        dynamic[verti][hori-1]=dynamic[verti][hori]+1;
                        cnt++;
                        a.push(verti);
                        b.push(hori-1);
                    }
                }
                if(cnt > ans)
                    ans=cnt;
                /*
                for(loop1=0;loop1 < n;loop1++)
                {
                    for(loop2=0;loop2 < n;loop2++)
                    {
                        printf("%d ",dynamic[loop1][loop2]);
                    }
                    printf("\n");
                }
                printf("\n");
                */
                init_dynamic();
            }
        }
    }
    printf("%d",ans);
    return 0;
}