/*
*   톱니바퀴
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> gear[4];

/**
 * 톱니바퀴를 방향에 따라 돌려줍니다
 * @param num           돌릴 톱니바퀴의 번호
 * @param dir           돌릴 방향
 * @param chainedNum
 *      -> case 0   : 가장 먼저 돌려진 톱니바퀴 입니다
 *      -> case -1  : 왼쪽 톱니바퀴로부터 연쇄적으로 돌려진 톱니바퀴 입니다
 *      -> case 1   : 오른쪽 톱니바퀴로부터 연쇄적으로 돌려진 톱니바퀴 입니다
 *      -> 톱니바퀴가 무한으로 도는 것을 방지하기 위한 매개변수 입니다
 */
void turnGearByDir(int num, int dir, int chainedNum);

/**
 * 사용자로부터 톱니바퀴의 정보와 돌릴 방향을 입력받아
 * 최종적인 톱니바퀴의 방향으로부터 점수를 얻어 출력하는 프로그램 입니다
 */
int main()
{
	for (int i = 0; i < 4; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < 8; j++)
		{
			gear[i].push_back(input[j] - '0');
		}
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		int dir;

		cin >> num;
		cin >> dir;
		turnGearByDir(num - 1, dir, 0);
	}
	int result = 0;
	if (gear[0][0] == 1) result += 1;
	if (gear[1][0] == 1) result += 2;
	if (gear[2][0] == 1) result += 4;
	if (gear[3][0] == 1) result += 8;

	cout << result << endl;
	return (0);
}

void turnGearByDir(int num, int dir, int chainedNum)
{
	int leftNum = num - 1 < 0 ? -1 : num - 1;
	int rightNum = num + 1 > 3 ? -1 : num + 1;

    // 만약 왼쪽 톱니바퀴가 존재하고 그것이 한번 돌려진 경우가 아닌경우 
	if (leftNum != -1 && chainedNum != -1)
	{
        // 극이 다를 경우
		if (gear[num][6] != gear[leftNum][2])
			turnGearByDir(leftNum, dir * -1, 1);
	}
    // 만약 오른쪽 톱니바퀴가 존재하고 그것이 한번 돌려진 경우가 아닌경우 
	if (rightNum != -1 && chainedNum != 1)
	{
        // 극이 다를 경우
		if (gear[num][2] != gear[rightNum][6])
			turnGearByDir(rightNum, dir * -1, -1);
	}
    // 회전 방향에 따라 회전
	if (dir > 0)
	{
		int temp = gear[num][7];
		for (int i = 7; i >= 1; i--)
		{
			gear[num][i] = gear[num][i - 1];
		}
		gear[num][0] = temp;
	}
	else
	{
		int temp = gear[num][0];
		for (int i = 0; i <= 6; i++)
		{
			gear[num][i] = gear[num][i + 1];
		}
		gear[num][7] = temp;
	}
}