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

       for(auto it = l1.begin(); it!=l1.end(); it++)
       {
              cout << *it << " ";
       }
       //***********************************/
        l1.sort();
       //***********************************/
        
       
        cout << "\n-----------------\n";
        for (auto it = l1.begin(); it != l1.end(); it++)
        {
               cout << *it << " ";
       }



       //***********************************/
       l1.pop_front();
       //***********************************/



          cout <<"\n-----------------\n";
       for(auto it = l1.begin(); it!=l1.end(); it++)
       {
              cout << *it << " ";
       }


       //***********************************/
       l1.pop_back();
       //***********************************/



       cout <<"\n-----------------\n";
       for(auto it = l1.begin(); it!=l1.end(); it++)
       {
              cout << *it << " ";
       }


       //***********************************/
       auto it = l1.begin();
       // move the iterator 0->1->2(move two steps) point on 3rd 
       advance(it,2); 
       // emplace before third position 
       l1.emplace(it, 18);
       //***********************************/


       cout <<"\n-----------------\n";
       for(auto it = l1.begin(); it!=l1.end(); it++)
       {
              cout << *it << " ";
       }

       //***********************************/
       l1.emplace_front(600);
       l1.emplace_back(800);
       //***********************************/



       cout <<"\n-----------------\n";
       for(auto it = l1.begin(); it!=l1.end(); it++)
       {
              cout << *it << " ";
       }

       //***********************************/
       l1.erase(l1.begin());
       //***********************************/



       cout <<"\n-----------------\n";
       for(auto it = l1.begin(); it!=l1.end(); it++)
       {
              cout << *it << " ";
       }
       //***********************************/
       l1.erase(it);
       //***********************************/


        cout <<"\n-----------------\n";
       for(auto it = l1.begin(); it!=l1.end(); it++)
       {
              cout << *it << " ";
       }
       //***********************************/
       l1.erase(l1.begin() , l1.end());
       //***********************************/

       
       cout <<"\n-----------------\n";
       if(l1.empty())
        cout<<"Empty LIST"<<endl;
}



