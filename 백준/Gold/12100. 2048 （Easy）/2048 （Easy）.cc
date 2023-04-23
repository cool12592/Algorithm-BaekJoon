#include <iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int n;


int max_num = 0;


void MyRecursion(vector<vector<int>>&vec_origin ,int count) //1왼쪽 2 오른쪽 3 위로 4 아래로
{
    if (count == 0)
        return;

   

    
    {
        vector<vector<int>>vec = vec_origin;
        for (int i = 0; i < n; i++)
        {
            vector<int> myvec;
            myvec.push_back(-1);
            for (int j = 0; j < n; j++)
            {
                
                if (vec[i][j] != 0)
                {
                    if (myvec[myvec.size()-1] != vec[i][j])
                    {
                        myvec.push_back(vec[i][j]);
                        vec[i][j] = 0;
                    }
                    else
                    {
                        int num = myvec[myvec.size() - 1];
                        myvec.pop_back();
                        myvec.push_back(num * 2);
                        myvec.push_back(-1);
                        vec[i][j] = 0;
                    }

                }
              
            }

            int k = 0;
            for (int a = 0; a < myvec.size(); a++)
            {
                if (myvec[a] != -1)
                {
                    vec[i][k] = myvec[a];
                    k++;

                    if (max_num < myvec[a])
                        max_num = myvec[a];
                }
            }
        }
        MyRecursion(vec, count - 1);
    }


    {
        vector<vector<int>>vec = vec_origin;
        for (int i = 0; i < n; i++)
        {
            vector<int> myvec;
            myvec.push_back(-1);
            for (int j = n-1; j >=0; j--)
            {

                if (vec[i][j] != 0)
                {
                    if (myvec[myvec.size() - 1] != vec[i][j])
                    {
                        myvec.push_back(vec[i][j]);
                        vec[i][j] = 0;
                    }
                    else
                    {
                        int num = myvec[myvec.size() - 1];
                        myvec.pop_back();
                        myvec.push_back(num * 2);
                        myvec.push_back(-1);
                        vec[i][j] = 0;
                    }

                }

            }

            int k = n - 1;
            for (int a = 0; a < myvec.size(); a++)
            {
                if (myvec[a] != -1)
                {
                    vec[i][k] = myvec[a];
                    k--;

                    if (max_num < myvec[a])
                        max_num = myvec[a];
                }
            }
        }
        MyRecursion(vec, count - 1);
    }




  
    {
        vector<vector<int>>vec = vec_origin;
        for (int j = 0; j < n; j++)
        {
            vector<int> myvec;
            myvec.push_back(-1);
            for (int i = 0; i < n; i++)
            {

                if (vec[i][j] != 0)
                {
                    if (myvec[myvec.size() - 1] != vec[i][j])
                    {
                        myvec.push_back(vec[i][j]);
                        vec[i][j] = 0;
                    }
                    else
                    {
                        int num = myvec[myvec.size() - 1];
                        myvec.pop_back();
                        myvec.push_back(num * 2);
                        myvec.push_back(-1); //합친거 또 이번턴에 합쳐지는 거 막기위해 -1방벽처둠
                        vec[i][j] = 0;
                    }

                }

            }

            int k = 0;
            for (int a = 0; a < myvec.size(); a++)
            {
                if (myvec[a] != -1)
                {
                    vec[k][j] = myvec[a];
                    k++;

                    if (max_num < myvec[a])
                        max_num = myvec[a];
                }
            }
        }
        MyRecursion(vec, count - 1);
    }
   
    {
        vector<vector<int>>vec = vec_origin;
            for (int j = 0; j < n; j++)
            {
                vector<int> myvec;
                myvec.push_back(-1);
                for (int i = n - 1; i >= 0; i--)
                {

                    if (vec[i][j] != 0)
                    {
                        if (myvec[myvec.size() - 1] != vec[i][j])
                        {
                            myvec.push_back(vec[i][j]);
                            vec[i][j] = 0;
                        }
                        else
                        {
                            int num = myvec[myvec.size() - 1];
                            myvec.pop_back();
                            myvec.push_back(num * 2);
                            myvec.push_back(-1);
                            vec[i][j] = 0;
                        }

                    }

                }

                int k = n - 1;
                for (int a = 0; a < myvec.size(); a++)
                {
                    if (myvec[a] != -1)
                    {
                        vec[k][j] = myvec[a];
                        k--;

                        if (max_num < myvec[a])
                            max_num = myvec[a];
                    }
                }
            }
            MyRecursion(vec, count - 1);
    }
}

int main()
{
    cin >> n;

    vector<vector<int>>vec(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &vec[i][j]);
           
        

    
    
    MyRecursion(vec,5);



    
    cout << max_num;
    return 0;
}