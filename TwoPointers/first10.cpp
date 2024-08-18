# include "../IMPORTME.cpp"




int* binarySearch() // Complexity O(nlog(n))
{
       int n;
       cin >> n;
       vector<int>arr(n+1);
       for(int i = 0; i < n; i++)cin >> arr[i];
       sort(arr.begin(),arr.end());
       /***********/
       int left = 0 , right = n-1 , target;
       cin >> target;
       while(left<=right)
       {
              int mid = (left+right)/2;
              if(arr[mid]==target)
              {
                     return &arr[mid];
              }
              else if(arr[mid]<target)
              {
                      left = mid+1;
              }
              else
              {
                     right = mid-1;
              }

       }
       return nullptr;
}
int lowerBound()
{
       int n;
       cin >> n;
       vector<int>arr(n+1);
       for(int i = 0; i < n; i++)cin >> arr[i];
       sort(arr.begin(),arr.end());
       /***********/
       int left = 0 , right = n-1 , target ,ans=0;
       cin >> target;
       while(left<=right)
       {
               int mid = (left+right)/2;
               if(arr[mid]>=target)
              {
                       ans=mid;
                       right = mid-1;
              }
              else
              {
                     left =mid+1;
              }
       }
       return  ans;

}

int upperBound()
{
       int n;
       cin >> n;
       vector<int>arr(n+1);
       for(int i = 0; i < n; i++)cin >> arr[i];
       sort(arr.begin(),arr.end());
       /***********/
       int left = 0 , right = n-1 , target ,ans=0;
       cin >> target;
       while(left<=right)
       {
               int mid = (left+right)/2;
               if(arr[mid]<=target)
              {
                     ans = mid;
                     left = mid + 1;
                    
              }
              else
              {
                      right = mid-1;
              }
       }
       return  ans;

}

pair<int,int>firstLastApear(vector<int>&nums)
{
       int size = nums.size();
       int left = 0, right = size - 1;
       int target;
       cin >> target;
       int firstAppear = -1, lastAppear = -1;

       while (left <= right)
       {
              int mid = (left + right) / 2;
              if (nums[mid] == target)
              {
                     firstAppear = mid;
                     right = mid - 1;
              }
              else if (nums[mid] < target)
              {
                     left = mid + 1;
              }
              else
              {
                     right = mid - 1;
              }
       }

       left = 0, right = size - 1;
       while (left <= right)
       {
              int mid = (left + right) / 2;
              if (nums[mid] == target)
              {
                     lastAppear = mid;
                     left = mid + 1;
              }
              else if (nums[mid] < target)
              {
                     left = mid + 1;
              }
              else
              {
                     right = mid - 1;
              }
       }

       return {firstAppear, lastAppear};
}


void worms()//O(n*log(n))
{
       //this is *1200 Div2 problem solution
       //https://codeforces.com/contest/474/problem/B
       int n;
       cin >> n;
       vector<int>arr(n + 1);
       vector<pair<int,int>>boxes(n + 1);
       for(int i = 0; i < n; i++)
       {
              cin >> arr[i];
              if(i==0)
              {
                     boxes[i] = {1,arr[i]};
              }
              else
              {
                     boxes[i] = {boxes[i-1].second+1,boxes[i-1].second+arr[i]};
              }
       }
       int q;
       cin >> q;
       while(q--) 
       {
              int target;
              cin >> target;
              int left = 0, right = boxes.size()-1;
              while(left<=right)
              {
                     int mid = (left + right) / 2;
                     if(boxes[mid].first>target)
                     {
                            right = mid - 1;
                     }
                     else if(boxes[mid].second<target)
                     {
                            left = mid + 1;
                     }
                     else
                     {
                            cout << mid + 1<<endl;
                            break;
                     }

              }
       }
}

/*LeetCode coins Problem */
/*https://leetcode.com/problems/arranging-coins/description/*/
long long coinsNeededTofillNrows(long long rows)
{
       return  rows*(rows+1)/2;
}
/*this function compare if your current coins is enough
to fill this number of rows or not */
bool canIfillNrowsWithMyCurrentCoins(long long rows/*Answer*/,long long myCoins)
{
       return coinsNeededTofillNrows(rows)<=myCoins;
}
/*Binary search on rows untill get the correct row i can fill*/
//O(log(n=10^5))=16 (very fast)
long long howManyRowsCanFillwithMycoins(long long myCoins)
{
      
       long long minRows = 0, maxRows = 1e5;
       long long FinalAnswer=0;
      
       while(minRows<=maxRows)
       {
              int midRows =(maxRows+minRows)/2;
              if(canIfillNrowsWithMyCurrentCoins(midRows,myCoins))
              {
                     FinalAnswer = midRows;
                     minRows = midRows+1;
              }
              else
              {
                     maxRows = midRows-1;
              }
       }
       return FinalAnswer;
}

/********************/
/*Lets make Some cockies Div2 rated:*1400*/
/*https://codeforces.com/contest/670/problem/D2*/
/*O(n*log(n))*/
vector<long long> gramsNeeded;
vector<long long> gramsHave;
long long numOfIngredientsToMakeOneCockie;

bool canImakeNCokies(long long numOfCockiesToMake,long long numOfMagicPowderIhave)
{
       for (long long curIngredient=0;curIngredient<numOfIngredientsToMakeOneCockie;curIngredient++)
       {
              if(numOfCockiesToMake*gramsNeeded[curIngredient]>gramsHave[curIngredient])
              {
                     numOfMagicPowderIhave-=(numOfCockiesToMake*gramsNeeded[curIngredient]-gramsHave[curIngredient]);
              }
              if(numOfMagicPowderIhave<0)
              {
                     return false;
              }
       }
       return numOfMagicPowderIhave>=0;
}

void getMaxNumberOfCockiesIcanDo()
{
       // Take the inputs
       long long numOfMagicPowderIhave;
       cin >> numOfIngredientsToMakeOneCockie >> numOfMagicPowderIhave;
       /***************/
       //Resize tje global vectors to fit the inputs
       gramsNeeded.resize(numOfIngredientsToMakeOneCockie);
       gramsHave.resize(numOfIngredientsToMakeOneCockie);
       /***************/
       //Take the grams needed and the grams i have
       for (long long i = 0; i<numOfIngredientsToMakeOneCockie;i++)
       cin>>gramsNeeded[i];
       for (long long i = 0; i<numOfIngredientsToMakeOneCockie;i++)
       cin>>gramsHave[i];
       /***************/
       //Binary search on the max number of cockies i can make

       long long minCockies = 0, maxCockies = 1e10;
       long long FinalAnswer=0;
       while(minCockies<=maxCockies)
       {
              long long midCockies = (minCockies+maxCockies)/2;
              if(canImakeNCokies(midCockies,numOfMagicPowderIhave))
              {
                     FinalAnswer = midCockies;
                     minCockies = midCockies+1;
              }
              else
              {
                     maxCockies = midCockies-1;
              }
       }
       cout<<FinalAnswer<<endl;


}











signed main()
{
       cout << (binarySearch()==nullptr?"NOT FOUND":"FOUND") << endl;
       //  cout<<lowerBound()<<endl;
       // cout<<upperBound()<<endl;
       // vector<int>nums = {1,1,2,2,3,3,5,7,7,8,8,10,11 ,11};
       // pair<int,int>p= firstLastApear(nums);
       // cout<<p.first<<" "<<p.second<<endl;
      // worms();
       // ll myCoins;
       // cin >> myCoins;
       // cout<<howManyRowsCanFillwithMycoins(myCoins);
       // getMaxNumberOfCockiesIcanDo();
}