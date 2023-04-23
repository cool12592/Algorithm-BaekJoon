#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> vec(n);
	int a, b;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		vec[i] = { a,b };
	}
	sort(vec.begin(), vec.end());
	priority_queue<int> pq;
	pq.push(-vec[0].second);


	int use_room = 1;
	int answer = 1;



	for (int i = 1; i < n; i++)
	{
		while (pq.size()>0 && vec[i].first >= -pq.top())
		{
			pq.pop();
			use_room--;
		}

		pq.push(-vec[i].second);
		use_room++;
		answer = max(answer, use_room);
	}
	cout << answer;

	return 0;
}