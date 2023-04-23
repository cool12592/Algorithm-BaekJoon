#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<set>
using namespace std;


int main()
{
	int n,m;
	cin >> n>>m;
	vector<int>indegree(n + 1, 0);
	vector<vector<int>>adj(n + 1);
	int a, b;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		indegree[b]++;
	}
	priority_queue<int> pq;
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0)
			pq.push(-i);

	while (pq.size() > 0)
	{
		int now = -pq.top();
		printf("%d ", now);
		pq.pop();
		for (int i = 0; i < adj[now].size(); i++)
		{
			int dest = adj[now][i];
			indegree[dest]--;
			if (indegree[dest] == 0)
				pq.push(-dest);
		}
	}
	
	return 0;
}