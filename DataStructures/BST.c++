#include <iostream>

using namespace std;


class Node{
public:
       Node *left;
       Node *right;
       int data;
    Node() : left(nullptr), right(nullptr), data(0) {}
    Node(int value) : left(nullptr), right(nullptr), data(value) {}

};

class BST
{

       Node *root;
public:
       BST(): root(nullptr){}
private:
       
       Node* insertHelper(Node *curNode , int value)
       {
              if(curNode==nullptr)
              {
                 return new Node(value);
              }
              else if(curNode->data<=value)
              {
                 curNode->right = insertHelper(curNode->right, value);
              }
              else
              {
                 curNode->left =insertHelper(curNode->left, value);
              }
              return curNode;
       }

       void displayAscendingHelper(Node * curNode)
       {
              if(curNode==nullptr) return ;
              displayAscendingHelper(curNode->left);
              cout << curNode->data << endl;
              displayAscendingHelper(curNode->right);
       }
       void displayDescendingHelper(Node * curNode)
       {
              if(curNode==nullptr)return;
              displayDescendingHelper(curNode->right);
              cout<<curNode->data<<endl;
              displayDescendingHelper(curNode->left);
       }
       Node* searchHelper(Node* curNode , int target)
       {
              if(curNode == nullptr)
                     return nullptr;
              
              if(curNode->data == target)
              {
                         return curNode;
              }
              else if(target>curNode->data)
              {
                     return searchHelper(curNode->right, target);
              }
              return searchHelper(curNode->left, target);
           
       }
       Node * findMinmumHelper(Node *curNode)
       {
              if(curNode==nullptr)
              return nullptr;
              if(curNode->left==nullptr)
                     return curNode;
             return findMinmumHelper(curNode->left);
       }

       Node* deleteHelper(Node* curNode , int target)
       {
              if(curNode == nullptr)
              return nullptr;
              if(curNode->data == target)
              {
                     if(curNode->right == nullptr and curNode->left == nullptr)
                     {
                            delete curNode;
                            return nullptr;
                     }
                     else if(curNode->right == nullptr and curNode->left != nullptr)
                     {
                            Node *temp = curNode->left;
                            delete curNode;
                            return temp;
                     }
                     else if(curNode->right != nullptr and curNode->left==nullptr)
                     {
                            Node *temp = curNode->right;
                            delete curNode;
                            return temp;
                     }
                     else
                     {
                            Node *replace = findMinmumHelper(curNode->right);
                            curNode->data = replace->data;
                            curNode->right = deleteHelper(curNode->right , replace->data);
                     }
              }
              else if(curNode->data<= target)
              {
                     curNode->right = deleteHelper(curNode->right , target);
              }
              else
              {
                     curNode->left = deleteHelper(curNode->left , target);
              }
              return curNode;
       }

void printTreeHelper() {
       // TO DO 
       // i want something like that 
       //             8        
       //         6       12
       //      2    4    7    13 
}

public:
      

       void insert(int value)
       {
              root = insertHelper(root, value);
       }

       void displayAscending()
       {
              displayAscendingHelper(root);
       }
       void displayDescending()
       {
              displayDescendingHelper(root);
       }
       Node* search(int target)
       {
              return searchHelper(root, target);
       }
       Node* findMinmum()
       {
              return findMinmumHelper(root);
       }
       void Delete(int target)
       {
            root = deleteHelper(root, target);
       }
       void printTree()
       {
              printTreeHelper();
       }

    

};

signed main()
{

       BST myTree;
       myTree.insert(1);
       myTree.insert(5);
       myTree.insert(4);
       myTree.insert(13);
       myTree.insert(10);
       myTree.insert(9);
       // myTree.printTree();

       myTree.displayAscending();
}