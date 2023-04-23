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
	int ry = 0, rx = 0;
	int by = 0, bx = 0;
	int time = 0;

};




//'.', '#', 'O', 'R', 'B'
int main()
{
	int n, m;
	cin >> n >> m;

	vector<string> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	info init;
	int dest_y = 0, dest_x = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (vec[i][j] == 'R')
			{
				init.ry = i;
				init.rx = j;
				vec[i][j] = '.';
			}
			if (vec[i][j] == 'B')
			{
				init.by = i;
				init.bx = j;
				vec[i][j] = '.';
			}
			if (vec[i][j] == 'O')
			{
				dest_y = i;
				dest_x = j;
				vec[i][j] = '.';
			}
		}

	}
	bool visit[10][10][10][10] = { 0, }; //ry rx by bx

	queue<info> q;
	q.push(init);
	int answer = -1;
	while (q.size())
	{
		info now = q.front();
		q.pop();

		//if (now.time >= 10) continue;



		//위로간다
		if (now.ry < now.by)
		{
			int ry = now.ry;
			int rx = now.rx;
			int by = now.by;
			int bx = now.bx;
			int suc = 0;
			while (true)
			{
				if (ry == dest_y && rx == dest_x)
				{
					ry = 0;
					rx = 0;
					suc += 1;
					answer = now.time + 1;
					break;
				}

				if (vec[ry - 1][rx] == '.' && !(ry - 1 == by && rx == bx))
					ry--;
				else
					break;


			}
			while (true)
			{
				if (by == dest_y && bx == dest_x)
				{
					suc = -100;
					break;
				}
				if (vec[by - 1][bx] == '.' && !(by - 1 == ry && bx == rx))
					by--;
				else
					break;
			}
			if (suc > 0)
			{
				cout << answer;
				return 0;
			}
			if (suc == 0 && visit[ry][rx][by][bx] == 0)
			{
				visit[ry][rx][by][bx] = 1;
				q.push({ ry,rx,by,bx,now.time + 1 });
			}
		}
		else
		{
			int ry = now.ry;
			int rx = now.rx;
			int by = now.by;
			int bx = now.bx;
			int suc = 0;

			while (true)
			{
				if (by == dest_y && bx == dest_x)
				{
					suc = -100;
					break;
				}
				if (vec[by - 1][bx] == '.' && !(by - 1 == ry && bx == rx))
					by--;
				else
					break;
			}
			while (true)
			{
				if (ry == dest_y && rx == dest_x)
				{
					ry = 0;
					rx = 0;
					suc += 1;
					answer = now.time + 1;

					break;
				}

				if (vec[ry - 1][rx] == '.' && !(ry - 1 == by && rx == bx))
					ry--;
				else
					break;


			}
			if (suc > 0)
			{
				cout << answer;
				return 0;
			}
			if (suc == 0 && visit[ry][rx][by][bx] == 0)
			{
				visit[ry][rx][by][bx] = 1;
				q.push({ ry,rx,by,bx,now.time + 1 });
			}
		}



		//아래로간다
		if (now.ry > now.by)
		{
			int ry = now.ry;
			int rx = now.rx;
			int by = now.by;
			int bx = now.bx;
			int suc = 0;
			while (true)
			{
				if (ry == dest_y && rx == dest_x)
				{
					ry = 0;
					rx = 0;
					suc += 1;
					answer = now.time + 1;

					break;
				}

				if (vec[ry + 1][rx] == '.' && !(ry + 1 == by && rx == bx))
					ry++;
				else
					break;


			}
			while (true)
			{
				if (by == dest_y && bx == dest_x)
				{
					suc = -100;
					break;
				}
				if (vec[by + 1][bx] == '.' && !(by + 1 == ry && bx == rx))
					by++;
				else
					break;
			}
			if (suc > 0)
			{
				cout << answer;
				return 0;
			}
			if (suc == 0 && visit[ry][rx][by][bx] == 0)
			{
				visit[ry][rx][by][bx] = 1;
				q.push({ ry,rx,by,bx,now.time + 1 });
			}
		}
		else
		{
			int ry = now.ry;
			int rx = now.rx;
			int by = now.by;
			int bx = now.bx;
			int suc = 0;

			while (true)
			{
				if (by == dest_y && bx == dest_x)
				{
					suc = -100;
					break;
				}
				if (vec[by + 1][bx] == '.' && !(by + 1 == ry && bx == rx))
					by++;
				else
					break;
			}

			while (true)
			{
				if (ry == dest_y && rx == dest_x)
				{
					ry = 0;
					rx = 0;
					suc += 1;
					answer = now.time + 1;

					break;
				}

				if (vec[ry + 1][rx] == '.' && !(ry + 1 == by && rx == bx))
					ry++;
				else
					break;


			}

			if (suc > 0)
			{
				cout << answer;
				return 0;
			}
			if (suc == 0 && visit[ry][rx][by][bx] == 0)
			{
				visit[ry][rx][by][bx] = 1;
				q.push({ ry,rx,by,bx,now.time + 1 });
			}
		}



		//오른쪽으로간다
		if (now.rx > now.bx)
		{
			int ry = now.ry;
			int rx = now.rx;
			int by = now.by;
			int bx = now.bx;
			int suc = 0;
			while (true)
			{
				if (ry == dest_y && rx == dest_x)
				{
					ry = 0;
					rx = 0;
					suc += 1;
					answer = now.time + 1;

					break;
				}

				if (vec[ry][rx + 1] == '.' && !(ry == by && rx + 1 == bx))
					rx++;
				else
					break;


			}
			while (true)
			{
				if (by == dest_y && bx == dest_x)
				{
					suc = -100;
					break;
				}
				if (vec[by][bx + 1] == '.' && !(by == ry && bx + 1 == rx))
					bx++;
				else
					break;
			}
			if (suc > 0)
			{
				cout << answer;
				return 0;
			}
			if (suc == 0 && visit[ry][rx][by][bx] == 0)
			{
				visit[ry][rx][by][bx] = 1;
				q.push({ ry,rx,by,bx,now.time + 1 });
			}
		}
		else
		{
			int ry = now.ry;
			int rx = now.rx;
			int by = now.by;
			int bx = now.bx;
			int suc = 0;

			while (true)
			{
				if (by == dest_y && bx == dest_x)
				{
					suc = -100;
					break;
				}
				if (vec[by][bx + 1] == '.' && !(by == ry && bx + 1 == rx))
					bx++;
				else
					break;
			}

			while (true)
			{
				if (ry == dest_y && rx == dest_x)
				{
					ry = 0;
					rx = 0;
					suc += 1;
					answer = now.time + 1;

					break;
				}

				if (vec[ry][rx + 1] == '.' && !(ry == by && rx + 1 == bx))
					rx++;
				else
					break;


			}

			if (suc > 0)
			{
				cout << answer;
				return 0;
			}
			if (suc == 0 && visit[ry][rx][by][bx] == 0)
			{
				visit[ry][rx][by][bx] = 1;
				q.push({ ry,rx,by,bx,now.time + 1 });
			}
		}

		//왼쪽으로간다
		if (now.rx < now.bx)
		{
			int ry = now.ry;
			int rx = now.rx;
			int by = now.by;
			int bx = now.bx;
			int suc = 0;
			while (true)
			{
				if (ry == dest_y && rx == dest_x)
				{
					suc += 1;
					ry = 0;
					rx = 0;
					answer = now.time + 1;

					break;
				}

				if (vec[ry][rx - 1] == '.' && !(ry == by && rx - 1 == bx))
					rx--;
				else
					break;


			}
			while (true)
			{
				if (by == dest_y && bx == dest_x)
				{
					suc = -100;
					break;
				}
				if (vec[by][bx - 1] == '.' && !(by == ry && bx - 1 == rx))
					bx--;
				else
					break;
			}
			if (suc > 0)
			{
				cout << answer;
				return 0;
			}
			if (suc == 0 && visit[ry][rx][by][bx] == 0)
			{
				visit[ry][rx][by][bx] = 1;
				q.push({ ry,rx,by,bx,now.time + 1 });
			}
		}
		else
		{
			int ry = now.ry;
			int rx = now.rx;
			int by = now.by;
			int bx = now.bx;
			int suc = 0;
			while (true)
			{
				if (by == dest_y && bx == dest_x)
				{
					suc = -100;
					break;
				}
				if (vec[by][bx - 1] == '.' && !(by == ry && bx - 1 == rx))
					bx--;
				else
					break;
			}

			while (true)
			{
				if (ry == dest_y && rx == dest_x)
				{
					ry = 0;
					rx = 0;
					suc += 1;
					answer = now.time + 1;

					break;
				}

				if (vec[ry][rx - 1] == '.' && !(ry == by && rx - 1 == bx))
					rx--;
				else
					break;


			}

			if (suc > 0)
			{
				cout << answer;
				return 0;
			}
			if (suc == 0 && visit[ry][rx][by][bx] == 0)
			{
				visit[ry][rx][by][bx] = 1;
				q.push({ ry,rx,by,bx,now.time + 1 });
			}
		}

	}
	cout << -1;
	return 0;
}