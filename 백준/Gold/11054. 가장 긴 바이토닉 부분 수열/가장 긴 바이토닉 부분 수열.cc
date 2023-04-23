#include<iostream>
#include<vector>

using namespace std;



int main()
{
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &vec[i]);
	}

	if (n == 1)
	{
		cout << 1;
		return 0;
	}
	
	vector<int> lis;
	lis.push_back(vec[0]);

	vector < pair<int, int>> dp(n, { 0,0 });
	int answer = 0;
    dp[0]={lis.size(),lis[lis.size()-1]};
    
	for (int i = 1; i < n; i++)
	{

		if (lis[lis.size() - 1] < vec[i])
		{
			lis.push_back(vec[i]);
		}
		else
		{
			lis[lower_bound(lis.begin(), lis.end(), vec[i]) - lis.begin()] = vec[i];
		}
		dp[i] = { lis.size(),lis[lis.size()-1] };
		
	}
	answer = lis.size();
	lis.clear();
	lis.push_back(vec[n-1]);
	vector<int> dp2(n, 0);


	if (dp[n - 2].second == vec[n - 1])
		dp2[n - 1] = dp[n - 2].first + lis.size() - 1;
	else
		dp2[n - 1] = dp[n - 2].first + lis.size();
	answer = max(answer, dp2[n - 1]);
	for (int i = n-2; i >=0; i--)
	{

		if (lis[lis.size() - 1] < vec[i])
		{
			lis.push_back(vec[i]);
		}
		else
		{
			lis[lower_bound(lis.begin(), lis.end(), vec[i]) - lis.begin()] = vec[i];
		}
		
        
        if(i==0)
			answer = max(answer, (int)lis.size() );
		else
		{
		
			
			if (dp[i - 1].second == lis[lis.size()-1])
				dp2[i] = dp[i - 1].first + lis.size() - 1;
			else
				dp2[i] = dp[i - 1].first + lis.size();
			answer = max(answer, dp2[i]);
		}
	}

	
	cout << answer;
	return 0;
}