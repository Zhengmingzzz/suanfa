#include <stdio.h>
#include <malloc.h>

#define Arrsize 3

typedef struct Node_t{
	int num;
	struct Node_t* next;
}Node;

typedef struct Head_t {
	Node* head;
}Head;

void init(Head* Head_t);
void link(Head* Head_t, int number);
void print(Head head_t);

int main() {
	Head head;

	int a[Arrsize] = { 1,2,3 };
	init(&head);

	for (int i = 0; i < Arrsize; i++) {
		link(&head, a[i]);
	}
	
	//找到中点

	Node* S = head.head->next;
	Node* F = S;

	while (F->next!=NULL && F->next->next != NULL ) {
		S = S->next;
		F = F->next->next;
		
	}

	//后半段逆序
	
	Node* s1 = S;
	Node* s2 = S;
	Node* temp = S;
	if (S->next == NULL) {
		printf("RIGHT");
		return 0;
	}
	if (S->next->next == NULL) {
		s1 = head.head->next;
		S = S->next;
		if (s1->num == S->num) {
			printf("RIGHT");
			return 0;
		}
		else {
			printf("ERROR");
			return 0;
		}
	}
	S = S->next;
	
	 do{
			s1 = S;
			S = S->next;
			s1->next = s2;
			s2 = s1;
	}while (S->next != NULL);
	S->next = s1;
	
	temp->next = NULL;
	/*for (; S->next != NULL; S = S->next) {
		printf("%d ", S->num);
	}*/

	s1 = head.head->next;
	while (s1 != NULL && S != NULL) {
		if (s1->num != S->num) {
			printf("ERROR");
			return 0;
		}
		s1 = s1->next;
		S = S->next;
	}
	printf("RIGHT");
	
	return 0;
}

void init(Head* Head_t) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->num = 0;
	p->next = NULL;

	Head_t->head = p;
}


void link(Head *Head_t,int number) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->num = number;
	p->next = NULL;

	Node* q = Head_t->head;
	for (; q->next!= NULL; q = q->next);
	q->next = p;


}

void print(Head head_t) {
	Node* p = head_t.head->next;
	while (p != NULL) {
		printf("%d ", p->num);
		p = p->next;
	}
}

