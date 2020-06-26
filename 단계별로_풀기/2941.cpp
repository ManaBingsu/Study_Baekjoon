/*
*   크로아티아 알파벳
*   https://www.acmicpc.net/problem/2941
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	string strs[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	cin >> str;
	int i = 0;
	int sum = str.size();
	int dzNum = 0;
	for (int i = 0; i < 8; i++)
	{
		string temp = str;
		while (temp.find(strs[i]) != str.npos)
		{
			if (i == 2)
				dzNum++;
			sum -= strs[i].size() - 1;
			if (dzNum > 0 && i == 7)
			{
				dzNum--;
				sum++;
			}
			temp = temp.substr(temp.find(strs[i]) + strs[i].size());
		}
	}
	cout << sum << "\n";
	return 0;
}