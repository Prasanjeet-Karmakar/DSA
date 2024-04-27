// Implementing Singly Linked List.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        if (this->next != NULL)
        {
            this->next = NULL;
        }
        free(next);
    }
};

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtPosition(Node *&head, Node *&tail, int data, int pos)
{
    int count = 1;
    if (pos == 1)
    {
        insertAtHead(head, data);
    }
    else
    {
        Node *currNode = head;
        Node *temp = new Node(data);
        while (count != pos - 1 && currNode != NULL)
        {
            currNode = currNode->next;
            count++;
        }
        if (currNode->next == NULL)
        {
            insertAtTail(tail, data);
            return;
        }
        temp->next = currNode->next;
        currNode->next = temp;
    }
}

void deleteNodeAt(Node *&head, Node *&tail, int pos)
{
    int count = 1;
    Node *currNode = head;
    if (pos == 1)
    {
        cout << head->data << endl;
        head = head->next;
        delete (currNode);
    }
    else
    {
        while (count != pos - 1)
        {
            currNode = currNode->next;
            count++;
        }
        if (currNode->next->next == NULL)
        {
            tail = currNode;
        }
        Node *temp = currNode->next;
        cout << temp->data << endl;
        currNode->next = currNode->next->next;
        delete (temp);
    }
}

void display(Node *&head)
{
    Node *currNode = head;
    while (currNode != NULL)
    {
        cout << (*currNode).data << " ";
        currNode = (*currNode).next;
    }
    cout << "\n";
}

int main()
{
    Node *node1 = new Node(10);
    cout << node1->data << endl;
    Node *head = node1;
    Node *tail = node1;
    // display(head);
    // insertAtHead(head, 20);
    // display(head);
    // insertAtHead(head, 30);
    // display(head);
    insertAtTail(tail, 40);
    display(head);
    insertAtTail(tail, 60);
    display(head);
    insertAtPosition(head, tail, 10, 3);
    display(head);
    insertAtPosition(head, tail, 20, 3);
    display(head);
    insertAtPosition(head, tail, 80, 6);
    display(head);
    insertAtTail(tail, 70);
    display(head);
    insertAtPosition(head, tail, 100, 1);
    display(head);
    deleteNodeAt(head, tail, 1);
    display(head);
    deleteNodeAt(head, tail, 4);
    display(head);
    deleteNodeAt(head, tail, 6);
    display(head);
    cout << tail->data << endl;

    return 0;
}