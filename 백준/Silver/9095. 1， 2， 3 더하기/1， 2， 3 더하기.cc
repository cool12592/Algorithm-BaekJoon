#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;


int main()
{
	int N;
	cin >> N;

	int input;
	vector<int> dp(11);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	
	for (int i = 4; i <= 10; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

	for (int i = 0; i < N; i++)
	{
		cin >> input;
		cout << dp[input] << endl;
	}
	

	return 0;
}