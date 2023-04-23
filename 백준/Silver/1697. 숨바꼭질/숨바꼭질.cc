#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int start, end;
	scanf("%d%d", &start, &end);
	queue<pair<int,int>> q;
	q.push(make_pair(start,0));
	int now;
	int cost;
	int visit[100001] = { 0, };
	while (q.size() > 0)
	{
		now = q.front().first;
		cost = q.front().second;
		q.pop();
	
		if (now == end)
		{
			cout << cost;
			return 0;
		}
		
		if (now - 1 >= 0&& visit[now - 1] == 0 )
		{
			q.push(make_pair(now - 1, cost + 1));
			visit[now-1] = 1;
		}
		if (now + 1 <= 100000 && visit[now + 1] == 0 )
		{
			q.push(make_pair(now + 1, cost + 1));
			visit[now + 1] = 1;
		}
		if (now * 2 <= 100000 && visit[now * 2] == 0)
		{
			q.push(make_pair(now * 2, cost + 1));
			visit[now * 2] = 1;
		}
		
	}


	return 0;
}