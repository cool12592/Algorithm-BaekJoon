#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<memory.h>
#include<string>
using namespace std;

int n;
vector<int>vec;
int dp[1000001];
int pos[1000001] = { 0, };
int dfs(int index,int now)
{
	if (dp[index] != -1) return dp[index];
	
    if ( index ==n-1 )
		return 1;

	int res = 1;
	if (index < pos[now + 1])
		res += dfs(pos[now + 1], now + 1);
	
	
	dp[index] = res;

	return res;
}

int main()
{
	int size;
	cin >> size;
	vec.resize(size);
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < size; i++)
	{
		int a;
		scanf("%d", &a);
		vec[i]=a;

		pos[a] = i;
	}
	n = size;
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, dfs(i, vec[i]));
	cout << n - ans;
	return 0;
}