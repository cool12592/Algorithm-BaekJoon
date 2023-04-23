#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<set>
using namespace std;

int n;
vector<int> vec;
vector<int> visit(100001,0);
vector<int> enable_team;
int answer;
int dfs(int now_node)
{

	if (enable_team[now_node] != 0)
		return -1;

	if (visit[now_node] == 1)
	{
		enable_team[now_node] = 1;
		visit[now_node] = 0;

		return now_node;
	}
	visit[now_node] = 1;

	int ret = dfs(vec[now_node]);
	if(ret>0)
	{
		enable_team[now_node] = 1;
		if (ret == now_node)
			ret = -1;
		
	}
	else
		enable_team[now_node] = -1;
	visit[now_node] = 0;
	return ret;




}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		answer = 0;
		enable_team.clear();
		enable_team.resize(n + 1);
		vec.clear();
		vec.resize(n + 1);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &vec[i]);
			
		}
		for(int i=1;i<=n;i++)
			dfs(i);


		for (int i = 1; i <= n; i++)
			if (enable_team[i] == -1)
				answer++;

		printf("%d\n", answer);
	}

	return 0;
}