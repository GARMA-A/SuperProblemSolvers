#include <iostream>

using namespace std;

class node
{
public:
       int data;
       node *next;
};

class stack
{
public:
       node *top;

public:
       stack()
       {
              top = NULL;
       }
       bool isEmpty()
       {
              return top == NULL;
       }

       int push(int value)
       {
              node *temp = new node();   // *->top=temp
              temp->next = top;
              top = temp;
              temp->data = value;
              return value;
       }
       void display()
       {

              node *cur = top;
              cout << "[ ";
              while (cur != NULL)
              {
                     cout << cur->data << " ";
                     cur = cur->next;
              }
              cout << "]\n";
       }
       int pop()
       {
              int deletedItem = 0;
              node *dlt = top;
              top = top->next;
              deletedItem = dlt->data;
              delete dlt;
              return deletedItem;
       }
       int peek()
       {
              return top->data;
       }
       int count()
       {
              node *cur = top;
              int count = 0;
              while (cur != NULL)
              {
                     count++;
                     cur = cur->next;
              }
              return count;
       }

       bool found(int value)
       {
              node *cur = top;
              while (cur != NULL && cur->data != value)
              {
                     cur = cur->next;
              }

              return (cur != NULL && cur->data == value);
       }
};

signed main()
{
       stack s;
       s.push(1);
       s.push(2);
       s.push(3);
       s.push(4);
       s.display();
       cout << s.pop() << "\n";
       s.display();
       cout << s.count() << "\n";
     
}