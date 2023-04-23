#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

vector<vector<int>>vec(9, vector<int>(9));
vector<vector<int>>myvec(9, vector<int>(9));


bool mycheck(int i, int j,int number)
{

    for (int a = 0; a < 9; a++)
    {
        if (a == j) continue;
        if (myvec[i][a] == number)
            return false;
    }
   
    for (int a = 0; a < 9; a++)
    {
        if (a == i) continue;
        if (myvec[a][j] == number)
            return false;
    }


    int range1 = 0;
    int range2 = 0;

    if (i < 3)
    {
        if (j < 3)
        {
            range1 = 0;
            range2 = 0;
            for (int a = range1; a < range1 +3; a++)
            {
                for (int b = range2; b < range2 +3; b++)
                {
                    if (a == i && b == j) continue;
                    if (myvec[a][b] == number)
                        return false;
                }
            }
        }
        else if (j < 6)
        {
            range1 = 0;
            range2 = 3;
            for (int a = range1; a < range1 + 3; a++)
            {
                for (int b = range2; b < range2 + 3; b++)
                {
                    if (a == i && b == j) continue;
                    if (myvec[a][b] == number)
                        return false;
                }
            }
        }
        else if (j < 9)
        {
            range1 = 0;
            range2 = 6;
            for (int a = range1; a < range1 + 3; a++)
            {
                for (int b = range2; b < range2 + 3; b++)
                {
                    if (a == i && b == j) continue;
                    if (myvec[a][b] == number)
                        return false;
                }
            }
        }
    }
    else if (i < 6)
    {
        if (j < 3)
        {
            range1 = 3;
            range2 = 0;
            for (int a = range1; a < range1 + 3; a++)
            {
                for (int b = range2; b < range2 + 3; b++)
                {
                    if (a == i && b == j) continue;
                    if (myvec[a][b] == number)
                        return false;
                }
            }
        }
        else if (j < 6)
        {
            range1 = 3;
            range2 = 3;
            for (int a = range1; a < range1 + 3; a++)
            {
                for (int b = range2; b < range2 + 3; b++)
                {
                    if (a == i && b == j) continue;
                    if (myvec[a][b] == number)
                        return false;
                }
            }
        }
        else if (j < 9)
        {
            range1 = 3;
            range2 = 6;
            for (int a = range1; a < range1 + 3; a++)
            {
                for (int b = range2; b < range2 + 3; b++)
                {
                    if (a == i && b == j) continue;
                    if (myvec[a][b] == number)
                        return false;
                }
            }
        }
    }
    else if (i < 9)
    {
        if (j < 3)
        {
            range1 = 6;
            range2 = 0;
            for (int a = range1; a < range1 + 3; a++)
            {
                for (int b = range2; b < range2 + 3; b++)
                {
                    if (a == i && b == j) continue;
                    if (myvec[a][b] == number)
                        return false;
                }
            }
        }
        else if (j < 6)
        {
            range1 = 6;
            range2 = 3;
            for (int a = range1; a < range1 + 3; a++)
            {
                for (int b = range2; b < range2 + 3; b++)
                {
                    if (a == i && b == j) continue;
                    if (myvec[a][b] == number)
                        return false;
                }
            }
        }
        else if (j < 9)
        {
            range1 = 6;
            range2 = 6;
            for (int a = range1; a < range1 + 3; a++)
            {
                for (int b = range2; b < range2 + 3; b++)
                {
                    if (a == i && b == j) continue;
                    if (myvec[a][b] == number)
                        return false;
                }
            }
        }
    }

    return true;
}


int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &vec[i][j]);
        }
    }
    myvec = vec;
  
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (vec[i][j] == 0) //내가채워야할곳 (원본벡터로봄) (다른곳은건들면안돰(이미채워져있던곳))
            {
                while (true)
                {
                  
                   
                    if (myvec[i][j] == 9) //갈곳없음
                    {
                        myvec[i][j] = 0; //내자리 초기화

                        
                        while (true)
                        {
                            //회귀
                            if (j >= 1)
                            {
                                j--;
                            }
                            else if (j == 0)
                            {
                                if (i == 0)
                                {
                                    return 0;//안되는데 첫자리면 걍 실패(돌아갈곳도없음)
                                }

                                i--;
                                j = 8;
                            }
                            if (vec[i][j] == 0)//원래빈칸이던곳
                                break;
                        }

                       
                        j--; //다시내려야됨 자동 j++라서
                      
                        break;
                    }
                    else
                    {
                        if (mycheck(i, j, ++myvec[i][j]))
                            break;
                    }
                }

                  
                
               
            }
        }
    }

    for (auto a : myvec)
    {
        for (auto b : a)
        {
            printf("%d ", b);
        }
        printf("\n");
    }
    
    return 0;
}