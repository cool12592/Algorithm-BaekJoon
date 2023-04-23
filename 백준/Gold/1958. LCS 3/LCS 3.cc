#include <string>
#include <vector>
#include<iostream>
#include <queue>
#include<algorithm>


using namespace std;

int getDP(vector<vector<vector<int>>> &dp,  int i, int j,int k)
{
    if (i < 0 || j < 0 || k<0)
        return 0;
    else
        return dp[i][j][k];
}

int main()
{
    string a, b,c;
    cin >> a >> b>>c;
    int len1 = a.size();
    int len2 = b.size();
    int len3 = c.size();

    vector<vector<vector<int>>> dp(100,vector<vector<int>>(100,vector<int>(100,0)));
    


    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            for (int k = 0; k < len3; k++)
            {
                if (a[i] == b[j] && b[j]== c[k]) dp[i][j][k] = getDP(dp, i - 1, j - 1,k-1) + 1;
                else dp[i][j][k] = max(  max(getDP(dp, i - 1, j,k), getDP(dp, i, j - 1,k)), getDP(dp, i, j, k-1));

            }

           

            //   cout << dp[i][j] << " ";
        }
        // cout << endl;
    }
    

   
        cout << dp[len1-1][len2-1][len3-1];



    return 0;
}
