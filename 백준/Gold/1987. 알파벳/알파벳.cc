#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<set>
using namespace std;
#define N 26
vector<vector<char>> vec;
int n, m;
struct pos
{
	int y;
	int x;
};

int answer = 0;
pos dir[4] = { {0,1},{0,-1},{1,0},{-1,0} };
void dfs(pos now, int visited, int count)
{
	if (answer < count)
		answer = count;

	int next_y;
	int next_x;
	for (int i = 0; i < 4; i++)
	{
		next_y = now.y + dir[i].y;
		next_x = now.x + dir[i].x;

		if (next_y >= n || next_x >= m || next_y < 0 || next_x < 0)
			continue;
		if (visited & (1 << (vec[next_y][next_x] - 65)))
			continue;

		dfs({ next_y,next_x }, visited | (1 << (vec[next_y][next_x] - 65)),count+1);

	}

	return;

}

int main()
{
	cin >> n >> m;
	vec.resize(n, vector<char>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf(" %c", &vec[i][j]);
		}
	}
	int visited = (1 << N);
	dfs({ 0,0 }, visited | (1 << (vec[0][0] - 65)), 1);
	cout << answer;
	return 0;
}