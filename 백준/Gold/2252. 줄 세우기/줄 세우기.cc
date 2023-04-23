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
	int n, m;
	cin >> n >> m;

	vector<vector<int>> vec(n + 1);
	int a, b;
	int candi = n;
	vector<int> indegree(n + 1,0);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		indegree[b]++;

	}
	queue<int> q;
	for (int i = 1; i <=n; i++)
	{
		if (indegree[i] == 0) //진입차수0인애들
			q.push(i);
	}
	
	while (q.size() > 0)
	{
		
		int now = q.front();
		printf("%d ", now);
		q.pop();
		for (int i = 0; i < vec[now].size(); i++)
		{
			indegree[vec[now][i]]--;
			if (indegree[vec[now][i]] == 0)
				q.push(vec[now][i]);
		}
	
	}

	return 0;
}