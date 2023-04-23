#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	int a;
	cin >> a;
	vector<pair<int, int>> vec;
	vector<pair<int, int>> dp;
	int b, c;
	for (int i = 0; i < a; i++)
	{
		scanf("%d %d", &b, &c);
		vec.push_back({ b,c });
	}
	dp = vec;
	int later_ind = 0;
	int max_ = 0;
	for (int i = 0; i < dp.size(); i++)
	{
	
		later_ind = i + dp[i].first;
		if (later_ind <= dp.size()) //작업을 완료할수 있어야됨
		{
			if (max_ < dp[i].second)
				max_ = dp[i].second;
		}
		while (later_ind < dp.size())
		{
			dp[later_ind].second = max(vec[later_ind].second + dp[i].second, dp[later_ind].second); //이전에 어떤애가 들렸을 수 있기 때문. 걔보다 커야 갱신도ㅚㅁ
			later_ind++;
		}
		
		


	}
	cout << max_;
	return 0;
}