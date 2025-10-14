#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node
{
   char element;
   struct node *next;

};

typedef struct node node_t;

typedef node_t *ListNodePtr;


 /*protototypes of function associated to this abstract data type*/

 

 void insert(ListNodePtr *head, char new_value); //  void insert(node_t **head, char new_value)


/*
The reason the function uses `ListNodePtr *head` instead of just `ListNodePtr head` is to allow the function to modify the actual head pointer of
the linked list.

- `ListNodePtr` is a pointer to a node (`node_t *`).
- If you pass `ListNodePtr head`, the function receives a copy of the pointer. Changes to this pointer inside the function do **not** affect 
the original head pointer in the calling function.
- By passing `ListNodePtr *head`, you are passing a pointer to the head pointer (i.e., a pointer to a pointer). 
This allows the function to update the head pointer itself, such as when inserting a new node at the beginning of the list.

This is necessary for operations that may change the head of the list, like inserting at the front. 

If you only need to traverse or read the list, you can use `ListNodePtr head`. 
But if you need to modify the head pointer, you must use `ListNodePtr *head`.
 
 
 
 */

 ListNodePtr create_new_node(char new_value);
 void insert_node(ListNodePtr *head, char new_value);
 void insert_at_end(ListNodePtr *head, char new_value);
 void insert_at_beginning(ListNodePtr *head, char new_value);
 void delete(ListNodePtr *head, char new_value);
 void delete_at_beginning(ListNodePtr *head, char new_value);
 bool is_empty(ListNodePtr head);
 void print_list(ListNodePtr this_node);

 int main(void)
 {
    ListNodePtr head = NULL;

    if(is_empty(head))
    {
        puts("The list is empty.");
    }
    else
    {
        puts("The list is not empty");
    }

    insert_at_beginning(&head, 'a'); // list is now a ->NULL
    insert_at_beginning(&head, 'b'); // list is now b->a->NULL
    insert_at_beginning(&head, 'c'); // list is now c->b->a->NULL
    insert_node(&head, 'd');

    print_list(head);

    if(is_empty(head))
    {
        puts("The list is empty.");
    }
    else
    {
        puts("The list is not empty");
    }

    delete(&head,'d');
    print_list(head);

    delete_at_beginning(&head, 'c');
    print_list(head);

    return 0;
 }



ListNodePtr create_new_node(char new_value)
{
    ListNodePtr new_node = (ListNodePtr) malloc(sizeof(node_t));

    new_node->element = new_value;
    new_node->next = NULL;

    return new_node;
}

 void insert_node(ListNodePtr *head, char new_value)
 {
    ListNodePtr new_node = create_new_node(new_value);

    if(*head == NULL) // the list is empty
    {
        *head = new_node;
        return;
    }

     //traverse to the last node
     ListNodePtr temp = *head;
     while (temp->next != NULL)
     {
        temp= temp->next;
     }
     
     temp->next = new_node;
 }



 void insert_at_beginning(ListNodePtr *head,char new_value)
 {
    ListNodePtr new_node = (ListNodePtr) malloc(sizeof(node_t));

    new_node->element = new_value;
    new_node->next = *head;
    *head = new_node;
 }

 void print_list(ListNodePtr this_node)
 {
    ListNodePtr current_node = this_node;
    while (current_node!=NULL)
    {
        printf("The element of the list is %c \n", current_node->element);
        current_node=current_node->next;
    }
 }

 bool is_empty(ListNodePtr this_node)
 {
    return (this_node == NULL);
 }

  void delete(ListNodePtr *head, char new_value)
  {
     if(*head ==NULL)
     {
        printf("The list is empty , i can not delete anything.");
        return;
     }

     ListNodePtr temp = *head;
     ListNodePtr prev = NULL;


     //case 1 new_value is in the head node (first node)
     if (temp!=NULL && temp->element == new_value)
     {
        *head = temp->next;
        free(temp);
        printf("Deleted the element %c from the list \n", new_value);
        return;
     }
     
     //traverse the linkedlist to search for the value to be removed
     while (temp!=NULL && temp->element != new_value)
     {
        prev = temp;
        temp = temp->next;
     }

     //case if the value was not found in the linkedlist
     if(temp == NULL)
     {
        printf("The value %c was not found in the linked list.\n", new_value);
        return;
     }
     
     //case if the value was found, out of the while loop now
     prev->next = temp->next;
     free(temp);
     printf("I have deleted the value %c from the linked list. \n", new_value);

  }

  void delete_at_beginning(ListNodePtr *head, char new_value)
  {
     ListNodePtr temp = *head;

     if(temp !=NULL && temp->element == new_value)
     {
        printf("I found the value %c at the beginning of the linked list and I deleted it\n",new_value);
        *head = (*head)->next;
        free(temp);
        return;
     }

  }


  /*
  
  Got it 👍 — that line is the heart of **removing a node** in a singly linked list, so let’s slow down and make it crystal clear.

---

### Picture the Linked List

Imagine you have a linked list like this:

```
head -> [10 | *] -> [20 | *] -> [30 | *] -> NULL
```

Each box is a node:

* Left part = data (10, 20, 30)
* Right part = pointer to next node (`*`)

Now suppose you want to delete `20`.

---

### Traversal

When we loop, we keep two pointers:

* `temp` = current node we are looking at (here it will point to the node with `20`).
* `prev` = the node just before `temp` (so for `20`, `prev` points to the node with `10`).

So, just before deletion:

```
prev -> [10 | *] -> [20 | *] -> [30 | *] -> NULL
         ↑             ↑
        prev          temp
```

---

### The Key Step

We want to **unlink** the node `20`.
That means:

* Instead of `prev->next` pointing to `temp` (20),
* We make `prev->next` point to `temp->next` (30).

Code:

```c
prev->next = temp->next;
```

After this assignment, the chain looks like:

```
prev -> [10 | *] ---------> [30 | *] -> NULL
                       (20 is no longer in the chain)
```

Node `20` is now **orphaned** — nothing points to it anymore.
So the last step is:

```c
free(temp);
```

to release its memory.

---

✅ **Summary of that line**

* `prev->next` means "the link inside the previous node."
* `temp->next` means "the link inside the node we’re deleting."
* Assigning `prev->next = temp->next` **skips over the node being deleted**.

---

👉 Do you want me to draw this step-by-step with ASCII diagrams for **head deletion**, **middle deletion**, and **last node deletion**? That way you’ll see how the pointer rewiring changes in each case.

  
  */