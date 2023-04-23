#include <iostream>

#include<vector>
#include<algorithm>
#include<unordered_map>
//10시 46분
using namespace std;
#define inf 987654321
//3시 38분
int main()
{  
    int n;
    scanf("%d", &n);
   // unordered_map<int, int> hash1;
   // unordered_map<int, int> hash2; //value값 최대 1600만 sum구할때 얘네 곱할거라 long long //근데 전부다르면 key 1600만개 생김 다 long long으론 무리
    vector<int>vec1(n, 0);
    vector<int>vec2(n, 0); //최대 2억6천
    vector<int>vec3(n, 0);
    vector<int>vec4(n, 0);

    vector<int>vecA(n*n, 0); //최대 5억2천
    vector<int>vecB(n*n, 0);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &vec1[i],&vec2[i],&vec3[i],&vec4[i]);
    }

    int i = 0;
    for (auto a:vec1)
    {
        for (auto b : vec2)
        {
            vecA[i] = a + b;
            i++;
          //  hash1[a + b]++; 
        }
    }
    i = 0;
    for (auto a : vec3)
    {
        for (auto b : vec4)
        {
            vecB[i] = a + b;
            i++;
           // hash2[a + b]++;

        }
    }
    sort(vecA.begin(), vecA.end());
    sort(vecB.begin(), vecB.end());

    int len = n * n;
    int left = 0;
    int right = len-1;
    int num = 0; //최대10억4천
    long long sol = 0; //최대 4000의 4제곱
    long long a = 0, b = 0;
    while (left < len && right >= 0) //둘중하나라도 벗어나면 더이상 없단얘기
    {
        num = vecA[left] + vecB[right];
        if (num > 0)
            right--;
        else if (num < 0)
            left++;

        else if (num == 0)
        {
           // sol += static_cast<long long>( hash1[vecA[left]] * hash2[vecB[right]]); //우항 최대값 1600만제곱
            a = 0; b = 0;
            int k=left;
            while (k<len && vecA[k] == vecA[left])
            {
                k++;
                a++;
            }
            k = right;
            while (k>=0 && vecB[k] == vecB[right])
            {
                k--;
                b++;
            }

            left +=a;
            right-= b;
            sol += a * b; //a*b 최대값 1600만 * 1600만
        }
    }

  
   
   cout << sol;
    return 0;
}
