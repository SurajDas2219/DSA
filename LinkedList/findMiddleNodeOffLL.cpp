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

int findLength(Node *&head)
{
    // O(N)
    int cnt = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

// naive approach
// Time complextiy:O(N+N/2);
// Space Complexity:O(1);
Node *middleOfLL(Node *&head)
{
    Node *temp = head;
    int length = findLength(head);
    int middle = (length / 2) + 1;
    while (temp != nullptr)
    {
        // O(N/2)
        middle--;
        if (middle == 0)
        {
            break;
        }
        temp = temp->next;
    }
    return temp;
}

// Optimal Approach:Tortoise & hare algo
// Time complextiy:O(N/2);
// Space Complexity:O(1);
Node *optimal(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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

    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = convertArrToLL(arr);
    //   head=middleOfLL(head);
    head = optimal(head);
    cout << "The Middle Node of LL is:" << head->data;
    return 0;
}