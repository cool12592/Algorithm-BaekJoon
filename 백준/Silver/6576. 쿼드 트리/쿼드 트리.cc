#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<bitset>
using namespace std;

vector<vector<int>> vec;
string str;

int index = 0;
//row~len, col~len 이게 한세트 이렇게 4세트 채우라
void divide(int cnt, int row,int col, int len)
{
	bool start = false;
	if (index == 0)
		start = true;

	if (str[index] == 'Q')
	{
		index++;
		divide(0, row, col, len / 2);
	}
	else
	{
		if (str[index] == 'B')
		{
			for (int i = row; i < row + len; i++)
			{
				for (int j = col; j < col + len; j++)
				{

					vec[i][j] = 1;
				}
			}
		}
		index++;
	}

	
	if (start)
		return;

	if (cnt == 0)
	{
		divide(1, row, col + len, len);
	}
	else if (cnt == 1)
	{
		divide(2, row + len, col - len, len);
	}
	else if (cnt == 2)
	{
		divide(3, row, col + len, len);
	}
	else
		return;
	

}

int myMultiple(int multi)
{
	int num = 1;
	while (0<multi)
	{
		num *= 2;
		multi--;
	}
	return num;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	vec.resize(n, vector<int>(n));
	cin >> str;
	divide(0, 0, 0, n);


cout<<"#define quadtree_width "<<n << "\n";
cout <<"#define quadtree_height "<<n << "\n";
cout << "static char quadtree_bits[] = {" << "\n";
//0xf0, 0xf0,
//0xf0, 0xf0,
//0xf0, 0xf0,
//0xf0, 0xf0,
//0x0f, 0x0f,
//0x0f, 0x0f,
//0x0f, 0x0f,
//0x0f, 0x0f,
//0xf0, 0xf0,
//0xf0, 0xf0,
//0xf0, 0xf0,
//0xf0, 0xf0,
//0x0f, 0x0f,
//0x0f, 0x0f,
//0x0f, 0x0f,
//0x0f, 0x0f,


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j += 8)
		{
			int num = 0;
			for (int k = j; k < j+8; k++)
			{
				if (vec[i][k] == 1)
				{
					num += myMultiple(k-j);
				}
			}
			if(num<16)
				cout << "0x0" << hex << num << ",";
			else
				cout<<"0x" << hex << num << ",";
		}
		cout << "\n";
	}
	cout << "};";
	return 0;
}