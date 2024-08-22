#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll sumOfDivisors()
{
       ll n , sum=1;
       cin >> n;
       if(n==1)return 0;
       for (ll i = 2; (i*i*1ll)<=n; i++)
       {
              if(n%i==0)
              {
                     sum+=i;
                     if(i!=n/i)
                            sum+=n/i;
              }
       }
       return sum;
}

signed main()
{
       
       int q;
       cin >> q;
       while (q--)
       {
             cout<< sumOfDivisors();
       }
       
}