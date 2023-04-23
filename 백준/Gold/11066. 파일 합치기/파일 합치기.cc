#include<iostream>
#include<vector>
#include<queue>
#include<stack>




using namespace std;
vector<vector<int>> dp;
vector<vector<int>> sum;




int mySum(int start, int end)
{
	if (sum[start][end] != 0)
		return sum[start][end];
	
	int sum_val = 0;
	for (int i = start; i <= end; i++)
		sum_val += sum[i][i];

	sum[start][end] = sum_val;
	return sum_val;

}

int dfs(int start, int end) //비용 리턴 
{

	if (dp[start][end]!=0)
		return dp[start][end];

	if (start == end)
		return 0;

	int cost = 0;
	for (int i = start; i <= end-1; i++)
	{
		if(cost==0)
			cost= dfs(start, i) + dfs(i + 1, end) + mySum(start, end);
		else
			cost = min(cost, dfs(start, i) + dfs(i + 1, end) + mySum(start, end));


	}
	dp[start][end] = cost;
	
	return dp[start][end];
}

int main()
{
	
	int t;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		
		dp.clear();
		dp.resize(500,vector<int>(500));
		sum.clear();
		sum.resize(500, vector<int>(500));


		for (int i = 0; i < n; i++)
			scanf("%d", &sum[i][i]);



	
		cout << dfs(0, n - 1)<< endl;
	}

	return 0;
}