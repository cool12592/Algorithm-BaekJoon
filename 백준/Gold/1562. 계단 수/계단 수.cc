#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include<string>

#include<memory.h>

#define inf 987654321
#define mod 1000000000
using namespace std;

int dp[101][10][(1 << 10)];
int n;
int dfs(int number, int ind, int bits)
{
    if (dp[ind][number][bits] != -1)
        return dp[ind][number][bits];

    if (n == ind)
    {
        if (bits == (1 << 10) - 1)
            return 1; //성공
        else
            return 0;
    }

    int res=0;
    if (number <= 8)
    {
        res+=dfs(number + 1, ind + 1, bits | 1 << (number+1))%mod;
    }
    if (number >= 1)
    {
        res += dfs(number - 1, ind + 1, bits | 1 << (number - 1)) % mod;

    }
    dp[ind][number][bits] = res;
    return res;

}
int main()
{
   
    cin >> n;
    long long answer = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= 9; i++)//시작숫자
    {
        answer += dfs(i, 1, 1<<i);
        answer=answer%mod;

    }
    cout << answer;

    return 0;
}