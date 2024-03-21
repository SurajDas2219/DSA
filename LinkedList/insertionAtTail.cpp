#include <bits/stdc++.h>
using namespace std;

/*
Problem 2: How to insert at a tail

Steps:
      1-Create a new node with the given data.
      2-tail->next=newNode
      3.tail=newNode

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

void insertAtHead(Node *&head, Node *&tail, int data)
{
    // Step 1;
    Node *newNode = new Node(data);
    // step-2
    newNode->next = head;

    if (head == NULL)
    {
        // This is because if both tail n head is NULL
        tail = newNode;
    }
    // step-3
    head = newNode;
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    // Step 1;
    Node *newNode = new Node(data);
    // step-2
    if (tail == NULL)
    {
        // If linkedList is empty
        tail = newNode;
        head = newNode;
    }
    else
    {
        tail->next = newNode;
    }
    // step-3
    tail = newNode;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    insertAtTail(head, tail, 90);
    insertAtHead(head, tail, 100);
    insertAtTail(head, tail, 80);
    insertAtHead(head, tail, 110);
    cout << "After Insertion of Nodes at the Head, the final linkedList is :" << endl;
    printLL(head);

    return 0;
}