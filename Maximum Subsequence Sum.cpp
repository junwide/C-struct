#include <stdio.h>
struct info
{
	int title; /*定义信息结构体，分别包含数列，头和尾巴*/
	int tail;
	int list_number[10002];
};

int result[3];
int allneg=1; //判断是不是负数种混有0 
//way three
int* MaxSubseqSum4(int list_number[], int a, int b, int c);


int main(void)
{
	struct info list_one;
	int *p;
	int length;
	scanf("%d", &length);

	for (int i = 0; i < length; i++)
	{
		scanf("%d", &list_one.list_number[i]);
		if (list_one.list_number[i]==0) allneg=0;
	}

	p = MaxSubseqSum4(list_one.list_number, length, list_one.title, list_one.tail);
	printf("%d %d %d", *p, *(p + 1), *(p + 2));
	return 0;
}

//在线处理
int* MaxSubseqSum4(int list_number[], int a, int title, int tail)
{
	int i;
	int ThisSum, MaxSum;
	

	int title_temp = 0;
	ThisSum = MaxSum = 0;
	title = 0;  tail = a - 1;
	for (i = 0; i < a; i++)
	{
		ThisSum += list_number[i];
		if (ThisSum > MaxSum)
		{
			MaxSum = ThisSum;
			tail = i;
			title = title_temp;
		}

		else if (ThisSum < 0)
		{
			ThisSum = 0;
			title_temp = i + 1;

		}
	}

	if (MaxSum == 0) {
		title = 0;
		tail = a - 1;
		if(allneg==0)
	    {
	       result[1] = 0;
	       result[2] = 0;
	    }
	   else {
	        result[1] = list_number[title];
	        result[2] = list_number[tail];
           }
	}
	else
	{ 
	result[0] = MaxSum;
	result[1] = list_number[title];
	result[2] = list_number[tail];
	}
	return result;
}
