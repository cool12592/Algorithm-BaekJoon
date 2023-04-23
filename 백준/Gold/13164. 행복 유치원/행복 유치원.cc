#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> vec(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &vec[i]);

	if (k == n)
	{
		cout << 0;
		return 0;
	}

	priority_queue<int>pq;

	int dif = 0;
	for (int i = n-1; i >=1; i--)
	{
		dif = vec[i] - vec[i - 1];
		pq.push(dif);
	}
	k--;
	while (pq.size()>0 && k--)
		pq.pop();

	int sum = 0;
	while (pq.size() > 0)
	{
		sum += pq.top();
		pq.pop();
	}

	cout << sum;
	return 0;
}