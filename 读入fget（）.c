
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10 /*���峣��*/ 


int main(void)
{

	int length;
	printf("input how many number:");
	scanf("%d", &length);

	fflush(stdin);   //��������� 

	if (length > MAX)
	{
		printf("error: 404");
		return 0;
	}


 
	int n; /*��ǰ������ַ�*/
	int i = 0;/*������*/
	int list_number[MAX]; /*���ת���������,��СΪ�����������*/
	char buf[1024];
	char *p;

	list_number[length] = 0;
	printf("Please input your number:");

	fgets(buf, 1024, stdin);//ȡһ���������


	for (p = strtok(buf, " \t"); p != NULL && i < MAX;) {
		sscanf(p, "%d", &n);
		list_number[i] = n;       /*����ASCII����ַ�ת��Ϊ����*/
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


