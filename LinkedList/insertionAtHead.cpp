#include <bits/stdc++.h>
using namespace std;

/*
Problem 2: How to insert a node before head

Steps:
      1-Create a new node with the given data.
      2-newNode-next should point to the head
      3.And Now the head is to be updated as head=newNode

*/

class Node
{

public:
    int data;
    Node *next;

    // Creating Constructor
    Node()
    {
        // When the node is created without any data
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        // When the node is created with any data
        this->data = data;
        this->next = NULL;
    }
};

// Print function to print the linked list

void printLL(Node *&head)
{
    // Step-4
    Node *temp = head; // Because we have to maintain the original address of head
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}

void insertAtHead(Node *&head, int data)
{
    // Step 1;
    Node *newNode = new Node(data);
    // step-2
    newNode->next = head;
    // step-3
    head = newNode;
}

int main()
{

    Node *head = new Node(10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    insertAtHead(head, 50);
    cout << "After Insertion of Nodes at the Head, the final linkedList is :" << endl;
    printLL(head);

    return 0;
}