#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

priority_queue<int,vector<int>,greater<int> > ans;

int alpha[26];

char in[100000000];

int main()
{
    scanf("%s",&in);
    int i;
    for(i=0;in[i]!=0;i++)
    {
        alpha[in[i]-65]++;
    }
        while(alpha[25] > 0) //ZERO
        {
            alpha[25]--;
            alpha[4]--;
            alpha[17]--;
            alpha[14]--;
            ans.push(0);
        }
        while(alpha[22] > 0) //TWO
        {
            alpha[14]--;
            alpha[19]--;
            alpha[22]--;
            ans.push(2);
        }
        while(alpha[20] > 0) //FOUR
        {
            alpha[5]--;
            alpha[14]--;
            alpha[20]--;
            alpha[17]--;
            ans.push(4);
        }
        while(alpha[23] > 0) //SIX
        {
            alpha[23]--;
            alpha[18]--;
            alpha[8]--;
            ans.push(6);
        }
        while(alpha[6] > 0) //EIGHT
        {
            alpha[4]--;
            alpha[8]--;
            alpha[6]--;
            alpha[7]--;
            alpha[19]--;
            ans.push(8);
        }
        while(alpha[14] > 0 && alpha[13] > 0 && alpha[4] > 0) //ONE
        {
            alpha[14]--;
            alpha[13]--;
            alpha[4]--;
            ans.push(1);
        }
        while(alpha[19] > 0 && alpha[7] > 0 && alpha[17] > 0 && alpha[4] > 1) //THREE
        {
            alpha[19]--;
            alpha[4]-=2;
            alpha[7]--;
            alpha[17]--;
            ans.push(3);
        }
        while(alpha[5] > 0 && alpha[8] > 0 && alpha[21] > 0 && alpha[4] > 0) //FIVE
        {
            alpha[5]--;
            alpha[8]--;
            alpha[21]--;
            alpha[4]--;
            ans.push(5);
        }
        while(alpha[18] > 0 && alpha[4] > 1 && alpha[21] > 0 && alpha[13] > 0) //SEVEN
        {
            alpha[18]--;
            alpha[4]-=2;
            alpha[21]--;
            alpha[13]--;
            ans.push(7);
        }
        while(alpha[13] > 1 && alpha[8] > 0 && alpha[4] > 0) //NINE
        {
            alpha[4]--;
            alpha[8]--;
            alpha[13]-=2;
            ans.push(9);
        }
    while(!ans.empty())
    {
        printf("%d",ans.top());
        ans.pop();
    }
    return 0;
}
