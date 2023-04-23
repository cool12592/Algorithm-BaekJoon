#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int a;
	vector<int> vec1;
	vector<int> vec2;
	bool zero_have = false;
	int one_count=0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if (a > 1)
			vec1.emplace_back(a);
		else if (a < 0)
			vec2.emplace_back(a);
		else if (a == 1)
			one_count++;
		else
			zero_have = true;
	}

	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());
	int i = vec1.size() - 1;
	int answer = 0;
	while (i >= 1)
	{
		answer += vec1[i] * vec1[i - 1];
		i = i - 2;
	}

	if (vec1.size() % 2 != 0) //홀수면남는거처리해야됨
	{

		answer += vec1[0];

	}
	//내가 캐치못한 예외상황 1은 유일하게 자연수중 곱하는것보다 더하는게 이득인애
	//얘는 다른애들이랑 엮일필요없고 자기들끼리만 더하면됨
	answer += one_count;

	if (vec2.size() % 2 != 0) //홀수면 남는거하나 처리해야됨
	{
		if (!zero_have) //0없으면 더해야됨(있으면 음수하나있는거 없앨수있음)
		{
			answer += vec2[vec2.size() - 1];
		}
	}
	i = 0; //음수는작은값부터 곱함
	if (vec2.size() >= 2)
	{
		while (i <= vec2.size() - 2)
		{
			answer += vec2[i] * vec2[i + 1];
			i = i + 2;
		}
	}
	cout << answer;
	return 0;
}