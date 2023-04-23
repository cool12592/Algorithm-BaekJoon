#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<set>
#include<string>
using namespace std;
//신기한 문제... 애초에 -1인경우는 없었고 이 무적논리면 모든경우 다 흰색만들기 가능했음...
//2번과 3번 연산은 매우 유사한데 본인자리를 뒤집냐 안뒤집냐 차이만있음 즉 인근에 변화없이 자기자리만 차이있음
//그래서 모든 자리 다 2연산을 했다치고 주변뒤집은다음에 나중에 남은 검은색 자리는 모두 "나사실2가아니라3임ㅋㅋ" 해주면됨;;;
//마법같은 논리네

int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };
int n, m;
void toggle(vector<vector<int>>& vec , int y, int x)
{

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		vec[ny][nx] = (vec[ny][nx]+1)%2;
	}
}



int main()
{

	cin >> n >> m;
	vector<vector<int>> vec(n,vector<int>(m));
	vector<vector<int>> ans(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			if (str[j] == 'W')
			{
				vec[i][j] = 0;
			}
			else
				vec[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			toggle(vec, i, j);
			ans[i][j] = 2;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (vec[i][j] == 1)
				ans[i][j] = 3;//나사실3였어 수법
		}
	}
	cout << 1 << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << ans[i][j];
		}
		cout << endl;
	}
	return 0;
}