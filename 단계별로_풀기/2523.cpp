/*
*   별 찍기 - 13
*   https://www.acmicpc.net/problem/2523
*/
#include <iostream>
using namespace std;
void print(int N, int depth)
{
	for (int i = 0; i < depth; i++)
		cout << "*";
	if (depth == N)
	{
		cout << "\n";
		return;
	}
	cout << "\n";
	print(N, depth + 1);
	for (int i = 0; i < depth; i++)
		cout << "*";
	cout << "\n";
}
int main()
{
	int N;
	cin >> N;
	print(N, 1);
	return 0;
}