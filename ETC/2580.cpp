// ½ºµµÄí
// https://www.acmicpc.net/problem/2580

#include <iostream>
#include <math.h>

#define CAPACITY 9

using namespace std;

int stage[CAPACITY][CAPACITY];

bool isEnd = false;

bool isEqualCol(int row, int col)
{
	for (int i = 0; i < CAPACITY; i++)
	{
		if (row != i && (stage[row][col] == stage[i][col]))
		{
			return true;
		}
	}
	return false;
}

bool isEqualRow(int row, int col)
{
	for (int i = 0; i < CAPACITY; i++)
	{
		if (col != i && (stage[row][col] == stage[row][i]))
		{
			return true;
		}
	}
	return false;
}

bool isEqualSquare(int row, int col)
{
	for (int i = row / 3 * 3; i < row / 3 * 3 + 3; i++)
	{
		for (int j = col / 3 * 3; j < col / 3 * 3 + 3; j++)
		{
			if (row != i && col != j && (stage[row][col] == stage[i][j]))
			{
				return true;
			}
		}
	}
	return false;
}

void print()
{
	for (int i = 0; i < CAPACITY; i++)
	{
		for (int j = 0; j < CAPACITY; j++)
		{
			cout << stage[i][j] << " ";
		}
		cout << "\n";
	}
}

void input()
{
	for (int i = 0; i < CAPACITY; i++)
	{
		for (int j = 0; j < CAPACITY; j++)
		{
			cin >> stage[i][j];
		}
	}
}

void dfs(int row, int col)
{
	if (isEnd)
	{
		return;
	}

	if (row == CAPACITY)
	{
		isEnd = true;
		print();
		return;
	}

	int nextRow = col + 1 < CAPACITY ? row : row + 1;
	int nextCol = col + 1 < CAPACITY ? col + 1 : 0;

	if (stage[row][col] == 0)
	{
		for (int i = 0; i < CAPACITY; i++)
		{
			stage[row][col] = i + 1;
			if (!isEqualSquare(row, col) && !isEqualRow(row, col) && !isEqualCol(row, col))
			{
				dfs(nextRow, nextCol);
				stage[row][col] = 0;
			}
			else if (i == CAPACITY - 1)
			{
				stage[row][col] = 0;
			}
		}
	}
	else
	{
		dfs(nextRow, nextCol);
	}
}

int main()
{
	input();
	dfs(0, 0);
	return 0;
}
