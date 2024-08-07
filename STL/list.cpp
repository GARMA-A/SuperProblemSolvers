#include<iostream>
#include<list>
#include<iterator>
using namespace std;








signed main()
{

       list<int> l1;
       l1.push_back(5);
       l1.push_back(4);
       l1.push_back(3);
       l1.push_back(7);
       l1.push_back(12);
       l1.push_back(1);

       //***********************************/
        l1.sort();
       //***********************************/

       //***********************************/
       l1.pop_front();
       //***********************************

       //***********************************/
       l1.pop_back();
       //***********************************/

       //***********************************/
       auto it = l1.begin();
       // move the iterator 0->1->2(move two steps) point on 3rd 
       advance(it,2); 
       // emplace before third position 
       l1.emplace(it, 18);
       //***********************************/
       //***********************************/
       l1.emplace_front(600);
       l1.emplace_back(800);
       //***********************************/
       //***********************************/
       l1.erase(l1.begin());
       //***********************************/
       //***********************************/
       l1.erase(it);
       //***********************************//
       //***********************************//
       l1.erase(l1.begin() , l1.end());
       //***********************************/
       if(l1.empty())
        cout<<"Empty LIST"<<endl;
}



