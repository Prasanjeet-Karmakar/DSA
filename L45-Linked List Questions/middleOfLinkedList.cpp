// Finding the middle node of a linked list.
// Brute force approach -> first find the length and then divide the length by 2 and then again traverse the list.
// Time Complexity -> O(3n/2) = O(n)
// Optimised Solution -> Using slow and fast pointer approach.
// Fast pointer -> fastPointer = fastPointer->next->next;
// Slow Pointer -> slowPointer = slowPointer->next;
// Time Complexity -> O(n/2) = O(n)

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor.
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertNode(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        tail = head;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        tail = temp;
    }
}

void display(Node *&head)
{
    Node *currNode = head;
    while (currNode != NULL)
    {
        cout << currNode->data << " ";
        currNode = currNode->next;
    }
    cout << endl;
}

int findMiddle(Node *&head)
{
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

int main()
{
    Node *head = NULL, *tail = NULL;

    insertNode(head, tail, 10);
    insertNode(head, tail, 15);
    insertNode(head, tail, 30);
    insertNode(head, tail, 20);
    display(head);
    cout << findMiddle(head) << "\n";

    return 0;
}