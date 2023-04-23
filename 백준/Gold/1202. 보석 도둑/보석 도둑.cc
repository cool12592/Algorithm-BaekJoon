#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
    int n, k;
    int a, b;
    priority_queue<int> pq;
    vector<pair<int,int>> jewelry;
    vector<int> bag;
    
    cin >> n >> k;
    
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        jewelry.push_back(make_pair(a, b)); //보석들 가격-무게 순으로 저장 비싼게장땡
    }
    for (int i = 0; i < k; i++)
    {
        cin >> a;
        bag.push_back(a); //가방무게저장
    }
    
    sort(jewelry.begin(), jewelry.end());
    sort(bag.begin(), bag.end());
    long long sum = 0;
    int j=0;
    for (int i = 0; i < k; i++)
    {
        while(j<n && bag[i]>=jewelry[j].first)
        {pq.push(jewelry[j].second); j++;}
        
        if(pq.size()>0)
        {
            sum+=pq.top();
            pq.pop();
        }
    }
       
    
    cout << sum ;


    return 0;
}