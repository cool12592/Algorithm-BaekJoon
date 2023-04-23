#include<iostream>
#include<memory.h>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<pair<int,int>> vec(n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a,&b);
		vec[i] = { a,b };
	}

	sort(vec.begin(), vec.end());

	vector<int> vec2(n);
	for (int i = 0; i < n; i++)
	{
		vec2[i] = vec[i].second;
			
	}

	vector<int>lis;
	
	for (int i = 0; i < n; i++)
	{
		if (lis.size() == 0) lis.push_back(vec2[i]);
		else
		{
			if (lis[lis.size() - 1] < vec2[i])
				lis.push_back(vec2[i]);
			else
			{
				lis[lower_bound(lis.begin(), lis.end(), vec2[i]) - lis.begin()] = vec2[i];
			}
		}

	}
	cout << n - lis.size();

	return 0;
}

