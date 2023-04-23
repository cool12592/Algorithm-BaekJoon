#include <string>
#include <vector>
#include<iostream>
#include <queue>
#include<algorithm>

using namespace std;
//3시 50분

int main()
{
	
	int n, l;
	cin >> n >> l;
	vector<vector<int>>vec(n, vector<int>(n, 0));
	vector<vector<int>>rope(n, vector<int>(n, 0));
	int answer = n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &vec[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-1; j++)
		{
			if (vec[i][j] == vec[i][j + 1]) //같은경사로면 ok
			{
				continue;
			}
			else if (vec[i][j] - vec[i][j + 1] ==-1) //내쪽이 낮은상황
			{
				int num = 0;
				int k = j;
				//bool ok = true;
				while (k >= 0 && num < l )
				{
					if (vec[i][k] == vec[i][j] && rope[i][k]==0)
					{

						num++;
						k--;
					}
					else
						break;
				}

				 k++;
				if (num == l)
				{
					for (int ind = k; ind <= j; ind++)
					{
						rope[i][ind] = 1;

					}
				}
				else
				{
					answer--;
					break;
				}

			}
			else if (vec[i][j] - vec[i][j + 1] == 1) //다음 쪽이 낮은상황
			{
				int num = 0;
				int k = j+1;
				//bool ok = true;
				while (k < n && num < l)
				{
					if (vec[i][k] == vec[i][j+1] && rope[i][k] == 0)
					{

						num++;
						k++;
					}
					else
						break;
				}
				 k--;
				if (num == l)
				{
					for (int ind = j+1; ind <= k; ind++)
					{
						rope[i][ind] = 1;

					}
					j = k-1;
				}
				else
				{
					answer--;
					break;
				}
			}
			else
			{
				answer--;
				break;
			}




		}
	}

	vector<vector<int>>rope2(n, vector<int>(n, 0));
	int answer2 = n;

	//세로때 로프초기화해야함
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (vec[i][j] == vec[i+1][j]) //같은경사로면 ok
			{
				continue;
			}
			else if (vec[i][j] - vec[i+1][j] == -1) //내쪽이 낮은상황
			{
				int num = 0;
				int k = i;
				//bool ok = true;
				while (k >= 0 && num < l)
				{
					if (vec[k][j] == vec[i][j] && rope2[k][j] == 0)
					{

						num++;
						k--;
					}
					else
						break;
				}

				k++;
				if (num == l)
				{
					for (int ind = k; ind <= i; ind++)
					{
						rope2[ind][j] = 1;

					}
				}
				else
				{
					answer2--;
					break;
				}

			}
			else if (vec[i][j] - vec[i+1][j] == 1) //다음 쪽이 낮은상황
			{
				int num = 0;
				int k = i+1;
				//bool ok = true;
				while (k < n && num < l)
				{
					if (vec[k][j] == vec[i+1][j] && rope2[k][j] == 0)
					{

						num++;
						k++;
					}
					else
						break;
				}
				 k--;
				if (num == l)
				{
					for (int ind = i+1; ind <= k; ind++)
					{
						rope2[ind][j] = 1;

					}
					i = k-1;
				}
				else
				{
					answer2--;
					break;
				}
			}
			else
			{
				answer2--;
				break;
			}




		}
	}
	cout << answer+answer2;

	return 0;
}