#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> dp(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	dp[0] = arr[0];
	if (arr.size() >= 2)
		dp[1] = arr[0] + arr[1];
	if (arr.size() >= 3)
		dp[2] = max(arr[0],arr[1])+arr[2];

	for (int i = 3; i < n; i++)
	{
		dp[i] = max(dp[i - 2], dp[i - 3] + arr[i - 1]) + arr[i];
	}
	cout << dp[n - 1];
	return 0;
}