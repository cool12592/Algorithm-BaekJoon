#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>

#define inf 987654321
using namespace std;
int dy[] = { 0,0,-1,1,0 };
int dx[] = { 1,-1,0,0,0 };
struct info {
    int y, x;
    int remain;
    int count;
};

int sunCheck(int count_)
{
    if (count_ % 2 != 0) return 1; //낮
    return 0;
}

int main()
{
    int n,m,k;
    cin >> n>>m>>k;
    vector<string> vec(n);
    bool visit[1000][1000][11][2] = { 0, }; //1낮 0밤

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
         
    }

    queue<info> q;
    q.push({ 0,0,k,1 });
    visit[0][0][k][1] = 1;
    while (q.size() > 0)
    {
        info now = q.front();
        q.pop();
        if (now.y == n - 1 && now.x == m - 1)
        {
            cout << now.count;
            return 0;
        }
        for (int i = 0; i < 5; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;

            //1위에서 계속 제자리에있을수있나k값은계속달라지니까. 1위에라서
            //놉 밤에는 1로이동불가라 q에 push안됨
            //그럼 0에선 제자리에계속? 놉 밤낮두번만 지나면 중복이라 제자리 불가
            //아!!! 벽부수고왔는데 그럼 밤되지? 그럼 무조건 제자리에 못있네 내 코드가
            //벽부수고 와도 그자리에서 대기할수 있는데!!!
            if (i !=4 && vec[ny][nx] == '1') //키포인트 i!=4 일때 !!! i==4일때 즉 제자리는 그냥 저 밑에랑 같은 효과임
            {

               

                if (now.remain>0 && sunCheck(now.count)&& visit[ny][nx][now.remain-1][0]==0) //다음상황으로비짓
                {
                    visit[ny][nx][now.remain - 1][0] = 1;
                    q.push({ ny,nx,now.remain - 1,now.count + 1 });
                }
            }
            else
            { 
                if (visit[ny][nx][now.remain][!sunCheck(now.count)] ==0) //다음상황이니까 지금 낮과 밤에서 반대라 느낌표
                {
                    visit[ny][nx][now.remain][!sunCheck(now.count)] = 1;
                    q.push({ ny,nx,now.remain,now.count + 1 });
                }
            }
        }

    }
    cout << -1;
    return 0;
}