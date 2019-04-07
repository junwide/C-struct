#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0

typedef int ElementType;
typedef int Position;

typedef struct LNode *List;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

//List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�1��ʼ�洢 */
Position BinarySearch(List L, ElementType X);

int main()
{
	List L;
	ElementType X;
	Position P;

	L->Data[1] = 4;

	scanf("%d", &X);
	P = BinarySearch(L, X);
	printf("%d\n", P);

	return 0;
}

Position BinarySearch(List L, ElementType X)
{
	unsigned int Left, Right;
	unsigned int Mid;

	Left = 1;
	Right = L->Last;

	

	for (Mid = (Right + Left) / 2; Left != Mid ; Mid = (Right + Left) / 2)
	{
		

		if (L->Data[Mid] == X)  return Mid;

		else
		{
			if (L->Data[Mid] > X)Right = Mid;
            else Left = Mid;
		}
	}
   
	if (L->Data[Left] == X) return Left;
	if (L->Data[Right] == X) return Right;
	

	return NotFound;
}