#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define inf 9876543
int main()
{
    int input;
    cin>>input;
    vector<int> dp(input+1,inf);
    dp[3]=1;
    dp[5]=1;
    for(int i=6;i<dp.size();i++)
        dp[i]=min(dp[i-3],dp[i-5]) +1 ;
    
    if(dp[dp.size()-1]>=inf) 
        cout<<-1; 
    else
        cout<<dp[dp.size()-1]<<endl;
    
   return 0; 
}