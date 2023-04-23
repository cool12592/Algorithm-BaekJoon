#include<iostream>
#include<memory.h>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

int dp[10001];
vector<int> mytime(10001);
vector<vector<int>> TechTree(10001);
int dfs(int num)
{
	if (dp[num] != -1)
		return dp[num];

	int t = mytime[num];
	int pastKing=0;
	for (int i = 0; i < TechTree[num].size(); i++)
	{
		pastKing = max(pastKing, dfs(TechTree[num][i]));
	}
	
	dp[num] = t + pastKing;
	return dp[num];

}
int main()
{


	int n;
	cin >> n;
	memset(dp, -1, sizeof dp);
	int sol = 0;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &mytime[i+1]);

		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{
			int a;
			scanf("%d", &a);
			TechTree[i + 1].push_back(a);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		sol = max(sol, dfs(i));
	}
	cout << sol;
	return 0;
}

