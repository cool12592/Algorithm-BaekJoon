#include <vector>
#include<iostream>
//9시 9뷴
//아 그냥 두번째로 빠른건줄... 문제잘못이해했따.. 30분만에푼건데..
#include<queue>
#include<set>
#include<unordered_map>

using namespace std;
#define inf 987654321

//생각해보니 같은 cost로 3가서 pq에 넣으면
//또 똑같은 로직 반복됨
//pq포화됨
//즉 같은 cost면 pq에는 않넣고 treace[node] (node까지의 최단경로로 가기위해 이전단계노드)
//여기에 내 node push_back 하면됨
//그래서 trace[6] 부터 역추적

int n, m, s, d;
vector<vector<int>> vec;
vector<vector<bool>> erase_adj;
vector<vector<int>> trace;
int djk()
{
	vector<int> cost(n, inf); //s에서 ?까지가는데 걸리는 cost
	vector<vector<pair<int, int>>> adj(n + 1);


	for (auto v : vec)
	{
		if(erase_adj[v[0]][v[1]])
		adj[v[0]].push_back({ v[2],v[1] }); //값 목적지
	}


	priority_queue<pair<int, int>>pq; //비용 노드 부모노드

	pq.push({ -0,s }); //값 노드번호 부모
	cost[s] = 0;


	while (pq.size()) 
	{
		int now_cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();


		if (cost[node] < now_cost)
			continue;

		for (auto k : adj[node]) // {비용 갈수있는노드}
		{
			int dest = k.second;
			int dest_cost = k.first;


			if (cost[dest] > now_cost + dest_cost)
			{
				cost[dest] = now_cost + dest_cost;
				pq.push({ -(now_cost + dest_cost), dest });
				trace[dest].clear(); //이전보다 더 짧은방법나옴
				trace[dest].push_back(node);
			}
			else if (cost[dest] == now_cost + dest_cost)
			{
				trace[dest].push_back(node);
			}

		}


	}

	return cost[d];
}

void remove_adj()
{
	//여기 중요한게
	//0->3 먼저고그다음 0->1 보는데
	//만약 visit안쓰면 0이 node 3때랑 1 두번 큐에들어가지? 이러면 이 로직에선 큐억수로중복일어남
	//즉 메모리 초과.
	//그럼 visit을 써야하는데 또문제가 0->3에서 0을 방문했다 체크했어
	//그럼 0->1에서 0은방문했으니패스한단말이야
	//그럼 0->1 노드는 erase되지 않는다
	//즉 visit을했으면 큐에는 넣지말되 erase_adj에는 체크하자 끝
	queue<int> bfs;
	bfs.push(d);
	vector<int> visit(n, 0);
	visit[d] = 1;
	while (bfs.size())
	{
		int node = bfs.front();
		bfs.pop();

		for (auto t : trace[node])
		{
			erase_adj[t][node] = false;
			if (visit[t] == 0)
			{
				visit[t] = 1;
				bfs.push(t);
			}
		}
	}
}



int main()
{

	while (true)
	{
		
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0)
			break;
		scanf("%d %d", &s, &d);
		
		vec.clear();
		vector<vector<int>> vec2(m, vector<int>(3, 0));
		vec = vec2;

		erase_adj.clear();
		vector<vector<bool>> erase_adj2(n, vector<bool>(n, true));
		erase_adj = erase_adj2;

		trace.clear();
		vector<vector<int>> trace2(n);
		trace = trace2;

		for (int i = 0; i < m; i++)
		{
			scanf("%d %d %d", &vec[i][0], &vec[i][1], &vec[i][2]);
		}

		int ans = djk();
		remove_adj();
		ans = djk();
		if (ans >= inf)
			cout << -1 << endl;
		else
			cout << ans<< endl;
	

	}

	return 0;
}
