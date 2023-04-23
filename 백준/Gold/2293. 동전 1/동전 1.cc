#include<iostream>
#include<memory>
#include<vector>
#include<deque>
using namespace std;




int main()
{
  
    int n, k;
    cin >> n >> k;

    vector<int> vec(k+1,0);
    vector<int>number_vec(n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &number_vec[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int now_num = number_vec[i];
        for (int j = 1; j <= k; j++)
        {
           
            if (now_num > j)
            {
                if (i == 0)
                    vec[j] = 0;
                else
                    vec[j] = vec[j];
            }
            else if(now_num == j)
            {
                if (i == 0)
                    vec[j] = 1;
                else
                    vec[j] = vec[j] +1;
            }
            else if (now_num < j)
            {
                if (i == 0)
                    vec[j] = vec[j-now_num];
                else
                    vec[j] = vec[j] + vec[j - now_num];
            }
        }
    }
    cout << vec[k];

    return 0;
}