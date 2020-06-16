/*
*   제야의 종
*   https://www.acmicpc.net/problem/18248
*/

#include <iostream>
#include <vector>

using namespace std;

class Human;

int N, M;
vector<Human> humans;

class Human
{
public:
	int distance;
	vector<int> isHear;
	Human()
	{
		this->distance = 0;
		isHear = vector<int>();
	}
};

bool process()
{
	for (int j = 0; j < M; j++)
	{
		int maxDist = 0;
		// 타종 소리 들은 여부에 따라 상대적 거리 늘림
		for (int i = 0; i < N; i++)
		{
			if (humans[i].isHear[j] == 0)
			{
				humans[i].distance += 1;
			}
		}
		// 타종 소리 범위에 따라 최소로 들어야 되는 거리 측정
		for (int i = 0; i < N; i++)
		{
			if (humans[i].isHear[j] == 1 && humans[i].distance > maxDist)
			{
				maxDist = humans[i].distance;
			}
		}
		// 최소로 들어야 되는 거리 안인데도 못들었을 경우 모순
		for (int i = 0; i < N; i++)
		{
			if (humans[i].isHear[j] == 0 && humans[i].distance <= maxDist)
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	cin >> N;
	cin >> M;
	
	humans = vector<Human>();

	for (int i = 0; i < N; i++)
	{
		humans.push_back(Human());
		for (int j = 0; j < M; j++)
		{
			int temp = 0;
			cin >> temp;
			humans[i].isHear.push_back(temp);
		}
	}

	bool isSuccess = process();
	if (!isSuccess)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}