#include<iostream>
#include<list>
#include<iterator>
using namespace std;



signed main()
{

list<int> l1;
l1.push_back(5);      // O(1) - Constant time to add an element at the end of the list
l1.push_back(4);     
l1.push_back(3);      
l1.push_back(7);      
l1.push_back(12);    
l1.push_back(1);      
l1.push_front(12);   // O(1) - Inserting an element at the front of the list
l1.push_front(6);

/********************/
// Access Elements on list 
list<int>::iterator iter = l1.begin();
advance(iter, 2);  // move to element number 3
*iter = 555;
copy(l1.begin(), l1.end(),ostream_iterator<int>(cout," "));

//***********************************/
l1.sort();            // O(n log n) - Sorting the list (mergesort is typically used for linked lists)
//***********************************/

l1.assign(10, 2); //O(n) reassign all elements in list to value = 2
// size= 10   
copy(l1.begin(), l1.end(),ostream_iterator<int>(cout , " "));

//***********************************/
l1.pop_front();       // O(1) - Removing the first element from the list
//***********************************/

//***********************************/
l1.pop_back();        // O(1) - Removing the last element from the list
//***********************************/
l1.insert(l1.begin(), 2, 10000); // O(n) n= number of elements inserted
l1.emplace(l1.begin(), 20000); // same but emplace faster
l1.emplace(l1.begin(), 20000);
//***********************************/
auto it = l1.begin(); // O(1) - Getting an iterator to the beginning of the list
// move the iterator 0->1->2(move two steps) point on 3rd 
advance(it, 2);       // O(n) - Advancing the iterator by 2 steps (O(k), where k is the number of steps)
// emplace before third position 
l1.emplace(it, 18);   // O(1) - Inserting an element before the position pointed to by the iterator (emplace is O(1) for lists)
//***********************************/


//***********************************/
l1.emplace_front(600);// O(1) - Inserting an element at the front of the list
l1.emplace_back(800); // O(1) - Inserting an element at the back of the list
//***********************************/

//***********************************/
l1.erase(l1.begin()); // O(1) - Erasing the first element (constant time since position is known)
//***********************************/

//***********************************/
l1.erase(it);         // O(1) - Erasing the element at the position pointed to by the iterator (constant time since position is known)
//**********************************//
l1.remove(6);         // O(n) - Removing all occurrences of the value 6 (requires scanning the entire list)

//***********************************/
// remove all el less than 7
 l1.remove_if([](int x) { return x < 7; }); // O(n) remove all elements make the function return true

//**************************************/
l1.erase(l1.begin(), l1.end()); // O(n) - Erasing all elements in the range (O(k) for k elements removed, where k = n here)
//***********************************/

//***********************************/
if(l1.empty())        // O(1) - Checking if the list is empty

    cout << "Empty LIST" << endl;

l1.push_back(4);      // O(1) - Constant time to add an element at the end of the list
l1.push_back(5);     
l1.push_back(6);
list<int> l2 = {1,2,3};
l1.merge(l2); // O(n) will put the smallest elemnts first then 
// the bigest elements
/***************************************/
l1.push_back(6);
l1.push_back(5);
// remove duplicate elements
l1.unique(); // O(n) will make all list elements unique
copy(l1.begin(), l1.end(), ostream_iterator<int>(cout, " "));
/***********************************************/




}
