#include <iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

string entire[5];
int rotateDir[5];
void rotate()
{
    for (int i = 1; i <= 4; i++)
    {
        if (rotateDir[i] == 100)
            continue;

        if (rotateDir[i] == 1) //시계
        {
            int temp = entire[i][7];
            for (int j = 6; j >= 0; j--)
            {
                entire[i][j + 1] = entire[i][j];
            }
            entire[i][0] = temp;
        }

        else if (rotateDir[i] == -1) //반시계
        {
            int temp = entire[i][0];
            for (int j = 1; j <= 7; j++)
            {
                entire[i][j - 1] = entire[i][j];
            }
            entire[i][7] = temp;
        }
    }
}
void checkRotateDirection(int num, int dir)
{
    for (int i = 0; i < 5; i++)
        rotateDir[i] = 100; //100이면 no회전
    rotateDir[num] = dir;
    //오른쪽
    for (int i = num; i <= 3; i++)
    {
        if (entire[i][2] != entire[i + 1][6])
            rotateDir[i+1] = -rotateDir[i];
        else //같다면 회전x
            break;
    }
    //왼쪽
    for (int i = num; i >=2 ; i--)
    {
        if (entire[i][6] != entire[i - 1][2])
            rotateDir[i - 1] = -rotateDir[i];
        else
            break;
    }


    rotate();
}


int main()
{
    string a, b, c, d;
    cin>> a >>b >>c>>d;
   
    entire[1] = a;
    entire[2] = b;
    entire[3] = c;
    entire[4] = d;

    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int aa, bb;
        scanf("%d %d", &aa, &bb);
        checkRotateDirection(aa, bb);
    }
    int sum = 0;
    if (entire[1][0] == '1')
        sum += 1;
    if (entire[2][0] == '1')
        sum += 2;
    if (entire[3][0] == '1')
        sum += 4;
    if (entire[4][0] == '1')
        sum += 8;
   
    cout << sum;
    return 0;
}