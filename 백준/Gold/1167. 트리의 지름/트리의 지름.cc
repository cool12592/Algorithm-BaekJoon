#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<set>
using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<vector<pair<int,int>>> vec(n+1);
	int num,input,dis;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &num);
		while (true)
		{
			scanf("%d", &input);
			if (input == -1)
				break;
			scanf("%d", &dis);
			vec[num].push_back({ input,dis });
		}
	}
	vector<int> visit(n + 1);


	queue<pair<int,int>>q;
	q.push({1,0});
	pair<int, int> long_node = {0,0};
	visit[1] = 1;
	while (q.size() > 0)
	{
		int now = q.front().first;
		int cost = q.front().second;
		if (long_node.second < cost)
			long_node = { now,cost };
		q.pop();
		

		for (int i = 0; i <vec[now].size(); i++)
		{
			int dest = vec[now][i].first;
			int dest_cost = vec[now][i].second;
	
			if (visit[dest] == 0)
			{
				visit[dest] = 1;
				q.push({ dest,cost + dest_cost });
			}
		}
	}

	vector<int> visit2(n + 1);


	queue<pair<int, int>>q2;
	q2.push({ long_node.first,0 });
	pair<int, int> long_node2 = { 0,0 };
	visit2[long_node.first] = 1;
	while (q2.size() > 0)
	{
		int now = q2.front().first;
		int cost = q2.front().second;
		if (long_node2.second < cost)
			long_node2 = { now,cost };
		q2.pop();
		

		

		for (int i = 0; i < vec[now].size(); i++)
		{
			int dest = vec[now][i].first;
			int dest_cost = vec[now][i].second;

			if (visit2[dest] == 0)
			{
				visit2[dest] = 1;
				q2.push({ dest,cost + dest_cost });
			}
		}
	}
	cout << long_node2.second;
	return 0;
}