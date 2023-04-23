#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<set>
using namespace std;
//9:30시작 23분 풀이완
int main()
{
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &vec[i]);

	int k;
	cin >> k;
	stack<pair<int,int>> calculate;
	vector< pair<int, int>> inputvec;
	int input;
	bool upper = true;

	for (int i = 0; i < k*2; i++)
	{
		scanf("%d", &input);
		if (i % 2 == 0) upper = true;
		else upper = false;
		inputvec.push_back({ input,upper });
	}
	for (int i = k * 2 - 1; i >= 0; i--)
	{
		if (calculate.size())
		{
			if (calculate.top().first < inputvec[i].first)
				calculate.push({ inputvec[i].first,inputvec[i].second });
		}
		else
			calculate.push({ inputvec[i].first,inputvec[i].second });
	}
	stack<int> sol;
	multiset<int>remain;
	int len = calculate.top().first;
	for (int i = n-1; i > len -1; i--)
		sol.push(vec[i]);
	for (int i = 0; i < calculate.top().first; i++)
		remain.insert(vec[i]);

	while (calculate.size())
	{
		bool upper = calculate.top().second;
		int num = calculate.top().first;
		calculate.pop();
		int number = num;
		if(calculate.size())
			number -= calculate.top().first;
		while (number--)
		{
			if (upper)
			{
				sol.push(*remain.rbegin());
				remain.erase(remain.find(*remain.rbegin()));
			}
			else
			{
				sol.push(*remain.begin());
				remain.erase(remain.find(*remain.begin()));
			}
		}
		

	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", sol.top());
		sol.pop();
	}
	return 0;
}