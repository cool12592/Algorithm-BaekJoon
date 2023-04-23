#include <vector>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;


int main()
{
	int n;
	scanf("%d", &n);

	vector<int> vec(n, 0); //int가능 이유 최대값 10억+10억 20억임


	for (int i = 0; i < n; i++)
	{
		scanf("%d", &vec[i]);
	}

	sort(vec.begin(), vec.end());
	int left = 0;
	int right = n - 1;
	int min_dif = 2000000001;
	int ans1 = left;
	int ans2 = right;
	while (left < right)//left와 right는 같은값이 성립안됨!! 일케 투포인터마다 그에맞게 조건과 종료조건 설정해야됨
	{
		int dif = (vec[right] + vec[left]);
		if (abs(dif) < min_dif)
		{
			ans1 = vec[left];
			ans2 = vec[right];
			min_dif = abs(dif);
		}

		if (dif == 0)
		{
			break;
		}
		if (dif > 0) //큰수를 줄여야함
			right--;
		else if (dif < 0)//작은수를 올려야함
			left++;
	}

	cout << ans1 << " " << ans2;
	return 0;
}
