#include<iostream>
#include<memory.h>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
string str1, str2;
string sol_str;
int dp1[100][20];
int dp2[100][20];
int dfs(bool isTop,int index,int solIndex )
{
	if (isTop && dp1[index][solIndex] != -1)
		return dp1[index][solIndex];
	if (!isTop && dp2[index][solIndex] != -1)
		return dp2[index][solIndex];
	
	if (solIndex==sol_str.size()-1)
	{
		if ( isTop)
			dp1[index][solIndex] = 1;
		if (!isTop)
			dp2[index][solIndex] = 1;
		return 1;
	}
	int s=0;
	if (isTop)
	{
		for (int i = index + 1; i < str2.size(); i++)
		{
			if (sol_str[solIndex + 1] == str2[i])
			{
				s += dfs(!isTop, i, solIndex + 1);
			}
		}
	}
	else
	{
		for (int i = index + 1; i < str1.size(); i++)
		{
			if (sol_str[solIndex + 1] == str1[i])
			{
				s += dfs(!isTop, i, solIndex + 1);
			}
		}
	}
	if (isTop)
		dp1[index][solIndex] = s;
	if (!isTop)
		dp2[index][solIndex] = s;

	return s;
}


int main()
{

	cin >> sol_str>>str1>>str2;
	memset(dp1, -1, sizeof dp1);
	memset(dp2, -1, sizeof dp2);

	int sum = 0;
	for (int i = 0; i < str1.size(); i++)
	{
		if (str1[i] == sol_str[0])
			sum+=dfs(true,i,0);
	}
	for (int i = 0; i < str2.size(); i++)
	{
		if (str2[i] == sol_str[0])
			sum += dfs(false,i,0);
	}
	cout << sum;
	return 0;
}

