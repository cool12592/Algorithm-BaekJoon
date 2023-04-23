#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int>vec(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &vec[i]);

    int accumulate = 0;
    pair<int, int> firstNumberRange = {-2000000001,2000000001 };
    for (int i = 0; i < n; i++)
    {
        int now = vec[i];
        //범위는점점좁아진다
        if (i % 2 == 0) //최대값갱신
        {
            firstNumberRange.second = min(firstNumberRange.second, now - accumulate);
        }
        else //최소값갱신
        {
            firstNumberRange.first = max(firstNumberRange.first,  accumulate - now);
        }
        accumulate = 2 * now - accumulate;
    }
    cout << max(firstNumberRange.second - firstNumberRange.first + 1,0);
    return 0;
}