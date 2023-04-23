#include<iostream>
#include<memory.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
using namespace std;
#define inf 987654321
struct node {
	int node;
	int cost;
	int time;
	
};

struct cmp {
	bool operator()(node x, node y) {
		if (x.time == y.time) return x.cost > y.cost;
		return x.time > y.time;   // 반대로.
	}
};


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		int a, b, c, d;
		vector<vector<node>> adj(n+1);
		for (int i = 0; i < k; i++)
		{
			scanf("%d %d %d %d", &a, &b, &c, &d);
			adj[a].push_back({b,c,d});

		}
		priority_queue <node, vector<node>, cmp> pq;
		pq.push({ 1, 0, 0 });

		vector<vector<int>>dp(n + 1, vector<int>(m + 1, inf)); //dp[i][j]=g; 1에서 i까지 최대j원들여서 갈때의 최소시간g
		dp[1][0] = 0;
		int sol = inf;
		while (pq.size() > 0)
		{

			node now = pq.top();
			pq.pop();
		
			if (dp[now.node][now.cost] < now.time)
				continue;

			for (int i = 0; i < adj[now.node].size(); i++)
			{
				node dest = adj[now.node][i];
				if (dest.cost + now.cost > m) //비용넘는건어떻게도못감
					continue;
				if (dp[dest.node][dest.cost + now.cost] > now.time + dest.time)
				{
					dp[dest.node][dest.cost + now.cost] = now.time + dest.time; //시간이 무조건짝은게 장땡이아님 시간이짧아도 나중에 cost막혀서 못가는거보다 시간이 길어도 cost안에 갈수있는게 있을수있기때문
					pq.push({ dest.node,dest.cost + now.cost,now.time + dest.time });
					if (dest.node == n)
					{
						sol = min(sol, dp[dest.node][dest.cost + now.cost]);

					}
				}
			}
		}
		if (sol == inf) printf("Poor KCM\n");
		else printf("%d\n", sol);
	}

	
	return 0;
}

