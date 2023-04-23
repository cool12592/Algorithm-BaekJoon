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
    int dp[101][101][2] = { 0, };
    dp[1][0][0] = 1;
    dp[1][0][1] = 1;
    //dp[1][1][0] = 0;
    //dp[1][1][1] = 0;

    for (int i = 2; i <= 100; i++)
    {
    
        for (int j = 0; j <=i; j++)
        {
            dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
           
            dp[i][j][1] = dp[i - 1][j][0];
            if (j != 0)
                dp[i][j][1]+= dp[i - 1][j - 1][1];
        }
    }
    int n;
    cin >> n;
    int a, b;
    while (n--)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", dp[a][b][0] + dp[a][b][1]);
    }

    return 0;
}