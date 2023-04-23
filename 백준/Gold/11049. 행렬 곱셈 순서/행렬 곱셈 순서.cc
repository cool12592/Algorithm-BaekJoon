#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<memory.h>
using namespace std;

vector<pair<int, int>> vec;
int dp[500][500] = { 0, };
int dfs(int left, int right)
{
	if (dp[left][right] != 0)
		return dp[left][right];
	if (right-left ==1)
		return vec[left].first * vec[left].second  * vec[right].second;

	int res = 0;
	int temp;
	for (int i = left; i < right; i++)
	{
		
		temp = dfs(left, i) + dfs(i + 1, right) + (vec[left].first * vec[i].second * vec[right].second); // 이거 혹은 vec[left].first * vec[i+1].first * vec[right].second
		if (res == 0) res = temp;
		else if (res > temp) res = temp;
	}

	dp[left][right] = res;
	return res;
}


int main()
{
	int n;
	cin >> n;
	vec.resize(n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a,&b);
		vec[i] = { a,b };
	}
	if (n == 1) cout << 1;
	else cout << dfs(0, n - 1);

	return 0;
}