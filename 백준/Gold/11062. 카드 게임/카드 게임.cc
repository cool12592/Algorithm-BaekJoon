#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;

int dp[2][1001][1001];


int dfs(vector<int>& vec, int left, int right,bool turn)
{
	if (left == right)
    {
        if(turn)
            return vec[left];
        else
            return 0;
    }

	if (dp[turn][left][right] != 0)
		return dp[turn][left][right];


	int res = 0;
	int res1, res2;
	if (turn)
	{
		res1 =vec[left] + dfs(vec, left + 1, right,    !turn);
		res2 = vec[right] +  dfs(vec, left, right - 1,   !turn);
	}
	else
	{
		res1 = dfs(vec, left + 1, right, !turn);
		res2 = dfs(vec, left, right - 1, !turn);
	}

	if (turn)
		res = max(res1, res2);
	else
		res = min(res1, res2);
	dp[turn][left][right] = res;
	return res;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		scanf("%d", &n);
		vector<int>vec(n);
		memset(dp, 0, sizeof dp);
		int i = 0;
		int nn = n;
		while (nn--)
		{
			scanf("%d", &vec[i]);
			i++;
		}
		

		printf("%d\n",dfs(vec, 0, n - 1,true));
	}

	return 0;
}