#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<set>
using namespace std;

struct pos {
	int y, x;
	int count;
};
pos dir[4] = { {0,1},{0,-1},{1,0},{-1,0} };

int main()
{

	int n;

	cin >> n;
	vector<vector<int>> vec(n,vector<int>(n));
	vector<vector<int>> island(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &vec[i][j]);
		}
	}
	int cnt = 0;
	queue<pos> expand;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (vec[i][j] == 1)
				expand.push({ i,j,1 });
			if (vec[i][j]==0 || island[i][j] != 0)
				continue;
			
			int now = vec[i][j];
			cnt++;
			island[i][j] = cnt;
			
			queue<pos> q;
			q.push({ i,j });
			while (q.size() > 0)
			{
				pos now = q.front();
				q.pop();
				int next_y, next_x;
				for (int i = 0; i < 4; i++)
				{
					next_y = now.y + dir[i].y;
					next_x = now.x + dir[i].x;
					if (next_y >= n || next_x >= n || next_y < 0 || next_x < 0)
						continue;
					if (vec[next_y][next_x] == 1 && island[next_y][next_x] == 0)
					{
						island[next_y][next_x] = cnt;
						q.push({ next_y,next_x });
					}
				}
			}
		}
	}
	int answer = -1;

	while (expand.size() > 0)
	{
		pos now = expand.front();
		int count = expand.front().count;
		expand.pop();
		int next_y, next_x;
		for (int i = 0; i < 4; i++)
		{
			next_y = now.y + dir[i].y;
			next_x = now.x + dir[i].x;
			if (next_y >= n || next_x >= n || next_y < 0 || next_x < 0 )
				continue;
			if (island[next_y][next_x] == 0) //영역확장
			{
				island[next_y][next_x] = island[now.y][now.x];
				vec[next_y][next_x] = count + 1; //확장길이
				expand.push({ next_y,next_x, count + 1 });
			}
			else if (island[next_y][next_x] != island[now.y][now.x]) //확장하려했는데 다른섬이다
			{
				if (answer == -1)
					answer = count + vec[next_y][next_x] - 2;//서로시작점1씩이라 거리는 2빼야됨
				else
					answer = min(answer, count + vec[next_y][next_x] - 2);
			}
		}

	}

	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << island[i][j] << " ";
		cout << endl;
	}*/

	cout << answer;
	return 0;
}