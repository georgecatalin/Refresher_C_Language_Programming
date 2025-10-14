#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node
{
    char element;
    struct node *next;
};

typedef struct node Node_t;

struct queue
{
    Node_t *front; // points to first element
    Node_t *rear; // points to last element
};

typedef struct queue Queue_t;

bool is_empty(Queue_t queue);
void init_queue(Queue_t *queue); //by passsing a pointer to queue we modify the value of queue inside the function
void enqueue(Queue_t *queue, char new_value); //(insert at rear)
char dequeue(Queue_t *queue); // (remove from front)
char peek(Queue_t *queue); // (view front element)

int main(void)
{
    Queue_t queue;
    init_queue(&queue);

    printf("Is the queue empty? %d \n", is_empty(queue));

    enqueue(&queue,'g');
    enqueue(&queue,'e');
    enqueue(&queue,'o');
 
    printf("Is the queue empty? %d \n", is_empty(queue));

    printf("I have peeked at %c .\n",peek(&queue)); //g
    printf("I shall dequeue %c.\n", dequeue(&queue)); //g
    printf("I shall dequeue %c . \n ", dequeue(&queue)); //e


    return 0;
}

bool is_empty(Queue_t queue)
{
   return (queue.front==NULL);
}


void init_queue(Queue_t *queue)
{
   queue->rear = NULL;
   queue->front = NULL;
}

void enqueue(Queue_t *queue, char new_value)
{
    Node_t *new_node = (Node_t *) malloc(sizeof(Node_t));

    //verify if memory allocation was successful
    if(!new_node)
    {
        printf("Memory allocation did not work for new value %c. \n", new_value);
        exit(EXIT_FAILURE);
    }

    //assign value to the newly added element
    new_node->element = new_value;
    new_node->next = NULL; // the new element will be at the rear, the last element

     
    if (queue->rear == NULL)
    {
        printf("The queue was empty, but i am adding the first new element now.");
        queue->rear = new_node;
        queue->front = queue->rear;
    }
    else
    {
        queue->rear->next=new_node;
        queue->rear = new_node;
    }

    printf("I have enqueued %c at the queue.\n",new_value);
}

char dequeue(Queue_t *queue)
{
   //verify if queue is empty
   if(is_empty(*queue))
   {
    puts("the queue is empty. i can not dequeue from it");
    exit(EXIT_FAILURE);
   }

   //save old front node into temporary
   Node_t *temp = queue->front;

   //extract the value
   char value_dequeued = temp->element;

   //advance front pointer
   queue->front = queue->front->next;

   //fix rear if queue is empty
   if(queue->front == NULL)
   {
    queue->rear == NULL;
   }

   //free old node to prevent memory leaks
   free(temp);

   //return the value
   return value_dequeued;
}

char peek(Queue_t *queue)
{
   //verify if queue is empty
   if(is_empty(*queue))
   {
    puts("The queue is empty, i can not remove from it");
    exit(EXIT_FAILURE);
   }

   return queue->front->element;
}
