#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<memory.h>
#include<string>
using namespace std;
vector<vector<int>>adj1;
//vector<vector<int>>adj2;
vector<bool> visit;
int dp[1000001][2];
/*
void make_tree(int parent, int now)
{
	if (parent != 0) adj2[parent].push_back(now);

	for (int child : adj1[now])
	{
		if (child == parent) continue;
		make_tree(now, child);
	}
}
*/
int dfs(int now, bool parent_state)
{
	if (visit[now] == true) return 0;
	if (dp[now][parent_state] != -1)
		return dp[now][parent_state];
	int res = 0;
	visit[now] = true;
	if (parent_state == true)
	{
		int num1 = 1, num2 = 0;

		for (int child : adj1[now])
		{
			num1 += dfs(child, true);
			num2 += dfs(child, false);
		}
		res = min(num1, num2);
		dp[now][parent_state] = res;
	}
	else
	{
		int num1 = 1;

		for (int child : adj1[now])
		{
			num1 += dfs(child, true);
		}
		res = num1;
		dp[now][parent_state] = res;
	}
	visit[now] = false;
	return res;
}

int main()
{
	int n;
	cin >> n;
	int i = n - 1;
	adj1.resize(n + 1);
	//adj2.resize(n + 1);
	visit.resize(n + 1,false);
	while (i--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		adj1[a].push_back(b);
		adj1[b].push_back(a);
	}
	//make_tree(0, 1);

	memset(dp, -1, sizeof dp);




    //어차피 visit은 되돌아옴 visit은백트랙킹형식이라 그래서다시초기화안해줘도됨

	cout << min(dfs(1, true), dfs(1, false));

	return 0;
}