#include <iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

//와 진짜 심하게 한끝차이였네..ㄷㄷ
//최근에 그 두번뒤집는문제도 앞에서부터맞추는거까진 생각했는데 안되면 뒤에서부터도맞춰보는거 빠뜨려서
//못풀었던것 보다 더 아쉽네
//이건아예그냥 부등호하나로놓침 나는 a+b ==c+d 여야된다봤는데 a+b<=c+d면되는거였네
//내가해보니까 경계야 아슬아슬하더라고 오른쪽항이커지면 그항이왼쪽항될때 안맞춰지고 이런식으로
//그래서 111
////    111
///     111
//혹은 
//123
//456
//789
//이런식만되는거같아서 a+b == c+d 여야되나 했는데
//좀더널널하게 전체i에서 a+b<=c+d 면되는구나

int main() 
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		vector<vector<int>> vec(n, vector<int>(m,0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &vec[i][j]);
			}
		}
		bool res = true;
		for (int i = 0; i < n-1; i++)
		{
			for (int j = 0; j < m-1; j++)
			{
				int a = vec[i][j];
				int b = vec[i + 1][j + 1];
				int c = vec[i][j+1];
				int d = vec[i + 1][j];
				if (a + b > c + d)
				{
					res = false;
					printf("NO\n");
					break;
				}
			}

			if (res == false)
				break;
		}
		if(res)
			printf("YES\n");
	}

}