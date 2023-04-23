#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include<string>
#include<memory.h>

#define inf 987654321

using namespace std;



int main()
{
    int n, m, k;

    cin >> n >> m >> k;
    vector<vector<int>> vec(n+1,vector<int>(n+1,0));
    int a, b, c;
    vector<int>truck(n+1);
    int truck_sum = 0;
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        vec[a][b] = c;// .push_back({ b,c });
    }
    
 
   
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {

        answer += truck[i];
        truck_sum -= truck[i];
        for (int j = i + 1; j <= n; j++)
        {

            if (vec[i][j] == 0) continue;
           // if (truck_sum == m) break;//꽉참
            if (truck_sum + vec[i][j] <= m)
            {
                truck_sum += vec[i][j];
                truck[j] += vec[i][j];
            }

            else
            {
                int num = vec[i][j];
               
                if (m - truck_sum >= 0)
                {
                    num -= m - truck_sum;
                    truck[j] += m - truck_sum;
                    truck_sum += m - truck_sum;
                   
                }
                if (num == 0) continue;

                for (int k = n; k >= j + 1; k--)
                {
                    if (truck[k] > 0)
                    {
                        if ( truck[k] >= num)
                        {
                            //truck_sum += num;
                            truck[j] +=num;
                            truck[k] -= num;
                        }
                        else
                        {
                           // truck_sum += truck[k];
                            num -= truck[k];
                            truck[j] += truck[k];
                            truck[k] = 0;
                          
                        }
                        if (num == 0) break;
                    }
                }
                
            }
        }
    }
    cout << answer;
    return 0;
}