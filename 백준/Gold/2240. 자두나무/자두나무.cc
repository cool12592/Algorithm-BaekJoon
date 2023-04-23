#include<iostream>
#include<memory.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
using namespace std;

int dp[3][31][1001];
vector<int> vec;

int changePos(int pos)
{
	if (pos == 1) return 2;
	else return 1;
}

int dfs(int pos, int remain_move, int sec)
{
	if (sec == vec.size())
		return 0;

	if (dp[pos][remain_move][sec] != -1)
		return dp[pos][remain_move][sec];

	int res = 0;
	if (vec[sec] == pos)
		res += 1;
	
	if (remain_move == 0)
	{
		res += dfs(pos, 0, sec + 1);
	}
	else
	{
		res += max(dfs(pos, remain_move, sec + 1), dfs(changePos(pos), remain_move - 1, sec + 1));
	}
	dp[pos][remain_move][sec] = res;
	return res;

}
int main()
{	
	memset(dp, -1, sizeof dp);
	int n, t;
	cin >> n >> t;
	vec.resize(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &vec[i]);
	}
	cout << max(dfs(1, t, 0),dfs(2,t-1,0));
	return 0;
}

