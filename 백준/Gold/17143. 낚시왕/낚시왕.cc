#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<set>
using namespace std;
int n, m, k;
struct shark
{
	int y, x, vel, dir, size;
	int time;
	int life;
};

vector<vector<int>>vec;
vector<shark> shark_vec;
int answer = 0;

void move_to(int num)
{
	
	shark& sh = shark_vec[num];
	sh.time++;
	int remain;
	if (sh.dir == 1 || sh.dir == 2)
	{
		if (sh.dir == 1)
		{
			remain = sh.y-1;

			if (sh.vel <= remain)
			{
				sh.y -= sh.vel;
			}
			else
			{
				int move1 = (sh.vel - remain) / (n - 1);
				int move2 = (sh.vel - remain) % (n - 1);
				if (move1 % 2 == 0)
				{
					sh.y = move2+1;
					sh.dir = 2;
				}
				else
					sh.y = n - move2;
			}
		}

		else if (sh.dir == 2)
		{
			remain = n-sh.y;

			if (sh.vel <= remain)
			{
				sh.y += sh.vel;
			}
			else
			{
				int move1 = (sh.vel - remain) / (n - 1);
				int move2 = (sh.vel - remain) % (n - 1);
				if (move1 % 2 == 0)
				{
					sh.y = n-move2;
					sh.dir = 1;
				}
				else
					sh.y =  move2+1;
			}
		}
	}

	else if (sh.dir == 3 || sh.dir == 4)
	{
		if (sh.dir == 4)
		{
			remain = sh.x-1;

			if (sh.vel <= remain)
			{
				sh.x -= sh.vel;
			}
			else
			{
				int move1 = (sh.vel - remain) / (m- 1);
				int move2 = (sh.vel - remain) % (m - 1);
				if (move1 % 2 == 0)
				{
					sh.x = move2+1;
					sh.dir = 3;
				}
				else
					sh.x = m - move2;
			}
		}

		else if (sh.dir == 3)
		{
			remain = m - sh.x;

			if (sh.vel <= remain)
			{
				sh.x += sh.vel;
			}
			else
			{
				int move1 = (sh.vel - remain) / (m - 1);
				int move2 = (sh.vel - remain) % (m - 1);
				if (move1 % 2 == 0)
				{
					sh.x = m - move2;
					sh.dir = 4;
				}
				else
					sh.x = move2+1;
			}
		}
	}
	
	
	
	//마지막에
	if (vec[sh.y][sh.x]!=0 && shark_vec[vec[sh.y][sh.x]].time == shark_vec[num].time)
	{
		if (shark_vec[vec[sh.y][sh.x]].size < shark_vec[num].size)
		{
			shark_vec[vec[sh.y][sh.x]].life = 0; //기존상어는없어지고
			vec[sh.y][sh.x] = num; //내가 더 크면 나로 갈아치움
			
		}
		else
			shark_vec[num].life = 0;
		
	}
	else
		vec[sh.y][sh.x] = num;

}

void hunt(int j)
{
	for (int i = 1; i <= n; i++)
	{
		if (vec[i][j] != 0)
		{
			
			answer+= shark_vec[vec[i][j]].size;
			shark_vec[vec[i][j]].life = 0;
			vec[i][j] = 0;//상어사냥
			
			return;
		}
	}

	return;
}

int main()
{
	
	cin >> n >> m >> k;
	int a, b, c, d, e;
	shark_vec.resize(k+1);
	vec.resize(n + 1,vector<int>( m + 1));
	for (int i = 1; i <= k; i++)
	{
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
		shark sh = { a,b,c,d,e,0 ,1 };
		shark_vec[i] = sh;
		vec[a][b] = i;


	}
	/*cout << endl; cout << endl; cout << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl; cout << endl; cout << endl;*/

	for (int t = 0; t < m; t++)
	{
		//cout << endl;
		//cout << endl;
		//cout << t + 1 << "초" << endl;
		//cout << endl;
		hunt(t + 1);

		for (int i = 1; i < shark_vec.size(); i++)
		{
			if (shark_vec[i].life == 0)
				continue;
			if(vec[shark_vec[i].y][shark_vec[i].x] == i ) //이자리차지하고있는애가 나라면
				vec[shark_vec[i].y][shark_vec[i].x] = 0;
			move_to(i);
		}

		/*for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{

				
				if (vec[i][j] != 0)
				{
					int sn = vec[i][j];
					if (shark_vec[sn].time != t)
						continue;
					
					vec[i][j] = 0;
					move_to(sn);

					
				}
			}
		
		}*/
	
	/*	for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cout << vec[i][j] << " ";
			}
			cout << endl;
		}*/
		
	}

	cout << answer;
	return 0;
}