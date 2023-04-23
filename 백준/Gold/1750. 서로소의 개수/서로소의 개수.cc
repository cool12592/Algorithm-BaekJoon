#include<iostream>
#include<memory.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
using namespace std;

#define mod 10000003

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
int main()
{	
	int n;
	cin >> n;
	vector<int>vec(n);

	int dp[50][100001];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &vec[i]);
		dp[i][vec[i]] = 1;
	}


	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= 100000; j++)
		{
			
			dp[i][j] += dp[i - 1][j];
			dp[i][j] %= mod;
			
			int k = gcd(vec[i], j);
			dp[i][k] += dp[i - 1][j];
			dp[i][k] %= mod;
		}
	}

	cout << dp[n - 1][1];
	return 0;
}

