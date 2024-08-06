#include "../IMPORTME.cpp"


// Complexity O(n^2)

void insertionSort(vector<int>&arr) 
{
       int size  = arr.size();
       for (int i = 1; i < size ;i++)
       {

              int curNum = arr[i], j = i - 1 ;
              while(j>=0 and arr[j]>curNum)
              {
                    arr[j+1]= arr[j] ;
                     j--;
              }
              arr[j + 1] = curNum;
       }

}





signed main()
{
       vector<int> v = {9,2,15,3,4};
       insertionSort(v);
       for(int n : v)
       {
              cout << n << " ";
       }
}