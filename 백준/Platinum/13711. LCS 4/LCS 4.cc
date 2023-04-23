#include <string>
#include <vector>
#include<iostream>
#include <queue>
#include<algorithm>


using namespace std;
vector<int> lis_vec;

void lis(vector<int>& sorted)
{
    lis_vec.push_back(sorted[1]);

    for (int i = 2; i < sorted.size(); i++)
    {
        if (lis_vec[lis_vec.size() - 1] < sorted[i])
            lis_vec.push_back(sorted[i]);
        else
            lis_vec[lower_bound(lis_vec.begin(), lis_vec.end(), sorted[i])- lis_vec.begin() ] = sorted[i];
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<int> b_ind(n+1);

    for (int i = 1; i <= n; i++)
        scanf("%d",&a[i]);

    int num = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num);
        b_ind[num] = i;
    }

    vector<int> sorted(n+1,0);
    for (int i = 1; i <= n; i++)
    {
        sorted[i] = b_ind[a[i]];
    }

   
    lis(sorted);
   /* for (int i = 0; i < lis_vec.size(); i++)
        cout << lis_vec[i] << " ";*/

    cout << lis_vec.size();

    return 0;
}
