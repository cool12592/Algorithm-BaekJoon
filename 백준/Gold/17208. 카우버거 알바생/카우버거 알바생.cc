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
	int n, a, b;
	cin >> n >> a >> b;
	vector<pair<int,int>> vec(n + 1);
	int dp[301][301] = {0,};

	for (int i = 1; i <= n; i++)
	{
		
		int aa, bb;
		scanf("%d %d", &aa, &bb);
		vec[i] = { aa,bb };
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = a; j >=1;j--)
		{
			for (int k = b; k >= 1; k--)
			{
				//if (j == 1 && k == 3)
				//	cout << 3;
				if (j - vec[i].first >= 0 && k - vec[i].second >= 0)
				{
					dp[j][k] = max(dp[j][k], dp[j - vec[i].first][k - vec[i].second]+1);
			
				}
			}
		}
	}

	cout << dp[a][b];

	return 0;
}

