#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int find_small(int a, int b, int c)
{
	int temp = min(a, b);
	return min(c, temp);
}

int main()
{
	int n;
	int a, b, c;

	scanf("%d", &n);

	vector<vector<int>> dp(n, vector<int>(3, 0));
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		dp[i][0] = a;
		dp[i][1] = b;
		dp[i][2] = c;
	}

	for (int i = 1; i < n; i++)
	{
		dp[i][0] = min(dp[i][0]+dp[i-1][1], dp[i][0]+dp[i-1][2]);
		dp[i][1] = min(dp[i][1] + dp[i-1][0], dp[i][1] + dp[i-1][2]);
		dp[i][2] = min(dp[i][2] + dp[i-1][0], dp[i][2] + dp[i-1][1]);
	}
	
	cout << find_small(dp[dp.size() - 1][0], dp[dp.size() - 1][1], dp[dp.size() - 1][2]);

	return 0;
}