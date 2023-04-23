#include<iostream>
#include<memory.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;


int main()
{
	int t = 3;
	while (t--)
	{
		bool dp[100][50001];
		memset(dp, 0,sizeof dp);
		vector<pair<int,int>>vec(100);//[동전의인덱스번호] = 동전의값,해당 동전의 갯수

		int n;
		cin >> n;
		int total = 0;
		for (int i = 0; i < n; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			vec[i] = { a,b };
			total += a * b;
		}
		//sort(vec.begin(), vec.end());
		if (total % 2 != 0)
		{
			printf("%d\n",0);
			continue;
		}
		for (int i = 1; i <= vec[0].second; i++)
		{
			if(vec[0].first*i<=total/2)
			dp[0][vec[0].first * i] = 1;
		}

		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j <= total / 2; j++)
			{
				//if (dp[i][j] == 1) continue;

				if (j % vec[i].first == 0 && j / vec[i].first <= vec[i].second)
					dp[i][j] = 1;


				if (dp[i - 1][j] == 1)
				{
					dp[i][j] = 1;
					for (int k = 1; k <= vec[i].second; k++)
					{
						if(j + vec[i].first * k<=total/2)
							dp[i][j + vec[i].first *k] = 1;
					}
						
				}

			}
		}
	
			printf("%d\n", dp[n-1][total/2]);
			continue;
		

	}
	return 0;
}

