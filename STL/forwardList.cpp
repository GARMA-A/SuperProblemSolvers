#include <iostream>
#include <forward_list>
#include <vector>
using namespace std;

/*
List on STL is doubly LinkedList 
forwardList is normally linked list


Complexity of std::forward_list Operations:
Accessing Elements:

Access First Element (front): O(1)
Access Other Elements (by iterating): O(n) — Requires traversing from the beginning of the list.
Insertion Operations:

Insert at Front (push_front): O(1)
Insert After a Given Position (insert_after): O(1) — Assuming you have an iterator pointing to the correct position.
Emplace at Front (emplace_front): O(1)
Emplace After a Given Position (emplace_after): O(1) — Assuming you have an iterator pointing to the correct position.
Deletion Operations:

Remove First Element (pop_front): O(1)
Remove After a Given Position (erase_after): O(1) — Assuming you have an iterator pointing to the correct position.
Remove Elements by Value (remove, remove_if): O(n)
Searching Operations:

Find Element (find, find_if): O(n)
Size Operations:

Size (size): O(n) — std::forward_list does not store its size, so calculating the size requires traversing the list.
Merging and Splicing:

Merge Two Lists (merge): O(n + m) — Merges two sorted lists.
Splice After a Position (splice_after): O(1) — Transfers elements from one forward_list to another.
Sorting:

Sort (sort): O(n log n)
Reversing:

Reverse (reverse): O(n)

*/



signed main()
{

       forward_list<int> fl{1, 2, 3, 4, 5, 6, 7};
       forward_list<int> fl2{10, 20, 30, 40, 50, 60, 70};
       forward_list<int>::iterator it = fl.begin();
       it = next(it , 2); // LIKE advance() output 3
       cout << *it<<"\n";

       // put all fl2 in f1  starting before begin
       fl.splice_after(fl.before_begin(), fl2);
       //output :10 20 30 40 50 60 70 1 2 3 4 5 6 7 
       for(int & it : fl)
       {
              cout << it << " ";
       }
       cout << endl;
       // you  can also define the range 
       fl.splice_after(fl.before_begin(), fl2, fl2.begin() , fl2.end());
       fl.sort(greater<>());
       for (int &it : fl)
       {
              cout << it << " ";
       }
      
}








