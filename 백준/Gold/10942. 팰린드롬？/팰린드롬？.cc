#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>



using namespace std;


vector<vector<int>> dp;
vector<int> vec;


bool dfs(int start, int end) //대칭이 되는지 리턴
{
	if (dp[start][end]!=-1)
		return dp[start][end];

	if (start > end)
		return 1;
	

	if (vec[start] != vec[end])
		return false;
	else
		dp[start][end]=dfs(start+1, end-1);


	return dp[start][end];
	
}




int main()
{
	int n, k;
	cin >> n;
	dp.resize(n, vector<int>(n,-1));
	vec.resize(n);
	int num;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &vec[i]);
		dp[i][i] = 1;
	}
	cin >> k;
	
	int s, e;

	for (int i = 0; i < k; i++)
	{
		scanf("%d %d", &s, &e);
		printf("%d\n", dfs(s-1,e-1));
	}	

	return 0;
}