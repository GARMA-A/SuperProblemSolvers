#include "../IMPORTME.cpp"
using namespace std;

void preFixCowsIds()
{
     // I have 3 IDs for cows (1, 2, 3)
     // and a list of cows that have these IDs.
     // Now I will give you a list of cows with their IDs.
     // Given N queries, output the number of cows that have ID 1,
     // ID 2, and ID 3 for each specific query.
     int n, q;
     cin >> n >> q;
     vector<vector<int>> cows(4,vector<int>(n+1,0));
     /*******/
     for(int i = 0; i < n; i++)
     {
          int id; cin >> id;
          cows[id][i] = 1;
     }
     /******/
     for (int id = 1; id <= 3; id++)
            for (int i = 1; i < n;++i)
              cows[id][i] = cows[id][i]+cows[id][i - 1];
     /******/
     while(q--)
     {
            int a, b;
            cin>>a>>b;
            a--, b--;
            if(a-1>=0)
            cout << cows[1][b] - cows[1][a - 1] << " ";
            else cout<<cows[1][b]<<" ";
            if(a-1>=0)
            cout << cows[2][b] - cows[2][a - 1] << " ";
            else cout<<cows[2][b]<<" ";
            if(a-1>=0)
            cout<<cows[3][b] - cows[3][a - 1] << endl;
            else cout<<cows[3][b]<<endl;
     }
}

void minMaxSubArrSum()
{
       // Given an array of integers, find the maximum sum of a subarray.
       // A subarray is a contiguous part of an array.
       // For example, the subarrays of [1, 2, 3] are [1], [1, 2], [1, 2, 3], [2], [2, 3], and [3].
       // Therefore the maximum sum of a subarray for [1, 2, 3] is 6.
       // Note there Can be negative numbers in the array.
       // ans: 
       int n;
       cin>> n;
       vector<int> arr(n);
       /*******/
       for (int i = 0; i < n; i++)
       {
               cin >> arr[i];
               if(i>0)
               arr[i]+=arr[i-1];
       }
       /*******/
       int mn = INT_MAX, maxSub = INT_MIN, minSub = INT_MAX, mx = INT_MIN;
       for (int r = 0; r < n;++r)
       {
             mn = min(mn, arr[r]);
             mx = max(mx, arr[r]);
             maxSub = max({maxSub, arr[r],  arr[r] - mn});
             minSub = min({minSub, arr[r],  arr[r] - mx});
       }
       cout << "min sub:"<<minSub<<endl;
       cout << "max sub:"<<maxSub<<endl;
       /*******/
}
void partialSum()
{
       // give big array add for me from l to r a number
       // this operation will be done for q times
       int n,q;
       cin>>n>>q;
       vector<int> arr(n+1);
       /*******/
       for(int i = 0; i < n; i++) cin>>arr[i];
       /*******/
       while(q--)
       {
              int l, r, val;
              cin>>l>>r>>val;
               l--, r--;
              arr[l] += val;
              arr[r+1] -= val;   
       }
       for (int i = 1; i < n; i++)
       {
              arr[i]+=arr[i-1];
       }
       /*******/
       copy(arr.begin(), arr.end()-1, ostream_iterator<int>(cout, " "));
}
void maxRestaurant()
{
      // Given the start and end times of each of n
      // people who have been in the restaurant,
      // find the maximum number of people present
      // in the restaurant at any given time.
       int q;
       cin>>q;
       vector<int> arr(1e5+1);
       /*******/
       while(q--)
       {
              int l, r;
              cin>>l>>r;
              arr[l] += 1;
              arr[r+1] -= 1;   
       }
       /*******/
       int mx = INT_MIN;
       for (int i = 1; i <= int(1e5+1); i++)
       {
              arr[i]+=arr[i-1];
              mx=max(mx,arr[i]);
       }
       cout << mx;
}

void preFix2DVersion()
{
       int n;
       cin >> n;
       vector<vector<int>> arr(n, vector<int>(n));
       /*******/
       for (int row = 0; row < n; row++)
       {
              for (int col = 0; col < n; col++)
              {
                     cin >> arr[row][col];
                     if (row > 0)
                         arr[row][col] += arr[row - 1][col];
                     if (col > 0)
                         arr[row][col] += arr[row][col - 1];
                     if (row > 0 && col > 0)
                         arr[row][col] -= arr[row - 1][col - 1];
              }
       }
       /*******/
     int q;
     cin >> q;
     while(q--)
     {
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                x1--, y1--, x2--, y2--;
                int ans = arr[x2][y2];
                if (x1 > 0)
                      ans -= arr[x1 - 1][y2]; 
                if (y1 > 0)
                      ans -= arr[x2][y1 - 1];
                if (x1 > 0 && y1 > 0)
                      ans += arr[x1 - 1][y1 - 1];
                cout << ans << endl;
     }
}


signed main()
{
       // preFixCowsIds();
       // minMaxSubArrSum();
       // partialSum();
       // maxRestaurant();
       //preFix2DVersion();
}



