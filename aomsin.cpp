#include<cstdio>

int main()
{
    unsigned long long n,m,sum=0,tempx,tempy,temp,tempz;
    scanf("%llu",&n);
    m=(n-1)*n;
    m=m/2;
    m=m%2559;
    printf("%llu\n",m);
    unsigned long long x[n],y[n],i,a[n-1],b[n-1],j;
    for(i=0;i<n;i++)
    {
        scanf("%llu",&x[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%llu",&y[i]);
    }
    if(n%2==1)
    {
        for(i=0;i<n/2+1;i++)
        {
            tempx=(x[n-i-1]-x[0])*(y[n-i-1]-y[0]);
            tempy=(x[n-1]-x[i])*(y[n-1]-y[i]);
            tempz=(x[n-i-1]-x[i])*(y[n-i-1]-y[i]);
            temp=tempx+tempy-tempz;
            temp=temp%2559;
            sum+=temp;
        }
        sum=sum%2559;
    }
    else
    {
        for(i=0;i<n;i++)
        {
            if(i<n/2)
            {
                tempx=(x[n-i-1]-x[0])*(y[n-i-1]-y[0]);
                tempy=(x[n-1]-x[i])*(y[n-1]-y[i]);
                tempz=(x[n-i-1]-x[i])*(y[n-i-1]-y[i]);
                temp=tempx+tempy-tempz;
                temp=temp%2559;
                //printf("%d ",temp);
                sum+=temp;
            }
            else
            {
                tempx=(x[n-i-1]-x[0])*(y[n-i-1]-y[0]);
                tempy=(x[n-1]-x[i])*(y[n-1]-y[i]);
                //tempz=(x[i]-x[n-i-1])*(y[i]-y[n-i-1])*2;
                temp=tempx+tempy;
                temp=temp%2559;
                //printf("%d ",temp);
                sum+=temp;
            }
        }
        sum+=(x[n-2]-x[1])*(y[n-2]-y[1]);
        sum=sum%2559;
    }
    printf("%llu",sum);
    return 0;
}
