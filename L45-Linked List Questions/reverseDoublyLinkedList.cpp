// Reversing doubly linked list.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
    }
    else
    {
        Node *currNode = new Node(data);
        currNode->next = head;
        head->prev = currNode;
        head = currNode;
    }
}

void reverseIterative(Node *&head)
{
    Node *prevNode = NULL;
    Node *currNode = head;

    while (currNode != NULL)
    {
        Node *nextNode = currNode->next;
        currNode->next = prevNode;
        currNode->prev = nextNode;
        prevNode = currNode;
        currNode = nextNode;
    }

    head = prevNode;
}

void reverseUtil(Node *&head, Node *currNode, Node *prevNode)
{
    // Base Condition.
    if (currNode == NULL)
    {
        head = prevNode;
        return;
    }

    reverseUtil(head, currNode->next, currNode);
    currNode->prev = currNode->next;
    currNode->next = prevNode;
}

void reverse(Node *&head)
{
    Node *currNode = head, *prevNode = NULL;

    reverseUtil(head, currNode, prevNode);
}

void display(Node *&head)
{
    Node *currNode = head;
    while (currNode != NULL)
    {
        cout << currNode->data << " ";
        currNode = currNode->next;
    }
    cout << "\n";
}

void displayreverse(Node *&head)
{
    Node *currNode = head;
    while (currNode->next != NULL)
    {
        currNode = currNode->next;
    }

    while (currNode != NULL)
    {
        cout << currNode->data << " ";
        currNode = currNode->prev;
    }
    cout << "\n";
}

int main()
{
    Node *head = NULL;
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 17);
    insertAtHead(head, 30);
    display(head);
    reverseIterative(head);
    display(head);
    reverse(head);
    display(head);
    displayreverse(head);

    return 0;
}