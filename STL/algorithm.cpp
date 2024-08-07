#include<iostream>
#include<algorithm>
#include<iterator>

using namespace std;

bool thereIsletterC(char c);

signed main()
{

       string s = {'b','d','f','c','a','e'};
      /*************************************/
       sort(s.begin(), s.end()); // O(n * logn) Ascending
       cout<<s<<endl;
       /*************************************/
       sort(s.rbegin(), s.rend()); // O(n * logn) Descending
       cout<<s<<endl;
       /*************************************/
       reverse(s.rbegin(), s.rend()); // O(n)
        cout<<s<<endl;
       /*************************************/
       // Best  For Large Elements
       cout<<*min_element(s.begin(), s.end())<<endl; // O(n)
       /*********************************** */
       max_element(s.begin(), s.end()); // O(n)
       /***********************************/
       auto p = minmax_element(s.begin(), s.end()); // O(n)
       cout<<*p.first<<" "<<*p.second<<endl;
       /***********************************/
       // Best  For Small Elements
       cout << min({5, 3, 2, 6}) << endl; // O(n)
       cout<<max({5,3,2,6})<<endl; // O(n)
       /***********************************/
       // Find first element make the function return true
       auto it = find_if(s.begin(), s.end() , thereIsletterC);
       cout<<*it<<endl; // print the 'c' // O(n) 
       /***********************************/
       find(s.begin(), s.end(), 'c'); // O(n)
       /************************************/
       string s2(s.size(),'\0') ;
       copy(s.begin(), s.end(), s2.begin()); // O(n)
       cout << s2<<endl;
       /************************************/
       // Another Way of Doing Copy (same Complexity)
       string s3(s.begin(), s.end()); // O(n)
       cout << s3<<endl;
       /*************************************/
       // If you Want To Copy Backward (right->left)
       string s4(s.size()+4, '0');
       copy_backward(s.begin(), s.end(), s4.end()-1);//O(n)
       cout << s4 << endl; //000abcdef0
       /*************************************/
       //Print All With Copy O(n)
       copy(s.begin(), s.end(), ostream_iterator<char>(cout, " "));
       /**************************************/
}

bool thereIsletterC(char c)
{
       return c == 'c' || c == 'C';
}




