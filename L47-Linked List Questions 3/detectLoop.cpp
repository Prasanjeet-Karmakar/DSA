// Detecting cycle in linked list using map.
#include <iostream>
#include <map>
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

void isLoop(Node *&head)
{
    Node *currNode = head;
    if (currNode == NULL)
    {
        cout << "Not circular\n";
        return;
    }

    map<Node *, bool> visited;
    while (currNode != NULL)
    {
        if (visited[currNode] == true)
        {
            cout << "Cycle Present in " << currNode->data << "\n";
            return;
        }

        visited[currNode] = true;
        currNode = currNode->next;
    }
    if (currNode == NULL)
    {
        cout << "No cycle present\n";
    }
}

int main()
{
    Node *head = NULL, *tail = NULL;
    insertNode(head, tail, 10);
    insertNode(head, tail, 60);
    insertNode(head, tail, 40);
    insertNode(head, tail, 20);
    insertNode(head, tail, 30);
    display(head);
    isLoop(head);
    insertCircular(head, 80, 4);
    isLoop(head);

    return 0;
}