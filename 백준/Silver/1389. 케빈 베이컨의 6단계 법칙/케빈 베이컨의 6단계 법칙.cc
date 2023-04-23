//5시 30분
//개념이해하는데 1시간
//6시25분 코딩시작 30분


//7시20분
//문제이해 및 풀이법까지 7분
//코딩 30분

//8시 45분
#include <vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define inf 987654321
int main() {
    
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>>vec(n + 1, vector<int>(n + 1, inf));
    for (int i = 0; i < vec.size(); i++)
        vec[i][i] = 0;
    for (int i = 0; i < m; i++)
    {
        int s, e;
        scanf("%d %d", &s, &e);
        vec[s][e] = 1;
        vec[e][s] = 1;
    }


    for (int i = 1; i <= n; i++) //경유지
    { 
        for (int j = 1; j <= n; j++) //출발지
        {
            for (int k = 1; k <= n; k++) //목적지
            {
                vec[j][k] = min(vec[j][k], vec[j][i] + vec[i][k]);
            }
        }
    }
    int answer = inf;
    int sol = 0;
    for (int i = 1; i <= n; i++)
    {
        int my_sum=0;
        for (int j = 1; j <= n; j++)
        {
            my_sum += vec[i][j];
        }
        if (my_sum < answer)
        {
            answer = my_sum;
            sol = i;
        }
    }
    cout << sol;

    return 0;
}