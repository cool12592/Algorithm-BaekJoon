#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<memory.h>
#include<string>
#include<set>
#include<unordered_map>
using namespace std;




int dy[] = { -1,0,0,1 };
int dx[] = { 0,-1,1,0 };


struct info
{
	int y = 0, x = 0;
	int time = 0;
	int color = 0;
};


int main() {

	
	int n, m, g, r;
	cin >> n >> m >> g >> r;
	vector<vector<int>> vec(n, vector<int>(m));
	vector<pair<int, int>> ground;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &vec[i][j]);
			if (vec[i][j] == 2)
			{
				ground.push_back({ i,j });
				vec[i][j] = 1;
			}
		}
	}
	vector<bool> b1(ground.size(),true);
	for (int i = 0; i < ground.size()-r; i++)
	{
		b1[i] = false;
	}
	map < vector<pair<int,int>>, bool> um_r;
	map < vector<pair<int, int>>, bool> um_g;
	
	vector<vector<int>> visit(n, vector<int>(m,0));
	vector<vector<pair<int,int>>> vec2(n, vector<pair<int, int>>(m));

	int turn = 0;
	int answer = 0;
	do
	{

		int ry, rx, gy, gx;
		
		vector<bool> b2(ground.size(), true);

		for (int i = 0; i < ground.size() - g; i++)
		{
			b2[i] = false;
		}

		do
		{
			bool noop = false;

			//서로 안겹치게 조합 됐는지 확인
			for (int i = 0; i < ground.size(); i++)
			{
				if (b2[i] && b1[i]) //서로 똑같은 장소에 심을 수 없음 곧 지금조합은x
				{
					noop = true;
					break;

				}
			}

			if (noop)
				continue;

			turn++;
			queue<info> q;

		

			for (int i = 0; i < ground.size(); i++)
			{
				if (b1[i])
				{
					ry = ground[i].first;
					rx = ground[i].second;
					vec2[ry][rx] = { 3,0 };
					q.push({ ry,rx,0,3 });
					visit[ry][rx] = turn;
				}

				if (b2[i])
				{
					gy = ground[i].first;
					gx = ground[i].second;
					vec2[gy][gx] = { 4,0 };
					q.push({ gy,gx,0,4 });
					visit[gy][gx] = turn;
				}
			}

			
			
			int flower_num = 0;

			while (q.size())
			{
				info now = q.front();
				q.pop();
				int y = now.y;
				int x = now.x;
				if (vec2[y][x].first == 5)//난 꽃이됐우
					continue;
				

				for (int i = 0; i < 4; i++)
				{
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (ny < 0 || nx < 0 || ny >= n || nx >= m || vec[ny][nx] == 0) continue;
					
					if (now.color == 3)
					{
						if (visit[ny][nx] == turn && vec2[ny][nx].first == 4 && vec2[ny][nx].second == now.time + 1)
						{
							vec2[ny][nx] = { 5,0 }; //꽃핌
							flower_num++;
							continue;
						}
						if (visit[ny][nx] != turn) //이번턴에 그쪽 안가봄(time아님 큰턴임 젤큰거)
						{
							q.push({ ny,nx,now.time + 1,3 });
							visit[ny][nx] = turn;
							vec2[ny][nx] = { now.color,now.time + 1 };
						}


					}
					else if (now.color == 4)
					{
						if (visit[ny][nx] == turn && vec2[ny][nx].first == 3 && vec2[ny][nx].second == now.time + 1)
						{
							vec2[ny][nx] = { 5,0 };//꽃핌
							flower_num++;
							continue;
						}

						if (visit[ny][nx] != turn) //이번턴에 그쪽 안가봄(time아님 큰턴임 젤큰거)
						{
							q.push({ ny,nx,now.time + 1,4 });
							visit[ny][nx] = turn;
							vec2[ny][nx] = { now.color,now.time + 1 };
						}
					}

				}
			}
			
			if (answer < flower_num)
				answer = flower_num;


		} while (next_permutation(b2.begin(), b2.end()));
		

	} while(next_permutation(b1.begin(), b1.end()));
	
	cout << answer;
	return 0;
}