#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int input;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input);
		pq.push(-input);
	}
	
	int gain_sum = 0;
	int super_sum=0;
	while (pq.size())
	{
		gain_sum = gain_sum - pq.top();
		super_sum += gain_sum;
		pq.pop();
	}
	cout << super_sum;
	return 0;
}