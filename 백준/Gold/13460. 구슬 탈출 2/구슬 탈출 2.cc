#include <string>
#include <vector>
#include<iostream>
#include <queue>
//7시 30분
using namespace std;
//내가 생각해낸 풀이
//bfs로 갈수있는곳 계속 이동
//visit은 빨간공 파란공위치 세트로 해야됨
//그 상황 해본적없다면 visit체크하고 큐에집어넣음
//가장먼저 빨강은 목표지점, 파란은 not목표지점되는 상황이정답
//파란공이 목표지점되면 그 상황은 x


pair<int, int> target, red, blue;
int n, m;
struct pos
{
	int ry, rx, by, bx;
	int count;
	
};


pos move_to(int dir,pos p , vector<vector<char>> vec)
{
	//파랑부터 하고 타겟지점 안가면 빨강하면됨
	pos dest = { -1,-1,-1,-1,p.count };
	bool success = false;
	
	//빨강먼저이동하는경우는 항상 파랑까지 확인해야함
	//파랑도 구멍안 통과해야 진짜 통과거든
	
	//위로
	if (dir == 0)
	{
		
		//기본은 파랑먼저 
		int first_ = 1; //1은 파랑먼저 -1는 빨강먼저
		if (p.bx == p.rx)
		{
			if (p.by - p.ry > 0) //by가 아래인경우
				first_ = -1; //빨먼저
			else 
				first_ = 1;
		}

		//파랑먼저 경로에 빨강없음 x가 같고 빨강이 나보다 위에있으면 
		//fist_는 -1임
		if (first_ == 1)
		{
			for (int i = p.by; i >= 0; i--)
			{
				if (vec[i][p.bx] == 'O')
				{
					return { -1,-1,-1,-1,-1 }; //이건안된단뜻
				}

				if (vec[i][p.bx] == '#')
				{
					dest.by = i + 1;
					dest.bx = p.bx;
					break;
				}
			}

			for (int i = p.ry; i >= 0; i--)
			{
				if (vec[i][p.rx] == '#' || (i==dest.by && p.rx==dest.bx))
				{
					dest.ry = i + 1;
					dest.rx = p.rx;
					break;
				}

				if (vec[i][p.rx] == 'O')
				{
					return { -2,-2,-2,-2,p.count }; //이건된단뜻
				}
			}

		}

		//빨강먼저
		else
		{
			for (int i = p.ry; i >= 0; i--)
			{
				if (vec[i][p.rx] == '#')
				{
					dest.ry = i + 1;
					dest.rx = p.rx;
					break;
				}

				if (vec[i][p.rx] == 'O')
				{
					dest.ry = i;
					dest.rx = p.rx;
					success = true;
					break;
					//return { -2,-2,-2,-2,p.count }; //이건된단뜻
				}
			}

			for (int i = p.by; i >= 0; i--)
			{
				if (vec[i][p.bx] == 'O')
				{
					return { -1,-1,-1,-1,-1 }; //이건안된단뜻
				}

				if (vec[i][p.bx] == '#' || (dest.ry==i && dest.rx == p.bx))
				{
					dest.by = i + 1;
					dest.bx = p.bx;
					break;
				}
			}

		
		}
		
		if(success)
			return { -2,-2,-2,-2,p.count }; //이건된단뜻

		return dest;
	}


	//아래
	if (dir == 1)
	{
		//기본은 파랑먼저 
		int first_ = 1; //1은 파랑먼저 -1는 빨강먼저
		if (p.bx == p.rx)
		{
			if (p.by - p.ry > 0) //by가 아래인경우
				first_ = 1; //파먼저
			else
				first_ = -1;
		}


		if (first_ == 1)
		{
			for (int i = p.by; i < n; i++)
			{
				if (vec[i][p.bx] == 'O')
				{
					return { -1,-1,-1,-1,-1 }; //이건안된단뜻
				}

				if (vec[i][p.bx] == '#')
				{
					dest.by = i - 1;
					dest.bx = p.bx;

				
					break;
				}


			}

			for (int i = p.ry; i < n; i++)
			{
				if (vec[i][p.rx] == '#' || (i==dest.by && p.rx==dest.bx))
				{
					dest.ry = i - 1;
					dest.rx = p.rx;
					break;
				}
				if (vec[i][p.rx] == 'O')
				{
					return { -2,-2,-2,-2,p.count }; //이건된단뜻
				}
			}
		}
		//빨강먼저
		else
		{
			for (int i = p.ry; i < n; i++)
			{
				if (vec[i][p.rx] == '#')
				{
					dest.ry = i - 1;
					dest.rx = p.rx;
					break;
				}
				if (vec[i][p.rx] == 'O')
				{
					dest.ry = i;
					dest.rx = p.rx;
					success = true;
					break;
					//return { -2,-2,-2,-2,p.count }; //이건된단뜻
				}
			}

			for (int i = p.by; i < n; i++)
			{
				if (vec[i][p.bx] == 'O')
				{
					return { -1,-1,-1,-1,-1 }; //이건안된단뜻
				}

				if (vec[i][p.bx] == '#' || (i==dest.ry && p.bx == dest.rx))
				{
					dest.by = i - 1;
					dest.bx = p.bx;


					break;
				}


			}


		}

		
		


		
		if (success)
			return { -2,-2,-2,-2,p.count }; //이건된단뜻

		return dest;
	}

	//왼
	if (dir == 2)
	{
		//기본은 파랑먼저 
		int first_ = 1; //1은 파랑먼저 -1는 빨강먼저
		if (p.by == p.ry)
		{
			if (p.bx - p.rx > 0) //bx가 오른쪽인 경우
				first_ = -1; //빨먼저
			else
				first_ = 1;
		}

		//파먼저
		if (first_ == 1)
		{
			for (int j = p.bx; j >= 0; j--)
			{
				if (vec[p.by][j] == 'O')
				{
					return { -1,-1,-1,-1,-1 }; //이건안된단뜻
				}

				if (vec[p.by][j] == '#')
				{
					dest.by = p.by;
					dest.bx = j + 1;

					break;
				}


			}

			for (int j = p.rx; j >= 0; j--)
			{
				if (vec[p.ry][j] == '#' || (p.ry==dest.by && j==dest.bx))
				{
					dest.ry = p.ry;
					dest.rx = j + 1;
					break;
				}

				if (vec[p.ry][j] == 'O')
				{
					return { -2,-2,-2,-2,p.count }; //이건된단뜻
				}
			}
		}
		//빨먼저
		else
		{
			for (int j = p.rx; j >= 0; j--)
			{
				if (vec[p.ry][j] == '#' )
				{
					dest.ry = p.ry;
					dest.rx = j + 1;
					break;
				}

				if (vec[p.ry][j] == 'O')
				{
					dest.ry = p.ry;
					dest.rx = j;

					success = true;
					break;
					//return { -2,-2,-2,-2,p.count }; //이건된단뜻
				}
			}

			for (int j = p.bx; j >= 0; j--)
			{
				if (vec[p.by][j] == 'O')
				{
					return { -1,-1,-1,-1,-1 }; //이건안된단뜻
				}

				if (vec[p.by][j] == '#' || (p.by==dest.ry && j==dest.rx))
				{
					dest.by = p.by;
					dest.bx = j + 1;

					break;
				}


			}
		}

		
		

		
		if (success)
			return { -2,-2,-2,-2,p.count }; //이건된단뜻

		return dest;
	}

	//오른
	if (dir == 3)
	{


		//기본은 파랑먼저 
		int first_ = 1; //1은 파랑먼저 -1는 빨강먼저
		if (p.by == p.ry)
		{
			if (p.bx - p.rx > 0) //bx가 오른쪽인 경우
				first_ = 1; //파먼저
			else
				first_ = -1;
		}

		if (first_ == 1)
		{
			for (int j = p.bx; j < m; j++)
			{
				if (vec[p.by][j] == 'O')
				{
					return { -1,-1,-1,-1,-1 }; //이건안된단뜻
				}

				if (vec[p.by][j] == '#')
				{
					dest.by = p.by;
					dest.bx = j - 1;
					break;
				}


			}


			for (int j = p.rx; j < m; j++)
			{
				if (vec[p.ry][j] == '#' || (p.ry==dest.by && j==dest.bx))
				{
					dest.ry = p.ry;
					dest.rx = j - 1;
					break;
				}

				if (vec[p.ry][j] == 'O')
				{
					return { -2,-2,-2,-2,p.count }; //이건된단뜻
				}
			}
		}

		else
		{
			for (int j = p.rx; j < m; j++)
			{
				if (vec[p.ry][j] == '#')
				{
					dest.ry = p.ry;
					dest.rx = j - 1;
					break;
				}

				if (vec[p.ry][j] == 'O')
				{
					dest.ry = p.ry;
					dest.rx = j;
					success = true;
					//return { -2,-2,-2,-2,p.count }; //이건된단뜻
				}
			}

			for (int j = p.bx; j < m; j++)
			{
				if (vec[p.by][j] == 'O')
				{
					return { -1,-1,-1,-1,-1 }; //이건안된단뜻
				}

				if (vec[p.by][j] == '#' || (p.by==dest.ry && j == dest.rx))
				{
					dest.by = p.by;
					dest.bx = j - 1;
					break;
				}


			}
		}
	
	}

	if (success)
		return { -2,-2,-2,-2,p.count }; //이건된단뜻

	return dest;

}

