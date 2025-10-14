/*
A binary tree is a hierarchical data structure where each node has at most two children:
- left child
- right child

Each node usually contains:
-some data
-a pointer to the left child
-a pointer to the right child
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *left_child;
    struct node *right_child;
};



typedef struct node node_t;


node_t *create_node(char this_data)
{
    node_t *new_node = (node_t *) malloc(sizeof(node_t));

    if(!new_node)
    {
        puts("There was an error during the memory allocation");
        exit(EXIT_FAILURE);
    }

    new_node->data = this_data;
    new_node->left_child = NULL;
    new_node->right_child = NULL;

    return new_node;
}


//traversing a binary tree

/*
Intuitive Analogy

Imagine you’re visiting a house (the root) with two rooms (left and right):

Inorder: Visit left room → check main hall → visit right room

Preorder: Check main hall first → then left room → then right room

Postorder: Visit left room → visit right room → check main hall last


*/
 
void inorder(node_t *root)
{
    if(root!=NULL)
    {
        inorder(root->left_child);
        printf("%c\t", root->data);
        inorder(root->right_child);
    }
}

void preorder(node_t *root)
{
    if(root!=NULL)
    {
        printf("%c\t",root->data);
        preorder(root->left_child);
        preorder(root->right_child);
    }
}

void postorder(node_t *root)
{
    if (root!=NULL)
    {
        postorder(root->left_child);
        postorder(root->right_child);
        printf("%c\t",root->data);
    }   
}


int main(void)
{
    node_t *root = create_node('g');
    root->left_child = create_node('e');
    root->right_child = create_node('f');
    root->left_child->left_child = create_node('o');
    root->left_child->right_child = create_node('r');

    //traversing the binary tree
    puts("traversing the binary tree with 'inorder' method");
    inorder(root); // o e r g f

    puts("traversing the binary tree with 'prenorder' method");
    preorder(root); // g e o r f

    puts("traversing the binary tree with 'postorder' method");
    postorder(root); // o e r g f



    return 0;
}