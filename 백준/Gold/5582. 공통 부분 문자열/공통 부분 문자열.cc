#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>



using namespace std;



int main()
{

	string a, b;
	cin >> a >> b;
	int answer = 0;

	vector<vector<int>> dp(a.size(), vector<int>(b.size(), 0));
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			if (a[i] == b[j])
			{

				if (i == 0 || j == 0)
					dp[i][j] = 1;
				else
					dp[i][j] = dp[i - 1][j - 1] + 1;

				if (answer < dp[i][j])
					answer = dp[i][j];
			}
		}
	}
	cout << answer;

	return 0;
}