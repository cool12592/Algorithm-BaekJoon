#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;


int main() {
    int n,k;
    cin >> n >> k;

 
    if (n == 2)
    {
        cout << "YES" << endl;
        cout << "swap 1 2" << endl;
        cout << "swap 1 2" << endl;
        cout << "swap 1 2" << endl;
        cout << "swap 1 2" << endl;
        cout << "swap 1 2" << endl;
    }
    else if (n == 3)
    {
        cout << "NO";
    }
    else
    {
        if (k == 1)
        {
            cout << "YES" << endl;
            cout << "reverse 2 " + to_string(n) << endl;
            cout << "reverse 1 " + to_string(n) << endl;

            cout << "swap 1 4"<< endl;
            cout << "swap 2 3"<< endl;
            cout << "reverse 1 4" << endl;
        }
        else if (k == n - 1)
        {
            cout << "YES" << endl;
            cout << "reverse 1 " + to_string(n-1) << endl;
            cout << "reverse 1 " + to_string(n) << endl;

            cout << "swap 1 4" << endl;
            cout << "swap 2 3" << endl;
            cout << "reverse 1 4" << endl;
        }
        else
        {
            cout << "YES" << endl;
            cout << "reverse 1 " + to_string(k) << endl;
            cout << "reverse "+ to_string(k+1)+" " + to_string(n) << endl;
            cout << "reverse 1 " + to_string(n) << endl;
            cout << "swap 1 2" << endl;
            cout << "swap 1 2" << endl;
        }
    }


    return 0;
}