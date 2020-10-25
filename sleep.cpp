#include<cstdio>
using namespace std;
int main()
{
    int n,i,temp,sleep;
    scanf("%d",&n);
    int wake,maxsleep=-999999,minwake=9999999;
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&sleep,&wake);
        if(sleep > maxsleep)
            maxsleep=sleep;
        if(wake < minwake)
            minwake=wake;
    }
    printf("%s",minwake-maxsleep < 0 ? "yes":"no");
    return 0;
}
