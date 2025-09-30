#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert- end
void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(struct Node* head) {
    printf("Roll Numbers in Linked List: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" → ");
        temp = temp->next;
    }
    printf("\n");
}

// Search
void search(struct Node* head, int rollNo) {
    struct Node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == rollNo) {
            printf("Roll number %d found at position %d in the list.\n", rollNo, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Roll number %d not found in the list.\n", rollNo);
}


int main() {
    struct Node* head = NULL;
    insert(&head, 101);
    insert(&head, 102);
    insert(&head, 103);
    insert(&head, 104);
    display(head);

    return 0;
}

