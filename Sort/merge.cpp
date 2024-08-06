#include "../IMPORTME.cpp"



vector<int>merge(vector<int>left , vector<int>right )
{

     vector<int> ans; 
     int i =0, j=0;
     while(i<left.size() and j<right.size())
     {
       if(left[i]<right[j])
       {
              ans.push_back(left[i++]);
       }
       else
       {
              ans.push_back(right[j++]);
       }
     }
     while(j<right.size())
     {
            ans.push_back(right[j++]);
     }
     while(i<left.size())
     {
            ans.push_back(left[i++]);
     }

     return ans;
}


// Complexity O(n*log(n))
// Space complexity O(n) 
vector<int> mergeSort(vector<int>arr) 
{
       if(arr.size()<=1)
       {
              return arr;
       }

       int mid = arr.size() / 2;

       vector<int> left(arr.begin(), arr.begin() + mid);
       vector<int> right(arr.begin() + mid, arr.end());
       left =  mergeSort(left);
       right =  mergeSort(right);
       return merge(left, right);
}






























signed main()
{
       vector<int> ans = mergeSort({10,5,2,0,7,6,4});
       for(int num : ans)
       {
              cout << num << " ";
       }
}