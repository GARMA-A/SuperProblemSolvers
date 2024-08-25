#include "../IMPORTME.cpp"


// Complexity O(d * (n + k)) 
// where d is the number of digits in the input numbers
void radixSort(vector<int> &arr) 
{ 
       vector<vector<int>> bits(10);
       int max = *max_element(arr.begin(), arr.end());
       int digitNum = log10(max) + 1;
       for (int i = 0; i < digitNum; i++) 
       {
              for (int j = 0; j < arr.size(); j++) 
              {
                     int digit = (arr[j] / (int)pow(10, i)) % 10;
                     bits[digit].push_back(arr[j]);
              }
              arr.clear();
              for (int j = 0; j < 10; j++) 
              {
                     for (int k = 0; k < bits[j].size(); k++) 
                     {
                            arr.push_back(bits[j][k]);
                     }
              }
              for (int j = 0; j < 10; j++) 
              {
                     bits[j].clear();
              }
       }
}

signed main()
{
       vector<int> v = {35, 100, 5,2146, 155};
       radixSort(v);
       for (int n : v) 
       {
              cout << n << " ";X
       }



}