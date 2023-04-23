#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>



using namespace std;


pair<int,int> dp[16][16][16][16];
vector<vector<int>> vec;
int n;
struct pos {
	int y1, x1; //더뒤에
	int y2, x2; //더 앞에 (머리)
	int mode;
};
vector<pos> move(pos now)
{
	vector<pos> next;

	if (now.mode == 0) //가로
	{
		if (now.x2 + 1 < n && vec[now.y1][now.x2 + 1] == 0)
			next.push_back({ now.y1,now.x2,now.y1,now.x2 + 1,0 });
		if(now.x2+1<n && now.y2+1 <n && vec[now.y2][now.x2+1]==0 && vec[now.y2+1][now.x2]==0  && vec[now.y2+1][now.x2+1]==0)
			next.push_back({ now.y2,now.x2,now.y2+1,now.x2 + 1,2 });
	}
	else if (now.mode == 1) //세로
	{
		if (now.y2 + 1 < n && vec[now.y2+1][now.x2] == 0)
			next.push_back({ now.y2,now.x2,now.y2+1,now.x2 ,1 });
		if (now.x2 + 1 < n && now.y2 + 1 < n && vec[now.y2][now.x2 + 1] == 0 && vec[now.y2 + 1][now.x2] == 0 && vec[now.y2 + 1][now.x2 + 1] == 0)
			next.push_back({ now.y2,now.x2,now.y2 + 1,now.x2 + 1,2 });
	}
	else if(now.mode==2)//대각
	{
		if (now.x2 + 1 < n && vec[now.y2][now.x2 + 1] == 0)
			next.push_back({ now.y2,now.x2,now.y2,now.x2 + 1,0 });
		if (now.y2 + 1 < n && vec[now.y2 + 1][now.x2] == 0)
			next.push_back({ now.y2,now.x2,now.y2 + 1,now.x2 ,1 });
		if (now.x2 + 1 < n && now.y2 + 1 < n && vec[now.y2][now.x2 + 1] == 0 && vec[now.y2 + 1][now.x2] == 0 && vec[now.y2 + 1][now.x2 + 1] == 0)
			next.push_back({ now.y2,now.x2,now.y2 + 1,now.x2 + 1,2 });
	}

	return next;
}

int dfs(pos now) //끝에 닿는 경우의 수 리턴
{
	if (dp[now.y1][now.x1][now.y2][now.x2].first != 0) //이미안다면
	{

		//cout << "가본길" << endl;
		//cout << now.y2 << " " << now.x2 << " " << now.mode << endl;
		//cout << dp[now.y1][now.x1][now.y2][now.x2].second << endl;
		//cout << endl;
		return dp[now.y1][now.x1][now.y2][now.x2].second;

	}

	if (now.y2 == n - 1 && now.x2 == n - 1) //끝에 다으면
		return 1;


	//cout << now.y2 << " " << now.x2 << " " << now.mode << endl;
	
	vector<pos> next = move(now);
	if (next.size() == 0) //다음이동불가
	{
		dp[now.y1][now.x1][now.y2][now.x2] = {1,0};
		return 0;
	}
	int num = 0;
	for (int i = 0; i < next.size(); i++)
	{
		num += dfs(next[i]);
		
	}



	dp[now.y1][now.x1][now.y2][now.x2] = { 1,num };
	return dp[now.y1][now.x1][now.y2][now.x2].second;

}
int main()
{
	cin >> n;
	vec.resize(n, vector<int>(n, 0));
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &vec[i][j]);
		}
	}


	

	pos first = { 0,0,0,1,0 };
	cout << dfs(first);

	return 0;
}