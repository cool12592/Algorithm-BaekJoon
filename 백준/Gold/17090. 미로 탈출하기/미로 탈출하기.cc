#include<iostream>
#include<memory.h>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

int n, m;
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
vector<string> vec;
int dp[500][500];
int visit[500][500];

bool dfs(int y,int x,int number_)
{
    
    if (y < 0 || x < 0 || y >= n || x >= m)
		return true;//경계선밖을나감

    
    if (dp[y][x] != -1)
	{
		if (dp[y][x] == 1)
			return true;
		if (dp[y][x] == 0)
			return false;
	}

    
	if (visit[y][x] == number_) //싸이클 //visit을 매번초기화하면 25만번을 25만번초기화해야되서 시간초과 
		return false; //즉이렇게 visit에들어간수가 이번턴에숫자인지(number)확인하므로 visit을 턴마다 초기화 안해줘도됨
	

	
	visit[y][x] = number_;


	bool res = false;

	if (vec[y][x] == 'U')
	{
		res=dfs(y - 1, x, number_);
	}
	else if (vec[y][x] == 'D')
	{
		res = dfs(y+1, x, number_);
	}
	else if (vec[y][x] == 'R')
	{
		res = dfs(y, x+1, number_);
	}
	else if (vec[y][x] == 'L')
	{
		res = dfs(y, x-1, number_);
	}

	if (res)
	{
		dp[y][x] = 1;
		return true;
	}
	else
	{
		dp[y][x] = 0;
		return false;
	}
	

}
int main()
{
	cin >> n >> m;
	vec.resize(n);
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	int sum = 0;
	memset(visit, 0, sizeof visit);
	int number = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			number++;
			if (dfs(i,j,number))
				sum++;
		}
	}
	cout <<sum;

	return 0;
}

