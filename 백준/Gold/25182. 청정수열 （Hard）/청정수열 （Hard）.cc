#include <iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

#define mod 1000000007


int main() 
{
	int n;
	cin >> n;
	
	unsigned long long sum1 = 2;
	unsigned long long a = 4;
	unsigned long long b = 5;
	unsigned long long ans1 = 2;
	unsigned long long ans2 = 1;
	//ans1 = ans1 + (sum+2*i)*i

	for (unsigned long long i = 2; i <= n; i++)
	{

		ans1 = (ans1 + (sum1 + 2ULL * i) * i)%mod;
		sum1 = sum1 + 2ULL * i;

		ans2 = (ans2 * a)%mod;

		a = a + b;
		b += 2;
	}
	cout << ans1<<" " << ans2;

}