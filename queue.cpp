#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
class Queue
{
public:
    Node *front;
    Node *rear;

    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    bool is_Empty()
    {
        return front == NULL;
    }

     void enQueue(int value) {
        Node* newNode = new Node(value);
        if (is_Empty()) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void deQueue()
    {
        if (is_Empty())
        {
            cout << "Queue is empty. you cannot deQueue." << endl;
            return;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            cout << temp->data << "deQueue from Queue." << endl;
            delete temp;
            if (front == NULL)
            {
                rear = NULL;
            }
        }
    }
    void display() {
        if (is_Empty()) {
            cout << "Queue is empty.\n";
        }
        else {
            Node* current = front;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    Queue q;
    q.enQueue(12);
    q.enQueue(14);
    q.enQueue(16);
    q.enQueue(18);

    q.deQueue();
    q.display();

    return 0;
}