/*
*   사분면 고르기
*   https://www.acmicpc.net/problem/14681
*/
#include <iostream>
using namespace std;
int print(int n) { cout << n; return 0; }
int main()
{
	int X, Y;
	cin >> X >> Y;
	X > 0 ? Y > 0 ? print(1) : print(4) : Y > 0 ? print(2) : print(3);
	return 0;
}