#include<iostream>
#include<memory.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int a, b, c;

	vector<int> childNum(n + 1);
	vector<vector<pair<int, int>>> parent(n + 1);
	queue<int> q;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		parent[b].push_back({ a,c });
		childNum[a]++;
	}
	vector<int> sol(n + 1, 0);
	int inven[101][101] = {0,};
	for (int i = 1; i <= n; i++)
	{
		if (childNum[i] == 0)
		{
			q.push(i);
			inven[i][i] = 1;
		}
	}
	while (q.size()>0)
	{
		int now = q.front();
		q.pop();
		if (now == n) 
		{
			for (int i = 1; i <= 100; i++)
			{
				if (inven[now][i] > 0)
				{
					printf("%d %d\n", i, inven[now][i]);
				}
			}
			return 0;
			break;
		}


		for (int i = 0; i < parent[now].size(); i++)
		{
			int par = parent[now][i].first;
			int cost = parent[now][i].second;
			childNum[par]--;
			if (childNum[par] == 0)
				q.push(par);

			for (int j = 1; j <= 100; j++)
			{
				if (inven[now][j] <= 0) continue;
				inven[par][j] += inven[now][j] * cost;		
				if(j== 10)
					cout<<1;
			}
		}
			

	}

	return 0;
}

