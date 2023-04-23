#include<iostream>
#include<memory.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
using namespace std;
//1.내가 우수마을이면 자식은 우수마을or낫우수마을
//2.내가 낫우수마을이면 자식은 우수마을
//dp로 제일큰값찾기
int point[10001] = {0,};
vector<vector<int>> adj2;//이건 단방향트리
vector<vector<int>> adj; //이건양방향
vector<vector<int>> dp;//dp[2][node] [2]는 이노드 우수마을or논우수마을
void make_tree(int parent, int now)
{
	if (parent != 0)adj2[parent].push_back(now);
	for (int next : adj[now])
	{
		if (next == parent) continue;
		make_tree(now, next);
	}
}

int dfs(bool good, int node , bool parentGood)
{
	if (dp[good][node] != 0)
		return dp[good][node];
	if (adj2[node].size() == 0)
	{
		if (good) return point[node];
		else return 0;
	}

	int res = 0;
	if (good) res = point[node];
	for (int i = 0; i < adj2[node].size(); i++)
	{
		int dest = adj2[node][i];
		
		if (parentGood)
		{
			if (!good)
			{
				res += max(dfs(true, dest,good),dfs(false,dest,!good));
			}
		}
		else if (!parentGood)
		{
			if (good)
			{
				res += dfs(false, dest, good);
			}
			else if (!good)
			{
				res += dfs(true, dest, good);
			}
		}


	}
	dp[good][node] = res;
	return res;

}

int main()
{
	int n;
	cin >> n;
	adj.resize(n+1);
	adj2.resize(n + 1);
	dp.resize(2,vector<int>(n+1));
	for (int i = 1; i <= n; i++)
		scanf("%d", &point[i]);

	for (int i = 1; i <= n - 1; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int root = 0;
	for (int i = 1; i <= n; i++)
	{
		if (adj[i].size()==1) //루트도 1이고 리프도 1인데암튼
		{
			make_tree(0, i);
			root = i;
			break;
		}

	}

	cout << max(dfs(true, root,false), dfs(false, root,false));


	return 0;
}

