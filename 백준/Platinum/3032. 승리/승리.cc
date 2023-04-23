#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;


vector<int> vec;
int dp[2][100][100];
int n;
int check(int ind)
{
	if (ind == -1)
		return n - 1;
	else if (ind == n)
		return 0;

	return ind;
}

int dfs(int turn, int left, int right)
{
	if (left == right)
	{
		if (turn && vec[left] % 2 != 0)
			return 1;
		else
			return 0;
	}
	if (dp[turn][left][right] != -1)
		return dp[turn][left][right];

	int res=0;
	
	if (turn)
	{
		int left_plus = 0;
		int right_plus = 0;
		if (vec[left] % 2 != 0)
			left_plus = 1;
		if (vec[right] % 2 != 0)
			right_plus = 1;

		res = max(left_plus + dfs(!turn, check(left - 1), right), 
			right_plus + dfs(!turn, left, check(right +1)));
	}
	else
	{
		res = min(  dfs(!turn, check(left - 1), right),
			  dfs(!turn, left, check(right + 1)));
	}
	dp[turn][left][right] = res;
	return res;

}


int main()
{
	
	cin >> n;
	vec.resize(n);
	int entire = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &vec[i]);
		if (vec[i] % 2 != 0)
			entire++;
	}
	int ans=0;
	memset(dp, -1, sizeof dp);
	
	for (int i = 0; i < n; i++)
	{
		int plus = 0;
		if (vec[i] % 2 != 0)
			plus = 1;
		int res = dfs(false, check(i - 1), check(i + 1)) +plus;
		if (res > entire / 2)
			ans++;

	}
	cout << ans;
	return 0;
}