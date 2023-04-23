#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<memory.h>
#include<string>
#include<set>
using namespace std;



struct pos
{
	int y=0, x=0;
	int level = 2;
	int time = 0;
	int exp = 0;

};

class comp {

	//연산자 오버로딩부분
public:	bool operator() (const pos a, const pos b) {
	if (a.time != b.time) return a.time > b.time;
	if (a.y != b.y) return a.y > b.y;
	return a.x > b.x;

}
};
int dy[] = { -1,0,0,1 };
int dx[] = { 0,-1,1,0 };
int main()
{
	int n;
	cin >> n;
	vector<vector<int>> vec(n, vector<int>(n));
	pos init;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &vec[i][j]);
			if (vec[i][j] == 9)
			{
				init = { i,j };
				vec[i][j] = 0;
			}
		}
	}
	
	priority_queue<pos,vector<pos>,comp> q;
	q.push(init);
	int answer = 0;
	while (true)
	{
		bool finish = true;
		vector<vector<int>> visit(n, vector<int>(n,0));
		visit[q.top().y][q.top().x] = 1;

		while (q.size())
		{
			pos now = q.top();
			q.pop();
			int y = now.y;
			int x = now.x;
			if (vec[y][x]!=0 && vec[y][x] < now.level)
			{
				//std::cout<<"냠냠  "<< vec[y][x]<<"  " << y << " " << x << endl;
				vec[y][x] = 0;
				now.exp++;
				if (now.exp == now.level)
				{
					now.exp = 0;
					now.level++;
				//	std::cout << "렙업 " << now.level << endl;
				}
				while (q.size()) q.pop();
				q.push(now);
				answer = now.time;
				finish = false;
				break;
			}

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || nx<0 || ny >= n || nx >= n || vec[ny][nx]> now.level || visit[ny][nx] == 1) continue;
				visit[ny][nx] = 1;
				//pos temp = { ny,nx,now.level,now.time + 1,now.exp };
				q.push({ ny,nx,now.level,now.time + 1,now.exp });
			}
		}

		if (finish) break;
	}
	std::cout << answer;

	return 0;
}