#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n, w;

	cin >> n >> w;
	vector<int> weight(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> weight[i];
	}

	vector<int> vec(1 << n);
	vector<pair<int, int>> dp(1 << n, {25,2100000000});
	dp[0] = { 1,0 };

	for (int i = 0; i < vec.size(); i++)
		vec[i] = i;

	for (int now : vec)
	{
		for (int j = 0; j < n; j++)
		{
			int newItem = (1 << j);
			int conTainCheck = (now & newItem);
			if (conTainCheck == 0)
			{
				int add = (now | newItem);
				if (dp[now].second + weight[j] <= w)
					dp[add] = min(dp[add], { dp[now].first, dp[now].second + weight[j] });
				else
					dp[add] = min(dp[add], { dp[now].first+1,  weight[j] });

			}
		}
	}
	cout << dp[(1 << n) - 1].first;
	return 0;
}