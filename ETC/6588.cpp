/*
* 골드바흐의 추측
* https://www.acmicpc.net/problem/6588
*/

#include <cstdio>
#include <vector>

using namespace std;

// 소인수 분해를 빠르게
class Sieve {
public:
	int maximumValue;
	vector<bool> isPrime;
	Sieve(int maximumValue) {
		this->maximumValue = maximumValue;
		this->isPrime.assign(maximumValue + 1, false);
		this->fillSieve();
	}

	/**
	* 소수인지 여부를 반환한다
	* @param num
	* @return 'num'이 소수라면 true, 그렇지 않으면 false
	*/
	bool isPrimeNumber(int num) const {
		return this->isPrime[num];
	}

	/**
	* isPrime 배열의 값을 채우는 함수
	*/
	void fillSieve() {
		isPrime.assign(this->maximumValue + 1, true); // 처음에는 모두 소수라고 저장한다.
		isPrime[0] = isPrime[1] = false; // 0과 1은 소수가 아니므로
		for (int num = 2; num <= maximumValue; num += 1) {
			// [2, N] 사이의 모든 자연수 num에 대해
			if (isPrime[num] == false) {
				// 이미 소수가 아니라고 체크되었다면 건너 뛴다
				continue;
			}

			// 이 때 num은 소수다
			// 그러므로 num의 모든 배수를 소수가 아니라고 체크한다
			// num보다 작은 k에 대해 mul=num*num으로 표현되는 모든 자연수는 이미 처리되었다
			// 그러므로 mul = num * num 부터만 처리하면 된다. 최대 100만의 제곱까지 --> long long 타입
			for (long long mul = (long long)num * num; mul <= maximumValue; mul += num)
			{
				// [!!] 이 때 mul 에 대해서 mul을 나누는 '최초의 소인수 num'이 등장한다.
				// 이 정보를 저장해두면 소인수 분해를 할 때 유용하다
				int index = (int)mul;
				isPrime[index] = false;
			}
		}
	}
};
/**
* 모든 소수의 정보가 담긴 int 벡터를 반환한다
* @param from
* @param to
* @return 소수의 정보가 담긴 int 벡터
*/
vector<int> getAllPrimeNumbers(int from, int to, const Sieve& sieve) {
	vector<int> primes;

	for (int num = from; num <= to; num += 1) {
		if (sieve.isPrimeNumber(num)) {
			primes.push_back(num);
		}
	}

	return primes;
}

void process(int caseNum, int MAX_VALUE, const vector<int>& primes) {

	int idxL = 0;
	int idxR = 0;
	int result = 0;

	for (; idxL < primes.size(); idxL++)
	{
		result = 0;
		for (idxR = idxL; idxR < primes.size(); idxR++)
		{
			result = primes[idxL] + primes[idxR];
			if (result >= caseNum)
			{
				if (result == caseNum)
				{
					printf("%d = %d + %d\n", caseNum, primes[idxL], primes[idxR]);
					return;
				}
				break;
			}
		}
	}
	printf("Goldbach's conjecture is wrong.\n");
}

/**
* 에라토스테네스의 체를 활용하여 소수를 판별하는 프로그램
*/

int main() {
	const int MAX_VALUE = 1000000;
	Sieve sieve = Sieve(MAX_VALUE);

	vector<int> allPrimeNumbers = getAllPrimeNumbers(0, MAX_VALUE, sieve);
	

	while (true)
	{
		int num;
		scanf("%d", &num);
		if (num == 0)
			break;
		process(num, MAX_VALUE, allPrimeNumbers);
	}

	return (0);
}
