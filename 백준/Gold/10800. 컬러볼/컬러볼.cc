#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include<string>
#include<memory.h>

#define inf 987654321

using namespace std;


//1시10분
int main()
{
   
    int n;
    cin >> n;
    int a, b;
    vector<pair<int, pair<int,int>>> vec(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        vec[i] = { b,{a,i} }; //점수,색깔,인덱스

    }
    vector<int> until_color(n+1,0);

  
    int until_sum = 0;

    vector<int>answer(n);
    sort(vec.begin(), vec.end());//logn번
    

    //값 중복이면(마지막값과 같으면) count만 세다가 중복 풀릴때 한번에 올림

    int next_num = 0;
    int count = 1;
    vector<int> overlap_section_color;
    bool escape = false;

    for (int i = 0; i < n; i++) //n번
    {
        if (escape)//중복이있었고 이번엔 중복이 아니라면 지금까지 중복이였던값들 한번에 처리
        {
            for (int k = 0; k < overlap_section_color.size(); k++)
            {
                until_color[overlap_section_color[k]] += vec[i-1].first;
            }
            until_sum += vec[i - 1].first * count;
            count = 1;
            overlap_section_color.clear();
            escape = false;
        }
        
        //지금까지 나온점수 - 내색으로 나온 점수 
        answer[vec[i].second.second] = until_sum - until_color[vec[i].second.first];
        
        if (i == n - 1)
            break;


        if ( vec[i].first == vec[i+1].first) 
        {
            count++;
            overlap_section_color.push_back(vec[i].second.first);
        }
        else if (count != 1) //중복구간탈출
        {
            overlap_section_color.push_back(vec[i].second.first);
            escape = true;
        }
        else
        {
            until_color[vec[i].second.first] += vec[i].first;//나중에 나올 내 컬러들아 지금까지나온 우리컬러들 점수만큼은 빼고가져가라~
            until_sum += vec[i].first;//지금까지 나온점수
           
        }
       
    }
       //총n+logn
    for (int i = 0; i < n; i++) //n번
    {
        printf("%d\n", answer[i]);
    }
    
    return 0;
} 