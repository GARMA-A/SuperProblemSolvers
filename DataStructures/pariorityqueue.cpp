#include <iostream>
using namespace std;


class Node{
       public:
       int data ;
       Node *next;
       Node()
       {
              data = 0;
              next = nullptr;
       }
};
class Pariorityqueue
{
       public:
              Node *front, *rear;
       Pariorityqueue()
       {
                     front = nullptr;
                     rear = nullptr;
       }

       bool isEmpty()
       {
              return  rear == nullptr;
       }

       void enQueue(int value)
       {
              Node *newNode = new Node();
              newNode->data = value;
              if (isEmpty())
              {
                     front = newNode;
                     rear = newNode;
                     newNode->next = nullptr;
              }
              else if(front->data<=value)
              {
                     newNode->next = front;
                     front = newNode;

              }
              else
              {
                     Node *temp = front;
                     while(temp->next != nullptr and  temp->next->data>=value)
                     {
                            temp  = temp->next;
                     }
                     if(temp->next ==nullptr)
                     {
                            rear->next = newNode;
                            rear = newNode;
                            newNode->next = nullptr;
                     }
                     else
                     {
                             newNode->next  =  temp->next;
                   temp->next = newNode;

                     }
                       
                  

              }
              

       }
       void display()
       {
              Node *temp = front;
              cout << "[ ";
              while(temp != nullptr)
              {
                     cout << temp->data << " ";
                     temp=temp->next;
              }
              cout << "]";
       }
       void deQueue()
       {
              if(isEmpty())
              {
                     cout<<"queue is empty"<<endl;
              }
              else if(front == rear)
              {
                     delete front;
                     front =nullptr;
                     rear = nullptr;
              }
              else
              {
                     Node *temp = front;
                     while(temp->next!=rear and temp->next != nullptr)
                     {
                            temp=temp->next;
                     }
                     delete rear;
                     rear = temp;
                     rear->next=nullptr;
              }
       }


};

signed main()
{
       Pariorityqueue p;
       p.enQueue(8);
       p.enQueue(8);
       p.enQueue(4);
       p.enQueue(4);
       p.enQueue(4);
       p.enQueue(16);
       p.enQueue(16);
       p.enQueue(1);
       p.enQueue(1);
       p.enQueue(1);
       p.deQueue();
       p.deQueue();

       p.display();
}

