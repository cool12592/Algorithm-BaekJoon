#include<iostream>
#include<memory.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
using namespace std;

bool isPrime(int n)
{ 
	if (n < 2)
		return false; 
	for (int i = 2; i * i <= n; i++) 
	{ 
		if (n % i == 0) 
		{ return false; } 
	} 
	return true; 
}


int main()
{
	int n;
	cin >> n;
	map<int,int> m;
	int input;
	int zeroCount = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input);
		if (input == 0)
		{
			zeroCount++;
			continue;
		}
		m[input] += 1;
	}
	vector<long long> dp(500001,0);
	auto now = m.begin();
	for (int i = 0; i < m.size(); i++)
	{
		dp[i] += 0;
		for (int j = 500000; j>=1; j--)
		{
			
			
				if (dp[j] > 0)
				{
					//dp[j] += dp[i - 1][j];
					//if (j % now->first == 0 && j / now->first <= now->second)
					//	continue;
					for (int k = 1; k <= now->second && j + k * now->first <= 500000; k++)
					{
						dp[j + k * now->first] += dp[j]; 
					}
				
				
			
				
			}
			if (j % now->first == 0 && j / now->first <= now->second)
				dp[j] += 1;
		}
		now++;
	}
	long long sum = 0;
	for (int i = 2; i <= 500000; i++)
	{
		if(isPrime(i))
		sum += dp[i];

	}
	cout << sum* zeroCount;

	return 0;
}

