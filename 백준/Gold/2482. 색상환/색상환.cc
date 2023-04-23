#include<iostream>
#include<memory.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
using namespace std;

#define mod  1000000003

int main()
{	
	int n, k;
	cin >> n >> k;
	vector<vector<int>> dp(n+1, vector<int>(k+1));
	
	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = 1;
		dp[i][1] = i;
	}
	
	for (int i = 2; i <= n; i++)
	{

		for (int j =2; j <= k; j++)
		{
		
			dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % mod;
				
			
		}
		
	}
	

	cout << (dp[n-1][k]+dp[n-3][k-1])%mod;
	return 0;
}

