#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<set>
using namespace std;

#define inf 200
int main()
{
	
	int hole, n;
	cin >> hole >> n;
	vector<int> vec(n);
	vector<queue<int>>remain(n+1);
	set<pair<int,int>> myset;
	vector<bool> in_use(n + 1,0);

	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &vec[i]);
		remain[vec[i]].push(i);
	}
	
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		remain[vec[i]].pop();
		
		


		if (in_use[vec[i]])
		{
			myset.erase(myset.begin()); //이거빼고새로업데이트해야됨
			
			
			if (remain[vec[i]].size() == 0)
				myset.insert({ inf,vec[i] });
			else
				myset.insert({ remain[vec[i]].front() ,vec[i] });

			continue;

		}
		else //플러그에 없는게 들어온다
		{
			in_use[vec[i]] = true;

			

			if (myset.size() == hole) //플러그자리없으면
			{
				in_use[myset.rbegin()->second] = false;//제일 나중에오는애를 뺌
				myset.erase(--myset.end());
				answer++;
			}
			
			
			if (remain[vec[i]].size() == 0)
				myset.insert({ inf,vec[i] });
			else
				myset.insert({ remain[vec[i]].front() ,vec[i] });
			
			
			
		}
	}
	cout << answer;

	return 0;
}