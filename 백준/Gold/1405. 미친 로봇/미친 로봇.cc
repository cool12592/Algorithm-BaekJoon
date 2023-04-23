#include<iostream>
#include<vector>

using namespace std;

int N;
double dong, seo, nam, book;
vector<vector<bool>>visit(900, vector<bool>(900, 0));
//visit중복방문인경우 그만(0리턴) 끝까지 중복안된경우 자기가 모아둔 확률리턴 
double trip(int n, pair<int, int>pos, double percentage)
{

	
	if (visit[pos.first][pos.second] == true) //이미방문한곳이면 땡
		return 0;
	

	if (n == N)
		return percentage;
	visit[pos.first][pos.second] = true; //방문체크

	double ret = trip(n + 1, { pos.first+1,pos.second }, percentage * (dong/ 100));
	ret += trip(n + 1, { pos.first-1,pos.second }, percentage * ( seo/100));
	ret += trip(n + 1, { pos.first,pos.second-1 }, percentage * (nam/100));
	ret += trip(n + 1, { pos.first,pos.second+1 }, percentage * (book/100));
	visit[pos.first][pos.second] = false;
	return ret;


	
}
int main() {

	
	cin >>	N >> dong >> seo >> nam >> book;

	double answer;
	
	answer = trip(0, { 14,14 },1); //n 갈방향 확률 visit
	cout.precision(10);
	cout << fixed << answer << endl;
	
	return 0;
}