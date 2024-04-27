// Sort 0's, 1's, 2's in Linked List.

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
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }

    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        tail = new Node(data);
        head = tail;
        return;
    }
    Node *temp = new Node(data);
    tail->next = temp;
    tail = tail->next;
}

void display(Node *&head)
{
    if (head == NULL)
    {
        cout << "Empty\n";
        return;
    }
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}

void sortList(Node *&head)
{
    if (head == NULL)
    {
        cout << "Empty\n";
        return;
    }

    if (head->next == NULL)
    {
        return;
    }
    // Linked List contains 2 or more nodes.

    Node *curr = head->next, *last = head, *first = head;
    Node *prev = head;
    // First points at starting node.
    // Last points at end node.
    while (last->next != NULL)
    {
        last = last->next;
    }
    cout << last->data << endl;

    while (curr != NULL)
    {
        Node *temp = curr->next;
        // cout << prev->data << " ";
        // cout << curr->data << " ";
        if (curr->data == 0)
        {
            prev->next = temp;
            curr->next = first;
            first = curr;
        }
        else if (curr->data == 2 && curr->next != NULL)
        {
            prev->next = temp;
            last->next = curr;
            last = curr;
            last->next = curr;
            cout << prev->next->data << " ";
        }
        else
        {
            prev = curr;
        }
        curr = temp;
    }

    head = first;
}

int main()
{
    Node *head = NULL, *tail = head;
    display(head);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 0);
    // insertAtTail(head, tail, 2);
    display(head);
    sortList(head);
    display(head);

    return 0;
}