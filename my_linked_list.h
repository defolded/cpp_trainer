#include <iostream>

struct Node {
    int data;
    struct Node *next;
};

void push(struct Node** head, int node_data) {
    auto* newNode = new Node;

    newNode->data = node_data;

    newNode->next = (*head);

    (*head) = newNode;
}

void insertBack(struct Node* prev_node, int node_data) {
    if (prev_node == NULL) {
        std::cout << "the given previous node is required,cannot be NULL";
        return;
    }


    auto* newNode =new Node;

    newNode->data = node_data;

    newNode->next = prev_node->next;

    prev_node->next = newNode;
}

void append(struct Node** head, int node_data) {
    auto* newNode = new Node;

    struct Node *last = *head;

    newNode->data = node_data;

    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
}

void print(struct Node *node) {
    while (node != NULL) {
        std::cout<<node->data<<"-->";
        node = node->next;
    }

    if(node== NULL)
        std::cout<<"null";
}