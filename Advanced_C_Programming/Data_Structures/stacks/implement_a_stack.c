#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Stacks can be implemented with:
- arrays , but there are limitations concerning the given dimension of the array in C
- linked lists, overcome the limitation of fix dimension in the array

*/

struct node
{
    char element;
    struct node *next;
};

typedef struct node Node_t;

struct Stack
{
    Node_t *top; //this will hold the top of the stack which is the last element of the stack as it is ruled by LIFO
};

typedef struct Stack Stack_t;

char pop(Stack_t *stack) ;
char push(Stack_t *stack, char new_value);
char peek(Stack_t *stack);
bool is_empty(Stack_t stack);
void init_stack(Stack_t stack);

int main(void)
{
  Stack_t stack;

  init_stack(stack);

  push(&stack,'g');
  push(&stack,'e');
  push(&stack,'o');

  printf("Is the stack empty? response %d \n", is_empty(stack));

  pop(&stack);

  peek(&stack);

  return 0;
}




char push(Stack_t *stack,char new_value) //(Insert at Top)
{
  Node_t *new_node = (Node_t *) malloc(sizeof(Node_t));

  //verify if the memory was allocated properly on the heap
  if(!new_node)
  {
    printf("The memory could not have been allocated on the heap");
    exit(EXIT_FAILURE);
  }

  new_node->element = new_value;
  new_node->next = stack->top;
  stack->top = new_node;

  return new_value;
}


char pop(Stack_t *stack) // (Remove from Top)
{
   //verify if the stack is not empty, cause if empty one can not pop
   if(stack->top == NULL)
   {
      puts("The stack is empty. One can not pop.");
      exit(EXIT_FAILURE);
   }

   Node_t *temp = stack->top;
   char value_popped = temp->element;
   stack->top = stack->top->next;
   free(temp);
   printf("I removed the value %c from the top.\n", value_popped);

  return value_popped;
}

char peek(Stack_t *stack) //(Look at Top)
{
  //verify if the stack is empty cause an empty stack can not be peeked into
  if(is_empty (*stack))
  {
    puts("The stack is empty. i can not peek on that.");
    exit(EXIT_FAILURE);
  }

  char value_peeked = stack->top->element;
  printf("I peeked at the value %c.\n",value_peeked);
  return value_peeked;
}


bool is_empty(Stack_t stack)
{
   return (stack.top == NULL);
}

void init_stack(Stack_t  stack)
{
  stack.top = NULL;
}
