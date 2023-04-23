#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include<string>
#include<memory.h>
#include<stack>
#define inf 987654321

using namespace std;


int main()
{
    int n,m;
    cin >> n>>m;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &vec[i]);

    int left = 0;
    int right = 30000;
    int answer = -1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int sum = 0;
        int val = 0;
        int b = false;
        int group_cnt = 1;
        int big_sum = 0;
        for (int i = 0; i < n; i++)
        {
            val = vec[i];
            if (val > mid)
            {
                b = true;
                break;
            }
            if (sum + val > mid)
            {
                sum = 0;
                group_cnt++;
            }
          

            sum += val;
            if (sum > big_sum)
                big_sum = sum;
        }

        if (group_cnt > m || b)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
            if (answer == -1)
            {
                answer = big_sum;
               
            }
            else
            {
                answer = min(answer, big_sum);
              
            }
        }

    }
    cout << answer << endl;
    int ansSize = 1;
    int num = 0, sum = 0;
    vector<int>ans(301);
    for (int i = 0; i < n; i++) {
        sum += vec[i];
        num++;
        if (sum > answer) {
            sum = vec[i];
            ans[ansSize] = num - 1;
            ansSize++;
            num = 1;
        }
    }
    ans[ansSize] = num;
    int difference = (m - ansSize);
    for (int i = 1; i <= ansSize; i++) {
        if (ans[i] == 1) printf("%d ", ans[i]);
        else {
            while (ans[i] >= 2 && difference >= 1) {
                printf("1 ");
                ans[i]--; difference--;
            }
            printf("%d ", ans[i]);
        }
    }

    return 0;
}