#include "../IMPORTME.cpp"
using namespace std;

vector<int> merge(vector<int> &a , vector<int> &b)
{
       vector<int> res;
       int i = 0  , j = 0;
       while(i<a.size() && j<b.size())
       {
              if(a[i]<b[j])
              {
                     res.push_back(a[i]);
                     i++;
              }
              else
              {
                     res.push_back(b[j]);
                     j++;
              }
       }
       while(i<a.size())
       {
              res.push_back(a[i]);
              i++;
       }
       while(j<b.size())
       {
              res.push_back(b[j]);
              j++;
       }
       return res;
}


void mergeSort(vector<int> &arr)
{
     if(arr.size()<=1)
            return;
       vector<int> left(arr.begin(), arr.begin() + arr.size()/2);
       vector<int> right(arr.begin() + arr.size()/2, arr.end());
       mergeSort(left);
       mergeSort(right);
       arr = merge(left, right);
}



int partition(int startIndex , int endInex , vector<int> &arr)
{
       int start = startIndex+1 , pivot = startIndex , end = endInex;
       while(start<=end)
       {
              if(arr[start]<=arr[pivot])
              {
                     start++;
              }
              else if(arr[end]>arr[pivot])
              {
                     end--;
              }
              else
              {
                     swap(arr[start],arr[end]);
                     
              }
             
       }
       swap(arr[pivot],arr[end]);
       return end;
}


void quickSortHelper(vector<int>&arr , int startIndex  , int endIndex)
{
   if(startIndex >= endIndex) return;
       int pivotIndex   = partition(startIndex , endIndex , arr);
       quickSortHelper(arr, startIndex, pivotIndex - 1);
       quickSortHelper(arr, pivotIndex + 1, endIndex);


}

void quickSort(vector<int>&arr)
{
       quickSortHelper(arr,0,arr.size()-1);
}


void radix(vector<int>&arr)
{
       //new radix sorting algorithm
       //https://youtu.be/ujb2CIWE8zY
       vector<int>output(arr.size());
       int max = *max_element(arr.begin(),arr.end());
       int digitNum = log10(max)+1;
       for(int curdigit = 0 ; curdigit<digitNum ; curdigit++)
       {
              vector<int>count(10);
              for (int i = 0; i < arr.size();i++)
              {
                     count[(arr[i]/(int)pow(10,curdigit))%10]++;
              }
              for(int i = 1 ; i<10 ; i++)
              {
                     count[i]+=count[i-1];
              }
              for(int i = arr.size()-1 ; i>=0 ; i--)
              {
                     output[--count[(arr[i]/(int)pow(10,curdigit))%10]] = arr[i];
                    
              }
              for(int i = 0 ; i<arr.size() ; i++)
              {
                     arr[i] = output[i];
              }
              

       }      


}

signed main()
{
       // //test
       vector<int> c{8, 1, 3, 6, 12, 7};
       // mergeSort(c);
       // for(int num : c)
       // {
       //        cout << num << " ";
       // }
    radix(c);
    for(auto el : c)
    {
        cout << el << " ";
    }
}

