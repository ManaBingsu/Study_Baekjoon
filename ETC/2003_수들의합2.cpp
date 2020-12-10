#include <iostream>

using namespace std;

int N, M;
int input[10000];
int counter = 0;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	int start = 0, end = 0, result = 0;
	while (start < N) {
		result = 0;
		for (int i = start; i <= end; i++) {
			result += input[i];
		}
		if (result >= M) {
			counter = result == M ? counter + 1 : counter;
			start++;
		}
		else{
			if (end + 1 < N)
				end++;
			else
				start++;
		}
	}
	cout << counter << "\n";
	return 0;
}
