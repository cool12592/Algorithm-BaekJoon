#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include <unordered_map>
#include<string>
#include<map>
#define inf 987654321
using namespace std;


    //앞으로만 혹은 뒤로만 가서 만날수있는애들은 나랑 인과관계가있는애들이다
int main()
{
    int n, m,s;
    cin >> n >>m;
    vector<vector<int>>vec(n+1, vector<int>(n+1));
    int a, b;
    for (int i = 0; i <m; i++)
    {
        
          scanf("%d %d", &a,&b);
          vec[a][b] = -1;
          vec[b][a] = 1;
        
    }
   
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (vec[i][k] != 0 && vec[i][k] == vec[k][j])
                {
                    vec[i][j] = vec[i][k];
                }
            }
        }

    }

    cin >> s;

    for (int i = 0; i < s; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", vec[a][b]);

    }


    return 0;
}