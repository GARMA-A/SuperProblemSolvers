#include "../IMPORTME.cpp"



// Time Complexity O(n+k) where k is the range of the input
// Space Complexity O(k) if the range of numbers is
// big then it is not a good idea to use count sort
void countSort(vector<int>& arr) 
{

       int vectorSize = arr.size();
       int max = *max_element(arr.begin(), arr.end());
       vector<int>countArr(max+1, 0);
       for(int i = 0; i < vectorSize; i++)
       {
              countArr[arr[i]]++;
       }
       int j = 0;
       for(int i = 1; i <= max; i++)
       {
              while(countArr[i] > 0)
              {
                     arr[j++] = i;
                     countArr[i]--;
              }
       }

}




signed main()
{
       vector<int> v = {9,2,15,3,4};
       countSort(v);
       for(int n : v)
       {
              cout << n << " ";
       }

}