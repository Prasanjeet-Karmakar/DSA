// Reverse the Linked List.

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

void reverseUtil(Node *currNode, Node *prevNode, Node *&head)
{
    if (currNode == NULL)
    {
        head = prevNode;
    }
    else if (currNode->next != NULL)
        reverseUtil(currNode->next, currNode, head);

    currNode->next = prevNode;
}

void reverse(Node *&head)
{
    Node *prevNode = NULL, *currNode = head;
    reverseUtil(currNode, prevNode, head);
}

void reverseIterative(Node *&head)
{
    Node *prev = NULL, *curr = head;

    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}

int main()
{
    Node *head = NULL, *tail = NULL;

    insertNode(head, tail, 10);
    insertNode(head, tail, 15);
    insertNode(head, tail, 30);
    insertNode(head, tail, 20);
    display(head);
    reverse(head);
    display(head);

    reverseIterative(head);
    display(head);

    return 0;
}