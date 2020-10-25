#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> ans;

int alpha[26];

char in[100000];

int main()
{
    scanf("%s",&in);
    int i;
    for(i=0;in[i]!=0;i++)
    {
        alpha[in[i]-65]++;
    }
        if(alpha[25] > 0) //ZERO
        {
            alpha[4]-=alpha[25];
            alpha[17]-=alpha[25];
            alpha[14]-=alpha[25];
            while(alpha[25]--)
                ans.push_back(0);
        }
        while(alpha[14] > 0 && alpha[13] > 0 && alpha[4] > 0) //ONE
        {
            alpha[14]--;
            alpha[13]--;
            alpha[4]--;
            ans.push_back(1);
        }
        if(alpha[22] > 0) //TWO
        {
            alpha[14]-=alpha[22];
            alpha[19]-=alpha[22];
            while(alpha[22]--)
                ans.push_back(2);
        }
        while(alpha[19] > 0 && alpha[7] > 0 && alpha[17] > 0 && alpha[4] > 1) //THREE
        {
            alpha[19]--;
            alpha[4]-=2;
            alpha[7]--;
            alpha[17]--;
            ans.push_back(3);
        }
        if(alpha[20] > 0) //FOUR
        {
            alpha[5]-=alpha[20];
            alpha[14]-=alpha[20];
            alpha[17]-=alpha[20];
            while(alpha[20]--)
                ans.push_back(4);
        }
        while(alpha[5] > 0 && alpha[8] > 0 && alpha[21] > 0 && alpha[4] > 0) //FIVE
        {
            alpha[5]--;
            alpha[8]--;
            alpha[21]--;
            alpha[4]--;
            ans.push_back(5);
        }
        if(alpha[23] > 0) //SIX
        {
            alpha[18]-=alpha[23];
            alpha[8]-=alpha[23];
            while(alpha[23]--)
                ans.push_back(6);
        }
        while(alpha[18] > 0 && alpha[4] > 1 && alpha[21] > 0 && alpha[13] > 0) //SEVEN
        {
            alpha[18]--;
            alpha[4]-=2;
            alpha[21]--;
            alpha[13]--;
            ans.push_back(7);
        }
        while(alpha[6] > 0) //EIGHT
        {
            alpha[4]-=alpha[6];
            alpha[8]-=alpha[6];
            alpha[7]-=alpha[6];
            alpha[19]-=alpha[6];
            while(alpha[6]--)
                ans.push_back(8);
        }
        while(alpha[13] > 1 && alpha[8] > 0 && alpha[4] > 0) //NINE
        {
            alpha[4]--;
            alpha[8]--;
            alpha[13]-=2;
            ans.push_back(9);
        }
    sort(ans.begin(),ans.end());
    for(i=0;i<ans.size();i++)
        printf("%d",ans[i]);
    return 0;
}
