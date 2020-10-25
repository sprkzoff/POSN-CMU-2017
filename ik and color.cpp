#include<cstdio>
#include<queue>

using namespace std;

queue<int> x,y;

int pic[100][100];

char in[100][100+1];

int n;

void bfs()
{
    if(!x.empty() && !y.empty())
    {
        int i,j;
        i=x.front();
        x.pop();
        j=y.front();
        y.pop();
        pic[i][j]=0;
        if(i-1 >= 0 && pic[i-1][j]==1)
        {
            x.push(i-1);
            y.push(j);
        }
        if(i+1 < n && pic[i+1][j]==1)
        {
            x.push(i+1);
            y.push(j);
        }
        if(j-1 >= 0 && pic[i][j-1]==1)
        {
            x.push(i);
            y.push(j-1);
        }
        if(j+1 < n && pic[i][j+1]==1)
        {
            x.push(i);
            y.push(j+1);
        }
        if(j-1 >=0 && i-1 >=0 && pic[i-1][j-1]==1)
        {
            x.push(i-1);
            y.push(j-1);
        }
        if(j-1 >=0 && i+1 < n && pic[i+1][j-1]==1)
        {
            x.push(i+1);
            y.push(j-1);
        }
        if(j+1 < n && i-1 >=0 && pic[i-1][j+1]==1)
        {
            x.push(i-1);
            y.push(j+1);
        }
        if(j+1 < n && i+1 < n && pic[i+1][j+1]==1)
        {
            x.push(i+1);
            y.push(j+1);
        }
        bfs();
    }
}

int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
            scanf("%s",&in[i]);
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            pic[i][j]=in[i][j] - '0';
    /*
    printf("\n\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d",pic[i][j]);
        printf("\n");
    }
    */
    int ans=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(pic[i][j] == 1)
                {
                    x.push(i);
                    y.push(j);
                    bfs();
                    ans++;
                }
            }
        }
    printf("%d",ans);
    return 0;
}
