/*
*   팩토리얼
*   https://www.acmicpc.net/problem/10872
*/
#include <iostream>

using namespace std;

int f(int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;
	return n * f(n - 1);
}

int main()
{
	int N;
	cin >> N;

	cout << f(N) << "\n";
	return 0;
}