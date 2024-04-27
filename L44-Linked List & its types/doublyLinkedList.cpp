// Implementing Doubly linked list in C++.
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        this->next = NULL;
        this->prev = NULL;
    }
};

int len(Node *&head)
{
    int count = 0;
    Node *currNode = head;
    while (currNode != NULL)
    {
        count++;
        currNode = currNode->next;
    }

    return count;
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

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
}

void insertAtTail(Node *&head, int data)
{
    Node *temp = new Node(data);

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        Node *currNode = head;
        while (currNode->next != NULL)
        {
            currNode = currNode->next;
        }
        currNode->next = temp;
        temp->prev = currNode;
    }
}

void insertAtPos(Node *&head, int data, int pos)
{
    if (pos == 1)
    {
        insertAtHead(head, data);
    }
    else
    {
        Node *temp = new Node(data);
        int count = 1;
        if (pos > len(head) + 1)
        {
            pos = pos % len(head) + 1;
        }

        if (pos == len(head) + 1)
        {
            insertAtTail(head, data);
        }
        else if (pos == 1)
        {
            insertAtHead(head, data);
        }
        else
        {
            Node *currNode = head;
            while (count != pos)
            {
                currNode = currNode->next;
                count++;
            }
            temp->next = currNode->next;
            temp->prev = currNode;
            currNode->next->prev = temp;
            currNode->next = temp;
        }
    }
}

void deleteAtHead(Node *&head)
{
    if (head->next == NULL)
    {
        delete (head);
    }
    else
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        delete (temp);
    }
}

void deleteAtTail(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        Node *temp = head;
        head = NULL;
        delete (temp);
    }
    else
    {
        Node *currNode = head;
        while (currNode->next != NULL)
        {
            currNode = currNode->next;
        }
        currNode->prev->next = NULL;
        delete (currNode);
    }
}

void deleteAtPos(Node *&head, int pos)
{
    pos = pos % (len(head) + 1);
    if (pos == 1)
    {
        deleteAtHead(head);
    }
    else if (pos == len(head))
    {
        deleteAtTail(head);
    }
    else
    {
        int count = 1;
        Node *currNode = head;
        while (count < pos)
        {
            currNode = currNode->next;
            count++;
        }
        currNode->prev->next = currNode->next;
        currNode->next->prev = currNode->prev;
        delete (currNode);
    }
}

int main()
{
    int data, pos;
    Node *head = NULL;
    while (1)
    {
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> data;
            insertAtHead(head, data);
            break;

        case 2:
            cin >> data;
            insertAtTail(head, data);
            break;

        case 3:
            cin >> data;
            cin >> pos;
            insertAtPos(head, data, pos);
            break;

        case 4:
            deleteAtHead(head);
            break;

        case 5:
            deleteAtTail(head);
            break;

        case 6:
            cin >> pos;
            deleteAtPos(head, pos);
            break;

        case 7:
            display(head);
            break;

        case 8:
            exit(1);
            break;

        default:
            cout << "Wrong choice\n";
            break;
        }
    }

    return 0;
}