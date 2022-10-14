#ifndef _stackArray_h
#define _stackArray_h
#include <stdlib.h>
#include <stdio.h>

typedef enum boolean { FALSE, TRUE } boolean;

typedef struct Node{
	
	char* data;
	struct Node* next;
	
} Node;

typedef struct Stack{
	
  Node* head;  	
} Stack;

Stack* createStack();
void freeStack( Stack *ps );
void freeStackElements( Stack *ps  );

char* pop( Stack *ps );
void push( Stack *ps, char *str );
char*top ( Stack *ps );

boolean isEmpty( Stack *ps );

#endif