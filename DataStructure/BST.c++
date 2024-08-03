#include <iostream>
#include <cctype>
using namespace std;

template <class t>
class node
{
public:
       node<t> *left;
       node<t> *right;
       t name;
       t phoneNumber;

       node()
       {
              left = NULL;
              right = NULL;
       }
};

template <class t>
class BST
{
public:
       node<t> *root;

       BST()
       {
              root = NULL;
       }

       node<t> *pointerInsert(node<t> *r, t name, t number)
       {
              if (r == NULL)
              {
                     node<t> *newNode = new node<t>();
                     newNode->name = name;
                     newNode->phoneNumber = number;
                     r = newNode;
              }
              else if (tolower(name[0]) < tolower(r->name[0]))
              {
                     r->left = pointerInsert(r->left, name, number);
              }
              else
              {
                     r->right = pointerInsert(r->right, name, number);
              }
              return r;
       }

       void insert(t name, t phone)
       {
              root = pointerInsert(root, name, phone);
       }

       void pointerDisplayInOrder(node<t> *r) // left root right
       {
              if (r == NULL)
                     return;
              pointerDisplayInOrder(r->left);
              cout << r->name << ": " << r->phoneNumber << endl;
              pointerDisplayInOrder(r->right);
       }

       void inOrder()
       {
              pointerDisplayInOrder(root);
       }

       void pointerRightRootLeft(node<t> *r)
       {
              if (r == NULL)
                     return;
              pointerRightRootLeft(r->right);
              cout << r->name << ": " << r->phoneNumber << endl;
              pointerRightRootLeft(r->left);
       }

       void rightRootLeft()
       {
              pointerRightRootLeft(root);
       }

       node<t> *searchByNamePointer(node<t> *r, t name)
       {
              if (r == NULL)
              {
                     cout << "Not found!" << endl;
                     return NULL;
              }
              else if (name == r->name)
              {
                     cout << r->name << ": " << r->phoneNumber << endl;
                     return r;
              }
              else if (tolower(name[0]) < tolower(r->name[0]))
              {
                     return searchByNamePointer(r->left, name);
              }
              else
              {
                     return searchByNamePointer(r->right, name);
              }
       }

       void searchByName(t name)
       {
              searchByNamePointer(root, name);
       }

       node<t> *searchByNumberPointer(node<t> *r, t number)
       {
              if (r == NULL)
              {
                     cout << "Not found!" << endl;
                     return NULL;
              }
              else if (number == r->phoneNumber)
              {
                     cout << r->name << ": " << r->phoneNumber << endl;
                     return r;
              }
              else if (tolower(number[0]) < tolower(r->phoneNumber[0]))
              {
                     return searchByNumberPointer(r->left, number);
              }
              else
              {
                     return searchByNumberPointer(r->right, number);
              }
       }

       void searchByNumber(t number)
       {
              searchByNumberPointer(root, number);
       }

       node<t> *findMax(node<t> *r)
       {
              if (r == NULL || r->right == NULL)
                     return r;
              return findMax(r->right);
       }

       node<t> *findMin(node<t> *r)
       {
              if (r == NULL || r->left == NULL)
                     return r;
              return findMin(r->left);
       }

       node<t> *deleteByNamePointer(node<t> *r, t name)
       {
              if (r == NULL)
              {
                     cout << "Not Found!" << endl;
                     return NULL;
              }
              else if (name == r->name)
              {
                     if (r->left == NULL && r->right == NULL) // leaf node
                     {
                            delete r;
                            return NULL;
                     }
                     else if (r->left != NULL && r->right == NULL)
                     {
                            node<t> *temp = r->left;
                            delete r;
                            return temp;
                     }
                     else if (r->right != NULL && r->left == NULL)
                     {
                            node<t> *temp = r->right;
                            delete r;
                            return temp;
                     }
                     else
                     {
                            node<t> *pre = findMax(r->left);
                            r->name = pre->name;
                            r->phoneNumber = pre->phoneNumber;
                            r->left = deleteByNamePointer(r->left, pre->name);
                     }
              }
              else if (tolower(name[0]) < tolower(r->name[0]))
              {
                     r->left = deleteByNamePointer(r->left, name);
              }
              else
              {
                     r->right = deleteByNamePointer(r->right, name);
              }
              return r;
       }

       void deleteByName(t name)
       {
              root = deleteByNamePointer(root, name);
       }
};

signed main()
{
       BST<string> tree;
       tree.insert("girgis", "01278203355");
       tree.insert("fahd", "010215623");
       tree.insert("mohamed", "012464648");
       tree.insert("emad", "123887986");
       tree.insert("hamza", "0257986233");
       tree.insert("memo", "111");
       tree.insert("zezo", "222");
       tree.insert("aba", "1");
       tree.insert("coco", "2");
       tree.inOrder();
       cout << "********************************" << endl;
       tree.deleteByName("emad");
       tree.inOrder();
       return 0;
}
