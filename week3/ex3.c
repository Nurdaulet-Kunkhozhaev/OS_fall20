#include <stdlib.h>

typedef struct {
    int data;
    struct node * next;
} node;

void print_list(node * head) {
    node * curr = head;

    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

int delete_node(node ** head, int n) {
    int i = 0;
    int result = -1;
    node * curr = *head;
    node * temp_node = NULL;

    for (i = 0; i < n-1; i++) {
        if (curr->next == NULL) {
            return -1;
        }
        curr = curr->next;
    }

    temp_node = curr->next;
    result = temp_node->data;
    curr->next = temp_node->next;
    free(temp_node);

    return result;

}

int main(){

    node node3 = {3, NULL};
    node node2 = {2, &node3};
    node node1 = {1, &node2};
    node *head = &node1;

    printf("Initial linked list:\n");
    print_list(head);
    printf("\n");

    delete_node(&head, 2);
    printf("Linked list after deletion:\n");
    print_list(head);
}
