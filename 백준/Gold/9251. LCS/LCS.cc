#include <string>
#include <vector>
#include<iostream>
#include <queue>
#include<algorithm>


using namespace std;

int getDP(vector<vector<int>> &dp, int i, int j)
{
    if (i < 0 || j < 0)
        return 0;
    else
        return dp[i][j];
}

int main() 
{
    string a, b;
    cin >> a >> b;
    int len1 = a.size();
    int len2 = b.size();
    vector<vector<int>> dp(len1, vector<int>(len2, 0));
    for (int i = 0; i <len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            if (a[i] == b[j]) dp[i][j] = getDP(dp, i - 1, j - 1) + 1;
            else dp[i][j] = max(getDP(dp, i - 1, j), getDP(dp, i, j - 1));

         //   cout << dp[i][j] << " ";
        }
       // cout << endl;
    }
  

    cout << dp[len1 - 1][len2 - 1] << endl;;

   // for (int i = 0; i < str.size(); i++)
   //     cout << str[i];

 

    return 0;
}
