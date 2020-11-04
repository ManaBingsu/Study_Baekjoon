/*
*   피보나치 수 5
*   https://www.acmicpc.net/problem/10870
*/
#include <iostream>

using namespace std;

int f(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return f(n - 2) + f(n - 1);
}

int main()
{
	int N;
	cin >> N;

	cout << f(N) << "\n";
	return 0;
}