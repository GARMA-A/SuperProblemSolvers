#include <iostream>

using namespace std;

#define size 5

class stack
{
public:
       int stackArr[size];
       int top;

public:
       stack()
       {
              top = -1;
       }

       bool isEmpty()
       {
              return top == -1;
       }
       bool isFull()
       {
              return top == size - 1;
       }

       int push(int value)
       {
              if (!isFull())
                     stackArr[++top] = value;
              return stackArr[top];
       }
       int peek()
       {
              if (isEmpty())
                     return -1;
              return stackArr[top];
       }
       int pop()
       {
              int deletedItem = 0;
              if (!isEmpty())
              {
                     deletedItem = stackArr[top];
                     stackArr[top--] = 0;
              }
              return deletedItem;
       }
       void display()
       {
              cout << "[ ";
              for (int i = top; i >= 0; i--)
                     cout << stackArr[i] << " ";
              cout << " ]\n";
       }
       int count()
       {
              return top + 1;
       }
    
};


signed main()
{
       stack s;
       s.push(1);
       s.push(2);
       s.push(3);
       s.push(12);
       s.push(5);
       s.display();
       cout << s.isFull()<<"\n";
       s.pop();
       cout << s.peek()<<"\n";
       cout<<s.count();
}
