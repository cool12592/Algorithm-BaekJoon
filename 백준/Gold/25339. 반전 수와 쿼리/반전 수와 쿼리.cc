#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<string>
#include<queue>
#include<map>
using namespace std;


int main() {
    int n, q;
    cin >> n >> q;
    int ans = 0;
    while (q--)
    {
        int a, i, j;
        scanf("%d %d %d", &a, &i, &j);
        if (a == 1)
        {
            ans = (ans + 1) % 2;
        }
        else
        {
            int len = j - i +1;
            int combi = ((len)*(len-1))/2;
            if(combi % 2 !=0)
                ans = (ans + 1) % 2;

        }
        printf("%d\n", ans);
    }

    return 0;
}