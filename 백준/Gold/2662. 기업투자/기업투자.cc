#include<iostream>
#include<memory.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
using namespace std;


int main()
{
	int n,m;
	cin >> n>>m;
	int num1,num2;
	map<int, vector<int>>mymap;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num1);
		
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &num2);
			mymap[num1].push_back(num2);
		}
	}

	int dp[20][301];
	memset(dp, 0, sizeof dp);
	
	int path[20][301]; //이번i,j까지중제일큰비용상황에서의 이번i에 투자한비용값을저장
	memset(path, 0, sizeof dp);
	int max_number = 0;

	int maxMoney = mymap.rbegin()->first;
	for (int i = 0; i < m; i++)
	{
		for (int j = 1; j <= maxMoney; j++)
		{
			if (i >= 1)
			{
				dp[i][j] = dp[i - 1][j];
				path[i][j] =0;//이번거를안쓰고 위에꺼를썼으니(이전것들로만구성)
			}

			for (auto now_money : mymap)
			{
				if (now_money.first > j) break;

				
				if (i == 0)
				{
					if (dp[i][j] < now_money.second[i])
					{
						dp[i][j] = now_money.second[i];
						path[i][j] = now_money.first;
						if (max_number < dp[i][j])
						{
							max_number = dp[i][j];
							
						}
					}
					

				
				}
				else if (j - now_money.first >= 0)
				{
					if (dp[i][j] < now_money.second[i] + dp[i - 1][j - now_money.first])
					{
						dp[i][j] = now_money.second[i] + dp[i - 1][j - now_money.first];
						path[i][j] = now_money.first;
						if (max_number < dp[i][j])
						{
							max_number = dp[i][j];
							
						}
					}
				}
				
			}
		}
	}
	cout << dp[m - 1][maxMoney] << endl;
	vector<int> vec2(m);

	for (int i = m - 1; i >= 0; i--)
	{
		vec2[i] = path[i][maxMoney];
		maxMoney -= path[i][maxMoney];
	}

	for (int i = 0; i < vec2.size(); i++)
		printf("%d ", vec2[i]);
	return 0;
}

