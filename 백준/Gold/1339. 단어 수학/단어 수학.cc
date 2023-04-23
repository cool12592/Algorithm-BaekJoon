#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;



int main() {

	int n;
	cin >> n;

	map<char, int> g_map;
	string input;
	vector<string> origin;

	//문자열 입력받아 해당 하는 자리수를 1로 변환
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		origin.push_back(input);
		for (int j = 0; j < input.size(); j++)
		{
			/*if (g_map.count(input[input.size() - 1 - j]) == 0)
			{
				g_map[input[input.size() - 1 - j]] = "00000000";

			}*/
			g_map[input[j]] += pow (10 , input.size() - 1 - j);

		}
	}

	//벡터로 이동 후 정렬
	vector<pair<int, char>> vec;
	for (auto it = g_map.begin(); it != g_map.end(); it++)
	{
		vec.push_back({ (it->second),it->first });
	}
	sort(vec.begin(), vec.end());

	//map으로문자에 맞는 숫자저장 
	map<char, int> map1;
	int now_num = 9;

	for (int i = vec.size() - 1; i >= 0; i--)
	{
		map1[vec[i].second] = now_num;
		now_num--;
	}

	//결과 값 계산
	long long sum = 0;
	for (int i = 0; i < origin.size(); i++)
	{
		for (int j = 0; j < origin[i].size(); j++)
		{
			sum += map1[origin[i][j]] * pow(10, -j + origin[i].size() - 1);
		}
	}
	cout << sum;
	return 0;
}