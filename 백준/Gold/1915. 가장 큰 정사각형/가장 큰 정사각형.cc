#include<iostream>
#include<vector>
#include<queue>
#include<stack>




using namespace std;

 


int main()
{
	
	int n, m;

	cin >> n >> m;

	vector<string> vec(n);
	vector<vector<int>> dp(n,vector<int>(m,0));
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	for (int i = 0; i < m; i++)
	{

		if(vec[0][i]=='1')
		{
			dp[0][i] = 1;
			answer = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{

		if (vec[i][0] == '1')
		{
			dp[i][0] = 1;
			answer = 1;
		}
	}
	
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (vec[i][j] == '1')
			{
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]))+1;
				answer = max(answer, dp[i][j] * dp[i][j]);
			}
		}
	}
	
	cout << answer;
	return 0;
}