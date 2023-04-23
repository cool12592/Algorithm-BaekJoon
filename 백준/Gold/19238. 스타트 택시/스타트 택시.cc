#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<memory.h>
#include<string>
#include<set>
using namespace std;




int dy[] = { -1,0,0,1 };
int dx[] = { 0,-1,1,0 };

struct info
{
	int y = 0, x = 0;
	int fuel = 0;
	int time = 0;

};

class comp
{
public:
	bool operator() (const info& a, const info& b)
	{
		if (a.time != b.time) return a.time > b.time;
		if (a.y != b.y) return a.y > b.y;
		return a.x > b.x;
	}
};



int main()
{
	int n, m, fuel;
	
	cin >> n >> m >> fuel;
	vector<vector<int>> vec(n, vector<int>(n ));
	vector<vector<pair<int,int>>> vec2(n, vector<pair<int, int>>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &vec[i][j]);
		}
	}
	int a, b;
	cin >> a >> b;
	info init = { a - 1,b - 1,fuel,0 };

	for (int i = 0; i < m; i++)
	{
		int q, w, e, r;
		scanf("%d %d %d %d", &q, &w, &e, &r);
		vec2[q - 1][w - 1] = { e ,r  };
	}
	priority_queue<info, vector<info>, comp> pq;
	pq.push(init);
	int answer = -1;
	int mm = m;
	while (true)
	{
		bool finish = true;
		vector<vector<int>> visit(n, vector<int>(n,0));
		visit[pq.top().y][pq.top().x] = 1;

		while (pq.size())
		{
			info now = pq.top();
			pq.pop();
			int y = now.y;
			int x = now.x;
			if (now.fuel == 0)
			{
				finish = true;
				break;

			}

			if (vec2[y][x].first != 0) //손님 탑승이요
			{
				finish = false;
				int dest_y = vec2[y][x].first-1;
				int dest_x = vec2[y][x].second-1;
				vec2[y][x] = { 0,0 };
				queue<info> q;
				vector<vector<int>> visit2(n, vector<int>(n,0));
				visit2[y][x] = 1;
				q.push({ y,x,now.fuel,0 });
				while (q.size())
				{
					info now2 = q.front();
					q.pop();
					int y = now2.y;
					int x = now2.x;
					if (now2.fuel == 0)
					{
						finish = true;
						break;

					}
					bool b = false;
					for (int i = 0; i < 4; i++)
					{
						int ny = y + dy[i];
						int nx = x + dx[i];
						if (ny >= n || nx >= n || ny < 0 || nx < 0 || vec[ny][nx] == 1 || visit2[ny][nx] == 1) continue;
						
						if (ny == dest_y && nx == dest_x)
						{
							while (pq.size()) pq.pop();
							pq.push({ ny,nx,now2.fuel - 1 + ((now2.time+1)*2) ,0 });
							answer = pq.top().fuel;
							b = true;
							mm--;
							break;
						}
						visit2[ny][nx] = 1;
						q.push({ ny,nx,now2.fuel - 1,now2.time+1});
					}
					if (b)
						break;
				}
				break;
			}


			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny >= n || nx >= n || ny < 0 || nx < 0 || vec[ny][nx] == 1 || visit[ny][nx] == 1) continue;
				visit[ny][nx] = 1;
				pq.push({ ny,nx,now.fuel - 1,now.time + 1 });
			}

		}
		if (finish) break;
	}
	if (mm > 0) answer = -1;
	cout << answer;
	return 0;
}