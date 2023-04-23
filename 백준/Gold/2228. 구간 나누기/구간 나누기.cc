#include<iostream>
#include<memory.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
using namespace std;



int main()
{
    int n, m;
    cin >> n >> m;
    int input;
    vector<int> vec(n+1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &input);
        vec[i] = input + vec[i - 1];
    }
  
    vector<vector<int>>dp(51, vector<int>(101, -100000000));


    for (int i = 1; i <= m; i++)
    {
        for (int j = (i * 2) - 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j - 1];
           
            for (int k = j; k >= (i * 2) - 1; k--)
            {
                if(k==1 || i==1) 
                    dp[i][j] = max(dp[i][j],  vec[j] - vec[k - 1]);
                else
                    dp[i][j] = max(dp[i][j], dp[i - 1][k - 2] + vec[j] - vec[k - 1]);
            }
        }
    }

    cout << dp[m][n];
    return 0;
}