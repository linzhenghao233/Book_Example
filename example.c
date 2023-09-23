#include <stdio.h>	//单链表方式的实现
#include <malloc.h>
typedef char ElemType;
typedef struct LNode {	//定义链表节点类型
	ElemType data;
	struct LNode* next;
}LNode, *LinkList;

/* 在带头节点的单链表中第i个位置（从1开始）之后插入元素 */
int ListInsert_L(LinkList head, int i, ElemType e) {
	LinkList p = head;
	LinkList s;
	int j;
	p = p->next;
	
	for (j = 1; j < i; j++) {
		if (p)
			p = p->next;
		else
			break;
	}

	if (!p || i < 1) {
		printf("error!!请输入正确的i值！！\n");

		return 0;
	}
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;	//在当前节点p之后插入节点s
	p->next = s;

	return 1;
}

/* 建立链表，输入元素，用头插法建立带头节点的单链表（逆序）。输入0结束 */
LinkList CreateList_L(LinkList head) {
	ElemType temp;
	LinkList p;
	int ch;

	printf("请输入节点值（输入0结束）：");
	fflush(stdin);		//清除键盘缓冲区
	scanf_s("%c", &temp);
	while (temp != '0') {
		if (('A' <= temp && temp <= 'Z') || ('a' <= temp && temp <= 'z')){
			p = (LinkList)malloc(sizeof(LNode));
			p->data = temp;
			p->next = head->next;
			head->next = p;	//在链表头部插入节点，即头插法
		}
		while ((ch = getchar()) != '\n' && ch != EOF);
		printf("请输入节点值（输入0结束）：");
		//fflush(stdin);
		scanf_s("%c", &temp);
	}
	return head;
}

/* 在带头结点的单链表中删除第i个位置（从1开始）的元素 */
int ListDel_L(LinkList head, int i) {
	LinkList p, tmp;
	int j;
	p = head->next;
	tmp = head;

	for (j = 1; j < i; j++) {
		if (p) {
			p = p->next;
			tmp = tmp->next;
		}
		else
			break;
	}

	if (!p || i < 1) {
		printf("error!!请输入正确的i值！！\n");

		return 0;
	}

	tmp->next = p->next;
	free(p);

	return 1;
}

/* 顺序输出链表的内容 */
void ListPint_L(LinkList head) {
	LinkList p;
	int i = 0;
	p = head->next;

	while (p != NULL) {
		i++;
		printf("第%d个元素是：", i);
		printf("%c\n", p->data);
		p = p->next;
	}
}

int main(void) {
	int i, ch;
	char cmd, e;
	LinkList head;
	head = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;
	CreateList_L(head);
	ListPint_L(head);
	do {
		printf("i,I...插入\n");
		printf("d,D...删除\n");
		printf("q,Q...退出\n");

		do {
			fflush(stdin);
			scanf_s("%c", &cmd);
		} while ((cmd != 'd') && (cmd != 'D') && (cmd != 'q') && (cmd != 'Q') && (cmd != 'i') && (cmd != 'I'));
		
		switch (cmd) {
		case 'i':
		case 'I':
			while ((ch = getchar()) != '\n' && ch != EOF);
			printf("请输入你要插入的数据：");
			fflush(stdin);
			scanf_s("%c", &e);
			printf("请输入你要插入的位置：");
			scanf_s("%d", &i);
			ListInsert_L(head, i, e);
			ListPint_L(head);
			break;
		case 'd':
		case 'D':
			printf("请输入你要删除元素的位置：");
			fflush(stdin);
			scanf_s("%d", &i);
			ListDel_L(head, i);
			ListPint_L(head);
			break;
		}
	} while ((cmd != 'q') && (cmd != 'Q'));
}