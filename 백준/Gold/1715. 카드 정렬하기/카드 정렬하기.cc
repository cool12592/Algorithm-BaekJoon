#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main()
{
	
	int n;
	scanf("%d", &n);
	priority_queue<int, vector<int>, greater<int>> pq;
	int a;
	for (int i = 0; i < n; i++)
	{
		
		scanf("%d", &a);
		pq.push(a);
	}

	//sum= 카드 합칠때마다 드는비용 누적
	long long sum = 0;
	int num1, num2;
	//만약 카드뭉치가 한뭉치면 합치는비용x 답은0
	//합치다가 카드뭉치 하나되면 끝 답은 지금까지 뭉친비용 sum
	while (pq.size() > 1)
	{
		num1 = pq.top();
		pq.pop();
		num2 = pq.top();
		pq.pop();
		pq.push(num1 + num2);
		sum += num1 + num2;
	}

	
	cout <<sum;
	return 0;
	
}