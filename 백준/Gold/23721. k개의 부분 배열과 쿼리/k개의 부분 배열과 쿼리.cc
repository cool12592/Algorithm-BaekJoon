#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

//참고 https://mangu.tistory.com/96

int main()
{

	
	int n;
	cin >> n;
	vector<int> vec(n);
	vector<int>dp(n);
	dp[0] = 1;

	for (int i = 0; i < n; i++)
	{
		scanf("%d",&vec[i]);
		if (i == 0) continue;
		if (vec[i] < vec[i - 1])
		{
			dp[i] = dp[i - 1] + 1;
		}
		else
		{
			dp[i] = dp[i - 1];
		}

	}

	int q;
	cin >> q;
	vector<int> ans(q);
	for (int i = 0; i < q; i++)
	{
		int a, b;
		scanf("%d %d", &a,&b);
		a--;
		b--;
		int dif = dp[b] - dp[a];

		if (dif == 0)
		{
			ans[i] = 1;
		}
		else if (dif >= 2)
		{
			ans[i] = 3;
		}
		else if(dif ==1) //다운이 한번발생
		{
			if (vec[a] < vec[b]) //어딘가에 끼워넣어야되는상황 12 56 34 다운은 3에서 한번발생했지만 34를 12 와 56사이 끼워야됨 (혹은 1 7 6) 
				ans[i] = 3;
			else // 7 2 3 4 그냥 맨앞에꺼를 맨뒤에 붙이면됨
				ans[i] = 2;
		}
	}


	for (int i = 0; i < q; i++)
	{
		printf("%d\n", ans[i]);
	}

	return 0;
}