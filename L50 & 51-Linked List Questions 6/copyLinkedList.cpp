// Copy linked list where each node consists of val, next and arbitrary pointer pointing to any node or NULL.
// Very Important Question.

// Approach 1: Create a clone LL using next pointer and then for every node measure the distance of the arb node from the head and assign it.
// T.C = O(n^2)    S.C = O(1)

// Approach 2: Use Map. Create a clone LL using next pointer and assign the map from old node to new node.
// In second iteration update the random pointer.
// T.C = O(n)      S.C = O(n)

// Approach 3: Changing links. Create a clone LL and insert in between the original linked list.
// Now every original node with point to its clone node and clone node will points to original node next node.
// We can now get the address of new node for random pointer as original->next->arb = original->arb->next.

#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *arb;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->arb = NULL;
    }

    // destructor
    ~Node()
    {
        if (this->next != NULL)
        {
            this->next = NULL;
        }
        if (this->arb != NULL)
        {
            this->arb = NULL;
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
        if (curr->arb != NULL)
        {
            cout << curr->arb->data;
        }
        curr = curr->next;
        cout << "\n";
    }
}

Node *copyLL(Node *&head)
{
    map<Node *, Node *> visited;
    Node *curr = head;
    Node *ansHead = NULL, *ansTail = NULL;

    // Creating all the nodes with their next as NULL.
    while (curr != NULL)
    {
        Node *temp = new Node(curr->data);
        visited[curr] = temp;
        if (ansTail == NULL)
        {
            ansHead = temp;
            ansTail = ansHead;
        }
        else
        {
            ansTail->next = temp;
            ansTail = temp;
        }

        curr = curr->next;
    }

    // Assigning the arb pointers to respective position.
    Node *curr1 = ansHead;
    curr = head;

    while (curr != NULL)
    {
        if (curr->arb != NULL)
        {
            curr1->arb = visited[curr->arb];
        }

        curr = curr->next;
        curr1 = curr1->next;
    }

    return ansHead;
}

Node *copyLL2(Node *&head)
{

    Node *curr = head;
    Node *ansHead = NULL, *ansTail = NULL;

    while (curr != NULL)
    {
        insertAtTail(ansHead, ansTail, curr->data);
        curr = curr->next;
    }

    // Inserting new list in between nodes of the old list.
    Node *curr1 = ansHead;
    curr = head;

    while (curr != NULL)
    {
        Node *temp1 = curr->next, *temp2 = curr1->next;
        curr->next = curr1;
        curr1->next = temp1;

        curr = temp1;
        curr1 = temp2;
    }
    // Adding random pointers to the node of the cloned linked list.

    curr = head;
    while (curr != NULL)
    {
        if (curr->arb != NULL)
        {
            curr->next->arb = curr->arb->next;
        }

        curr = curr->next->next;
    }

    // Yaha tak sahi h...

    // Removing the links between the old nodes and new Nodes.
    ansHead = NULL, ansTail = NULL;
    curr = head;
    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = curr->next->next;
        if (ansTail == NULL)
        {
            ansHead = temp;
            ansTail = ansHead;
        }
        else
        {
            ansTail->next = temp;
            ansTail = temp;
        }
        ansTail->next = NULL;
        curr = curr->next;
    }

    return ansHead;
}

int main()
{
    Node *head = NULL, *tail = NULL;

    insertAtTail(head, tail, 2);
    Node *tail1 = tail;
    insertAtTail(head, tail, 1);
    Node *tail2 = tail;
    insertAtTail(head, tail, 3);
    Node *tail3 = tail;
    insertAtTail(head, tail, 5);
    Node *tail4 = tail;
    insertAtTail(head, tail, 4);
    Node *tail5 = tail;

    tail2->arb = tail4;
    tail5->arb = tail3;

    // cout << tail1->data << " " << tail2->data << " " << tail3->data << " " << tail4->data << " " << tail5->data << "\n";
    // display(head);

    // Node *head1 = copyLL(head);
    // display(head1);

    Node *ans = copyLL2(head);
    cout << "The new list is: \n";
    display(ans);

    cout << "The old list is : \n";
    display(head);

    return 0;
}