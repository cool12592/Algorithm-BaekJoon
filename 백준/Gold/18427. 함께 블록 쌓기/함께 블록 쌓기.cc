#include<iostream>
#include<memory.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;


int main()
{
	int n, m, h;
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> h;
	cin.ignore(1);
	vector<vector<int>>vec(n);
	for (int i = 0; i < n; i++) {
		string temp;
		getline(cin, temp, '\n');

		for (int j = 0; j < temp.size(); j++)
			if (temp[j] == ' ' || j == 0)
				vec[i].push_back(stoi(&temp[j]));


	}
	long long dp[50][1001];
	memset(dp, 0, sizeof dp);
	for (int i = 0; i < n; i++)
		dp[i][0] = 1;

	for (int i = 0; i < vec[0].size(); i++)
		dp[0][vec[0][i]] = 1;

	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 1; j < n; j++)
		{
			dp[j][i] += dp[j - 1][i];//위에꺼받아오고
			for (int k = 0; k < vec[j].size(); k++)
			{
				if(i-vec[j][k]>=0)
				dp[j][i] += dp[j - 1][i - vec[j][k]];
				dp[j][i]%=10007;
			}
		}
	}
	cout << dp[n - 1][h];

	return 0;
}

