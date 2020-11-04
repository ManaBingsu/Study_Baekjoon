#include <iostream>

using namespace std;

int dp[500][1000];
int input[500][500];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cin >> input[i][j];
		}
	}

	dp[0][0] = input[0][0];

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			dp[i][j] = input[i][j];

			int store[2] = { -1, -1 };
			int count = 0;

			store[0] = j - 1 >= 0 ? dp[i - 1][j - 1] : -1;
			store[1] = j <= i ? dp[i - 1][j] : -1;

			dp[i][j] += store[0] > store[1] ? store[0] : store[1];
		}
	}

	int maxValue = 0;
	for (int i = 0; i < N + 1; i++)
	{
		if (dp[N - 1][i] > maxValue)
			maxValue = dp[N - 1][i];
	}

	cout << maxValue;
	return 0;
}
