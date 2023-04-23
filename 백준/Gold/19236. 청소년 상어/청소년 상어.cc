#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include<string>
#define inf 987654321
//6시 20분 시작 읽고 풀이 10분
using namespace std;

struct pos {
    int y=0, x=0;
};
struct fish {
    pos mypos;
    int num;
    int dir;

    bool alive = true;
    
};

struct info {
     
    fish fishes[17];
    int arr[4][4];
    pos shark_pos;
    int shark_dir;
    int count = 0;


};



int main()
{
    int n = 4;
    int a, b;
   
    info start;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d %d", &a, &b);
            start.fishes[a]={ {i,j}, a,b,true };
            start.arr[i][j] = a;
        }
    }

    pos next[] = { {0,0}, {-1,0},{-1,-1}, {0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1} };

    start.shark_pos = { 0,0 };
    start.shark_dir = start.fishes[start.arr[0][0]].dir;
    start.count = { start.arr[0][0] };
    start.fishes[start.arr[0][0]].alive = false;
    start.arr[0][0] = 0;
    queue<info> q;
    q.push(start);
    int answer = start.count;
    while (q.size() > 0)
    {
        info now = q.front();
        q.pop();
        answer = max(answer, now.count);
        for (int i = 1; i <= 16; i++)
        {
            fish& now_fish = now.fishes[i];
            if (now_fish.alive == false) continue;

            int y = now_fish.mypos.y;
            int x = now_fish.mypos.x;
            int dir_count = 0;

            while (dir_count < 8)
            {
               
                int ny = y + next[now_fish.dir].y;
                int nx = x + next[now_fish.dir].x;
              
                if (ny < 0 || nx < 0 || ny >= n || nx >= n || (now.shark_pos.y == ny && now.shark_pos.x == nx))
                {
                    now_fish.dir += 1;
                    if (now_fish.dir == 9)
                        now_fish.dir = 1;
                    dir_count += 1;
                    continue;
                }
                //fish nfish = now.fishes[now.arr[ny][nx]];
                //죽은애있던자리는 다 0 으로 만들자 
                //규칙은 내가 이동할때 원래있던자리 0 으로 만들기
                if (now.arr[ny][nx]==0)//가려는 곳 빈칸
                {
                    now.arr[y][x] = 0;
                    now.arr[ny][nx] = i;
                    now_fish.mypos = { ny,nx };
                    break;
                }
                else
                {
                    now.fishes[now.arr[ny][nx]].mypos = { y,x };
                    now_fish.mypos = { ny,nx };
                    now.arr[y][x] = now.arr[ny][nx];
                    now.arr[ny][nx] = i;
                    break;
                   
                }

            }

           
        }

        for (int mul = 1; mul <= 3; mul++)
        {
            int y = now.shark_pos.y;
            int x = now.shark_pos.x;

            int ny = y + next[now.shark_dir].y * mul;
            int nx = x + next[now.shark_dir].x * mul;

            if (ny < 0 || nx < 0 || ny >= n || nx >= n || now.arr[ny][nx] == 0)//갈수없음
            {

                continue;
            }

            info temp = now;
            temp.shark_pos = { ny,nx };
            temp.shark_dir = temp.fishes[temp.arr[ny][nx]].dir;
            temp.count += temp.arr[ny][nx];
            
            temp.fishes[temp.arr[ny][nx]].alive = false;

            temp.arr[y][x] = 0;
            temp.arr[ny][nx] = 0;
            q.push(temp);

        }
      
    }
    cout << answer;
    return 0;
}