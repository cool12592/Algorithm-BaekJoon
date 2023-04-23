#include <vector>
#include<iostream>
//7시 52분
#include<queue>
using namespace std;
#define inf 987654321
int main()
{
	int n, m, x;
	
	
	scanf("%d %d %d", &n, &m, &x);
	vector<vector<int>> vec(m, vector<int>(3, 0));
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &vec[i][0], &vec[i][1], &vec[i][2]);
	}
	

	
	int answer = 0;
	int mini_answer = 0;
	vector<vector<pair<int,int>>> adj(n+1);
	
	vector<vector<int>> cost(n + 1,vector<int>(n+1, inf)); //a에서 b까지가는데 걸리는 cost
	for (auto i : vec)
	{
		adj[i[0]].push_back({ i[2],i[1] }); //값 목적지
	}

	bool myx = false;
	for (int i = 1; i <= n; i++)
	{
		if (i == x) myx = true;
		else myx = false;
		
		priority_queue<pair<int, int>>pq;
		vector<int> visit(n + 1, 0);
		pq.push({ -0,i }); //값 노드번호
		cost[i][i] = 0;
		 
		while (pq.size()) //pq는 진짜 방문때 visit해야함 (뒤에들어가는게 더 값쌀수있어서)
		{
			int now_cost = -pq.top().first;
			int node=pq.top().second;
			pq.pop();
			if (visit[node] == 1)
				continue;
			visit[node] = 1;

			if (!myx)
			{
				if (node == x) //x빼고는 x까지의 최소경로만 보면됨 (x는다른애들 다봐야됨)
				{
					break;
				}
			}

			for (auto k : adj[node]) // {비용 갈수있는노드}
			{
				if (visit[k.second] == 0 && cost[i][k.second] > now_cost + k.first)
				{
					cost[i][k.second] = now_cost + k.first;
					pq.push({ -(now_cost + k.first)  , k.second });
				}
			}


		}
	}

	for (int i = 1; i <= n; i++)
	{
		answer = max(answer, cost[i][x] + cost[x][i]);
	}

	cout << answer;
	return 0;
}
