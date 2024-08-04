#include <iostream>
using namespace std;

#define size 6

template <class t>
class queue
{

private:
       t arr[size];
       int front;
       int rear;

public:
       queue()
       {
              front = -1;
              rear = -1;
       }

       bool isEmpty()
       {
              return front == -1;
       }

       bool isFull()
       {
              return (rear + 1) % size == front;
       }

       void enqueue(t value)
       {
              if (isFull())
              {
                     cout << "queue is full !";
                     return;
              }
              if (isEmpty())
                     front = 0;

              rear = (rear + 1) % size;
              arr[rear] = value;
       }

       void dequeue()
       {
              if (isEmpty())
              {
                     cout << "queue is empty!";
                     return;
              }
              if (front == rear)
              {
                     front = -1;
                     rear = -1;
              }
              else
              {
                     front = (front + 1) % size;
              }
       }
       void display()
       {
              if (isEmpty())
              {
                     cout << "queue is empty";
                     return;
              }
              int current = front;

              cout << "[";
              while (current != rear)
              {
                     cout << arr[current] << " ";
                     current = (current + 1) % size;
              }
              cout << arr[current];

              cout << "]\n";
       }
};

int main()
{
       queue<int> q;
       q.enqueue(1);
       q.enqueue(2);
       q.enqueue(3);
       q.enqueue(4);
       q.enqueue(5);
       q.enqueue(6);

       q.display();

       q.dequeue();
       q.dequeue();
       q.enqueue(7);
       q.enqueue(8);

       q.display();
}