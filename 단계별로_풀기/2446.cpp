/*
*   별 찍기 - 9
*   https://www.acmicpc.net/problem/2446
*/
#include <iostream>
using namespace std;
void print(int N, int depth)
{
	for (int i = 0; i < N * 2 - 1 - depth; i++)
	{
		if (i < depth)
			cout << " ";
		else
			cout << "*";
	}
	if (depth == N - 1)
	{
		cout << "\n";
		return;
	}
	cout << "\n";
	print(N, depth + 1);
	for (int i = 0; i < N * 2 - 1 - depth; i++)
	{
		if (i < depth)
			cout << " ";
		else
			cout << "*";
	}cout << "\n";
}
int main()
{
	int N;
	cin >> N;
	print(N, 0);
	return 0;
}