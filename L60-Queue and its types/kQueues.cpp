// Implement queues in an array.

#include <iostream>
using namespace std;

class KQueue
{
public:
    int *arr;
    int *front;
    int *rear;
    int size;
    int K;
    int *next;
    int freeBlock;

public:
    KQueue(int n, int k)
    {
        this->size = n;
        this->K = k;
        arr = new int[size];
        front = new int[K];
        rear = new int[K];
        freeBlock = 0;
        next = new int[size];

        for (int i = 0; i < K; i++)
        {
            front[i] = rear[i] = -1;
        }

        for (int i = 0; i < n - 1; i++)
        {
            next[i] = i + 1;
        }
        next[n] = -1;
    }

    void push(int data, int m)
    {

        if (freeBlock == -1)
        {
            cout << "Queue is Full\n";
            return;
        }

        int index = freeBlock;
        freeBlock = next[freeBlock];

        // If queue has 0 elements.
        if (front[m - 1] == -1)
        {
            front[m - 1] = rear[m - 1] = index;
        }
        // If queue has 1 or more elements.
        else
        {
            next[rear[m - 1]] = index;
            rear[m - 1] = index;
            next[index] = -1;
        }

        arr[rear[m - 1]] = data;
    }

    void pop(int m)
    {
        if (rear[m - 1] == -1)
        {
            cout << "Queue is Empty \n";
            return;
        }
    }

    void display(int m)
    {
        if (front[m - 1] == -1)
        {
            cout << "Stack is empty \n";
            return;
        }

        int i = front[m - 1];
        while (i != -1)
        {
            cout << arr[i] << " ";
            i = next[i];
        }
        cout << endl;
    }
};

int main()
{

    int n, k;
    cin >> n >> k;

    KQueue q(n, k);
    q.push(20, 1);
    q.push(50, 1);
    q.push(10, 1);
    q.push(30, 1);
    q.display(1);

    return 0;
}