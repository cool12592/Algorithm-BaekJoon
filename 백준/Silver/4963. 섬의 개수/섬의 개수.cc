//6시 18분

#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main()
{
	while (true)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == 0 && b==0)
			break;
		vector<vector<int>> vec(b, vector<int>(a, 0));
		bool visit[51][51] = { false, };
		int sol = 0;
		queue<pair<int,int>> q;
		for(int i=0;i<b;i++)
			for(int j=0;j<a;j++)
				scanf("%d",&vec[i][j]);

	
		for (int i = 0; i < b; i++)
			for (int j = 0; j < a; j++)
			{
				if (vec[i][j] == 1 && visit[i][j] == 0)
				{
					//bfs시작
					q.push({ i,j });
					visit[i][j] = 1;
					sol++;
					while (q.size() > 0)
					{
						int x, y;
						y = q.front().first;
						x = q.front().second;
						q.pop();
						//위쪽
						if (y - 1 >= 0 && visit[y-1][x]==0 && vec[y - 1][x] == 1)
						{
							visit[y - 1][x] = 1;
							q.push({y-1,x});
						}
						//아래쪽
						if (y + 1 < b && visit[y + 1][x] == 0 && vec[y + 1][x] == 1)
						{
							visit[y + 1][x] = 1;
							q.push({ y+1,x });
						}
						//왼쪽
						if (x - 1 >= 0 && visit[y][x-1] == 0 && vec[y][x-1] == 1)
						{
							visit[y][x-1] = 1;
							q.push({ y,x-1 });
						}
						//오른쪽
						if (x + 1 < a && visit[y][x+1] == 0 && vec[y][x+1] == 1)
						{
							visit[y][x+1] = 1;
							q.push({ y,x+1 });
						}
						//왼쪽 위
						if (y - 1 >= 0 && x-1>=0 && visit[y - 1][x-1] == 0 && vec[y - 1][x-1] == 1)
						{
							visit[y - 1][x-1] = 1;
							q.push({ y -1 ,x -1 });
						}
						//오른쪽 위
						if (y - 1 >= 0 && x+1 < a && visit[y - 1][x+1] == 0 && vec[y - 1][x+1] == 1)
						{
							visit[y - 1][x+1] = 1;
							q.push({ y-1 ,x+1 });
						}
						//왼쪽 아래
						if (y + 1 < b&& x-1>=0 && visit[y +1 ][x-1] == 0 && vec[y + 1][x-1] == 1)
						{
							visit[y + 1][x-1] = 1;
							q.push({ y+1,x-1 });
						}
						//오른쪽 아래
						if (y + 1 <b && x+1<a && visit[y + 1][x+1] == 0 && vec[y + 1][x+1] == 1)
						{
							visit[y + 1][x+1] = 1;
							q.push({ y+1,x +1});
						}

					}
				}
					
			}
		cout << sol << endl;

	}
	return 0;
}