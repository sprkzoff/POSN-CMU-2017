#include<stdio.h>
#include<string.h>
int main()
{
    char x[36],y[36],z[36];
    scanf("%s",&x);
    scanf("%s",&y);
    strrev(x);
    int i,k=0,j;
    for(i=0;x[i]!= 0;i++)
    {
        if(x[i]==',')
        {
            continue;
        }
        else
        {
            z[k]=x[i];
            k++;
        }
    }
    z[k]=0;
    strcpy(x,z);
    for(j=i;j<36;j++)
    {
        x[j]=0;
    }
    k=0;
    strrev(y);
    for(i=0;y[i]!= 0;i++)
    {
        if(y[i]==',')
        {
            continue;
        }
        else
        {
            z[k]=y[i];
            k++;
        }
    }
    z[k]=0;
    strcpy(y,z);
    for(j=i;j<36;j++)
    {
        y[j]=0;
    }
    for(i=0;i<36;i++)
    {
        z[i]=0;
    }
    for(i=0;i<36;i++)
    {
        if((x[i]-48)+(y[i]-48)>=10 && x[i]!=0 && y[i]!=0)
        {
            z[i]=(((x[i]-48)+(y[i]-48))%10)+48;
            x[i+1]++;
        }
        else if(y[i]==0)
        {
            z[i]=x[i];
        }
        else if(x[i]==0)
        {
            z[i]=y[i];
        }
        else if((x[i]-48)+(y[i]-48)< 10 && x[i]!=0 && y[i]!=0)
        {
            z[i]=((x[i]-48)+(y[i]-48))+48;
        }
    }
    strrev(z);
    printf("%s",z);
    return 0;
}
