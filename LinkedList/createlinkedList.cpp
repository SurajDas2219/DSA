#include <bits/stdc++.h>
using namespace std;

// Creation of a linked list

// Step-1 create a node
//  Class Node consist of two thing
/*
    1-data in the node
    2-address of the next node i.e a pointer variable to the next node
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

int main()
{

    // Creating node dynamically :-Step 2
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);

    // Connecting the node :-Step-3
    head->next = second;
    second->next = third;
    third->next = fourth;

    cout << "Printing The singly linkedList:" << endl;
    printLL(head);

    return 0;
}