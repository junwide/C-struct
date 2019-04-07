#include <stdio.h>

int list_number[100002];
//way one
int MaxSubseqSum1(int list_number[], int a);
//way two
int MaxSubseqSum2(int list_number[], int a);
//way three
int MaxSubseqSum3(int list_number[], int a);
 //use by  MaxSubseqSum3
int DivideAndConquer(int list[], int left, int right); //use by  MaxSubseqSum3
//way four
int MaxSubseqSum4(int list_number[], int a);


int main(void)
{

	unsigned int length;
	scanf("%d", &length);
	
	for (int i = 0; i < length; i++)
	{
		scanf("%d", &list_number[i]);
	}


	printf("%d\n", MaxSubseqSum4(list_number, length));
	return 0;
}

/*暴力遍历法=x^3*/

int MaxSubseqSum1(int list_number[], int a)
{

	int i, j, k;
	int ThisSum, MaxSum = 0;

	for (i = 0; i < a; i++)
	{
		for (j = i; j < a; j++)
		{
			ThisSum = 0;
			for (k = i; k <= j; k++)
			{
				ThisSum += list_number[k];
				if (ThisSum > MaxSum)
					MaxSum = ThisSum;
			}
		}
	}

	return MaxSum;
}

/*改进版x^2*/
int MaxSubseqSum2(int list_number[], int a)
{
	int i, j;
	int ThisSum, MaxSum = 0;

	for (i = 0; i < a; i++)
	{
		ThisSum = 0;
		for (j = i; j < a; j++)
		{
			ThisSum += list_number[j];
			if (ThisSum > MaxSum)
				MaxSum = ThisSum;

		}
	}

	return MaxSum;


}

/*分而治之*/
int MaxSubseqSum3(int list_number[], int a)
{
	return DivideAndConquer(list_number, 0, a - 1);
}
//两边处理
int DivideAndConquer(int list[], int left, int right)
{
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, MaxRightBorderSum;

	int LeftBorderSum, RightBorderSum;
	int center, i;

	if (left == right)
	{
		if (list[left] > 0) return list[left];
		else return 0;
	}

	center = (left + right) / 2;
	//两边的最大
	MaxLeftSum = DivideAndConquer(list, left, center);
	MaxRightSum = DivideAndConquer(list, center + 1, right);

	//跨中线的最大
	MaxLeftBorderSum = 0; LeftBorderSum = 0;
	for (i = center; i >= left; i--)
	{
		LeftBorderSum += list[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}

	MaxRightBorderSum = 0; RightBorderSum = 0;
	for (i = center + 1; i <= right; i++)
	{
		RightBorderSum += list[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}

	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}
//判断
int Max3(int A, int B, int C)
{
	return A > B ? A > C ? A : C : B > C ? B : C;
}

//在线处理
int MaxSubseqSum4(int list_number[], int a)
{
	int i;
	int ThisSum, MaxSum;

	ThisSum = MaxSum = 0;
	for ( i = 0; i < a; i++)
	{
		ThisSum += list_number[i];
		if (ThisSum > MaxSum)MaxSum = ThisSum;

		else if (ThisSum < 0) ThisSum = 0;
	}
	return MaxSum;
}
