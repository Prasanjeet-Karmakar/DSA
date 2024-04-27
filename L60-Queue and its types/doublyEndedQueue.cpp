// Implement doubly ended queue using array.

#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    Queue(int s)
    {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push_back(int data)
    {
        // Overflow.
        if (front == 0 && rear == size - 1)
        {
            cout << "Queue is Full \n";
            return;
        }

        if (front == -1)
        {
            front = rear = 0;
            arr[front] = data;
        }

        else
        {
            rear = (rear + 1) % size;
            *(arr + rear) = data;
        }
    }

    void push_front(int data)
    {
        // Overflow.
        if (front == 0 && rear == size - 1)
        {
            cout << "Queue is Full \n";
            return;
        }

        if (front == -1)
        {
            front = rear = 0;
        }

        else
        {
            front = (front - 1) % size;
        }

        arr[front] = data;
    }

    int pop_back()
    {
        // Underflow condition.
        if (front == -1)
        {
            cout << "Queue is Empty \n";
            return -1;
        }

        int data = arr[rear];

        // Only one element present in array.
        if (rear == front)
        {
            rear = front = -1;
        }

        else
        {
            rear = (rear - 1) % size;
        }

        return data;
    }

    int pop_front()
    {
        // Underflow Condition.
        if (rear == -1)
        {
            cout << "Queue is Empty \n";
            return -1;
        }

        int val = arr[front];

        // Only one element is present.
        if (rear == front)
        {
            rear = front = -1;
        }

        else
        {
            front = (front + 1) % size;
        }

        return val;
    }

    int peek_front()
    {
        if (front == -1)
        {
            cout << "Queue is Empty \n";
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    int peek_rear()
    {
        if (rear == -1)
        {
            cout << "Queue is Empty \n";
            return -1;
        }
        else
        {
            return arr[rear];
        }
    }

    bool isempty()
    {
        if (front == -1)
            return true;

        else
            return false;
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Queue is Empty \n";
            return;
        }

        int a = front;
        while (a != rear)
        {
            cout << arr[a] << " ";
        }
        cout << arr[rear] << "\n";
    }
};

int main()
{
    Queue q(5);

    cout << q.isempty() << endl;

    q.push_back(10);
    q.push_front(5);

    cout << q.isempty() << endl;

    q.display();

    return 0;
}