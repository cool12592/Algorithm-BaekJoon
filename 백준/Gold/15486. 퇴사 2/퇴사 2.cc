#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<pair<int, int>> vec;
    int current_max = 0;
    int N;
    cin >> N;
    int a, b;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &a, &b);
        vec.push_back({ a,b });
    }
    vector<int> dp(N + 1, 0); //dp는 한자리크게만듬
    int later_index = 0;
    for (int i = 0; i < dp.size(); i++)
    {
        if (current_max < dp[i]) //아 내차례됐다 내 보너스푼다ㅋㅋ
            current_max = dp[i];
        later_index = i + vec[i].first;
        if (later_index < dp.size())
            dp[later_index] = max(dp[later_index], vec[i].second + current_max); //현재꺼+지금까지쓸수있는보너스중 젤큰거(current_max)
    }


    cout << current_max;
    return 0;
}