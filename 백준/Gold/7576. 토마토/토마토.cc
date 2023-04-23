#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main()
{
	
	int m, n;
	cin >> n >> m;
	int inf = m * n+1;
	int input;
	vector<vector<int>> vec(m,vector<int>(n));
	queue<vector<int>> q;
	int day = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &input);
			if (input == 0)
				vec[i][j] = inf;
			else if (input == 1)
			{
				vec[i][j] = input;
				q.push({ i,j,input}); //x좌표 y좌표 날짜
			}
			else
				vec[i][j] = input; //-1
				
		}
	}
	int now_day, now_i, now_j;
	while (q.size() > 0)
	{
		now_day = q.front()[2];
		now_i = q.front()[0];
		now_j = q.front()[1];
		if (day < now_day - 1)
			day = now_day - 1; //vec에다가 날짜 박아둘거임 1은 0일때 만들어지니까 1빼줌
		q.pop();

		//갈수 있는범위 & 내날짜+1 이 거기날짜보다 짧을 때 push 단, -1은 젤작으니까 저절로걸러짐
		if (now_i + 1 < m && now_day + 1 < vec[now_i + 1][now_j])
		{
			q.push({ now_i + 1,now_j,now_day + 1 });
			vec[now_i + 1][now_j] = now_day + 1;
		}
		if (now_i - 1 >= 0 && now_day + 1 < vec[now_i - 1][now_j])
		{
			q.push({ now_i - 1,now_j,now_day + 1 });
			vec[now_i - 1][now_j] = now_day + 1;
		}
		if (now_j + 1 < n && now_day + 1 < vec[now_i][now_j + 1])
		{
			q.push({ now_i,now_j + 1,now_day + 1 });
			vec[now_i][now_j+1] = now_day + 1;
		}
		if (now_j - 1 >= 0 && now_day + 1 < vec[now_i][now_j - 1])
		{
			q.push({ now_i,now_j - 1,now_day + 1 });
			vec[now_i][now_j - 1] = now_day + 1;
		}
	}
	


	//다 못바꾼경우
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (vec[i][j] == inf)
			{
				cout << -1;
				return 0;
			}
		}
	}

	cout << day;
	return 0;

}