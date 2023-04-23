#include<iostream>
#include<queue>
using namespace std;
#define inf 987654321
int main()
{
	int start, end;
	scanf("%d%d", &start, &end);
	queue<pair<int, int>> q;
	q.push(make_pair(start, 0));
	int now;
	int cost;
	vector<int> visit(100001, inf);
    if(start==end) {cout<<0;return 0;}
	while (q.size() > 0)
	{
		now = q.front().first;
		cost = q.front().second;
		q.pop();

		if (now == end)
		{
			break;
		}

		if (now - 1 >= 0 && visit[now - 1] > cost+1)
		{
			q.push(make_pair(now - 1, cost + 1));
			visit[now - 1] = cost+1;
		}
		if (now + 1 <= 100000 && visit[now + 1] > cost+1)
		{
			q.push(make_pair(now + 1, cost + 1));
			visit[now + 1] = cost+1;
		}
		if (now * 2 <= 100000 && visit[now * 2] > cost)
		{
			q.push(make_pair(now * 2, cost));
			visit[now * 2] = cost;
		}

	}

	cout << visit[end];
	return 0;
}