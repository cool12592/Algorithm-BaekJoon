#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n, k;
    string num;
    cin >> n >> k >> num;
    int i = 0;
    string sol;
    sol.push_back(num[0]);
    while (i < n - 1)
    {
        if (k > 0 && sol.back() < num[i + 1])
        {

            sol.pop_back();
            k--;
            if (sol.size() == 0)
            {
                sol.push_back(num[i + 1]);
                i++;
            }
        }
        else
        {
            sol.push_back(num[i + 1]);
            i++;
        }
    }

    while (k > 0)
    {
        sol.pop_back();
        k--;
    }
    if (sol.front() == '0')
    {
        cout << "0" << endl;
        return 0;
    }
    cout << (sol) << endl;
    return 0;
}