#include<iostream>
#include<memory.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<queue>
using namespace std;
int n, m, k;

struct info{
	long long cost;
	int node;
	int erase_edge;


};
struct cmp
{
	bool operator()(info a, info b)
	{
		return a.cost > b.cost;

	}
};

int main()
{
	cin >> n >> m >> k;
	vector<vector<pair<int,int>>> adj(n+1);
	vector<vector<long long>> cost(n+1,vector<long long>(k+1,-1));
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
	
		//if(b!=1)
		adj[a].push_back({ b,c });
		//if(a!=1)
		adj[b].push_back({ a,c });


	}


	priority_queue<info,vector<info>,cmp> pq;
	pq.push({ 0,1,0 });
     cost[1][0]=0;
	while (pq.size())
	{
		info now = pq.top();
		pq.pop();
        if (now.cost > cost[now.node][now.erase_edge])
			continue;
		for (int i = 0; i < adj[now.node].size(); i++)
		{
			int dest_node = adj[now.node][i].first;
			long long dest_cost = adj[now.node][i].second;
			if (cost[dest_node][now.erase_edge] > now.cost + adj[now.node][i].second
				|| cost[dest_node][now.erase_edge]==-1)
			{
				cost[dest_node][now.erase_edge] = now.cost + adj[now.node][i].second;
				pq.push({ cost[dest_node][now.erase_edge], dest_node, now.erase_edge});

			}
			if (now.erase_edge < k)
			{
				//여기서 글로가는 edge를 지움 그래서 지금비용만
				if (cost[dest_node][now.erase_edge + 1] > now.cost || cost[dest_node][now.erase_edge + 1] == -1)
				{
					cost[dest_node][now.erase_edge + 1] = now.cost;
					pq.push({ now.cost , dest_node, now.erase_edge + 1 });

				}
			}
		}

	}

	long long sol = -1;
	for (int i = 0; i <= k; i++)
	{
		if (cost[n][i] == -1)
			continue;

		if (sol == -1)
			sol = cost[n][i];
		else
			sol =min(sol, cost[n][i]);
	}
	cout << sol;

	return 0;
}

