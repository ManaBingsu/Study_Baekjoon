#include <iostream>
#include <cmath>

using namespace std;

int N, M;
int ban[10];

int result = 0;
int comb[11] = { 0, };
int memo[10] = { 0, };

int get_digit(int n) {
	if (n == 0)
		return 1;
	int count = 0;
	while (n != 0) {
		n /= 10;
		count++;
	}
	return count;
}

int get_comb_num() {
	int index = 0;
	for (int i = 0; i < 11; i++) {
		if (comb[i] == -1) {
			index = i;
			break;
		}
	}
	int ret = 0;
	for (int i = 0; i < index; i++) {
		ret += comb[index - i - 1] * pow(10, i);
	}
	return ret;
}

void caculate(int digit) {
	int num = get_comb_num();
	int value = abs(N - num) + digit;
	if (result > value)
		result = value;
}

void mix(int depth, int limit) {
	if (depth >= limit) {
		comb[depth] = -1;
		caculate(limit);
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (ban[i] != 1) {
			memo[i] = 1;
			comb[depth] = i;
			mix(depth + 1, limit);
			memo[i] = 0;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int num = 0;
		cin >> num;
		ban[num] = 1;
	}
	result = abs(N - 100);
	int digit = get_digit(N);
	if (digit != 1)
		mix(0, digit - 1);
	mix(0, digit);
	if (digit != 6)
		mix(0, digit + 1);
	cout << result << "\n";
	return 0;
}
