#include<iostream>
#include<vector>
#include<queue>
#include<stack>




using namespace std;




int main()
{
	int n;
	cin >> n;
	
	int a, b, c;
	int one, two, three;
	int one2, two2, three2;
	int new_one, new_two, new_three;

	for (int i = 0; i < 1; i++)
	{

		scanf("%d %d %d", &a,&b,&c);

		one = a;
		two = b;
		three = c;

		one2 = a;
		two2 = b;
		three2 = c;

		
	}

	for (int i = 1; i < n; i++)
	{

		scanf("%d %d %d", &a, &b, &c);

		 new_one =  max(one, two) + a;
		 new_two = max(one, max(two, three)) + b;
		 new_three = max(two, three) + c;

		 one = new_one;
		 two = new_two;
		 three = new_three;

		 new_one = min(one2, two2) + a;
		 new_two = min(one2, min(two2, three2)) + b;
		 new_three = min(two2, three2) + c;

		 one2 = new_one;
		 two2 = new_two;
		 three2 = new_three;


	}

	
	cout << max(one, max(two, three)) << " " << min(one2, min(two2, three2));

	return 0;
}