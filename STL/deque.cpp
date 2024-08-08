#include<iostream>
#include<deque>
#include<iterator>

using namespace std;


/*
When to Use deque Instead of vector
When You Need Efficient Front Operations: 
If your use case involves frequent insertions or deletions 
at both the front and back of the container, deque
 might be more suitable.

When You Don’t Need Random Access:
If you don’t require constant-time random access 
to elements and the operations are primarily at the ends,
deque can be a better choice.


In summary, choose deque when you need efficient
operations at both ends and can tolerate slightly
higher memory overhead. Use vector for scenarios 
where fast random access and efficient use of memory
are more important.
*/


signed main()
{
  deque<int> dq;
  dq.push_back(3); // O(1)
  dq.push_front(2);// O(1)
  dq.emplace_back(4);// O(1)
  dq.emplace_front(1);// O(1)
  copy(dq.begin(),dq.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  /***************************************/
  // Use emplace Faster Than Insert
   dq.emplace(dq.begin(), 2); // O(n)
   dq.insert(dq.begin(), 2); // O(n)
   /*********************************/
   // You can Accsess Elements in O(1)
   for (int i; i<dq.size() ;i++)
          cout << dq[i] << " ";
   cout << endl;
   /****************************************/
   //dq.clear(); // Clear The memory Taken BY this Deque
   /*********************************/
   // cout<<dq.back(); // return the value of the last element
   //cout<<dq.front(); // return the value of the front element
   /************************************************/
   
}


