#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2)
            return ptr1;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main() {

    int n, m;

    printf("Enter size of first list: ");
    scanf("%d", &n);
    printf("Enter elements of first list:\n");
    struct Node* head1 = createList(n);

    printf("Enter size of second list: ");
    scanf("%d", &m);
    printf("Enter elements of second list:\n");
    struct Node* head2 = createList(m);

 

    struct Node* temp1 = head1;
    struct Node* temp2 = head2;
    struct Node* intersection = NULL;

    while (temp2->next != NULL)
        temp2 = temp2->next;
    int found = 0;

    while (temp1 != NULL && !found) {
        struct Node* search = head2;
        while (search != NULL) {
            if (temp1->data == search->data) {
                temp2->next = temp1;  
                found = 1;
                break;
            }
            search = search->next;
        }
        temp1 = temp1->next;
    }

    intersection = findIntersection(head1, head2);

    if (intersection != NULL)
        printf("%d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}