#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct pos {
	int y, x, val,count;
};



int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
vector<vector<int>>dp;
int n, m;
vector<vector<int>> vec;

int dfs(int y,int x)
{


	if (y == n - 1 && x == m - 1)
	{
		return 1;
	}

	if (dp[y][x] != -1) return dp[y][x];

	dp[y][x] = 0;
	
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			
			if (vec[ny][nx] < vec[y][x] )
			{
				dp[y][x] = dp[y][x] + dfs(ny, nx);
			}


		}
		return dp[y][x];
}

int main()
{
	
	cin >> n >> m;
	vector<vector<int>> vec2(n, vector<int>(m, 0));
	vec = vec2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &vec[i][j]);
		}
	}
	


	vector<vector<int>> temp(n, vector<int>(m, -1));
	dp = temp;
	//dp[0][0] = 0;



	cout << dfs(0,0)<<endl;
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
	*/
	return 0;
}