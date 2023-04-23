#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;


//12시 16분 시작
//모든 n을 구간별로나눔
//지금구간을 뒤집으면 왼쪽구간+지금구간+오른쪽구간 이렇게 3파트가 합쳐짐
//이게 제일 긴거 출력
int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    vector<pair<int,int>> section;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vec[i]);
    }

    section.push_back({ 0,0 });
    for (int i = 1; i < n; i++)
    {
        if (vec[i - 1] == vec[i])
        {
            section.back().second = i - 1;
            section.push_back({ i,i });
        }
    }
    section.back().second = n - 1;

    int answer = 0;

    if (section.size() == 1)
        answer = section[0].second - section[0].first;
    else if(section.size()==2)
        answer = section[1].second - section[0].first;
    else
    {
        for (int i = 0; i < section.size() - 2; i++)
        {
            int sum = section[i + 2].second - section[i].first;
            answer = max(answer, sum);
        }
    }
    cout << answer+1;
    return 0;
}