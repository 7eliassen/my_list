#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node_t;

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

void list_push(node_t * head, int val) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

int list_return_n(node_t * head,int n) {
    node_t * current = head;
    int counter = 0;
    while (counter != n) {
        current = current->next;
        if (current == NULL) {
            return -1;
        }
        counter++;
    }
    return current->val;
}

node_t* create_list(int val) {
    node_t* head = NULL;
    head = (node_t*) malloc(sizeof(node_t));
    head->next = NULL;
    head->val = val;
    return head;
}

int list_insert(node_t * head, int n, int val) {
    if (n == 0) {
        node_t* new_node;
        new_node = (node_t*) malloc(sizeof(node_t));
        new_node->val = head->val;
        new_node->next = head->next;
        head->next = new_node;
        head->val = val;
    }
    else {
        node_t * current = head;
        int counter = 0;
        while (counter != n - 1) {
            current = current->next;
            if (current == NULL) {
                return -1;
            }
            counter++;
        }
        node_t* new_node;
        new_node = (node_t*) malloc(sizeof(node_t));
        new_node->val = val;
        new_node->next = current->next;
        current->next = new_node;
    }
}

int list_remove(node_t *head, int n) {
    node_t * current = head;
        int counter = 0;
        while (counter < n - 1) {
            current = current->next;
            if (current == NULL) {
                return -1;
            }
            counter++;
        }
        node_t* left = current->next->next;
        current->next = left;
}




