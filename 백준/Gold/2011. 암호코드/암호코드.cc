#include<iostream>
#include<memory.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
using namespace std;

#define mod 1000000

int main()
{	
	string str="0";
	string str2;
	cin >> str2;
	str += str2;
	int n = str.size();
	vector<int>dp(n+1);

	dp[0] = 1;



	for (int i = 1; i < n + 1; i++)
	{
		if (str[i] != '0')
		{
			dp[i] += dp[i - 1];
			dp[i] %= mod;
		}
		int num = (str[i] - '0') + (str[i - 1] - '0') * 10;
		if (10 <= num &&num<= 26)
		{
			dp[i] += dp[i - 2];
			dp[i] %= mod;
		}
	}
	cout << dp[str.size() - 1];
	return 0;
}

