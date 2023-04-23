#include<iostream>
#include<memory.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
using namespace std;

int dp[3][31][1001];
vector<int> vec;


int main()
{
	int dp[10001] = {0,};

	int n, t;
	cin >> n >> t;
	vector<pair<int,int>>vec(n+1);
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		vec[i] = { a,b };
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = t; j >= 1; j--)
		{
			if(j - vec[i].first>=0)
				dp[j] = max(dp[j], dp[j - vec[i].first] + vec[i].second);
		}
	}
	cout << dp[t];
	return 0;
}

