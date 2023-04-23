#include<iostream>
#include<memory.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
using namespace std;

int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };

//1. 이분탐색을이용 mid값 = 정답 = 최소차이
// 초기 mid값 = 0~200사이
// 이제 이 mid값으로 출발점에서 도착점까지 이동가능한지확인해보는거임
//그런데 mid값이 최소값과 최대값의 차이잖아
//그럼 mid값은알겠는데 최소값과 최대값은 여러개있수있잖아?? 그럼멀로해야돼
//mid값이 3이면 최소최대쌍이 0 3 / 1 4 / 2 5 / 3 6 여러개잖아 다해보면됨 
//minvalue 를증가하면서 minvalue+mid 가 maxvalue되기 까지 다해봄
//가는 길이  minvalue 와 minvalue+mid 사이여야됨
//그럼 이중한번이라도 도착지점 도착하면 이 mid값은 된다는것 end=mid-1해서 다시 mid구해서해봄
//전부 도착지점 못가면 이 mid값은 안됨 mid값 올려야됨 다시말하자면 mid값은 최대값과최소값차이임(이문제의정답)
//start = mid+1

//한가지또 추가) 아예 시작도 못하면 mid값이 너무 큰거임 (for문에 minvalue+mid <=maxvalue가 안되는거니까)
//이때도 end=mid-1 로 mid값줄여줘야됨

int main() {
   
    int n;
    cin >> n;
    int minvalue = 205;
    int maxvalue = -1;
    vector<vector<int>> vec(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &vec[i][j]);
            minvalue = min(minvalue, vec[i][j]);
            maxvalue = max(maxvalue, vec[i][j]);
        }
    }
    int start = 0; int end = 200;
    int mid = 100;
    vector<vector<int>> visit(n, vector<int>(n));
    int visitnumber = 0;
    int sol = 201;
    while (start <= end)
    {
        mid = (start + end) / 2;
        bool arr = false;
        bool depart = false;
        for (int value = minvalue; value +mid <= maxvalue; value++)
        {
            depart = true;
            if (arr) break;
            visitnumber++;
            queue<pair<int, int>>q;
            int endvalue = value + mid;
            if (value<=vec[0][0] && endvalue>=vec[0][0])
                q.push({ 0,0 });

            while (q.size() > 0)
            {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();

                if (y == n - 1 && x == n - 1)
                {
                    arr = true;
                    break;
                }


                for (int i = 0; i < 4; i++)
                {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                    if (value > vec[ny][nx] || endvalue < vec[ny][nx]) continue;
                    if (visit[ny][nx] == visitnumber) continue;

                    visit[ny][nx] = visitnumber;
                    q.push({ ny,nx });

                }

            }

        }
        //첨에 mid가 되게 크면 모든 vec[i][j]갈수있으니 무조건되는거아니야? 생각할수있지만
        //minvalue와 maxvalue 보다 큰 mid는 존재할수도 없음 코드안돌아감(for문에안들어감)
        if (depart == false)//아예시작도못했으면 mid를 줄여야됨 (mid가너무커서 for문에 minvalue+mid <=maxvalue가 안되는거니까)
        {
            end = mid - 1;
        }
        else if (arr)  //이 mid값으로 도착성공 mid값타이트하게더줄여봄
        {
            end = mid - 1; //mid값
            sol = min(sol,mid);
        }
        else //이mid로 실패 여유생기게 mid값더 늘려봄
        {
            start = mid + 1;
        }

    }
    cout << sol;
    return 0;
}
