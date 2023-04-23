#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;


int main()
{
	int N;
	cin >> N;
	int input;

	int left_continent; //왼쪽대륙
	int right_continent;
	int king = -2000;

	vector<int>dp(N,0);
	vector<int> vec(N);
	int new_;

	bool all_negative = true; //전부 0 or 음수 일땐 젤큰애가 그냥 답 //양수있으면 dp에걸려듬
	int first_Positive_index=-1;

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &input);
		vec[i] = input;

		if (king < input)
			king = input;

		if (all_negative && input > 0)
		{
			first_Positive_index = i;
			all_negative = false;
		}
		
	}

	bool mode = true;
	int Jatturi = 0;//짜투리

	//음수만나면 음수아닐때까지더함(음수연속일수있으니)
	// left대륙-마이너스집단이 음수면 끊어야됨왼쪽대륙 king에 기록해두고 오른쪽대륙으로새출발
	//만약 양수면 이값은 짜투리로남아서 오른쪽 대륙에 보태줌
	int now_minus=0;
	if (all_negative == false)
	{
		left_continent = vec[first_Positive_index];
		king= vec[first_Positive_index];

		
		for (int i = first_Positive_index+1; i < N; i++)
		{
				if (vec[i] >= 0)
				{
					left_continent += vec[i];
					//king = left_continent;
				}
				else //왼쪽대륙두고 오른쪽 탐험해야할때
				{
					for (int j = i; j < N; j++) 
					{
						if (vec[j] < 0)
							now_minus += vec[j];
						else //음수 연속 끊길 때 결산
						{

							if (left_continent + now_minus > 0)
								left_continent = left_continent  + now_minus;
							else
								left_continent = 0;
							
							i = j - 1;//다음 큰포문때 다시 지금 j로 와야됨
							now_minus = 0;
							break;
						}
					}
				}
				king = max(king, left_continent);
			 
		}
	}


	//답

	cout << king;

	
	return 0;
}