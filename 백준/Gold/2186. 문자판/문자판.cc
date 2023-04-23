#include<iostream>
#include<memory.h>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

vector<string> vec;
string target;
int dp[100][100][80];

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
int n, m, k;
int dfs(int y, int x, int target_index)
{
	if (dp[y][x][target_index] != -1)
		return dp[y][x][target_index];
	if (target_index == target.size() - 1)
		return 1;

	//나자신일때도 체크해야돼 이거 잊을삘이다 제자리체크!!!!
	//아 아니네 반드시 이동해야되는데 같은칸 또이동가능한거구나~
	int res = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int move = 1; move <= k; move++)
		{
			int ny = y + dy[i] * move;
			int nx = x+ dx[i] * move;

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

			if (vec[ny][nx] == target[target_index + 1])
				res += dfs(ny, nx, target_index + 1);

		}
	}



	dp[y][x][target_index] = res;
	return dp[y][x][target_index];

}

int main()
{

	cin >> n >> m >> k;
	vec.resize(n);
	for (int i = 0; i < n; i++)
	{

		cin >> vec[i];
	}
	cin >> target;

	memset(dp, -1, sizeof dp);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (vec[i][j] == target[0])
			{
				sum += dfs(i,j,0);
			}
		}
	}
	cout << sum;
	return 0;
}

