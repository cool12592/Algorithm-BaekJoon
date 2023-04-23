#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int parent[200001];
int find(int a)
{
	if (a == parent[a]) return a;

	return parent[a] = find(parent[a]);
}
void unite(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}
int main()
{
	int n;
	cin >> n;
	priority_queue<pair<long long, int>>pq;
	int a; long long b;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		pq.push({ b,a });

		parent[i] = i;
	}
	parent[n] = n;

	int sum = 0;
	while (pq.size() > 0)
	{
		int cost = pq.top().first;
		int line = pq.top().second;
		pq.pop();
		if (find(line) == 0)
			continue;
		sum += cost;

		unite(line, find(line) - 1);

	}

	cout << sum;
	return 0;
}