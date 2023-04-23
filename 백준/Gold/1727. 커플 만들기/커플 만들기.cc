#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> vec;
	int n, m;
	cin >> n >> m;
	vector<int> boy(n);
	vector<int> girl(m);
	for (int i = 0; i < n; i++)
		scanf("%d", &boy[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &girl[i]);
	sort(boy.begin(), boy.end());
	sort(girl.begin(), girl.end());
	vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
	//dp[0][0] [0]들어간건 다 빈자리 (안찍는다는의미)\
	//이것때문에 dp는 하나 더 많음
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)  //이게 가정을해보는거임 작은것들 부터 이것만 있을때의 상황을
		{
			dp[i][j] = dp[i-1][j-1] + abs(boy[i-1] - girl[j-1]); //i랑 j같으면 무조건커플 (i=2 j=2는 둘둘씩있는 상황가정임)
			if (i < j)
				dp[i][j] = min(dp[i][j], dp[i][j - 1]); //j가 더많으면 i는 이번 j안찍고 이전 j꺼찍을수있음
			if (j < i)
				dp[i][j] = min(dp[i][j], dp[i-1][j]); //i가 여유있는 상황은 i가 이번 j안찍고 이전i가 j찍은게 더 좋으면 그걸로감
		}
	}

	cout << dp[n][m];
	return 0;

}