#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // Constructor
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, Node *&tail, int data)
{
    // When LL is beeen empty
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // LL is non empty
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    // When LL is beeen empty
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // LL is non empty
    Node *newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void insertAtPosition(int data, int position, Node *&head, Node *&tail)
{
    // case 1:What if LL is empty;
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // Case 2:Where I have to insert the node at the position 0
    if (position == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }
    // Case 3:I have to insert a node at the middle of the given position node
    // step1:Find the of the prev and current node
    int i = 1;
    Node *prev = head;

    while (i < position && prev->next != NULL)
    {
        prev = prev->next;
        i++;
    }
    Node *curr = prev->next;
    // Step 2:Create a new Node
    Node *newNode = new Node(data);
    // Step 3:
    newNode->next = curr;
    prev->next = newNode;

    // Case 3:What if i have to add a node to last position of the node
    if (curr == NULL)
    {
        tail = newNode; // Update tail if we inserted at the end
    }
}

void printRes(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 77);
    insertAtTail(head, tail, 76);
    insertAtHead(head, tail, 78);
    insertAtTail(head, tail, 75);
    printRes(head);
    cout << endl;
    cout << "head:" << head->data << endl;
    cout << "tail:" << tail->data << endl;
    cout << "After insertion:" << endl;
    insertAtPosition(101, 7, head, tail);
    printRes(head);
    cout << endl;
    cout << "head:" << head->data << endl;
    cout << "tail:" << tail->data << endl;
    return 0;
}