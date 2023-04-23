#include <string>
#include <vector>
#include<iostream>
#include <queue>
//12시
using namespace std;

int main()
{
	int num;
	cin >> num;

	for (int entire = 0; entire < num; entire++)
	{
		string s;
		cin >> s;
		int n;
		scanf("%d", &n);
		vector<int> vec(n, 0);
		char nope;
		scanf(" %c", &nope);
		for (int i = 0; i < (n * 2)-1; i++)
		{
			if(i%2==0)
				scanf("%d", &vec[i/2]);
			else
				scanf(" %c", &nope);
		}
		scanf(" %c", &nope);


		bool berror = false;
		bool isLeft = true;
		int left = 0;
		int right = n - 1;

		for (int i = 0; i < s.size(); i++)
		{
			//뒤집기
			if (s[i] == 'R')
			{
				isLeft = !isLeft;
			}
			//버리기
			else if (s[i] == 'D')
			{
				if (isLeft)
				{
					if (left > right)  //지울게없는상황이면 에러
					{
						berror = true;
						printf("error\n");
						break;
					}

					left++;
					
				}
				else
				{
					if (left > right) //지울게없는상황이면 에러
					{
						berror = true;
						printf("error\n");
						break;
					}

					right--;
					
				}
			}
		}
		//에러가 안났다면
		if (berror == false)
		{
			if (left > right) //안남은상황
			{
				printf("[]\n");

			}
			else
			{
				printf("[");
				if (isLeft)
				{
					for (int i = left; i < right; i++)
					{
						printf("%d,", vec[i]);
					}
					printf("%d", vec[right]);
				}
				else
				{
					for (int i = right; i > left; i--)
					{
						printf("%d,", vec[i]);
					}
					printf("%d", vec[left]);
				}

				printf("]\n");
			}
		}
	}

	return 0;
}