#include <iostream>
#include<vector>
#include<algorithm>


using namespace std;

#define inf 1000000001

int main()
{


    int n;
    cin >> n;
    vector<int> vec(n , 0);
    for (int i = 0; i < n; i++)
        scanf("%d",&vec[i]);
    
  

    vector<int> cal(n - 1);

    int num;
    int k = 0;

   for (int i = 0; i < 4; i++)
   {
       scanf("%d", &num);
       while (num--)
       {
           if (i == 0)
               cal[k] = 1;//더하기
           else if (i == 1)
               cal[k] = 2;//빼기
           else if (i == 2)
               cal[k] = 3;//곱
           else
               cal[k] = 4;//나눔
           k++;
       }
   }

   int max_=-inf, min_=inf;
    do
    {
        int sum = vec[0];
        for (int i = 1; i < n; i++)
        {
            if (cal[i - 1] == 1)
            {
                sum = sum + vec[i];
            }
            else if (cal[i - 1] == 2)
            {
                sum = sum - vec[i];
            }
            else if (cal[i - 1] == 3)
            {
                sum = sum * vec[i];
            }
            else if (cal[i - 1] == 4)
            {
                sum = sum / vec[i];
            }
        }
        if (sum > max_)
            max_ = sum;
        if (sum < min_)
            min_=sum;

    } while (next_permutation(cal.begin(), cal.end()));

        printf("%d\n%d", max_, min_);

    return 0;
}
