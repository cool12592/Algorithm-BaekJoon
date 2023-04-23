#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>



using namespace std;



int main()
{

	int n, target;
	cin >> n >> target;

	vector<int> value(n);
	vector<int> weight(n);
	vector<vector<int>> dp(n,vector<int>(10001,0));
	for (int i = 0; i < n; i++)
		scanf("%d", &value[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &weight[i]);

	int answer = 0;
		for (int j = weight[0]; j <= 10000; j++) //weight
		{
			dp[0][j] = value[0];
			
		}
		if (value[0] >= target)
		{
			answer = weight[0];
			
		}
	
		
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= 10000; j++) //weight
		{

				dp[i][j] = dp[i - 1][j];
				if (j - weight[i] >= 0)
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[i]] + value[i]);
					if (dp[i][j] >= 10000000)  dp[i][j] = 10000000;

					if (dp[i][j] >= target)
					{

						
						if (answer == 0)
							answer = j;
						else
							answer = min(answer, j);
						
				
					}
				}
			
		}
	}
	
	cout << answer;

	return 0;
}