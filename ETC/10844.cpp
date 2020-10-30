#include <iostream>

using namespace std;

#define INT_MAX 2147483647

int cache[100][10] = { 0, };
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cache[0][0] = 0;
	for (int i = 1; i < 10; i++)
	{
		cache[0][i] = 1;
	}

	for (int i = 1; i < 100; i++)
	{
		cache[i][0] = cache[i - 1][1] % 1000000000;
		for (int j = 1; j < 9; j++)
		{
			cache[i][j] = (cache[i - 1][j - 1] + cache[i - 1][j + 1]) % 1000000000;
		}
		cache[i][9] = cache[i - 1][8] % 1000000000;
	}

	cin >> N;

	int ret = 0;

	for (int i = 0; i < 10; i++)
	{
		ret += cache[N - 1][i];
		ret %= 1000000000;
	}

	cout << ret;

	return 0;
}
