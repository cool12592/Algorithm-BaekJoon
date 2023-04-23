#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

long long dp[101][101][101];
int main()
{
	int n,l,r;
	cin >> n >> l>>r;


	dp[1][1][1] = 1;
	
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= l; j++)
			for (int k = 1; k <= r; k++)
				dp[i][j][k] =( dp[i - 1][j][k] * (i - 2) + dp[i - 1][j][k - 1] + dp[i - 1][j - 1][k])% 1000000007;
	cout << dp[n][l][r];
	return 0;
}