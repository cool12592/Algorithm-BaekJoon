#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>

using namespace std;
int n, m;
struct pos {
	int y, x;
};
pos dir[3] = { {-1,1},{0,1},{1,1} };
vector<vector<char>> vec;
vector<vector<int>>visit;
bool dfs(int y, int x)
{
	if (x == m - 1)
		return true;
	//visit[y][x] = 1;
	for (int i = 0; i < 3; i++)
	{
		int next_y = y + dir[i].y;
		int next_x = x + dir[i].x;

		if (next_y >= n || next_x >= m || next_y < 0 || next_x < 0)
			continue;
		if (vec[next_y][next_x] == '.' && visit[next_y][next_x] == 0)
		{
			visit[next_y][next_x] = 1;
			if (dfs(next_y, next_x))
				return true;
			

		}

	}
	return false;

}

int main()
{
	
	cin >> n >> m;
	vec.resize(n, vector<char>(m));
	visit.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf(" %c", &vec[i][j]);
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++)
		result+=dfs(i, 0);

	cout << result;
	return 0;
}