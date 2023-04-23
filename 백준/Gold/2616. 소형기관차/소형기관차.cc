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
    int n, k;
    int arr[50001];
    arr[0] = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        arr[i] += arr[i - 1];
    }
    cin >> k;

    int dp[4][50001] = { 0, };

    for (int i = 1; i <= 3; i++)
    {
        for (int j = i * k; j <= n; j++)
        {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - k] + (arr[j] - arr[j - k]));
        }
    }
    cout << dp[3][n];

    
}