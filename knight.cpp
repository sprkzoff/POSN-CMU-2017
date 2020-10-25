#include<cstdio>
#define N 8
#include<queue>

using namespace std;

queue<int> x,y;

int grid[N][N];

void bfs(int count)
{
    int i,j;
    if(!x.empty() && !y.empty())
    {
        i=x.front();
        j=y.front();
        x.pop();
        y.pop();

        if(grid[i][j] == -1)
            grid[i][j]=count;

        if(grid[i][j] > count)
            grid[i][j]=count;
        if(i-2 >=0 && j-1 >= 0 && grid[i-2][j-1] == -1)
        {
            //grid[i-2][j-1]=count+1;
            x.push(i-2);
            y.push(j-1);
            bfs(count+1);
        }
        if(i-2 >=0 && j+1 < N && grid[i-2][j+1] == -1)
        {
            //grid[i-2][j+1]=count+1;
            x.push(i-2);
            y.push(j+1);
            bfs(count+1);
        }
        if(i-1 >=0 && j-2 >= 0 && grid[i-1][j-2] == -1)
        {
            //grid[i-1][j-2]=count+1;
            x.push(i-1);
            y.push(j-2);
            bfs(count+1);
        }
        if(i+1 < N && j-2 >= 0 && grid[i+1][j-2] == -1)
        {
            //grid[i+1][j-2]=count+1;
            x.push(i+1);
            y.push(j-2);
            bfs(count+1);
        }
        if(i+2 < N && j+1 < N && grid[i+2][j+1] == -1)
        {
            //grid[i+2][j+1]=count+1;
            x.push(i+2);
            y.push(j+1);
            bfs(count+1);
        }
        if(i+2 < N && j-1 >= 0 && grid[i+2][j-1] == -1)
        {
            //grid[i+2][j-1]=count+1;
            x.push(i+2);
            y.push(j-1);
            bfs(count+1);
        }
        if(i+1 < N && j+2 < N && grid[i+1][j+2] == -1)
        {
            //grid[i+1][j+2]=count+1;
            x.push(i+1);
            y.push(j+2);
            bfs(count+1);
        }
        if(i-1 >=0 && j+2 < N && grid[i-1][j+2] == -1)
        {
            //grid[i-1][j+2]=count+1;
            x.push(i-1);
            y.push(j+2);
            bfs(count+1);
        }
    }
}

int main()
{
    char start[3],stop[3];
    int i1,j1,i2,j2;
    scanf("%s %s",&start,&stop);
    i1=start[0] - 'a';
    j1=start[1] - '1';
    i2=stop[0] - 'a';
    j2=stop[1] - '1';
    //printf("(%d,%d) (%d,%d)\n",i1,j1,i2,j2);

    //format input pass

    x.push(i1);
    y.push(j1);
    int i,j;

    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            grid[i][j]=-1;
    bfs(0);
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%5d",grid[i][j]);
        }
        printf("\n");
    }
    printf("%d",grid[i2][j2]);
    return 0;
}
