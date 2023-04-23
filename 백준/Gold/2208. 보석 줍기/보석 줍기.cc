#include<iostream>
#include<memory.h>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
#define inf 987654321

int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	int dp[100001] = { 0, };
	//memset(dp, -inf, sizeof dp);
	dp[0] = 0;
	vector<int> vec(n+1);
	vector<int> sumvec(n + 1);
	sumvec[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &vec[i]);
		sumvec[i] = sumvec[i - 1] + vec[i];
	}

	int sol = 0;
	dp[m - 1] = sumvec[m - 1];
	for (int i = m; i <= n; i++)
	{
		dp[i] = max(dp[i - 1] + vec[i], sumvec[i] - sumvec[i - m]);//기존값 누적 or 새롭게 시작
		sol = max(sol, dp[i]);
	}
	cout << sol;
	return 0;
}

