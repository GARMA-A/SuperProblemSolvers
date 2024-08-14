#include<iostream>
#include<set>



using namespace std;


/*
Represented as
RED BLACK BINARY TREE 
all elements sorted not repeated
SET FOR READ ONLY !


*/ 

signed main()
{
      set<int> s = {8, 1, 5, 6, 2}; // Ascending order
      set<int,greater<int>> s2 = {8, 1, 5, 6, 2}; // Descending order


       set<int>::iterator it = s.begin();
       advance(it, 2);
       cout << *it<<endl; // 5
       // 1 2 5 6 8
       for(int el :s) cout << el<<" ";
       cout << endl;
       /*
        For more Info About this functions see vector.cpp File
        All of them complexity O(1)
        s.begin();
        s.end();
        s.rend();
        s.rbegin();
        s.cbegin();
        s.cend();
        s.crend();
        s.crbegin();
       */
       s.emplace(10); // O(log(n))
       s.erase(s.begin()); // O(log(n))
       auto check = s.find(8); // O(log(n))
       cout << (check == s.end() ? "Not Found" : "Found")<<endl;
       cout << *s.lower_bound(5) << endl; // O(log(n))
       cout << *s.upper_bound(5)<<endl; // O(log(n))
       //output : 2 5 6 8 10 
       for (int el: s) cout << el << " ";

       // INSERT ELEMENTS WITh O(1)
       // NOTE THAT ENSERTION ELEMENTS MUST BE SORTED
       set<string> names;
       set<string>::iterator ptr = names.begin();//O(1)
       ptr = names.emplace_hint(ptr, "EMAD");//O(1)
       ptr = names.emplace_hint(ptr, "GARMA"); //O(1)
       ptr = names.emplace_hint(ptr, "GIRGIS");//O(1)

       
}