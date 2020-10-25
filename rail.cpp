//rail
#include<cstdio>
#include<stack>

using namespace std;

stack<int> a;

int main()
{
    int n,i,now;
    scanf("%d",&n);
    int x[n];
    while(1)
    {
        for(i=n-1;i>=0;i--)
        {
            scanf("%d",&x[i]);
            if(x[n-1]==0)
            {
                return 0;
            }
        }
        now=n;
        for(i=0;i<n;i++)
        {
            a.push(x[i]);
            while(a.size()>0 && a.top() == now)
            {
                a.pop();
                now--;
            }
        }
        if(now == 0)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
            while(!a.empty())
            {
                a.pop();
            }
        }
    }
    return 0;
}
