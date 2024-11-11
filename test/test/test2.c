
#include "test.h"


void SeqListInit(SL* p)
{
	p->a = NULL;
	p->capacity = 0;
	p->size = 0;

}
void TestSeqlist1()
{
	SL s1;
	SeqListInit(&s1);

}
void SeqListPushBack(SL* p, int  x)
{
	if (p->size == p->capacity)
	{
		int newcapacily = p->capacity == 0 ? 4 : p->capacity * 2;
		int* tmp = (int*)realloc(p->a, newcapacily * sizeof(int));
		if (tmp == NULL)
		{
			printf("ÉêÇëÊ§°Ü\n");
			exit(-1);
		}
		p->a = tmp;
		p->capacity = newcapacily;
	}
	p->a[p->size] = x;
	p->size++;

}
void DEL(SL* p)
{
	p->size--;
	p->a[p->size] = 0;
	p->size++;
}
void SeqListPrintf(SL* p)
{
	p->size--;
	for (int i = 0;i < p->size;i++)
	{
		printf("%d ", p->a[i]);

	}
	printf("\n");
	p->size++;
}
void SeqListPushFront(SL* p, int n, int x)
{
	if (p->size == p->capacity)
	{
		int newcapacily = p->capacity == 0 ? 4 : p->capacity * 2;
		int* tmp = (int*)realloc(p->a, newcapacily * sizeof(int));
		if (tmp == NULL)
		{
			printf("ÉêÇëÊ§°Ü\n");
			exit(-1);
		}
		p->a = tmp;
		p->capacity = newcapacily;
	}
	p->a[p->size] = x;
	p->size++;
	int end = p->size - 1;
	while (end >= n)
	{
		p->a[end + 1] = p->a[end];
		end--;
	}
	p->a[n] = x;
	
}
void SLPopLast(SL* p)
{
	for (int i = 1;i < p->size;i++)
	{
		p->a[i-1] = p->a[i];
	}
	p->size--;
}
int main()
{
	SL s1;
	SeqListInit(&s1);

	SeqListPushBack(&s1, 1);

	SeqListPushBack(&s1, 2);


	SeqListPrintf(&s1);
	SeqListPushFront(&s1, 0, 5);
	SeqListPushFront(&s1, 0, 5);
	SeqListPushFront(&s1, 1, 4);
	SeqListPrintf(&s1);
	SLPopLast(&s1);
	printf("%d", s1.size);
	SeqListPrintf(&s1);
	return 0;

}