#include "../IMPORTME.cpp"




void selectionSort(vector<int> & arr)//Complexity O(n^2)
{
       for (int i = 0; i < arr.size(); i++)
       {
              int mn = i, cur = i;
              while(cur<arr.size())
              {
                     if(arr[cur]<arr[mn])
                     {
                            mn = cur;
                     }
                     cur++;
              }
              swap(arr[i], arr[mn]);
       }

}







signed main()
{
       vector<int> c{8, 1, 3, 6, 12, 7};
       selectionSort(c);
       for(int num : c)
       {
              cout << num << " ";
       }
     
}



