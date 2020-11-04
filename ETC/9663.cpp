/*
	N-Queen
	https://www.acmicpc.net/problem/9663
*/


#include <iostream>
#include <math.h>

#define CAPACITY 15

using namespace std;

int N;
int result = 0;
int route[CAPACITY] = { 0, };

bool isTargetExitOnDiagonal(int depth, int height)
{
	for (int i = 0; i < depth; i++)
	{
		if (abs(depth - i) == abs(height - route[i]))
			return true;
	}
	return false;
}

bool isTargetExitOnHeight(int depth, int height)
{
	for (int i = 0; i < depth; i++)
	{
		if (route[i] == height)
			return true;
	}
	return false;
}

void dfs(int depth)
{
	if (depth == N)
	{
		result++;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (!isTargetExitOnDiagonal(depth, i) && !isTargetExitOnHeight(depth, i))
		{
			route[depth] = i;
			dfs(depth + 1);
			route[depth] = 0;
		}
	}
}

int main()
{
	cin >> N;
	dfs(0);
	cout << result << "\n";
	return 0;
}
