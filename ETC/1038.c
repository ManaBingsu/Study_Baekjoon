/*
* 감소하는 수
* https://www.acmicpc.net/problem/1038
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void getResult(char *numStr, int pick);

int main()
{
	int     n;
	char    *buf;
	long     num;

	scanf("%d", &n);
	num = 0;
	buf = (char *)malloc(sizeof(char) * 11);
	sprintf(buf, "%ld", num);
	for (int i = 0; i < n; i++)
	{

		if (atoi(buf) == -1)
			break;
		getResult(buf, strlen(buf) - 1);
	}
	printf("%s", buf);
	return (0);
}

void getResult(char *numStr, int pick)
{
	int digit = strlen(numStr);

	if (pick == 0)
	{
		if (digit == 10 && numStr[0] == '9')
		{
			sprintf(numStr, "%d", -1);
			return;
		}
		if (numStr[0] == '9')
		{
			long result = 0;
			for (int i = 1; i < digit + 1; i++)
			{
				result += i * (long)pow(10, i);
			}
			sprintf(numStr, "%ld", result);
		}
		else
			numStr[pick]++;
		return;
	}

	if (numStr[pick - 1] <= numStr[pick] + 1)
	{
		numStr[pick] = digit - pick - 1 + '0';
		getResult(numStr, pick - 1);
	}
	else
	{
		numStr[pick]++;
	}
}
