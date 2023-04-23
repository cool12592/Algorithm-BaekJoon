#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

typedef long long ll;
struct info
{
	ll section;
	ll pos;
};

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, len;
	cin >> n >> len;
	ll sum_arrive_time = 0;
	vector<int>dest(3);
	vector<info>vec;
	unordered_map<ll, int>visit;
	for (int i = 0; i < n; i++)
	{
		char c;
		ll input_section,pos_, dir_;
		cin >> c>>pos_>>dir_;
		
		if (c == 'A')
			input_section = 0;
		else if(c=='B')
			input_section = 1;
		else if(c=='C')
			input_section = 2;

		ll time = 0;
		if (dir_ == 1)
		{
			dest[input_section]++;
			time = len - pos_;
		}
		else
		{
			visit[pos_]++;
			time = pos_ + len;
			vec.push_back({ input_section,pos_ });
		}
		sum_arrive_time += time;
	}

	for (int i = 0; i < vec.size(); i++)
	{
		if (visit[vec[i].pos] > 1) //원점에서 상대랑부딪혀서 그대로 내섹션으로돌아옴
		{
			dest[vec[i].section]++;
		}
		else //원점에서 안 부딪혀서 내오른쪽섹션으로감
		{
			vec[i].section = (vec[i].section + 1) % 3;
			dest[vec[i].section]++;
		}

	}
	cout << sum_arrive_time << endl;
	cout << dest[0] << " " << dest[1] << " " << dest[2] << endl;
}