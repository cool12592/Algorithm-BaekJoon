#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>



using namespace std;



int main()
{

	int t;
	cin >> t;
	for (int ind = 0; ind < t; ind++)
	{
		int n;
		cin >> n;
		vector<int>coin(n+1);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &coin[i]);
		}
		int target;
		cin >> target;

		vector<vector<int>>dp(n+1, vector<int>(target + 1, 0));

	
	
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= target; j++)
			{
				
				dp[i][j] = dp[i - 1][j];
				 if(j==coin[i])
					dp[i][j] += 1;

				if (j - coin[i] >= 0)
					dp[i][j] += dp[i][j - coin[i]];
			}
		}

		printf("%d\n", dp[n][target]);



	}
	
	return 0;
}