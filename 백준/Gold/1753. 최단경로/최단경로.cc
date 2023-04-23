#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;
#define inf -987654321
int main()
{

	int a, b, start_num;
    //cin >> a >> b >> start_num;
	scanf("%d%d%d",&a,&b,&start_num); 

	vector<int>cost(a + 1, inf);
	vector<int>visit(a + 1, 0);

	 vector<vector<pair<int, int>>> route(a+1);
    
    int a1,b1,c1;
	for (int i = 0; i < b; i++)
	{
        //cin>>a1>>b1>>c1;
        scanf("%d%d%d",&a1,&b1,&c1); 
		route[a1].push_back(make_pair(b1, c1));
	}
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start_num));
	cost[start_num] = 0;
	
	
	int to_;
	int from_;
	int new_cost;
	while (pq.size() > 0)
	{
		from_ = pq.top().second;
		pq.pop();
		if (visit[from_] == 1)
			continue;
		visit[from_] = 1;

		


		for (int i = 0; i < route[from_].size(); i++)
		{
			to_ = route[from_][i].first;
			new_cost = route[from_][i].second;
			if (visit[to_] == 0&&cost[to_] < cost[from_] - new_cost )
			{
				pq.push(make_pair(cost[from_] - new_cost, to_));
				cost[to_] = cost[from_] - new_cost;
			}

		}
	}

	for (int i = 1; i < cost.size(); i++)
	{
		if (cost[i] == inf)
			printf("INF\n");//cout << "INF" << endl;
		else
			printf("%d\n",-cost[i]);//cout << -cost[i] << endl;
	}




	return 0;
}