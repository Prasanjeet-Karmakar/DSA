// Check whether the linked list is palindrome or not.
// Approach 1: Create a new reverse linked list and check the values.
// Approach 2: Store the values in an array and check whether the array is palindrome or not.
// Approach 3: Find mid of the array and reverse the linked list after the mid. Now check from starting and the mid for palindrome or not.
// Eg. 1 2 3 3 2 1 = 1 2 3 1 2 3  True
// Eg. 1 2 3 4 5 1 = 1 2 3 1 5 4  False

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

void isPalindrome(Node *&head)
{

    if (head == NULL || head->next == NULL)
    {
        cout << "Palindrome \n";
        return;
    }

    Node *prev = NULL;
    Node *curr = head, *fast = head, *slow = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;

        prev = slow;
        slow = slow->next;
    }
    cout << slow->data << "\n";
    reverse(slow);
    prev->next = slow;
    display(head);
    cout << slow->data << "\n";

    while (slow != NULL)
    {
        if (curr->data != slow->data)
        {
            cout << "Not Palindrome \n";
            return;
        }
        curr = curr->next;
        slow = slow->next;
    }

    cout << "Palindrome \n";
}

int main()
{
    Node *head = NULL, *tail = NULL;
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    isPalindrome(head);
    return 0;
}