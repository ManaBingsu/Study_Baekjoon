/*
*   그룹 단어 체커
*   https://www.acmicpc.net/problem/1316
*/
#include <iostream>
#include <string>
using namespace std;

int alphaCheck[26];

int main()
{
	int N;
	cin >> N;

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int i = 0; i < 26; i++)
			alphaCheck[i] = 0;
		string str;
		cin >> str;
		string::iterator it;
		bool isGrp = true;
		char past = str[0];
		for (it = str.begin(); it != str.end(); it++)
		{
			if (alphaCheck[*it - 'a'] == 0)
				alphaCheck[*it - 'a'] = 1;
			else if (it != str.begin() && alphaCheck[*it - 'a'] == 1 && *it != past)
				isGrp = false;
			past = *it;
		}
		if (isGrp)
			cnt++;
	}
	cout << cnt << "\n";
	return 0;
}