#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
	int full;
	int *array;
	int capacity;
	int in, out;
} Q;
void Make_Q(Q *q);
int Insert_Q(Q *q, int key);
int Pop_Q(Q *q);
void print_all(Q *q);
int Is_empty(Q *q);
int Is_full(Q *q);
int main()
{
	int _capacity;
	int loop = 1;
	Q que;
	que.array = NULL;
	que.full = 0;
	que.in = 0, que.out = 0;
	printf("Q원소개수를 입력 : ");
	scanf("%d", &_capacity);
	que.capacity = _capacity;
	Make_Q(&que);
	while ( loop )
	{
		int key;
		int num;
		printf("insert = 1, pop = 2, print_queue = 3, exit = 4   :  ");
		scanf("%d", &num);
		switch ( num )
		{
			case 1:
				printf("q에넣을 수를 입력하세요 : ");
				scanf("%d", &key);
				printf("\n");
				Insert_Q(&que, key);
				break;
			case 2:
				Pop_Q(&que);
				break;
			case 3:
				print_all(&que);
				break;
			case 4:
				loop = 0;
				break;
			default:
				printf("다시 입력하세요. : ");
		}
	}
	free(que.array);
	return 0;
}


void Make_Q(Q *q)
{
	q->array = (int *)malloc(q->capacity * sizeof(int));
	q->full = 0;
	q->in = 0, q->out = 0;
	printf("Q생성.\n");

}

int Insert_Q(Q *q,int key)
{
	if ( q->full == 1 )
	{
		printf("Q가 꽉찼습니다. \n");
		return 0;
	}
	q->array[q->in] = key;
	q->in += 1;
	q->in = (q->in) % (q->capacity);
	if ( q->in == q->out )
		q->full = 1;
	return 1;
}

int Pop_Q(Q *q)
{
	if ( q->full == 0 && q->in == q->out )
	{
		printf("Q가 비어있습니다.\n");
		return -1;
	}
	int n = q->array[q->out];
	q->array[q->out] = 0;
	q->out += 1;
	q->out = q->out % q->capacity;
	q->full = 0;
	return n;	
}
int Is_empty(Q *q)
{
	return q->full == 0 && q->in == q->out;
}

int Is_full(Q *q)
{
	return q->full == 1 && q->in == q->out;
}
void print_all(Q *q)
{
	int n1 = q->out;
	int n2 = q->in;
	if ( Is_empty(q) )
	{
		printf("Q가 비어있습니다.\n");
		return;
	}
	while ( n1 != n2 )
	{
		printf("%d ",q->array[n1]);
		n1++;
		n1 = n1 % q->capacity;
	}
	printf("\n");
}