#include <stdio.h>
#include <stdlib.h>

struct dnode {            // Defining a node for the doubly linked list
    int data;
    struct dnode* prev;
    struct dnode* next;
};

struct dnode* head = NULL; // Head pointer initialized to NULL

void insatbeg();
void insatend();
void insatpos();
void delbeg();
void delend();
void delpos();
void display();
void search();

void main() {
    int is_running = 1, choice;
    while (is_running) {
        printf("\n\n1. Insert at beginning");
        printf("\n2. Insert at end");
        printf("\n3. Insert at a specific position");
        printf("\n4. Delete first node");
        printf("\n5. Delete last node");
        printf("\n6. Delete node at a specific position");
        printf("\n7. Search for an element");
        printf("\n8. Display list");
        printf("\n9. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insatbeg();
                break;

            case 2:
                insatend();
                break;

            case 3:
                insatpos();
                break;

            case 4:
                delbeg();
                break;

            case 5:
                delend();
                break;

            case 6:
                delpos();
                break;

            case 7:
                search();
                break;

            case 8:
                display();
                break;

            case 9:
                is_running = 0;
                break;

            default:
                printf("Invalid choice\n");
                break;
        }
    }
}

void insatbeg() {
    struct dnode* new = (struct dnode*)malloc(sizeof(struct dnode));
    printf("\nEnter the value to be inserted: \n");
    scanf("%d", &new->data);

    new->prev = NULL;
    new->next = head;
    if (head != NULL) {
        head->prev = new;
    }
    head = new;

    printf("\nNode inserted at beginning\n");
}

void insatend() {
    struct dnode* new = (struct dnode*)malloc(sizeof(struct dnode));
    printf("\nEnter the data to be inserted: ");
    scanf("%d", &new->data);

    new->next = NULL;

    if (head == NULL) {
        new->prev = NULL;
        head = new;
    } else {
        struct dnode* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
        new->prev = current;
    }
    printf("\nNode inserted at the end\n");
}

void insatpos() {
    int p, i = 1;
    printf("\nEnter the position to be inserted: \n");
    scanf("%d", &p);

    struct dnode* new = (struct dnode*)malloc(sizeof(struct dnode));
    printf("\nEnter the data to be inserted: \n");
    scanf("%d", &new->data);

    if (p == 1) {
        new->prev = NULL;
        new->next = head;
        if (head != NULL) {
            head->prev = new;
        }
        head = new;
    } else {
        struct dnode* current = head;
        while (i < p - 1 && current != NULL) {
            current = current->next;
            i++;
        }
        if (current == NULL) {
            printf("\nPosition is out of range\n");
            free(new);
            return;
        }
        new->next = current->next;
        new->prev = current;
        if (current->next != NULL) {
            current->next->prev = new;
        }
        current->next = new;
    }
    printf("Inserted at position: %d\n", p);
}

void delbeg() {
    if (head == NULL) {
        printf("\nList is Empty\n");
    } else {
        struct dnode* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        printf("\nDeleted the first element\n");
    }
}

void delend() {
    if (head == NULL) {
        printf("\nList is Empty\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("\nDeleted the last element\n");
    } else {
        struct dnode* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->prev->next = NULL;
        free(current);
        printf("\nDeleted the last element\n");
    }
}

void delpos() {
    int p, i = 1;
    if (head == NULL) {
        printf("\nList is empty\n");
    } else {
        printf("\nEnter position to delete: \n");
        scanf("%d", &p);
        struct dnode* current = head;
        while (i < p && current != NULL) {
            current = current->next;
            i++;
        }
        if (current == NULL) {
            printf("\nPosition is out of range\n");
            return;
        }
        if (current->prev != NULL) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
        free(current);
        printf("\nDeleted the element at position %d\n", p);
    }
}

void search() {
    int found = -1;
    struct dnode* current = head;
    if (head == NULL) {
        printf("\nThe list is empty\n");
    } else {
        printf("\nEnter the element to be searched: \n");
        int key;
        scanf("%d", &key);
        while (current != NULL) {
            if (current->data == key) {
                found = 1;
                break;
            }
            current = current->next;
        }
        if (found == 1) {
            printf("\nYes, %d is present.\n", key);
        } else {
            printf("\nNo, %d is not present.\n", key);
        }
    }
}

void display() {
    if (head == NULL) {
        printf("\nThe list is empty\n");
    } else {
        struct dnode* current = head;
        printf("\nDoubly Linked List: NULL <- ");
        while (current != NULL) {
            printf("%d", current->data);
            if (current->next != NULL) {
                printf(" <-> ");
            }
            current = current->next;
        }
        printf(" -> NULL\n");
    }
}
