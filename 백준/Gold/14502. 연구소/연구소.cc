#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


struct pos
{
	int y;
	int x;

	bool operator==(const pos& their)
	{
		return (their.x == x && their.y == y);
	}
};
int main() 
{

	int y,x;
	cin >> y>>x;
	vector<vector<int>> vec(y,vector<int>(x,0));
	vector<pos> mypos;
	vector<pos> virus;
	int maxnum = 0;
	int num = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			scanf("%d",&vec[i][j]);
			if(vec[i][j]==0) //빈곳들 전부 저장 (여기다가 벽세워야함)
				mypos.push_back({ i,j });
			if (vec[i][j] == 2) //바이러스 초기위치저장
				virus.push_back({ i,j });

	
		}
	}
	int origin_zero = mypos.size()-3;
	long long virus_number = 2;
	queue<pos> q;
	for (auto a : mypos)
	{
		
		vec[a.y][a.x] = 1;
		for (auto b : mypos)
		{
			if (b == a) continue;
			vec[b.y][b.x] = 1;
			for (auto c : mypos)
			{
				if (c == a || c == b) //벽 세우는 좌표 겹치면 pass
					continue;
				vec[c.y][c.x] = 1;


				num = origin_zero;
				
				pos now;
				for (auto v : virus)
				{
					q.push(v);
					vec[v.y][v.x] = virus_number; //바이러스 원본위치에 바이러스 넘버로 초기화
				}
				
				//바이러스 퍼뜨리기 
				//벽이아니고 현재 바이러스넘버가 아니면 전염
				while (q.size())
				{
					now = q.front();
					q.pop();

					if (now.x + 1 < x && vec[now.y][now.x + 1] != 1 && vec[now.y][now.x + 1] != virus_number)
					{
						q.push({ now.y,now.x+1 });
						vec[now.y][now.x + 1] = virus_number;
						num--;
					}
					if (now.x - 1 >= 0 && vec[now.y][now.x - 1] != 1 && vec[now.y][now.x - 1] != virus_number)
					{
						q.push({ now.y,now.x- 1 });
						vec[now.y][now.x - 1] = virus_number;
						num--;
					}
					if (now.y + 1 < y && vec[now.y + 1][now.x] != 1 && vec[now.y + 1][now.x] != virus_number)
					{
						q.push({ now.y+1,now.x  });
						vec[now.y+1][now.x] = virus_number;
						num--;
					}
					if (now.y - 1 >=0 && vec[now.y - 1][now.x] != 1 && vec[now.y - 1][now.x] != virus_number)
					{
						q.push({ now.y-1,now.x});
						vec[now.y - 1][now.x] = virus_number;
						num--;
					}
				}
			
				
				if (num > maxnum)
					maxnum = num;

				virus_number++; //바이러스 넘버는 2와3을 왓다리갓다리

				vec[c.y][c.x] = 0; //벽 세워둔곳 원래대로되돌려놓기
			}
			vec[b.y][b.x] = 0;
		}
		vec[a.y][a.x] = 0;
	}
	cout << maxnum;
	return 0;
}