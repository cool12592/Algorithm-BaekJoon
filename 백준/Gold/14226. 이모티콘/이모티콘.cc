#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>



using namespace std;

struct info {
	int num;
	int clip;
	int command;
};


int main()
{
	int answer = 0;
	int target;
	cin >> target;

	queue<info> q;
	info first = { 1,0,0 };
	q.push(first); //숫자 클립보드

	//num과 clip으로 커맨드 체크
	vector<vector<int>> visit(2001,vector<int>(2001, -1));
	visit[1][0] = 0;
	while (q.size() > 0)
	{
		info now = q.front();
		q.pop();

		if (now.num == target)
		{
			cout << now.command;
			break;
			
		}

		info clip_ = now;
		info num_= now;
		info minus_ = now;
		if (clip_.clip != now.num )
		{
			clip_.clip = now.num;
			clip_.command++;

			if (visit[clip_.num][clip_.clip] == -1)
			{
				q.push(clip_);
				visit[clip_.num][clip_.clip] = clip_.command;
			}
			else if (clip_.command < visit[clip_.num][clip_.clip])
			{
				q.push(clip_);
				visit[clip_.num][clip_.clip] = clip_.command;
			}
		}
		//visit필수 거기다 커맨드입력 내커맨드가더 작으면 ㅍ푸시

	
		if (minus_.num >= 1)
		{
			minus_.num -= 1;
			minus_.command++;
			

			if (visit[minus_.num][minus_.clip] == -1)
			{
				q.push(minus_);
				visit[minus_.num][minus_.clip] = minus_.command;
			}
			else if (minus_.command < visit[minus_.num][minus_.clip])
			{
				q.push(minus_);
				visit[minus_.num][minus_.clip] = minus_.command;
			}
		}
		
		num_.num += num_.clip;
		num_.command++;
		if (num_.num <= 2000)
		{
			if (visit[num_.num][num_.clip] == -1)
			{
				q.push(num_);
				visit[num_.num][num_.clip] = num_.command;
			}
			else if (num_.command < visit[num_.num][num_.clip])
			{
				q.push(num_);
				visit[num_.num][num_.clip] = num_.command;
			}
		}

	}
	//cout << answer;
	
	return 0;
}