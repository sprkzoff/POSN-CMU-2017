#include<cstdio>
#include<algorithm>
#include<cstring>
 
using namespace std;
 
char in[1000+2];
 
int dynamic[1000+2][1000+2];
 
int main()
{
    int i,k,n;
    scanf("%s",&in);
    n=strlen(in);
    for(i=0;i<n;i++)
        dynamic[i][i]=1;
    for(i=0;i+1<n;i++)
    {
        if(in[i]==in[i+1])
            dynamic[i][i+1]=2;
        else dynamic[i][i+1]=1;
    }
    for(k=2;k<n;k++)
    {
        for(i=0;i+k<n;i++)
        {
            if(in[i]==in[i+k])
                dynamic[i][i+k]=2+dynamic[i+1][i+k-1];
            else dynamic[i][i+k]=max(dynamic[i][i+k-1],dynamic[i+1][i+k]);
        }
    }
    /*
    for(i=0;i<n;i++)
    {
        for(k=0;k<n;k++)
        {
            printf("%d ",dynamic[i][k]);
        }
        printf("\n");
    }
    */
    printf("%d",dynamic[0][n-1]);
    return 0;
}