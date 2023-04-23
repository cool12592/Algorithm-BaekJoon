#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


//이문제가 시리즈인데 이전시리즈에서는 n=20이라 dp문제였음
//(사실 이게 더 영양가있겠다)
//근데이건 n이커서 규칙을 직접찾아야되는 에드혹문제가됨
//n=1 n=2 n=3 n=4 까지 적어서 직적해보면 규칙이있음
//규칙이어려움 n=1 ~ n=4까지 적어봐야되서 노가다성도 있고
//고로 갠적으로 별로였던 문제

int main() 
{
	int n;
	cin >> n;

	//1 + 2 + 3 + 4....+n  => n(n+1)/2
	//1step + 2step + 3step
	int ans = n * (n + 1) / 2 + n + n * (n + 1) / 2;
	cout << ans << endl;
	//1step
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (i % 2)
				printf("1 %d\n", j);
			else
				printf("2 %d\n", j);
		}
	}

	//2step
	for (int i = 1; i <= n; i++)
	{
		if (n % 2)
			printf("2 %d\n", i);
		else
			printf("1 %d\n", i);
	}

	//3step
	bool whiteFirst = true;
	if (n % 2 == 0)
		whiteFirst = false;

	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (whiteFirst)
				printf("1 %d\n", j);
			else
				printf("2 %d\n", j);
		}
		whiteFirst = !whiteFirst;
	}
}