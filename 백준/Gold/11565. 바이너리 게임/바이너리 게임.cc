#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<set>
#include<string>
#include<queue>
using namespace std;

//백준 바이너리 게임
//신기한문제 (이것도 아이디어가 중요한,마법같은문제) 그 흰색으로만들기 문제랑비슷한느낌
//문자열 a b 어떻게 생긴지는 사실 상관이없다 ㄷㄷㄷ
//문자열 1의 개수만 맞춰주면 어떻게든 b로 바꿔줄수있다
//b가 100110 이런식이면
//a에서 문자열 뒤에 100110그대로 붙이면됨 (앞에원본a는 지우고)
//1이필요하면 1의 개수를 홀수로 조절하면되고 0이필요하면 1의개수를 짝수로 조절하면됨
//앞에꺼 (원본 a문자열) 지워가면서 1의개수 자가조절하면됨
//결론 b의 1의개수보다 a의 1의개수가 [이상]이면 어떤수든만들수있고
//1의개수가 1개부족한 홀수여도 바로 1추가해주면 1의개수맞춰지니까 이경우도가능
//1의개수가 1개부족한데 짝수이면 1추가 못해서 이경우는 안됨
int main()
{
	string a, b;
	cin >> a >> b;
	int a_one = 0, b_one=0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == '1')
			a_one++;
	}
	for (int i = 0; i < b.size(); i++)
	{
		if (b[i] == '1')
			b_one++;
	}
	if (a_one >= b_one)
		cout << "VICTORY";
	else
	{
		if (a_one % 2 != 0 && b_one - a_one == 1)
			cout << "VICTORY";
		else
			cout << "DEFEAT";
	}
	return 0;
}