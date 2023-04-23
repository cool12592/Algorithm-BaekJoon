#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


//학생들에게서 자신보다 뒤에 서있으면서 더 작은 번호의 카드를 가진 
//학생들의 명단을 하나도 <빠짐없이> 모두 받았다.

//즉!!!! 명단에 없는 case는 무조건 뒤에사람이 더 큰번호를 가진거야!!!!

int main() 
{
	int n,m;
	cin >> n>>m;

	vector<int>vec(n+1);
	vector<int>visit(n+1, 0);
	for (int i = 1; i <= n; i++)
		vec[i] = i;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		vec[a]++;
		vec[b]--;
	}

	for (int i = 1; i <= n; i++)
	{
		int now = vec[i];
		if (visit[now] == 0)
			visit[now] = 1;
		else
		{
			cout << -1;
			return 0;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", vec[i]);
	}
}