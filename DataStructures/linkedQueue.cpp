#include <iostream>

using namespace std;

template <class t>
class node
{
public:
       t data;
       node<t> *next;
       node()
       {
              data = 0;
              next = NULL;
       }
};
template <class t>
class queue
{
public:
       node<t> *front;
       node<t> *rear;
       queue()
       {
              front = NULL;
              rear = NULL;
       }
       bool isEmpty()
       {
              return front == NULL;
       }

       void enqueu(t newItem)
       {
              node<t> *newNode = new node<t>();
              if (isEmpty())
              {
                     front = newNode;
                     rear = newNode;
              }

              else
              {
                     rear->next = newNode;
                     rear = newNode;
              }
              newNode->data = newItem;
       }
       void display()
       {
              node<t> *temp = front;
              cout << '[';
              while (temp != rear)
              {
                     cout << temp->data << " ";
                     temp = temp->next;
              }
              cout << temp->data;
              cout << ']' << endl;
       }

       void find(t item)
       {
              if (isEmpty())
              {
                     cout << "EMPTY!! QUEUE";
                     return;
              }

              node<t> *temp = new node<t>();
              temp = front;
              int ctr = 0;
              while (temp != rear && temp->data != item)
              {
                     temp = temp->next;
                     ctr++;
              }
              if (temp == rear && temp->data != item)
              {

                     cout << "not found";
              }
              else
              {
                     cout << "found index:" << ctr << "\n";
              }
       }
       void dequeue()
       {
              node<t> *temp = front;
              front = front->next;
              delete temp;
       }
       void deleteValue(t value)
       {
              
        
              
       }
};

signed main()
{
       queue<int> myqueu;
       myqueu.enqueu(12);
       myqueu.enqueu(13);
       myqueu.enqueu(14);
       myqueu.enqueu(15);
       myqueu.enqueu(16);
       myqueu.enqueu(17);
       // myqueu.display();
       // myqueu.find(13);
       // myqueu.dequeue();
       // myqueu.dequeue();
       // myqueu.display();
       // myqueu.deleteValue(16);
       myqueu.display();
}
