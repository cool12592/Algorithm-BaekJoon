#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

//엄청 오래 헷갈린부분 구간 = 지금 최대고를수 있는 날짜중 제일 dest긴꽃 고르는곳
//근데 처음구간이 1.1 ~ 3.1 임 즉 3.1 도 고를 수 있음 갱신이 필요한건 3.1보다 클때임 3.1포함이 아니고
//마찬가지로 내 지금 꽃중 제일긴게 5.5까지피고 5.6에 져물어 그럼 고를수있는 구간 최대날짜는?
//5.5가 아니고 5.6임;; 이게 엄청헷갈렸음 5.6을 고를수있는 이유 
//이전꽃이 5.5에지니까 5.6때피는꽃고르면 5.5도 꽃있고 5.6도 꽃있잖아 즉 갱신필요한때는 5.6< (클때)

vector<int> month = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return !(a.second <= b.second);
	else
		return !(a.first > b.first);
}
int changeDay(int m, int d)
{
	if (m >= month.size())
	{
		while (true)
			cout << 1;
	}
	for (int i = 0; i <= m - 1; i++)
		d += month[i];

	return d;
}

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> vec(n);

	for (int i = 0; i < n; i++)
	{
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		vec[i] = { changeDay(a,b),changeDay(c,d) };
	}
	//기준점이 12월1일되면끝 12월1일이 기준점이란것은 11월30일까지피어있단것
	sort(vec.begin(), vec.end(), cmp);
	int s = changeDay(3, 1);
	int e = changeDay(11, 30);
	int standard = s;
	int tempDest = standard;
	int num = 0;
	for (int i = 0; i < n; i++)
	{

		int a = vec[i].first;
		int b = vec[i].second;
		if (standard < a) //갱신필요
		{
			if (tempDest < a)
			{
				cout << 0;
				return 0;
			}
			else
			{
				//tempDest = max(tempDest, b);
				standard = tempDest;
				num++;
			}
		}

		tempDest = max(tempDest, b);
		if (e < tempDest)
		{
			cout << num + 1;
			return 0;
		}



	}
	cout << 0;
	return 0;
}