#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#define inf 10000000
using namespace std;


int main()
{
	int vertex,edge;
	cin >> vertex >> edge;
	vector<vector<int>> cost(vertex + 1,vector<int>(vertex+1, inf));
	int a, b, c;
	for (int i = 0; i < edge; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		cost[a][b] = c;
		cost[b][a] = c;
	}
	for (int i = 1; i <= vertex; i++)
		cost[i][i] = 0;
	
	int stopover1, stopover2;
	cin >> stopover1 >> stopover2;

	//경유지 출발지 도착지
	for (int i = 1; i <= vertex; i++)
	{
		for (int j = 1; j <= vertex; j++)
		{
			for (int k = 1; k <= vertex; k++)
			{
				cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]); //직빵 vs 경유
			}
		}
	}

	int route1 = cost[1][stopover1] + cost[stopover1][stopover2] + cost[stopover2][vertex];
	int route2 = cost[1][stopover2] + cost[stopover2][stopover1] + cost[stopover1][vertex];
	int answer= min(route1, route2);
	if (answer >= inf)
		cout << -1;
	else
		cout << answer;
	return 0;
}