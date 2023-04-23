#include <iostream>

#include<vector>
#include<algorithm>
#include<unordered_map>
//10시 46분
using namespace std;
#define inf 2000000001
//3시 38분
int main()
{  
    int n,m;
    scanf("%d %d", &n,&m);
   vector<int>vec(n, 0);

   

    

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vec[i]);
    }

    if (n == 1 || m==0)
    {
        cout << 0;
        return 0;
    }
    sort(vec.begin(), vec.end());
    
    int min_dif = inf;
    int dif = 0;
    int right, left,mid;

    for (int i = 0; i < n; i++)
    {
       
        
        if (vec[n - 1] - vec[i] >= m)//오른쪽구간
        {
            left = i + 1;
            right = n - 1;
            
            while (left < right)
            {
                mid = (left + right) / 2;
                if (vec[mid] - vec[i] >= m)
                {

                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }


            }

            dif = vec[right] - vec[i];
            if (dif == m)
            {
                cout << m;
                return 0;
            }
            min_dif = min(dif, min_dif);
        }
        if (vec[i] - vec[0] >= m) //왼쪽구간
        {
            left = 0;
            right = i-1;

            while (left < right)
            {
                mid = (left + right) / 2;
                if (vec[i] - vec[mid] >= m)
                {
                    if (mid == left)
                    {
                        break;
                    }
                    left = mid;
                }
                else
                {
                    right = mid - 1;
                }
            }
            dif = vec[i]-vec[left];
            if (dif == m)
            {
                cout << m;
                return 0;
            }
            min_dif = min(dif, min_dif);
        }
    }
  
   
   cout << min_dif;
    return 0;
}
