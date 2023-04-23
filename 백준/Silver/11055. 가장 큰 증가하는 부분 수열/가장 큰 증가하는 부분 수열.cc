#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> vec(n);
	vector<int> dp(n);
	int sum = 0;
	int maxsum = 0;
	int a;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		vec[i] = a;
		
		dp[i] = vec[i];
	
		for (int j = i - 1; j >= 0; j--)
		{
			if (vec[j] < vec[i] && dp[i] < dp[j] + vec[i])
				dp[i] = dp[j] + vec[i];
		}
		if (dp[i] > maxsum)
			maxsum = dp[i];
	}
	
	cout << maxsum;
	return 0;
}