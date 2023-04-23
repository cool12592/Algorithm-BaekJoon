#include<iostream>
#include<memory.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
using namespace std;

#define mod 1000000007

int main()
{
    long long dp[5001] = { 0, };

    dp[0] = 1;
    dp[2] = 1;

    for (int i = 4; i <= 5000; i +=2)
    {
        for (int j = 2; j <= i; j+=2)
        {
             dp[i] += dp[j - 2] * dp[i - j];
                  dp[i] %=mod;    
        }
      
    }
      int n;
    cin >> n;
    while (n--)
    {
        int a;
        scanf("%d", &a);
        printf("%d\n", dp[a]);
    }
}