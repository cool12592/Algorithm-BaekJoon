//6시 18분 50분
//8시
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define inf 987654321
struct jelda
{
	int y, x, mycost;
};
int dy[4] = { -1, 1, 0, 0 };  // 상하좌우
int dx[4] = { 0, 0, -1, 1 };
int main()
{
	int number = 0;
	while (true)
	{
		number++;
		int n;
		scanf("%d", &n);
		if (n == 0)
			break;
		vector<vector<int>> vec(n, vector<int>(n, 0));
		vector<vector<int>> cost(n, vector<int>(n, inf));
		int sol = 0;
		queue<jelda> q;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&vec[i][j]);

	
	
				
					//bfs시작
					q.push({ 0,0,vec[0][0] });
					cost[0][0] = vec[0][0];
					
					

					while (q.size() > 0)
					{
						int x, y,now_cost;
						y = q.front().y;
						x = q.front().x;
						now_cost = q.front().mycost;
						q.pop();

						for (int k = 0; k < 4; k++) 
						{
							//nx ny => 가려는 장소
							//(현재 좌표에 방향을 더함)
							int ny = y + dy[k];
							int nx = x + dx[k];

							//경계선체크 먼저
							if (0 > ny || ny > n - 1 || 0 > nx || nx > n - 1) continue;
        
							if (now_cost + vec[ny][nx] < cost[ny][nx]) //갈수있는 조건
							{
								cost[ny][nx] = now_cost + vec[ny][nx];
								q.push({ ny ,nx,cost[ny][nx] });
							}
							
						}

						
						
					}
				
					printf("Problem %d: %d\n", number, cost[n - 1][n - 1]);
				

	}
	return 0;
}