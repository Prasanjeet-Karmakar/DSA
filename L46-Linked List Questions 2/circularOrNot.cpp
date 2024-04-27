// Check whether the linked list is circular or not.
// Initial Approach -> using fast and slow pointer.

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

int len(Node *head)
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

void insertCircular(Node *&head, int data, int k)
{
    if (k > len(head))
    {
        k = k % (len(head) + 1);
    }
    Node *temp = NULL, *currNode = head;
    int count = 0;
    while (currNode->next != NULL)
    {
        if (count == k - 1)
        {
            temp = currNode;
        }
        currNode = currNode->next;
        count++;
    }
    currNode->next = new Node(data);
    currNode->next->next = temp;
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

void checkCircular(Node *head)
{
    if (head == NULL)
    {
        cout << "Not Circular \n";
        return;
    }

    Node *slow = head, *fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (fast != NULL && fast != slow);

    if (fast == slow)
    {
        cout << "Circular"
             << "\n";
    }
    else
    {
        cout << "Not Circular\n";
    }
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
    insertCircular(head, 50, 3);
    checkCircular(head);

    return 0;
}