#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

unordered_map<char, int> myhash;

void Combination(vector<char> arr, vector<char> comb, int r, int index, int depth)
{
    if (r == 0)
    {
        int left = 0, right = 0;
        bool possible = false;
        for (int i = 0; i < comb.size(); i++)
        {
            if (myhash[comb[i]])
                left++;
            else
                right++;

            if (left >= 1 && right >= 2)
            {
                possible = true;
                break;
            }
        }
        if (possible)
        {
            for (int i = 0; i < comb.size(); i++)
                cout << comb[i];
            cout << endl;
        }
    }
    else if (depth == arr.size())  // depth == n // 계속 안뽑다가 r 개를 채우지 못한 경우는 이 곳에 걸려야 한다.
    {
        return;
    }
    else
    {
        // arr[depth] 를 뽑은 경우
        comb[index] = arr[depth];
        Combination(arr, comb, r - 1, index + 1, depth + 1);

        // arr[depth] 를 뽑지 않은 경우
        Combination(arr, comb, r, index, depth + 1);
    }
}

int main()
{

    int r, n;
    cin >> r >> n;//4 6 //6개중 4개(r)뽑기
    vector<char> vec(n);

    myhash['a'] = 1;
    myhash['e'] = 1;
    myhash['i'] = 1;
    myhash['o'] = 1;
    myhash['u'] = 1;
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &vec[i]);
    }

    sort(vec.begin(), vec.end());


    vector<char> comb(r);

    Combination(vec, comb, r, 0, 0);  // {'a', 'b', 'c', 'd', 'e'}의 '5C3' 구하기 

    return 0;
}