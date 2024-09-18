#include "../IMPORTME.cpp"
using namespace std;

vector<int> merge(vector<int> &a , vector<int> &b)
{
       vector<int> res;
       int i = 0  , j = 0;
       while(i<a.size() && j<b.size())
       {
              if(a[i]<b[i])
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

void 


signed main()
{
       //test
       vector<int> c{8, 1, 3, 6, 12, 7};
       mergeSort(c);
       for(int num : c)
       {
              cout << num << " ";
       }

}

