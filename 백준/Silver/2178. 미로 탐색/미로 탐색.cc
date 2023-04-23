#include<iostream>
//12시
#include<vector>
#include<string>
#include<queue>
using namespace std;


int main()
{
	int row, col;
	cin >> row >> col;
	string a;
	vector<string> vec(row);

	for (int i = 0; i < row; i++)
	{
		cin >> a;
		vec[i] = a;
	}
	queue<pair<int,pair<int,int>>> q;
	q.push(make_pair(1,make_pair(0, 0)));

	vector<vector<int>> visit(row, vector<int>(col, 0));

	int count, m, n;
	while (q.size() > 0)
	{
		count = q.front().first;
		 m = q.front().second.first;
		 n = q.front().second.second;
		q.pop();

		if (m == row - 1 && n == col - 1)
		{
			cout << count;
			return 0;
		}


		if (m + 1 < row && vec[m + 1][n] == '1' && visit[m + 1][n] == 0) //경계선안 & 갈수있는곳 & 안가본곳
		{
			q.push(make_pair(count+1,make_pair(m+1, n)));
			visit[m+1][n] = 1;
		}
		if (n + 1 < col && vec[m][n + 1] == '1' && visit[m][n + 1] == 0)
		{
			q.push(make_pair(count+1,make_pair(m, n + 1)));
			visit[m][n+1] = 1;
		}
		if (m - 1 >= 0 && vec[m - 1][n] == '1' && visit[m - 1][n] == 0)
		{
			q.push(make_pair(count+1,make_pair(m-1, n )));
			visit[m-1][n] = 1;
		}
		if (n - 1 >= 0 && vec[m][n - 1] == '1' && visit[m][n - 1] == 0)
		{
			q.push(make_pair(count+1,make_pair(m, n - 1)));
			visit[m][n - 1] =  1;
		}

	
	}

	
	


	return 0;
}