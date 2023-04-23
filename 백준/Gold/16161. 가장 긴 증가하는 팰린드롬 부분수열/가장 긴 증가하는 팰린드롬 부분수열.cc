#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<set>
#include<string>
using namespace std;

//50분 1트같은 2트 
//0인상황은 없고 최소답은 1이었음
void initStack(stack<int>& st,int& num)
{
	while (st.size())
	{
		st.pop();
	}
	st.push(num);
}

void restart(stack<int>& st, int& num, int& ans,int& cnt)
{
	initStack(st, num);
	ans = max(ans, cnt);
	cnt = 0;
}

int main()
{

	int n;
	cin >> n;
	stack<int> st;
	int num;
	cin >> num;
	int pastnum = num;
	st.push(num);

	//이전값보다 값이 크면 stack에push
	//이전값보다 값이 작으면 stack에서 pop해서비교(처음 한번은 달라도 봐줌 두번은 실패)
	bool isIncreasing = false;
	int ans = 0;
	int cnt = 0;

	for (int i = 1; i < n; i++)
	{
		cin >> num;
		if (pastnum < num)
		{
			if (isIncreasing)
			{
				st.push(num);
			}
			else
			{
				while (st.size())
				{
					st.pop();
				}
				st.push(pastnum);
				st.push(num);
				
				ans = max(ans, cnt);
				cnt = 0;
			}
			isIncreasing = true;
		}
		else
		{
			if (st.size())
			{
				int top = st.top();
				st.pop();
				if (top == num)
				{
					cnt += 2;
					isIncreasing = false;
				}
				else
				{
					if (isIncreasing == true) //처음에 한번은 달라도봐줌
					{
						int top = st.top();
						st.pop();
						if (top == num)
							cnt += 3;
						else
						{
							restart(st, num, ans, cnt);
						}
						isIncreasing = false;
					}
					else
					{
						restart(st, num, ans, cnt);

					}
				}
			}
			else
			{
				restart(st, num, ans, cnt);

			}
		}

		pastnum = num;
	}

	ans = max(ans, cnt);
	if (ans == 0)
		ans = 1;
	cout << ans;
	return 0;
}