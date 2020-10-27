#include <iostream>

using namespace std;

int T;
int zero = 0, one = 0;
int memo[41] = { 0, };

int fibonacci(int n) {

	if (n == 0) {
		zero++;
		return memo[0] = 0;
	}
	else if (n == 1) {
		one++;
		return memo[1] = 1;
	}
	else if (memo[n] != 0)
	{
		return memo[n];
	}
	else {
		return memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	fibonacci(40);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		if (N == 0)
		{
			zero = 1;
			one = 0;
		}
		else
		{
			zero = memo[N - 1];
			one = memo[N];
		}
		cout << zero << " " << one << "\n";
		zero = 0;
		one = 0;
	}
	return 0;
}
