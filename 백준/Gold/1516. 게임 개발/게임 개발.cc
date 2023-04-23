#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;
vector<int> dp;
vector<vector<int>> origin;
int dfs(int num) //dp[num]값 리턴
{
	if (dp[num] != 0)
		return dp[num]; //이미 dp값 알면 리턴
    
    if (origin[num].size() == 1)
    {
        dp[num]=origin[num][0]; 
        return origin[num][0];
    }

	int mydp = 0;
	for (int i = 1; i < origin[num].size(); i++)
		mydp = max(mydp, dfs(origin[num][i])); //하위건물중 젤 dp값 큰애가 mynum됨
	mydp += origin[num][0];//마무리는 자기값더함
    dp[num]=mydp;
	return mydp;

}

int main()
{
	int N;
	cin >> N;

	int input;

	vector<vector<int>> vec(N + 1);

	for (int i = 1; i < N+1; i++)
	{
		while (true)
		{
			scanf("%d", &input);
			if (input == -1)
			{
				break;
			}

			vec[i].push_back(input);
		}
	}
	origin = vec; //전역초기화
	vector<int>tempdp(origin.size(), 0);
	dp = tempdp; //전역초기화

	for (int i = 1; i < origin.size(); i++)
	{
		cout <<  dfs(i)<< endl;
	}
	
		

	return 0;
}