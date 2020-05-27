#include <iostream>
#include <cstdio>
#include <math.h>
#include <limits>
#include <vector>
// Level에 따른 Code값 정의
#define ONE		1
#define TWO		86
#define THREE	172
#define FOUR	256
using namespace std;
class Node;
// Code 값이 담긴 배열
int levelArr[4] = { ONE, TWO, THREE, FOUR };
/*
*	최소 변환 비용을 찾기 위해 각 연산의 결과를 저장하는 클래스
*/
class Node {
public:
	// 현재 Node의 Code값과 대조했을 때 최소값이 나오는 이전 노드
	Node *prevNode;
	// Node의 level
	int level;
	// prevNode와 현재 Node의 level을 합산한 값
	int sum;
	Node(int level)
	{
		prevNode = NULL;
		this->level = level;
		sum = 0;
	}
};
/*
*	Node를 level 개수만큼 가지고 있는 클래스
*/
class NodeFloor {
public:
	// 층에 존재하는 Node, level 이 총 4개 있으므로 nodes도 공간 4만큼 할당
	Node *nodes[4];
	// 몇 층의 NodeFloor 인가
	int floor;
	NodeFloor()
	{
		for (int i = 0; i < 4; i++)
		{
			nodes[i] = new Node(i + 1);
		}
	}
};
/*
*	최소 변환 비용으로 압축된 배열의 코드를 출력하는 함수
*	@param N			총 level의 수
*	@param binaryArr	최소 변환 비용으로 압축된 배열
*/
void printBinaryArr(int N, int *binaryArr)
{
	int n = binaryArr[0];
	switch (n)
	{
	case 1:
		printf("00");
		break;
	case 2:
		printf("01");
		break;
	case 3:
		printf("10");
		break;
	case 4:
		printf("11");
		break;
	}
	for (int i = 1; i < N; i++)
	{
		if (binaryArr[i] != n)
		{
			n = binaryArr[i];
			printf("1");
			switch (n)
			{
			case 1:
				printf("00");
				break;
			case 2:
				printf("01");
				break;
			case 3:
				printf("10");
				break;
			case 4:
				printf("11");
				break;
			}
		}
		else
		{
			printf("0");
		}
	}
	printf("\n");
}
/*
*	최소 변환 비용으로 압축된 배열의 코드를 출력하는 함수
*	@param N			총 level의 수
*	@param W			가중치
*	@param inputArr		사용자가 입력한 원본 이미지 픽셀 정보 배열
*	@param nodeFloors	연산 결과를 저장할 NodeFloor 클래스
*	@param floor		현재 층, 함수가 재귀로 작동하므로 끝내기 위해 알아야 할 변수
*/
void convertByLevel(int N, int W, const int* inputArr, vector<NodeFloor> &nodeFloors, int floor)
{
	// 만약 더 이상 층이 없을 경우 함수 종료
	if (floor == N)
		return;
	// 현재 층에 존재하는 4개의 Node 각각의 최소 비용을 계산한다 
	for (int i = 0; i < 4; i++)
	{
		int min = numeric_limits<int>::max();
		int minNodeIdx = 0;
		int compareNum = 0;
		// 이전 층의 4개의 Node에 저장된 최소 비용과 비교한뒤 최소의 비용이 나오는 조합을 찾아 현재 Node에 저장한다
		for (int j = 0; j < 4; j++)
		{
			// 만약 현재 Node와 아래층의 Node의 Level이 같을 경우 0과 에러코드만 더한다
			if (nodeFloors[floor].nodes[i]->level == nodeFloors[floor - 1].nodes[j]->level)
				compareNum = W + abs(inputArr[floor] - levelArr[nodeFloors[floor].nodes[i]->level - 1]);
			// Level이 다른 경우 1을 추가한뒤 Level과 에러코드를 더한다
			else
				compareNum = W * 3 + abs(inputArr[floor] - levelArr[nodeFloors[floor].nodes[i]->level - 1]);
			// 이전 층 까지의 합 새로 생긴 compareNum의 결과 합산
			if (nodeFloors[floor - 1].nodes[j]->sum + compareNum < min)
			{
				min = nodeFloors[floor - 1].nodes[j]->sum + compareNum;
				minNodeIdx = j;
			}
		}
		// 최소 연산의 결과가 나오는 이전 Node를 현재 Node의 prevNode에 저장한다
		nodeFloors[floor].nodes[i]->prevNode = nodeFloors[floor - 1].nodes[minNodeIdx];
		// 연산의 합을 현재 node의 sum에 저장한다
		nodeFloors[floor].nodes[i]->sum = min;
	}
	// 재귀 호출
	convertByLevel(N, W, inputArr, nodeFloors, floor + 1);
}
/*
*	사용자로부터 입력받은 배열을 통해 최소 비용을 구하고 출력한다
*/
void process(int N, int W, const int *inputArr)
{
	// N층의 NodeFloor 초기화
	vector<NodeFloor> nodeFloors = vector<NodeFloor>(N);
	for (int i = 0; i < N; i++)
	{
		nodeFloors.push_back(NodeFloor());
	}
	// 최소 연산을 가진 Node의 인덱스 값
	int minNodeIndex = -1;
	// 최소 연산 비용
	int minCost = numeric_limits<int>::max();
	// 최소 연산 비용을 계산할 가장 아래층의 Node들을 초기화
	for (int i = 0; i < 4; i++)
		nodeFloors[0].nodes[i]->sum = W * 2 + abs(inputArr[0] - levelArr[nodeFloors[0].nodes[i]->level - 1]);
	// 모든 층의 Node 연산
	convertByLevel(N, W, inputArr, nodeFloors, 1);
	// 연산 결과 최소 비용을 가진 Node를 찾아낸다
	for (int i = 0; i < 4; i++)
	{
		int compareNum = nodeFloors[N - 1].nodes[i]->sum;
		if (compareNum < minCost)
		{
			minNodeIndex = i;
			minCost = compareNum;
		}
	}
	// 최소 비용을 가진 Node가 가진 prevNode를 역으로 탐색하며 압축 코드 배열을 만든다
	int *binaryArr = new int[N];
	Node *node = nodeFloors[N - 1].nodes[minNodeIndex];
	for (int i = 0; i < N; i++)
	{
		binaryArr[N - i - 1] = node->level;
		node = node->prevNode;
	}
	// 최소 비용 출력 
	printf("%d\n", minCost);
	// 압축된 코드 배열 출력
	printBinaryArr(N, binaryArr);
}
/*
*	이미지를 압축할 때 드는 최소 변환 비용을 구하는 프로그램
*/
int main()
{
	// N : 이미지 수열의 길이
	// W : 가중치
	int N, W;
	// 사용자로부터 N, W 입력받음
	scanf("%d %d", &N, &W);
	// 사용자로부터 입력받은 배열, N 만큼 할당
	int *inputArr = new int[N];
	// inputArr에 입력 값 넣기
	int input = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &input);
		inputArr[i] = input;
	}
	// 최소 변환 비용 구한 후 출력
	process(N, W, inputArr);
	// 메모리 해제
	delete[] inputArr;
	return 0;
}