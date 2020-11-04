/*
*   별 찍기 - 10
*   https://www.acmicpc.net/problem/2447
*/
#include <iostream>

using namespace std;

int **arr;

void f(int n, int x, int y, int zone)
{
	if (zone == 4)
		return;
	if (n / 3 == 0)
		return;
	if (n / 3 == 1)
		arr[x][y] = 1;
	else
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				f(n / 3, i + x * 3, j + y * 3, i * 3 + j);
	}
}

int main()
{
	int N;
	cin >> N;
	arr = new int*[N];
	for (int i = 0; i < N; i++)
		arr[i] = new int[N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			arr[i][j] = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			f(N, i, j, i * 3 + j);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j])
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
	}
	return 0;
}