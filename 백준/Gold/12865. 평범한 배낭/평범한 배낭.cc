#include <string>
#include <vector>
#include<iostream>
#include <queue>
#include<algorithm>

using namespace std;
//7시 40분

int main()
{
	int answer = 0;
	int n, kg;
	cin >> n >> kg;
	vector<pair<int, int>> item(n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		item[i] = { a,b };

	}

	vector<vector<int>> dp(n, vector<int>(kg+1, 0));

	for (int j = item[0].first; j <= kg; j++)
	{
		dp[0][j] = item[0].second;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < item[i].first; j++)
		{
			dp[i][j] = dp[i - 1][j];
		}

		for (int j = item[i].first; j <= kg; j++)
		{
			if (dp[i - 1][j - item[i].first] + item[i].second > dp[i - 1][j])
				dp[i][j] = dp[i - 1][j - item[i].first] + item[i].second;
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n - 1][kg];


	//cout << answer;
	return 0;
}