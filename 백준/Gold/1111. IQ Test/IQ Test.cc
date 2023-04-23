#include <string>
#include <vector>
#include<iostream>
#include <queue>
#include<algorithm>

using namespace std;



// 일단 연립방정식은 잘 생각했음
// 허나 생각해야했던것들
// 1. n=1일때는 뒤에 머가 와도 공식이 성립됨 답A
// 2. n=2 일때 두 수가 같으면 그수가 답 아니면 A
// 3. 위 2상황이 아닐때 모든 수가 같으면 그게 정답
// 마지막으로내가 1시간 20분 지나야 생각해낸 거
// 나는 처음껄로만 공식만들었자나 근데 뒤에 아무때나 이상한숫자가 올수도있음!!
//그래서 공식 다 되는지 첨부터끝까지 적용해봐야됨....
int main()
{
  
    int n;
    cin >> n;
    vector<int> vec(n);
   
    bool all_same = true;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vec[i]);
        if (i >= 1)
        {
            if (vec[i] != vec[i - 1])
                all_same = false;
        }
    }


    if (n == 1)
    {
        cout << "A";
        return 0;
    }
    if (n == 2)
    {
        if(vec[0]==vec[1])
            cout << vec[0];
        else
            cout << "A";
        return 0;
    }


    if (all_same)
    {
        cout << vec[0];
        return 0;
    }
 

    double x = double(vec[1] - vec[2]) / double(vec[0] - vec[1]);
    if (x != (int)x)
    {
        cout << "B";
        return 0;
    }


    double y = vec[1] - (vec[0] * x);
   

    for (int i = 1; i < n; i++)
    {
        if (vec[i - 1] * x + y != vec[i])
        {
            cout << "B";
            return 0;
               
        }
    }


    cout << int(vec[n - 1] * x + y);


    return 0;
}