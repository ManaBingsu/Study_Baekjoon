/*
*   하노이 탑 이동 순서
*   https://www.acmicpc.net/problem/11729
*/
#include <iostream>
#include <cmath>

using namespace std;

void f(int n, int from, int via, int to)
{
	if (n == 1)
		cout << from << " " << to << "\n";
	else
	{
		f(n - 1, from, to, via);
		cout << from << " " << to << "\n";
		f(n - 1, via, from, to);
	}
}

int main()
{
	int N;
	cin >> N;
	int result = 1;
	for (int i = 0; i < N; i++)
		result *= 2;
	cout << result - 1 << "\n";
	f(N, 1, 2, 3);
	return 0;
}