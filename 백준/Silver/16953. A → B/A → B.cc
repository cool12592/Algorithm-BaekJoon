#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>

using namespace std;

int main()
{



	long long num, target;
	cin >> num>>target;

	queue<pair<long long,int>> q;
	q.push({num,1});
	int count = 1;
	//vector<long long> visit(target + 1, 0); //백터 공간 10억개 못만듬
	unordered_map<long long,int> myhash; //그래서 해쉬 키값을이용해서 visit체크
	while (q.size())
	{
		num = q.front().first;
		count = q.front().second;
		q.pop();
		
		if (num * 2 <= target )// && visit[num * 2]==0)
		{
			if (num * 2 == target)
			{
				cout << count + 1;
				return 0;
			}
			q.push({ num * 2,count + 1 });
			//visit[num * 2] = 1;

		}
		
		if (num * 10+1 <= target  )//&& visit[num * 10 +1] == 0)
		{
			if (num * 10 + 1 == target)
			{
				cout << count + 1;
				return 0;
			}
			q.push({ num * 10 + 1,count + 1 });
			//visit[num * 10 + 1] = 1;
			
		}
	
	}

	cout << -1 << endl;


	return 0;

}