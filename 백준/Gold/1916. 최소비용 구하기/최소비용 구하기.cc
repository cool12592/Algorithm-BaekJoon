#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define inf 987654321
int main()
{
	int a, b, source, destinatioin;
	

	scanf("%d%d", &a, &b);
	vector<vector<pair<int,int>>> vec(a+1);
	int a1, b1, c1;
	for (int i = 0; i < b; i++)
	{
		scanf("%d%d%d", &a1, &b1,&c1);
		vec[a1].push_back(make_pair(b1, c1));
	}
	scanf("%d%d", &source, &destinatioin);
	
	priority_queue<pair<int, int>> pq;
	vector<int> cost(a + 1,inf);
	vector<int> visit(a + 1,0);
	cost[source] = 0;
	pq.push(make_pair(0, source));
	int now;
	int from_, to_, new_cost;
	while (pq.size() > 0)
	{
		from_ = pq.top().second;
		pq.pop();
		if (visit[from_] == 1)
			continue;
			visit[from_]= 1;

			if (from_ == destinatioin)
			{
				cout << cost[from_];
				return 0;
			}
		for (int i = 0; i < vec[from_].size(); i++)
		{
			to_ = vec[from_][i].first;
			new_cost = vec[from_][i].second;
			if (visit[to_] == 0 && cost[to_] > cost[from_]+ new_cost )
			{
				pq.push(make_pair(-(cost[from_]+new_cost ), to_)); //다진짜값 pq넣을떄만 -
				cost[to_] = cost[from_] + new_cost;
			}
		}

	}
	
	
	//cout << cost[destinatioin];
	return 0;
}