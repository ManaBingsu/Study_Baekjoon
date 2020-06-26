/*
*   별 찍기 - 21
*   https://www.acmicpc.net/problem/10996
*/
#include <iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	if (N == 1)
	{
		cout << "*\n";
		return 0;
	}
	for (int i = 0; i < N * 2; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i % 2 == 0)
				if (j % 2) cout << " "; else cout << "*";
			else
				if (j % 2) cout << "*"; else cout << " ";
		}
		cout << "\n";
	}
	return 0;
}