#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<memory.h>
#include<string>
using namespace std;




int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> vec1;
	vector<int> vec2;
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		if (a > 0) vec1.push_back(a);
		else vec2.push_back(-a);
	}
	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());

	bool big1 = true;
	if (vec1.size() > 0 && vec2.size() > 0)
	{
		if (vec1.back()>= vec2.back())
			big1 = true;
		else
			big1 = false;
	}
	else if(vec1.size() > 0)
		big1 = true;
	else
		big1 = false;

	int ans = 0;
	if (big1)
	{
		ans += vec1.back();
		int i = m;
		while (i--)
		{
			if (vec1.size())
				vec1.pop_back();
		}
	}
	else
	{
		ans += vec2.back();
		int i = m;
		while (i--)
		{
			if (vec2.size())
				vec2.pop_back();
		}
	}

	while (vec1.size())
	{
		ans += vec1.back() *2;
		int i = m;
		while (i--)
		{
			if(vec1.size())
				vec1.pop_back();
		}
	}

	while (vec2.size())
	{
		ans += vec2.back() *2;
		int i = m;
		while (i--)
		{
			if (vec2.size())
				vec2.pop_back();
		}
	}
	cout << ans;
	return 0;
}