#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, k;



int main()
{
	
	cin >> n >> k;
	vector<vector<int>> dp(k+1,vector<int>(n+1,1));

	//for (int j = 0; j <= n; j++)
	//	dp[1][j] = 1;
	
	for (int i = 2; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
	}

	cout << dp[k][n];


	return 0;
}