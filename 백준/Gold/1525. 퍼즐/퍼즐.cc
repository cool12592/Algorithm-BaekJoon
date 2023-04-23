
#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include <unordered_map>
#include<string>
using namespace std;

unordered_map<int, int> um;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };

int mypow(int i)
{
    int num = 1;
    while (i)
    {
        num = num * 10;
        i--;
    }
    return num;
}
int main()
{

    int a;
    int start = 0;
    for (int i = 8; i >= 0; i--)
    {
        scanf("%d", &a);
        if (a == 0) a = 9;
        start +=mypow(i) * a;
    }

    int answer = -1;
    um[start] = 0;
    queue<pair<int,int>> q;
    q.push({ start,0 });
    while (q.size() > 0)
    {
        int now = q.front().first;
        int cost = q.front().second;
        q.pop();
        if (now == 123456789)
        {
            answer = cost;
            break;
        }

        string s = to_string(now);
        int pos=s.find('9');

        int y = pos / 3; //이런방법이있었네ㄷㄷ
        int x = pos % 3;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= 3 || nx >= 3 || ny < 0 || nx < 0)
                continue;
            string temp = s;
            swap(temp[y * 3 + x], temp[ny * 3 + nx]);
            int next = stoi(temp);
            if (um.count(next) == 0)
            {
                um[next] = cost +1;
                q.push({ next,cost + 1 });

            }
        }
    }


     cout << answer;
 
    return 0;
}