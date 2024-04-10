#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
Node *convertArrToLL(vector<int> &arr)
{

    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
// Iterative way to reverse a LL
// Time Compkexity:O(N);
// Space Complexity:O(1);
Node *reverseLL(Node *&head)
{
    Node *temp = head;
    Node *prev = NULL;
    while (temp != nullptr)
    {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

void printLL(Node *&head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertArrToLL(arr);
    cout << "Before reversing a LL" << endl;
    printLL(head);
    cout << endl;
    head = reverseLL(head);
    cout << "After reversing a LL" << endl;
    printLL(head);
    return 0;
}

/*
OUTPUT:
Before reversing a LL
1 2 3 4 5
After reversing a LL
5 4 3 2 1

*/