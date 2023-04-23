#include <iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<unordered_map>
//10시 46분
using namespace std;
#define inf 2000000001
//3시 38분
int main()
{  
    int g;
    cin >> g;
    long long a = 1;
    double b;
    bool possible = false;
    while (a*a-((a-1)*(a-1))<=g) //이거벗어나면 이제 답없는거임
    {
      
        b = a * a - g;
        b = sqrt(b);
        if (b != 0)
        {
            if (b == (int)b)
            {
                printf("%d\n", a);
                possible = true;
            }
        }
        a++;

    }
    if (!possible)
        cout << -1;
    return 0;
}
