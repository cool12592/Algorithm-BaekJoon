#include<iostream>
#include<memory.h>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;


int main()
{
	int n;
	cin >> n;
	int dp[31] = { 0, };
	dp[0] = 1;
	dp[2] = 3;
	for (int i = 4; i <= n; i+=2)
	{
		//        왼쪽    * 새로생긴오른쪽2칸
		dp[i] = dp[i - 2] * dp[2];
		for (int j = 4; j <= i; j += 2)
		{
			       //특수모양칸뺀나머지왼쪽 *특수모양수 (4의특수모양, 6의특수모양 ,8의특수모양) (근데 뜻은이렇지만 특수모양수는 모두 2임 그래서 걍2)
			dp[i] += dp[i - j] * 2;
		}
	}
	cout << dp[n];
}

