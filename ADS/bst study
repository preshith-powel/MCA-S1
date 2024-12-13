#include <stdio.h>
#include <stdlib.h>
void insert();
int display();
void delete();
void search();


struct node {
    int data;
    struct node *left;
    struct node *right;
}*new;
struct node *root = NULL;
int main(){
    int x;
  while (1)
    {

        printf("\nchoose the option\n1.insert\n2.delete\n3.display\n4.search\n5.exit\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            search();
            break;
        case 5:
            return 0;
            break;
        default:
            printf("Invalid choice!!!");
            break;
        }
    }
}
void insert(){
    int n;
     new = (struct node *)malloc(sizeof(struct node));
    printf("enter the element to insert: \n");
    scanf("%d",&n);
    new->data=n;
    new->right=NULL;
    new->left=NULL;
    if(root==NULL)
    {
      root= new;
    }
    else
    {
        struct node *temp=root;
        struct node *parent=NULL;
        while(temp!=NULL){
           parent=temp;
           if(new->data > temp->data)
           {
            temp=temp->right;
           } 
           else
           {
            temp=temp->left;
           }
        }
        if(new->data>parent->data)
        {
            parent->right=new;
        }else{
            parent->left=new;
        }
    }
}

void preOrder(struct node *root) {
    if (root == NULL)
        return;

    printf("%d -> ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
// Left->Root->Right
void inOrder(struct node *root) {
    if (root == NULL)
        return;

    inOrder(root->left);
    printf("%d -> ", root->data);
    inOrder(root->right);
}
// Left->Right->Root
void postOrder(struct node *root) {
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%d -> ", root->data);   
}
int display() {
    if (root == NULL) {
        printf("Tree is empty!\n");
        return 1;
    }

    printf("Preorder: ");
    preOrder(root);
    printf("NULL\nInorder: ");
    inOrder(root);
    printf("NULL\nPostorder: ");
    postOrder(root);
    printf("NULL\n");
    return 0;
}

void deleteNode(int n) {
    struct node *parent = NULL;
    struct node *current = root;
    struct node *temp = NULL;
    int found = 0;

    // Search for the node to be deleted
    while (current != NULL) {
        if (current->data == n) {
            found = 1;
            break;
        }
        parent = current;
        if (n < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (!found) {
        printf("Element not found in the tree.\n");
        return;
    }

    // Case 1: Deleting a leaf node
    if (current->left == NULL && current->right == NULL) {
        if (current == root)
            root = NULL;
        else if (parent->left == current)
            parent->left = NULL;
        else
            parent->right = NULL;
        free(current);
    }
    // Case 2: Deleting a node with one child
    else if (current->left == NULL || current->right == NULL) {
        if (current->left != NULL)
            temp = current->left;
        else
            temp = current->right;

        if (current == root)
            root = temp;
        else if (parent->left == current)
            parent->left = temp;
        else
            parent->right = temp;
        free(current);
    }
    // Case 3: Deleting a node with two children
    else {
        struct node *succParent = current;
        struct node *succ = current->right;

        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }

        current->data = succ->data;
        if (succParent->left == succ)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
        free(succ);
    }
}


void delete() {
    int x;
    printf("Enter the element to be deleted: ");
    scanf("%d", &x);
    deleteNode(x);
}

void search()
{
  int x,found=0;
  struct node *current = root;
  struct node *parent = NULL;
  printf("Enter the element to search: ");
  scanf("%d",&x);
  
      while (current != NULL) {
        if (current->data == x) {
            found = 1;
            break;
        }
        parent = current;
        if (x < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (found) {
        printf("Element found in the tree.\n");
        return;
    }
    else{
        printf("Element not found in the tree.\n");
        return;
    }
    
}
