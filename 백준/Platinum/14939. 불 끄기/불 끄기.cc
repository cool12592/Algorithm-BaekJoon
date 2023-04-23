#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<set>
#include<string>
using namespace std;
int answer = 987654321;
int cnt = 0;
vector<vector<int>> vec(10, vector<int>(10, 0));
vector<vector<int>> initvec (10, vector<int>(10,0));
int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };

void toggle(int y, int x)
{
	vec[y][x] = (vec[y][x] + 1) % 2;
	cnt++;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= 10 || nx >= 10) continue;
		vec[ny][nx] = (vec[ny][nx] + 1) % 2;
	}
}

void checkToggle(int y, int x)
{
	if (y == 0) return;

	if (vec[y - 1][x] == 1) //위에가 켜져있으면 내꺼 토글해서 위에꺼 꺼줌
		toggle(y, x);
}

int main()
{
	
	for (int i = 0; i < 10; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < 10; j++)
		{
			if (str[j] == 'O')
				initvec[i][j] = 1;
			else
				initvec[i][j] = 0;
		}
	}
	
	for (int step = 0; step < (1 << 10); step++)
	{
		vec = initvec;
		cnt = 0;
		for (int bit = 0; bit < 10; bit++)
		{
			if (step & (1<<bit)) //이자리는 눌러라
			{
				toggle(0, bit);
			}
		}

		for (int i = 1; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				checkToggle(i, j);
			}
		}

		bool successed = true;
		for (int i = 0; i < 10; i++) //이 로직상, 다 꺼졌는지확인은 마지막줄만하면됨
		{
			if (vec[9][i] == 1)
			{
				successed = false;
				break;
			}
		}
		if (successed)
			answer = min(answer, cnt);
	}
	if (answer == 987654321)
		answer = -1;
	cout << answer;
	return 0;
}