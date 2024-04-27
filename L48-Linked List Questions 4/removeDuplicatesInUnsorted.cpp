// Removing duplicate elements in unsorted Linked list.
// Approach 1 : Brute Force -> Compare each node to every other next node in LL. = O(n)
// Approach 2: Sort the Linked List using merge Sort and apply remove duplicates in sorted LL. = O(nlog n + n) = O(log n)
// Approach 3: Using Hash Map. => T.C = O(n) and S.C = O(n)

#include <iostream>
#include <map>
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

void removeDuplicates(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    Node *curr = head;
    map<int, bool> visited;
    while (curr->next != NULL)
    {
        visited[curr->data] = true;
        if (visited[curr->next->data] == true)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete (temp);
        }
        else
        {
            curr = curr->next;
        }
    }
}

int main()
{
    Node *head = NULL, *tail = head;
    display(head);
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 60);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 10);
    display(head);
    removeDuplicates(head);
    display(head);
    return 0;
}