#include <iostream>
#include <math.h>
#include<vector>
#include<algorithm>
//지금이 5시 7분이니까 대략 4시 30분시작? 40분시작? 40분이라치자 
using namespace std;
#define inf 987654321
//9시 20분
int main()
{
    int n, s;
    scanf("%d %d", &n, &s);
    vector<int>vec(n, 0);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vec[i]);
    }
    int i = 0;

    int j = i;
    int sum = vec[i];
    int sol = inf;
    
    while (true)
    {
        if (sum >= s) 
        {
            sol = min(sol, j - i + 1);
            if (i == j)
            {
                cout << 1;
                return 0;
            }
            sum -= vec[i];
            i++;
           // sum += vec[i];
          
        }
        else
        {
            j++;
            if (j == n) break;
            sum += vec[j];
        }

    }

    if (sol == inf)cout << 0;
    else cout << sol;
    return 0;
}
