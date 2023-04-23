#include <string>
#include <vector>
#include<iostream>
#include <queue>
#include<algorithm>

using namespace std;
//7시 40분

struct pos {
	int y, x, dir;
};
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
int main()
{
	int n, m;
	cin >> n >> m;
	pos first;
	cin >> first.y >> first.x >> first.dir;

	vector<vector<int>> vec(n,vector<int>(m,0));
	vector<vector<int>> clean(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
		
			scanf("%d", &vec[i][j]);
		}
	}
	int answer = 0;
	queue<pos> q;
	clean[first.y][first.x] = 1;

	q.push(first);
	while (q.size() > 0)
	{
		pos now = q.front();
		q.pop();
		
		answer++; //이자리청소

		int y = now.y;
		int x = now.x;
		int dir_count = 0;


		//cout << endl;
		//cout << endl;
		//cout << endl;
		//cout <<"방향 "<< now.dir << endl;
		//cout << endl;
		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = 0; j < m; j++)
		//	{
		//		if(vec[i][j]==1)
		//			cout << 2<<" ";
		//		else
		//		{
		//			if (i == y && j == x)
		//				cout << "나 ";
		//			else
		//				cout << clean[i][j] << " ";
		//		}
		//	}
		//	cout << endl;
		//}

		
		while (dir_count<=3)
		{
			if (now.dir == 0)
			{
				now.dir = 3; //왼쪽
				if (x - 1 >= 0 && vec[y][x - 1] == 0 && clean[y][x - 1] == 0)
				{
					clean[y][x - 1] = 1;
					q.push({ now.y,now.x - 1,now.dir });
					break;
				}
				else
				{
					dir_count++;
					continue;
				}
			}
			else if (now.dir == 3)
			{
				now.dir = 2; // 아래쪽
				
				if (y + 1 < n && vec[y+1][x] == 0 && clean[y+1][x] == 0)
				{
					clean[y+1][x] = 1;
					q.push({ now.y+1,now.x ,now.dir });
					break;
				}
				else
				{
					dir_count++;
					continue;
				}
				
				
			}
			else if (now.dir == 2)
			{
				now.dir = 1; //오른쪽

				if (x + 1 < m && vec[y][x + 1] == 0 && clean[y][x + 1] == 0)
				{
					clean[y][x + 1] = 1;
					q.push({ now.y,now.x + 1,now.dir });
					break;
				}
				else
				{
					dir_count++;
					continue;
				}
			}
			else if (now.dir == 1)
			{
				now.dir = 0; //위쪽

				if (y - 1 >= 0 && vec[y - 1][x] == 0 && clean[y - 1][x] == 0)
				{
					clean[y - 1][x] = 1;
					q.push({ now.y - 1,now.x ,now.dir });
					break;
				}
				else
				{
					dir_count++;
					continue;
				}
			}
		}
		if (dir_count == 4) //전방향놉
		{
			if (now.dir == 0)
			{
				if (y + 1 < n && vec[y + 1][x] == 0)
				{
					q.push({ y + 1,x,now.dir });
					answer--;//후진하고 거기 다시 닦을거니까
				}
			}
			else if (now.dir == 3)
			{
				if (x + 1 < m && vec[y][x+1] == 0)
				{
					q.push({ y,x+1,now.dir });
					answer--;//후진하고 거기 다시 닦을거니까
				}
			}
			else if (now.dir == 2)
			{
				if (y - 1 >=0 && vec[y - 1][x] == 0)
				{
					q.push({ y - 1,x,now.dir });
					answer--;//후진하고 거기 다시 닦을거니까
				}
			}
			else if (now.dir == 1)
			{
				if (x - 1 < m && vec[y][x - 1] == 0)
				{
					q.push({ y,x - 1,now.dir });
					answer--;//후진하고 거기 다시 닦을거니까
				}
			}
			else
			{
				break;
			}
		}

	}

	cout << answer;
	return 0;
}