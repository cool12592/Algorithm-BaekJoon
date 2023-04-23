#include<iostream>
#include<memory.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
using namespace std;

int parent[30001] = {0,};
int childNum[30001] = { 0, };
int childPoint[30001] = { 0, };
int find(int x)
{
	if (x == parent[x])
		return x;
	else
		return parent[x] = find(parent[x]);
}
void unite(int x, int y)
{
	x = find(x);
	y = find(y);

	parent[y] = x;

	//childNum[x] += childNum[y];
	//childPoint[x] += childPoint[y];
}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<int>point(n+1);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &point[i]);
		childPoint[i] = point[i];
		childNum[i] = 1;
		parent[i] = i;
	}
	//vector<int> visit(n + 1,0);
	int a, b;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d",&a,&b);
		unite(a, b);
	}

	for (int i = 1; i <= n; i++)
	{
		if (find(i) != i)
		{
			childNum[find(i)]++;
			childPoint[find(i)] += point[i];
		}
	}

	vector<pair<int,int>> group;
	for (int i = 1; i <= n; i++)
	{
		if (find(i) == i)//자기가대장인애
		{
			group.push_back({ childPoint[i] , childNum[i]});
		}
	}

	vector<int> dp(k,0);
	int sol = 0;
	for (int i = 0; i < group.size(); i++)
	{
		for (int j = k-1; j >= 1; j--)
		{
			if (j - group[i].second < 0) continue;
			
			if (dp[j] < dp[j - group[i].second] + group[i].first)
			{
				dp[j] = dp[j - group[i].second] + group[i].first;
				sol = max(sol, dp[j]);
			
			}
		}
	}
	cout << sol<<endl;
	return 0;
}

