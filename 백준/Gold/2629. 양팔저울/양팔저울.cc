#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include <unordered_map>
#include<string>
#include<map>
#include<set>
#include<list>

#define inf 987654321
using namespace std;



int main()
{
    int dp[31][40001] = { 0, };
    int n;
    cin >> n;
    vector<int>vec(n+1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &vec[i]);

    dp[1][vec[1]] = true;


    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= 40001; j++)
        {
            if (dp[i - 1][j] == 1) dp[i][j] = 1; //위줄에서 됐으면 가능
            else if (vec[i] == j) dp[i][j] = 1; //행렬같으면 가능
            else if (vec[i] - j >= 1 && dp[i - 1][vec[i] - j] == 1) //위줄에서 행-열되면가능
                dp[i][j] = 1;
            else if (j - vec[i] >= 1 && dp[i - 1][j - vec[i]] == 1) //위줄에서 열-행되면가능
                dp[i][j] = 1;
            else if (j + vec[i] <= 40000 && dp[i - 1][j + vec[i]] == 1) dp[i][j] = 1;
            else
                dp[i][j] = 0;
        }
    }
    int k;
    cin >> k;
    int num;
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &num);
        if (dp[n][num] == 1) printf("Y ");
        else  printf("N ");
       
    }
    return 0;
}