#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;


int main() {
    int n,m;
    cin >> n>>m;
    vector<vector<bool>> vec(n, vector<bool>(m));
    unordered_map<int, string> m1;
    unordered_map<string, int> m2;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            if (str[j] == '0')
                vec[i][j] = 0;
            else
                vec[i][j] = 1;
        }

        m1[i] = str;
        m2[str]++;
    }
    int k;
    cin >> k;

   
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int zeroCount = 0;
        for (int j = 0; j < m; j++)
        {
            if (vec[i][j] == false)
                zeroCount++;
        }
        if (zeroCount <= k && k % 2 == zeroCount % 2) //이러면 이 행을 다 1로만들수있다
        {
            ans = max(ans, m2[m1[i]]); //이 행과 똑같이 생긴 행의 갯수
        }
    }
    cout << ans;
    return 0;
}