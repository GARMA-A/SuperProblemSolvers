#include<iostream>
#include<vector>
using namespace std;

/*
What's Special About Vectors
------------------------
Accessing an element by index: O(1)
-------------------------
Pushing an element to the back: Amortized O(1)
-------------------------
Popping an element from the back: O(1)
-------------------------
Inserting or erasing an element at the end (with iterator): 
O(1) if no reallocation happens; 
O(n) if reallocation is required
-------------------------
Inserting or erasing an element in the middle 
(with iterator): O(n)
-------------------------
Clearing the vector: Linear in the size of the vector
-------------------------
Resizing the vector 
(without any new elements being inserted): O(n)
-------------------------
Resizing the vector (
with new elements being inserted): O(n)
------------------------

*/




signed main()
{

    vector<int> vec = {1, 2, 3, 4, 5};
     /******************************** */
    // Inserting an element at the end
    vec.insert(vec.end(), 6); // O(n)
    // Inserting an element in the middle
    vec.insert(vec.begin() + 2, 10); // O(n)
    /******************************** */
    // Emplace is faster than insert 
    vec.emplace_back(20); // O(1)
    vec.emplace(vec.begin()+3, 20); // O(n)

    /******************************** */
    // Resizing the vector
     vec.resize(3); //O(n)
     // Resizing the vector and inserting new elements O(n)
    vec.resize(8, 0);  // Resize to 8 elements, filling new elements with 0

   /********************************** */
    // point to first element 
    vector<int>::iterator it1 = vec.begin(); 
     // point to after last  element 
    vector<int>::iterator it2 = vec.end(); 


   /********************************** */
   // point to last element 
    vector<int>::reverse_iterator rit1 = vec.rbegin();
   // point to before the first element 
    vector<int>::reverse_iterator rit2 = vec.rend();
    cout << *(rit2);

    /**********************************/
    // Return Constant Iterators (NOT Editable)
    vector<int>::const_iterator cit1 = vec.cbegin(); 
    vector<int>::const_iterator cit2 = vec.cend(); 
    vector<int>::const_reverse_iterator cit3 = vec.crbegin();
    vector<int>::const_reverse_iterator cit4 = vec.crend();
    /********************************** */
}



