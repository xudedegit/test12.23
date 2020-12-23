#include "stdio.h"
#include "stdlib.h"
typedef struct List
{
	int data; //������
	struct List* next; //ָ����
} List;
void TailCreatList(List* L) //β�巨��������
{
	List* s, * r;//s����ָ�������ɵĽڵ㡣rʼ��ָ��L���ն˽ڵ㡣
	r = L; //rָ����ͷ�ڵ㣬��ʱ��ͷ�ڵ����ն˽ڵ㡣
	for (int i = 0; i < 10; i++) {
		s = (struct List*)malloc(sizeof(struct List));//sָ��������Ľڵ�
		s->data = i; //���½ڵ��������������i
		r->next = s; //��r�������½ڵ�
		r = s; //rָ���ն˽ڵ�
	}
	r->next = NULL; //Ԫ���Ѿ�ȫ��װ������L��
	//L���ն˽ڵ�ָ����ΪNULL��L�������
}
void HeadCreatList(List* L) //ͷ�巨��������
{
	List* s; //������β�巨һ������һ���ն˽ڵ㡣
	L->next = NULL;
	for (int i = 0; i < 10; i++) {
		s = (struct List*)malloc(sizeof(struct List));
		s->data = i;
		s->next = L->next; //��Lָ��ĵ�ַ��ֵ��S;//ͷ�巨��β�巨�Ĳ�֮ͬ����Ҫ�ڴˣ�
		//s��ָ���½ڵ��ָ����nextָ��L�еĿ�ʼ�ڵ�
		L->next = s; //ͷָ���ָ����nextָ��s�ڵ㣬ʹ��s��Ϊ��ʼ�ڵ㡣
	}
}
void DisPlay(List* L)
{ 	//��ӡ�ڵ�
	List* p = L->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
int main()
{
	List* L1, * L2;
	L1 = (struct List*)malloc(sizeof(struct List));
	L2 = (struct List*)malloc(sizeof(struct List));
	HeadCreatList(L1);
	DisPlay(L1);
	TailCreatList(L2);
	DisPlay(L2);
}