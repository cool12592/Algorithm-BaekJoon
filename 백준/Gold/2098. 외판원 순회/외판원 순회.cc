#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>

#define N 16
#define inf 987654321
using namespace std;
vector<vector<int>> adj;

int dp[N][1 << N];
int n;
int TSP(int now, int visited)
{
	if (dp[now][visited] != 0)
		return dp[now][visited];

	if (visited == ((1 << n) - 1)) //다돌았다면 이제 여기서 처음도시로 돌아가야함
	{
		if (adj[now][0] == 0)//근데 처음도시로가는길이없다면
			return inf; //얘는안되는루트
		else
			return adj[now][0]; //되는 루트
	}


	int ret = inf;
	for (int i = 0; i < n; i++)
	{
		if (adj[now][i] == 0 || visited & (1 << i)) //1<<i가 다음목적지 //이미가봤으면 그 비트자리 1끼리 곱해서 0이안되서 트루가됨
			continue;
		ret = min(ret, adj[now][i] + TSP(i, visited | (1 << i)));

	}
	dp[now][visited] = ret;
	return dp[now][visited];
}
int main()
{
	
	cin >> n;
	adj.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &adj[i][j]);
		}
	}
	cout << TSP(0, 1);
	return 0;
}