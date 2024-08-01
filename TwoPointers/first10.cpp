# include "../IMPORTME.cpp"


int* binarySearch(vector<int>& v , int target) // Complexity: O(log(n))
{
       int right = v.size()-1, left = 0;

       while(left<=right)
       {
              int mid = (left+right)/2;
              if(v[mid] == target)
              {
                     return &v[mid];
              }
              else if (v[mid]<target)
              {
                     left = mid + 1;
              }
              else
              {
                     right = mid - 1;
              }
       }
       return nullptr;
}

int * lowerBound(vector<int> &v , int target)// Complexity: O(log(n))
{
       int left = 0, right = v.size() - 1 ;
       int *ans = nullptr;
       while(left <= right)
       {
              int mid = (left + right )/ 2;
              if(v[mid] >= target)
              {
                     right = mid - 1;
                     ans=&v[mid];
              }
              else
              {
                     left = mid + 1;
              }
       }
       return ans;
}

int * upperBound(vector<int> &v , int target)// Complexity: O(log(n))
{
       int left = 0, right = v.size() - 1 ;
       int *ans = nullptr;
       while(left <= right)
       {
              int mid = (left + right )/ 2;
              if(v[mid] >= target)
              {
                     left = mid +1;
                     ans=&v[mid];
              }
              else
              {
                     left = mid + 1;
              }
       }
       return ans;   
}

pair<int*,int*> firstLastApear(vector<int>& v, int target)// Complexity: O(log(n))
{
       int left = 0 , right = v.size()-1;
       int *firstApear=nullptr, *lastApear = nullptr;
       while(left <= right)
       {
              int mid = (left + right)/2;
              if(v[mid]==target)
              {
                     right = mid - 1;
                     firstApear = &v[mid];
              }
              else if(v[mid]>target)
              {
                     right = mid - 1;

              }
              else
              {
                     left = mid + 1;
              }

       }
       left = 0, right = v.size() - 1;
       while (left <= right)
       {
              int mid = (left + right)/2;
              if(v[mid]==target)
              {
                     left = mid + 1;
                     lastApear = &v[mid];
              }
              else if(v[mid]>target)
              {
                     right = mid - 1;

              }
              else
              {
                     left = mid + 1;
              }

       }
       return {firstApear, lastApear};
}


signed main()
{
       vector<int> arr = {3, 46, 52, 72, 112, 200,415,415,415,800};
       // int *ptr = lowerBound(arr, 801);
       // auto cppptr = lower_bound(arr.begin(), arr.end(), 801);
       // if(ptr != nullptr) {
       //        cout << "index :" << ptr - &arr[0]<<"\n";
       //        cout<<"value :"<<*ptr<<"\n";
       // }
       // if(ptr != nullptr) {
       //        cout << "my index : " << ptr - &arr[0] << "\n";
       //        cout<<"my value : "<<*ptr<<"\n";
          
              
       // }
       // else
       // {
       //        cout << "not found"<<"\n";
       // }
       // if(cppptr == arr.end())
       // {
       //        cout<<"not found"<<"\n";
       // }
       // else
       // {
       //   cout<<"index :"<<cppptr-arr.begin()<<"\n";
       //   cout<<"value : "<<*cppptr<<"\n";
       // }
       pair<int *, int *> pr = firstLastApear(arr, 415);
       cout << "start index : " << pr.first - &arr[0] << "\n";
       cout << "end index : " << pr.second - &arr[0] << "\n";
}