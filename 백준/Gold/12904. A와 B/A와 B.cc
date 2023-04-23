#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include<string>
#include<memory.h>

#define inf 987654321

using namespace std;



int main()
{
    
    string a, b;
    cin >> a >> b;

    while (true)
    {
        if (a.length() == b.length())
        {
            if (a == b) cout << 1;
            else cout << 0;
            return 0;

        }
        if (b[b.length() - 1] == 'A')
            b.pop_back();
        else
        {
            b.pop_back();
            reverse(b.begin(), b.end());
        }
    }
    
    return 0;
}