#include <iostream>

using namespace std;

#define size 5

class queue
{
public:
       int queueArr[size];
       int front;
       int rear;

public:
       queue()
       {
              front = -1;
              rear = -1;
       }

       bool isFull()
       {
              return ((rear + 1) % size == front);
       }
       bool isEmpty()
       {
              return rear == -1;
       }

       int enQueue(int value)
       {

              if (isEmpty())
              {
                     queueArr[++rear] = value;
                     ++front;
              }
              else if (!isFull())
              {
                     rear = (rear + 1) % size;
                     queueArr[rear] = value;
                     return queueArr[rear];
              }

              return 0;
       }

       int deQueue()
       {
              if (isEmpty())
              {
                     return 0;
              }
              else if (front == rear)
              {
                     rear = -1;
                     front = -1;
              }
              else
              {
                     front = (front + 1) % size;
              }

              return queueArr[front];
       }

       void display()
       {
              int cur = front;
              cout << "[";
              while (cur != rear)
              {
                     cout << queueArr[cur] << " ";
                     cur = (cur + 1) % size;
              }
              cout << queueArr[cur] << "]\n";
             
       }
};

signed main()
{

       queue q;
       q.enQueue(1);
       q.enQueue(2);
       q.enQueue(3);
       q.enQueue(4);
       q.enQueue(5);
       q.display();
       q.enQueue(6);
       q.display();
       q.deQueue();
       q.enQueue(6);
       q.display();
}