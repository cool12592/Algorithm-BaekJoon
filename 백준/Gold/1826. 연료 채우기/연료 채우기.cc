#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int point[1000001] = { 0, };
	int a, b;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		point[a] = b;

		
	}
	int enegy, finish;
	cin >> finish >> enegy;
	int ind = 0;

	int answer = 0;
	priority_queue<int> pq;
	while (true)
	{
		if (ind == finish)
		{
			cout << answer;
			return 0;

		}

		if (point[ind] != 0)
			pq.push(point[ind]);

		if (enegy == 0)
		{
			if (pq.size() == 0)
			{
				cout << -1;
				return 0;
			}
			else
			{
				answer++;
				enegy += pq.top();
				pq.pop();
			}
		}
		enegy--;
		ind++;

	}
	return 0;
}