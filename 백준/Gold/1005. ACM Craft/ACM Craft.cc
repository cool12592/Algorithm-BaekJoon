#include<iostream>
#include<vector>
#include<queue>
#include<stack>




using namespace std;

int n, k, destination;
int dfs(int num, vector<int>& dp , vector<vector<int>>& adj , vector<int>& point) //dp[num] 리턴
{

	if (dp[num] != -1)
		return dp[num];

	if (adj[num].size() == 0)
        return point[num];
    
    


	for (int i = 0; i < adj[num].size(); i++)
		dp[num] = max(dp[num], dfs(adj[num][i],dp,adj,point)); //빨대들중젤 큰애 

	dp[num] = dp[num] + point[num]; //마무리는 자기원본더함



	return 	dp[num];
}


int main()
{
	int test;
	cin >> test;
	for (int ind = 0; ind < test; ind++) //테스트 케이스
	{
		
		//cin >> n >> k;
		scanf("%d %d",&n,&k);

		vector<int> dp(n+1, -1);
		vector<vector<int>> adj(n+1);
		vector<int> point(n+1); //원본점수
		

		for (int i = 1; i <= n; i++)
			scanf("%d", &point[i]);

		int num1,num2;
		for (int i = 0; i < k; i++)
		{
			scanf("%d %d", &num1,&num2);
			adj[num2].push_back(num1);
		}
		scanf("%d",&destination);
		
        printf("%d\n", dfs(destination,dp,adj,point) );


	}
	
	return 0;
}