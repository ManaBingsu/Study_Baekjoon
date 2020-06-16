/*
*   A → B
*   https://www.acmicpc.net/problem/16953
*/

#include <iostream>
using namespace std;
class Node;
// 정답이 들어있는 Node 클래스의 주소 입니다
Node     *resultNode = NULL;
/**
 * 연산의 경우를 담고 있는 Node 클래스 입니다
 * @long    value   연산이 수행된 A의 값
 * @int     depth   연산이 수행된 깊이, 연산 횟수
 * @Node    *left   두 가지 경우 중 2를 곱한 경우의 Node
 * @Node    *right  두 가지 경우 중 10을 곱하고 1을 더한 경우의 Node
 * @Function Constructor
 *      -> Node를 생성합니다
 *      -> 생성한 Node의 value가 target(B) 보다 작을 경우
 *          -> 각각의 연산이 수행 된 Left Node 와 Right Node를 생성합니다
 *      -> 생성한 Node의 value가 target(B) 보다 크거나 같을 경우
 *          -> 만약 value가 target과 같을 경우 resultNode의 주소는 this 입니다
 * @Function getDepth
 *      -> this의 depth 값을 반환합니다
 */
class Node
{
private:
	long    value;
	int     depth;
	Node    *left;
	Node    *right;
public:
	Node(long value, int depth, long target)
	{
		this->value = value;
		this->depth = depth;
		if (value < target)
		{
			this->left = new Node(value * 2, depth + 1, target);
			this->right = new Node(value * 10 + 1, depth + 1, target);
		}
		else
		{
			if (value == target)
				resultNode = this;
		}
	}
	int getDepth()
	{
		return (depth);
	}
};
/**
 * A에 2를 곱하는 연산 또는 맨 끝자리에 1을 추가하는 연산을 반복하여
 * B가 되었을 때 몇 번을 연산하였는지 출력하는 프로그램 입니다
 * 만약 B가 될 수 없는 경우 -1을 출력합니다
 */
int main()
{
	long A;
	long B;
	cin >> A;
	cin >> B;
	Node *init = new Node(A, 1, B);
    // 만약 resultNode 가 존재한다면 해당 depth(연산 횟수)를 출력합니다
	if (resultNode != NULL)
		cout << resultNode->getDepth();
	else
		cout << -1;
	return (0);
}