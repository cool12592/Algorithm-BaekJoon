#include <iostream>
#include <string>
#include<vector>
#include<memory.h>
#include<map>
#include<set>
using namespace std;

//https://boomrabbit.tistory.com/34
//이거 어캐풀어? 싶어 풀이를봤다
//문제 이름이 신기한연산인데 풀이도 정말 신기한풀이다 (마법풀이)
int main()
{
	int n, m, q;
	cin >> n >> m >> q;
	
	while (q--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
	}

	int english = 0;

	string ans;
	string str;

	while (n>0 && m>0)
	{
		n--;
		m--;
		str += (char)(english + 97);
		if (m > 0)
		{
			m--;
			str += (char)(english + 97);
		}
		english++;
	}
	ans = str;
	int ind = 0;
	while (m > 0)
	{
		m--;
		ans += str[ind];
		ind++;
		if (ind == str.size())
			ind = 0;
	}

	cout << ans;

}