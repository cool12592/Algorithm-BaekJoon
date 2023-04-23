#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
//55분 1트 (왜케 오래걸렸지??)

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n, len, k;
		cin >> n >> len >> k;
		vector<pair<int, int>> vec(n);
		vector<pair<int, int>> remainTime(n);
		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			vec[i] = { a,b };

			if (b > 0)
			{
				remainTime[i] = { len - a,b };
			}
			else
			{
				remainTime[i] = { a,b };
			}
		}

		sort(remainTime.begin(), remainTime.end());

		//그 시간에 떨어지는개미중 id가 낮은애가먼저나오게 set으로함
		map<int,set<int>> arriveId; //key시간 value그시간에 떨어지는 id들

		int left=0, right = 1;

		for (int i = 0; i < remainTime.size(); i++)
		{
			int time = remainTime[i].first;
			
			if (remainTime[i].second > 0)
			{
				arriveId[time].insert(vec[vec.size() - right].second);
				right++;
			}
			else
			{
				arriveId[time].insert(vec[left].second);
				left++;
			}
		}

		int num = 0;
		for (auto element : arriveId)
		{
			for (auto id : element.second)
			{
				num++;
				if (num == k)
					cout << id << "\n";
			}
		}
	}
	return 0;
}