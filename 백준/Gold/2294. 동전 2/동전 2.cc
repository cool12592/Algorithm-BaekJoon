#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<memory.h>
using namespace std;




int main()
{
	int n, k;
	cin >> n >> k;
	vector<int>vec(n);
	vector<int>dp(k+1);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &vec[i]);
	}
	dp[0] = 0; 
    sort(vec.begin(),vec.end());
	for (int now : vec)
	{
		dp[now] = 1;
		for (int i = now + 1; i <= k; i++)
		{
			if (dp[i - now] != 0)
			{
				if(dp[i]==0) 
					dp[i] = dp[i - now] + 1;
				else if (dp[i] > dp[i - now]+1)
					dp[i] = dp[i - now]+1;
			}
		}
	}
    if(dp[k]==0) cout<<-1;
	else cout << dp[k];
	return 0;
}