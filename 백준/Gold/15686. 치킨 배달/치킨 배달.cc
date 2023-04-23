#include <string>
#include <vector>
#include<iostream>
#include <queue>
#include<algorithm>
//3시 18분 30분 고민해보다 도저히 생각안나서 gg....
//정답은 그냥 브루트포스.. 다 해보는거였음...
using namespace std;




int answer = 0;

vector<pair<int, int>> home_pos;
void solution( vector<pair<int, int>>comb)
{
    int all_dis = 0;
    
    int dis;

    int cost[50][50] = { 0, };
    //치킨집마다 모든 집까지감
    for (int i = 0; i < comb.size(); i++)
    {
       
        for (int j = 0; j < home_pos.size(); j++)
        {
            dis = abs(home_pos[j].first - comb[i].first) + abs(home_pos[j].second - comb[i].second);
           
            if (cost[home_pos[j].first][home_pos[j].second] == 0)
            {
                cost[home_pos[j].first][home_pos[j].second] = dis;
                all_dis += dis;
            }
            else
            {
                if (cost[home_pos[j].first][home_pos[j].second] <= dis)
                {
                    all_dis = all_dis; //이번거리가 더 길면 걍 아무것도아님
                }
                else //더 짧으면 변경필요함
                {
                    //원래값 빼주고
                    all_dis -= cost[home_pos[j].first][home_pos[j].second]; 
                    all_dis += dis;//새값넣어줌

                    cost[home_pos[j].first][home_pos[j].second] = dis; //갱신
                }
            }

        }
    }


    if (answer == 0)
        answer = all_dis;
    else
        answer = min(answer, all_dis);
   
}

void Combination(vector<pair<int, int>> arr, vector<pair<int, int>>comb, int r, int index, int depth)
{
    if (r == 0)
    {
        //for (int i = 0; i < comb.size(); i++)
        //    cout <<"{"<< comb[i].first<<", " << comb[i].second << "} ";
        //cout << endl;

        solution(comb);
    }
    else if (depth == arr.size())  // depth == n // 계속 안뽑다가 r 개를 채우지 못한 경우는 이 곳에 걸려야 한다.
    {
        return;
    }
    else
    {
        // arr[depth] 를 뽑은 경우
        comb[index] = arr[depth];
        Combination(arr, comb, r - 1, index + 1, depth + 1);

        // arr[depth] 를 뽑지 않은 경우
        Combination(arr, comb, r, index, depth + 1);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    int num;
    vector<pair<int, int>> chick_pos;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &num);
            if (num == 2)
                chick_pos.push_back({ i,j });
            
            if (num == 1)
                home_pos.push_back({ i, j });
        }
    }

    
    int r = m;
    vector<pair<int, int>> comb(r);
    Combination(chick_pos, comb, r, 0, 0);  // {'a', 'b', 'c', 'd', 'e'}의 '5C3' 구하기 


    cout << answer;
    return 0;
}