int main()
{
	//bluey bluex redy redx 순
	int visit[10][10][10][10] = { 0, };
	cin >> n >> m;
	vector<vector<char>> vec(n,vector<char>(m,' '));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf(" %c", &vec[i][j]);
			if (vec[i][j] == 'O')
				target = { i,j };

			else if (vec[i][j] == 'R')
				red = { i,j };

			else if (vec[i][j] == 'B')
				blue = { i,j };
		}
	}

	queue<pos> q;
	//queue<vector<int>> dir_q;
	//dir_q.push({ -1 });
	q.push({ red.first,red.second,blue.first,blue.second,0 });

	while (q.size() > 0)
	{
		pos now = q.front();
		q.pop();

		
		

		
		if (now.count == 10) //더이동불가
			continue;

		//이동함수구현 좌표와 방향 주면 막히는곳까지 이동해서 도착지점 좌표리턴
		//현재30분소모 8시24분다시시작
		
		for (int i = 0; i < 4; i++)
		{
			pos dest = move_to(i, now, vec);
			dest.count +=1;
			if (dest.by == -1 && dest.bx == -1)
				continue;

			if (dest.ry == -2 && dest.rx == -2)
			{
				cout << dest.count;
				//vector<int> temp = dir_q.front();
				//temp.push_back(i);
				//cout << endl;
				//for (int i = 0; i < temp.size(); i++)
				//	cout << temp[i] << endl;

				return 0;
			}

			if (visit[dest.by][dest.bx][dest.ry][dest.rx] == 0)
			{
				//vector<int> temp = dir_q.front();
				//temp.push_back(i);
				//dir_q.push(temp);

				q.push(dest);
				
				
				visit[dest.by][dest.bx][dest.ry][dest.rx] = 1;
			}
		}
		//dir_q.pop();

		

	}


	cout <<-1;
	return 0;
}