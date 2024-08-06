#include "../IMPORTME.cpp"


//Complexity O(n^2)
// No extra Memory O(n)
void bubbleSort(vector<int>&arr) 
{
       for (int i = 0; i < arr.size()-1;i++)
       { 
              // for printing all steps
              for(int k = 0 ; k<arr.size();k++)
                     cout << arr[k] << " ";
              cout << endl;
              //-----------------------

              for(int j = 0; j < arr.size()-1-i;j++)
              if(arr[j]>arr[j+1])
                     swap(arr[j], arr[j + 1]);

              
       }
       // for printing all steps
        for(int k = 0 ; k<arr.size();k++)
                     cout << arr[k] << " ";
              cout << endl;
       //-----------------------
              

}









signed main()
{
       vector<int> v = {8, 5, 7, 3, 2};
       bubbleSort(v);
      
}


