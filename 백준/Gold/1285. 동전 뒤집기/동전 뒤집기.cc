#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> str(n);
	vector<vector<bool>> vec(n,vector<bool>(n,false));
	
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (str[i][j] == 'T')
				vec[i][j] = true;
		}
	}
	int answer = -1;
	for (int bit = 0; bit <= (1 << n) - 1; bit++)
	{
		int sum = 0;
		for (int x = 0; x < n; x++)
		{
			int tall = 0;
			for (int y = 0; y < n; y++)
			{
				bool my = vec[y][x];
				if ((bit & (1 << y)) != 0)
					my = !my;
				if (my == true)
					tall++;
			}

			int res = min(tall, n - tall);
			sum += res;

		}
		if (answer == -1) answer = sum;
		else answer = min(answer, sum);
	}

	cout << answer;
	
}