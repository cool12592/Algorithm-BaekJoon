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
    int n, target;
    while (cin >> target >> n)
    {
        bool possible = false;
        int left = 0;
        int right = n - 1;
        int sum = 0;
        vector<int> vec(n, 0);
        for (int i = 0; i < n; i++)
            scanf("%d", &vec[i]); //값 최대 1억 길이 최대 백만
        target *= 10000000; //나노미터 변환 천만곱함

        sort(vec.begin(), vec.end());


        while (left < right)
        {
            sum = vec[left] + vec[right];
            if (sum == target)
            {
                possible = true;
                break;
            }
            if (sum < target)//올려야함
                left++;
            else
                right--;
        }
        if (possible)
            printf("yes %d %d\n", vec[left], vec[right]);
        else
            printf("danger\n");
    }
    return 0;
}
