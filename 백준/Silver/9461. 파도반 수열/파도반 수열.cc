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
	vector<int> vec(N);;
	long long dp[101];
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	//6부터는 계속 5칸씩 회전~회오리
	for (int i = 6; i <= 100; i++)
		dp[i] = dp[i - 1] + dp[i - 5];

	for (int i = 0; i < N; i++)
	{
		cin>>input; 
		cout << dp[input] << endl;
	}
	
	return 0;
}