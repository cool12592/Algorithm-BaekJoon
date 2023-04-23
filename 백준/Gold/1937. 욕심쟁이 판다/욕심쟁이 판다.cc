#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


int n;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
int  dp[500][500] = { 0, };
int vec[500][500] = { 0, };
int answer = 1;
int dfs(int y,int x)
{

	bool no_road = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n)
			continue;



		if (vec[ny][nx] <= vec[y][x]) //대나무더많은데로 이동해야됨
			continue;

		no_road = false;

		if (dp[ny][nx] != 0) //이미 가봤던길
			dp[y][x] = max(dp[y][x],dp[ny][nx]+1); //왼쪽루트로가면 백만로드인데 위에는 이미가본길임 근데 그 수가 작음 그럼 백만로드로 가야지 그래서 max로 (상하좌우중젤큰거)
			//max안하면 무조건 상하좌우중 이미갔던길로만감(다른길이 더좋아도)
		else
			dp[y][x] =max(dp[y][x], dfs(ny, nx)+1 ); //상하좌우로 다 갈수가 없음 한쪽길로만 가야하기 때문에 max로 (상하좌우중 제일 긴 길 선택)
			//max안하면 상화좌우값 다 누적됨
		
			
	
	}
	if (no_road)
	{
		dp[y][x] = 1;
		return 1;

	}


	answer = max(answer, dp[y][x]);
	return dp[y][x];

}
int main()
{

	cin >> n;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &vec[i][j]);
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//bfs시작

			//이미 이 길다른데서 가봄
			if (dp[i][j] != 0) continue;

			dfs(i, j);
				
		}
	}


	

	cout << answer;
	return 0;
}