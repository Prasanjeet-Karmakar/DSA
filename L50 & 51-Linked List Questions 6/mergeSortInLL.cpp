// Implementing Merge Sort in Linked List.

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

Node *findMid(Node *&head)
{
    Node *slow = head, *prev = NULL, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next;
        if (fast->next != NULL)
            fast = fast->next;

        prev = slow;
        slow = slow->next;
    }

    // Removing the link between the prev and curr
    prev->next = NULL;
    // display(head);
    // display(slow);
    return slow;
}

Node *merge(Node *&head, Node *&mid)
{
    Node *curr1 = head, *curr2 = mid;
    Node *ansHead = NULL, *ansTail = NULL;
    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->data <= curr2->data)
        {
            if (ansTail == NULL)
            {
                ansTail = curr1;
                ansHead = ansTail;
            }
            else
            {
                ansTail->next = curr1;
                ansTail = curr1;
            }
            curr1 = curr1->next;
        }
        else
        {
            if (ansTail == NULL)
            {
                ansTail = curr2;
                ansHead = ansTail;
            }
            else
            {
                ansTail->next = curr2;
                ansTail = curr2;
            }
            curr2 = curr2->next;
        }
    }

    while (curr1 != NULL)
    {
        ansTail->next = curr1;
        ansTail = curr1;
        curr1 = curr1->next;
    }

    while (curr2 != NULL)
    {
        ansTail->next = curr2;
        ansTail = curr2;
        curr2 = curr2->next;
    }

    ansTail->next = NULL;

    return ansHead;
}

void mergeSort(Node *&head)
{

    if (head->next == NULL)
    {
        return;
    }

    Node *mid = findMid(head);

    mergeSort(head);
    mergeSort(mid);

    head = merge(head, mid);
}

int main()
{
    Node *head = NULL, *tail = NULL;

    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 6);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 3);
    display(head);

    mergeSort(head);
    display(head);

    return 0;
}