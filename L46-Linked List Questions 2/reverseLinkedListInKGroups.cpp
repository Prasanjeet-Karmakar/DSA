// Reversal of elements in linked list in groups of k.
// 1->2->3->4->5 and k = 2
// Output: 2->1->4->3->5.

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

Node *reverseK(Node *head, int k)
{
    Node *currNode = head, *prev = NULL;

    // Base condition.
    if (currNode == NULL)
    {
        return NULL;
    }
    int count = 0;
    while (count < k && currNode != NULL)
    {
        Node *temp = currNode->next;
        currNode->next = prev;
        prev = currNode;
        currNode = temp;
        count++;
    }

    head->next = reverseK(currNode, k);
    return prev;
}

Node *reverseInGroup(Node *&head, int k)
{
    // Solve 1 case and recursion will handle the rest.
    Node *currNode = head;
    head = reverseK(currNode, k);

    return head;
}

int main()
{
    Node *head = NULL, *tail = NULL;

    insertNode(head, tail, 10);
    insertNode(head, tail, 15);
    insertNode(head, tail, 30);
    insertNode(head, tail, 20);
    insertNode(head, tail, 25);
    insertNode(head, tail, 40);
    display(head);
    Node *newHead = reverseInGroup(head, 4);
    display(newHead);

    return 0;
}