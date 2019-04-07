
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10 /*定义常量*/ 


int main(void)
{

	int length;
	printf("input how many number:");
	scanf("%d", &length);

	fflush(stdin);   //清除缓冲区 

	if (length > MAX)
	{
		printf("error: 404");
		return 0;
	}


 
	int n; /*当前处理的字符*/
	int i = 0;/*计数器*/
	int list_number[MAX]; /*存放转换后的数字,大小为常量所定义的*/
	char buf[1024];
	char *p;

	list_number[length] = 0;
	printf("Please input your number:");

	fgets(buf, 1024, stdin);//取一行你的输入


	for (p = strtok(buf, " \t"); p != NULL && i < MAX;) {
		sscanf(p, "%d", &n);
		list_number[i] = n;       /*根据ASCII码把字符转换为数字*/
		++i;
		if ((p = strtok(NULL, " \t\n")) == NULL || i == MAX)
			break;
		/**/

	}


	if (list_number[length] != 0)
	{
		printf("error:202");
		return 0;
	}
 
	return 0;
}


