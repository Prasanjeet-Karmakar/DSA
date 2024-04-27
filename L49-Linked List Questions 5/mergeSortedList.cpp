// Merge two sorted linked list.

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

Node *solve(Node *first, Node *second)
{
    // First's first is always smaller than the second's first element.

    if (first->next == NULL)
    {
        first->next = second;
        return first;
    }

    Node *curr1 = first, *next = first->next, *curr2 = second;

    while (next != NULL && curr2 != NULL)
    {
        if (curr2->data >= curr1->data && curr2->data <= next->data)
        {
            Node *temp = curr2->next;
            curr1->next = curr2;
            curr2->next = next;
            curr2 = temp;
        }
        curr1 = curr1->next;
        next = curr1->next;
    }

    while (next != NULL)
    {
        curr1->next = next;
        curr1 = next;
        next = next->next;
    }

    while (curr2 != NULL)
    {
        curr1->next = curr2;
        curr1 = curr2;
        curr2 = curr2->next;
    }

    return first;
}

Node *mergeList(Node *list1, Node *list2)
{
    // If list1 is empty..
    if (list1 == NULL)
    {
        return list2;
    }
    // If list2 is empty..
    if (list2 == NULL)
    {
        return list1;
    }

    Node *head = NULL;
    if (list1->data <= list2->data)
    {
        head = solve(list1, list2);
    }
    else
    {
        head = solve(list2, list1);
    }

    return head;
}

int main()
{
    Node *list1 = NULL, *tail1 = NULL, *tail2 = NULL, *list2 = NULL;
    insertAtTail(list1, tail1, 1);
    insertAtTail(list1, tail1, 2);
    insertAtTail(list1, tail1, 3);
    insertAtTail(list2, tail2, 0);
    insertAtTail(list2, tail2, 3);
    insertAtTail(list2, tail2, 4);
    insertAtTail(list2, tail2, 7);
    display(list1);
    display(list2);
    Node *newHead = mergeList(list1, list2);
    display(newHead);

    return 0;
}