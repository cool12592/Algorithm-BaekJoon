#include <iostream>
#include<vector>
#include<algorithm>


using namespace std;

//1시 55분
vector<vector<int>> vec;
int N;
bool check(int y, int x)
{
    for (int i = y-1; i >= 0; i--)
    {
        if (vec[i][x] == 1)
            return false;
    }

    int i = y-1;
    int j = x-1;
    while (i >= 0 && j >= 0)
    {
        if (vec[i][j] == 1)
            return false;
        i--;
        j--;
    }

     i = y - 1;
     j = x + 1;
    while (i >= 0 && j <N)
    {
        if (vec[i][j] == 1)
            return false;
        i--;
        j++;
    }
    return true;
   
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> vec2(n, vector<int>(n, 0));
    //전역초기화
    vec = vec2;
    N = n;
    bool enable;
    int sol = 0;
    vector<int> pos(n, -1); //여기+1이 그 줄에서 출발지임(이전에있던 체스위치부터)
    for (int i = 0; i < n; i++)
    {
        enable = false;
       
        for (int j = pos[i]+1; j < n; j++) //처음하는줄은 0부터 다시하는줄은 이전체스+1부터
        {
            if (check(i, j))
            {
                if (i == n - 1)//마지막 클리어
                {
                    sol++; //이러면 실제 두지는 않고 sol만 올림 옆쪽으로 계속 진행
                }
                else //마지막 줄 아니면
                {
                    vec[i][j] = 1;
                    pos[i] = j;
                    enable = true;
                    break;
                }
            }

        }
        if (!enable)//이줄에 둘 곳 없는경우 돌아가야함
        {
            if (i == 0) //첫줄에 둘곳없어지면 끝
                break;
            int p = pos[i - 1]; //전줄에 체스있는위치
            vec[i - 1][p] = 0;//그 체스 뺌

             //이게 핵심 
            //1) 이전 줄로 돌아가서 그놈은 pos +1부터 다시 시작한다
            //2) 대신 그럼 그 이후 줄부터는 기존위치를 초기화시켜 첫칸부터해야한다
            for (int k = i; k < n; k++)
                pos[k] = -1;


            i -= 2; //이래야한줄뒤로감


           
        }
    }

    cout << sol;
    return 0;
}
