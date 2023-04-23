#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<string>
#include<queue>
#include<map>
using namespace std;

int gcd(int a, int b)
{
    while (1)
    {
        int r = a % b;
        if(r==0)
            break;
        a = b;
        b = r;
    }
    return b;
}

int main() {
    //자기인덱스에 자기 인덱스숫자면 서로소1은아님

    //k개만큼 놉서로소
    //n-k 개 서로소
    //나랑 옆에애랑 바꿔주면 둘다 서로소임 (swap)
    // 1은무조건서로소임 즉 k가 짝수면 1부터 swap
    // 홀수면 2부터 swap하면됨
    //서로소아닌건그냥자기인덱스숫자그대로면됨
    int n, k;
    cin >> n >> k;
    vector<int> vec(n+1);
    for (int i = 1; i <= n; i++)
    {
        vec[i] = i;
    }
    k = n - k; //이제 k는 서로소의개수가됨
    if (k == 0) //1은무조건누구랑도서로소임
    {
        cout << "Impossible";
        return 0;
    }

    if (k % 2 == 0)
    {
        int ind = 1;
        while (k>0)
        {
            swap(vec[ind], vec[ind + 1]);
            k -= 2;
            ind += 2;
        }
    }
    else
    {
        int ind = 2;
        k--;
        while (k > 0)
        {
            swap(vec[ind], vec[ind + 1]);
            k -= 2;
            ind += 2;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << vec[i] << " ";
    }

    return 0;
}