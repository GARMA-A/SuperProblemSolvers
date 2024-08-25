#include<bits/stdc++.h>

using namespace std;

// Solution to this problem 
/*https://codeforces.com/group/yg7WhsFsAp/contest/355494/problem/P33*/

int thanosSort(vector<int>& arr) {
   if(is_sorted(arr.begin() , arr.end()))
   {
          return arr.size();
   }
   vector<int> left(arr.begin(), arr.begin() + arr.size() / 2);
   vector<int> right(arr.begin() + arr.size() / 2, arr.end());
   return max(thanosSort(left),thanosSort(right));
}



signed main()
{
       int size;
       cin >> size;
       vector<int> v(size);
       for(int i = 0; i < size; i++)
       {
              cin >> v[i];
       }
       cout << thanosSort(v);

}