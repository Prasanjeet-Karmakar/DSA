// Implementing Circular Singly Linked List.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        this->next = NULL;
    }
};

int len(Node *&head)
{
    if (head == NULL)
        return 0;
    else if (head->next = head)
        return 1;
    else
    {
        int count = 1;
        Node *currNode = head->next;
        while (currNode != head)
        {
            count++;
            currNode = currNode->next;
        }
        return count;
    }
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        head->next = head;
        tail = head;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
        tail->next = head;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        insertAtHead(head, tail, data);
    }
    else
    {
        Node *currNode = new Node(data);
        tail->next = currNode;
        tail = currNode;
        currNode->next = head;
    }
}

void insertAtPos(Node *&head, Node *&tail, int data, int pos)
{
    pos = pos % (len(head) + 1);
    if (pos == 1)
    {
        insertAtHead(head, tail, data);
    }
    else if (pos == len(head) + 1)
    {
        insertAtTail(head, tail, data);
    }
    else
    {
        int count = 1;
        Node *currNode = head;
        while (count < pos - 1)
        {
            currNode = currNode->next;
            count++;
        }
        Node *temp = currNode->next;
        currNode->next = currNode->next->next;
        delete (temp);
    }
}

void display(Node *&head)
{
    if (head->next == head)
    {
        cout << head->data << "\n";
        return;
    }
    else
    {
        cout << head->data << " ";
        Node *currNode = head->next;
        while (currNode != head)
        {
            cout << currNode->data << " ";
            currNode = currNode->next;
        }
        cout << endl;
    }
}

int main()
{

    Node *head = NULL, *tail = NULL;
    int choice, data, pos;

    while (1)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> data;
            insertAtHead(head, tail, data);
            break;
        case 2:
            cin >> data;
            insertAtTail(head, tail, data);
            break;
        case 3:
            cin >> data;
            cin >> pos;
            insertAtPos(head, tail, data, pos);
            break;
        case 7:
            display(head);
            break;
        case 8:
            exit(1);
            break;
        default:
            cout << "Wrong Choice \n";
            break;
        }
    }
    return 0;
}