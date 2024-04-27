// Two no.s with their digits in different nodes are present.
// Output is the new list containing the digits of the sum.
// lis1 = 3->5->4     lis2 = 5->4
// Sum = 4->0->8

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

void reverse(Node *&head)
{
    Node *curr = head, *prev = NULL;

    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    head = prev;
}

Node *sum(Node *&head1, Node *&head2)
{
    Node *ansHead = NULL;
    int sum = 0, carry = 0;

    Node *curr1 = head1, *curr2 = head2;
    while (curr1 != NULL && curr2 != NULL)
    {
        sum = carry + curr1->data + curr2->data;
        carry = sum / 10;
        sum = sum % 10;
        Node *temp = new Node(sum);
        temp->next = ansHead;
        ansHead = temp;

        // Increasing the nodes.
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    while (curr1 != NULL)
    {
        sum = carry + curr1->data;
        carry = sum / 10;
        sum = sum % 10;
        Node *temp = new Node(sum);
        temp->next = ansHead;
        ansHead = temp;

        curr1 = curr1->next;
    }

    while (curr2 != NULL)
    {
        sum = carry + curr2->data;
        carry = sum / 10;
        sum = sum % 10;
        Node *temp = new Node(sum);
        temp->next = ansHead;
        ansHead = temp;

        curr2 = curr2->next;
    }

    if (carry == 1)
    {
        Node *temp = new Node(carry);
        temp->next = ansHead;
        ansHead = temp;
    }

    return ansHead;
}

Node *sumList(Node *&lis1, Node *&lis2)
{
    Node *head1 = lis1, *head2 = lis2;

    // Reversing the list.
    reverse(head1);
    reverse(head2);
    Node *ans = sum(head1, head2);

    display(ans);
}

int main()
{
    Node *lis1 = NULL, *lis2 = NULL;
    Node *tail1 = NULL, *tail2 = NULL;

    insertAtTail(lis1, tail1, 0);
    insertAtTail(lis1, tail1, 0);
    insertAtTail(lis1, tail1, 1);
    insertAtTail(lis2, tail2, 1);
    insertAtTail(lis2, tail2, 5);
    display(lis1);
    display(lis2);

    sumList(lis1, lis2);

    return 0;
}