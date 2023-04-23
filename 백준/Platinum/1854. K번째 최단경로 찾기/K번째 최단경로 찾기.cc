#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<memory.h>
#include<string>
#include<set>
using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<int,int>>> adj(n+1);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back({ b,c });
	}

	vector<priority_queue<int>> cost(n+1);
	
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 1 });
	cost[1].push(0);

	while (pq.size())
	{
		int now = pq.top().second;
		int now_cost = -pq.top().first;
		pq.pop();
		if (cost[now].size() == k && cost[now].top() < now_cost) continue;

		for (auto v : adj[now])
		{
			int dest = v.first;
			int dest_cost = v.second + now_cost;

			if (cost[dest].size() < k)
			{
				pq.push({ -dest_cost , dest });
				cost[dest].push(dest_cost);
			}
			else 
			{
				if (cost[dest].top() > dest_cost)
				{
					cost[dest].pop();
					cost[dest].push(dest_cost);
					pq.push({ -dest_cost,dest });
				}
			}

		}

	}
	for (int i = 1; i <= n; i++)
	{
		if (cost[i].size() == k) printf("%d\n", cost[i].top());
		else printf("-1\n");
	}
	return 0;
}