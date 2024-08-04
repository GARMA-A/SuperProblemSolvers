#include <iostream>
using namespace std;

template <class t>
class node
{
public:
       t data;
       node<t> *next;
};

template <class t>
class list
{
public:
       node<t> *head;

public:
       list()
       {
              head = NULL;
       }

       bool isEmpty()
       {
              return head == NULL;
       }

       void addFirst(t newValue)
       {
              node<t> *newNode = new node<t>();
              newNode->data = newValue;
              if (isEmpty())
                     newNode->next = NULL;

              else
                     newNode->next = head;

              head = newNode;
       }

       void addBefore(t oldItem, t newItem)
       {
              if (isEmpty())
                     cout << "list is empty !";
              else
              {
                     node<t> *temp = head;
                     while (temp->next != NULL && temp->next->data != oldItem)
                     {
                            temp = temp->next;
                     }
                     if (temp->next == NULL && temp->data != oldItem)
                     {
                            cout << oldItem << " Not found!" << endl;
                     }
                     else
                     {
                            node<t> *newNode = new node<t>();
                            newNode->data = newItem;
                            newNode->next = temp->next;
                            temp->next = newNode;
                     }
              }
       }

       void apend(t oldValue, t newValue)
       {
              if (isEmpty())
                     cout << " list empty !" << endl;
              node<t> *temp = head;

              while (temp != NULL && temp->data != oldValue)
              {
                     temp = temp->next;
              }

              if (temp == NULL)
              {
                     cout << oldValue << " Not Found !" << endl;
              }
              else
              {
                     temp->data = newValue;
              }
       }
       void addLast(t newValue)
       {
              node<t> *newNode = new node<t>();
              if (isEmpty())
              {
                     head = newNode;
              }
              else
              {
                     node<t> *temp = head;
                     while (temp->next != NULL)
                     {
                            temp = temp->next;
                     }
                     temp->next = newNode;
              }
              newNode->data = newValue;
              newNode->next = NULL;
       }

       void deleteFirst()
       {
              if (isEmpty())
                     cout << "list empty !" << endl;
              else
              {
                     node<t> *delptr = head;
                     head = head->next;
                     delete delptr;
              }
       }

       void deleteNode(t nodeValue)
       {
              if (isEmpty())
                     cout << "list empty!" << endl;
              else
              {
                     node<t> *prev = head;
                     while (prev->next->data != nodeValue && prev != NULL)
                     {
                            prev = prev->next;
                     }
                     if (prev == NULL)
                            cout << nodeValue << " Not Found !" << endl;
                     else
                     {
                            node<t> *delptr = prev->next;
                            node<t> *after = delptr->next;
                            prev->next = after;

                            delete delptr;
                     }
              }
       }

       void display()
       {
              if (isEmpty())
                     cout << "list empty !";
              else
              {
                     node<t> *temp = head;
                     cout << '[';
                     while (temp != NULL)
                     {
                            cout << temp->data << " ";
                            temp = temp->next;
                     }
                     cout << "]\n";
              }
       }
};

int main()
{
       list<int> l;
       l.addFirst(10);
       l.addFirst(15);
       l.addFirst(20);
       l.display();

       l.addBefore(15, 17);
       l.display();

       l.apend(10, 12);
       l.display();

       l.addLast(50);
       l.display();

       l.deleteNode(50);
       l.display();
       
       l.addLast(18);
       l.display();
}
