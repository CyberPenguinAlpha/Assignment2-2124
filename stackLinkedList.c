#include "stackLinkedList.h"

/* createStack
 * input: none
 * output: a pointer to a stack (this is malloc-ed so must be freed eventually!)
 *
 * Creates a new empty stack and returns a pointer to it.
 */
Stack* createStack(){
	
    Stack* ps = (Stack*) malloc(sizeof(Stack));
	
	if(ps == NULL){
		printf("ERROR in 'createStack': null Stack pointer.\n");
		return NULL;
	}
	
	ps->head = NULL;

    return ps;
}

/* freeStack
 * input: a pointer to a stack
 * output: none
 *
 * frees the given stack pointer.  Also call freeStackElements if you want to free every element in the stack.
 */
void freeStack(Stack* ps){
    free(ps);
}

/* freeStackElements
 * input: a pointer to a stack
 * output: none
 *
 * pops and then frees all of the elements currently in the stack.  Does not free the stack itself.  Call freeStack to also free the stack.
 */
void freeStackElements(Stack* ps)
{    
	if(ps == NULL || isEmpty(ps)) return;
	
	Node* temp = ps->head;
	ps->head = ps->head->next;
	
	free(temp->data);
	free(temp);
	
	freeStackElements(ps); //recurses until the stack is completely empty
	
	return;
}

/* pop
 * input: a pointer to a stack
 * output: a string
 *
 * pops and returns the char* stored in the top element in the stack.  It does not free the pop-ed element.
 */
char* pop(Stack* ps)
{	
	if(ps == NULL || isEmpty(ps))
	{
		printf("Tried to pop, but Stack was empty\n");
		return NULL;
	}
	
	Node* temp = ps->head;
	ps->head = ps->head->next;
	
	char* data = temp->data;
	free(temp);
	
	return data;
}

/* push
 * input: a pointer to a stack, a string
 * output: none
 *
 * pushes the string onto the top of the given stack.
 */
void push(Stack* ps, char* str){
    
	Node* temp = (Node*) malloc(sizeof(Node));
	
	temp->next = ps->head;
	temp->data = str;
	
	ps->head = temp;
	
	return;
	
}

/* top
 * input: a pointer to a stack
 * output: a string
 *
 * returns the string on top of the stack
 */
char* top(Stack* ps)
{
	if(ps == NULL || isEmpty(ps))
	{
		printf("Tried to peek at the top of the Stack, but it was empty.\n");
		return NULL;
	}
	
	return ps->head->data;
}

/* isEmpty
 * input: a pointer to a stack
 * output: a boolean
 *
 * returns TRUE if the stack is empty and FALSE otherwise
 */
boolean isEmpty(Stack* ps)
{    
	if(ps == NULL) return TRUE;
	if(ps->head == NULL) return TRUE;
	else return FALSE;
}