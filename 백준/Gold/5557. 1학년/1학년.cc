#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>



using namespace std;


vector<vector<long long>> dp;
vector<int> vec;




int main()
{
	int n, k;
	cin >> n;
	dp.resize(n, vector<long long>(21,0));
	vec.resize(n);
	int num;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &vec[i]);
	}

	dp[0][vec[0]] = 1;

	for (int i = 1; i < n-1; i++)
	{
		
		for (int j = 0; j <= 20; j++)
		{
			if (j - vec[i] >= 0)
				dp[i][j] += dp[i - 1][j - vec[i]];
			if (j + vec[i] <= 20)
				dp[i][j] += dp[i - 1][j + vec[i]];
		}

	}
	cout << dp[n - 2][vec[n - 1]];
	return 0;
}