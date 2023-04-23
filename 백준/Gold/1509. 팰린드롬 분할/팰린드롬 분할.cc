#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include<string>
#include<memory.h>
#define inf 987654321

using namespace std;

string str;
int dp[2501][2501];
//O(n^2)
int dfs(int start_ind, int end_ind)
{
    if (start_ind > end_ind)
        return 1; //여기까지 왔다면 성공

    if (dp[start_ind][end_ind] != -1)
        return dp[start_ind][end_ind];

    if (str[start_ind] == str[end_ind])
        dp[start_ind][end_ind] = dfs(start_ind + 1, end_ind - 1);
    else
        return 0;

    return  dp[start_ind][end_ind];
}

int main()
{
   
   
    cin >> str;
    int len = str.size();
    int answer = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            dfs(i, j);
        }
    }
    int dp2[2501] = { 0, };
    dp2[0] = 1;
    for (int i = 1; i < len; i++)
    {
        dp2[i] = dp2[i - 1] + 1;

        if (dp[0][i] == 1)
        {
            dp2[i] = min(dp2[i],1);
        }
        for (int j = 1; j <i; j++)
        {
            if (dp[j][i] == 1)
            {
                dp2[i] = min(dp2[i], dp2[j - 1] + 1);
            }
        }
    }
    cout << dp2[len-1];
    return 0;
}