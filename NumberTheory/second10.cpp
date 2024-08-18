//#include "../IMPORTME.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPrime(int n){
       if(n==1)
              return false;
       for (int i = 2; i * i <= n; i++)
       if(n%i==0)
              return false;
       return true;
}

vector<bool>sieve(int n=1e7)
{
       vector<bool> isPrime(n + 1, true);
       isPrime[0] = isPrime[1] = false;
       for (int i = 2; i * i <= n;i++)
       {
              if(isPrime[i])
              {
                     for (int j = i * i; j <= n;j+=i)
                     {
                            isPrime[j] = false;
                     }
              }
       }
       return isPrime;
}

/*Div2 Rating:1300*/
/*https://codeforces.com/contest/230/problem/B*/

void TPrimeSlow() // O(N*sqrt(N))//Accepted
{
       int size;
       cin >> size;
      
       for (int i = 0; i < size; i++)
       {
              ll num;
              cin >> num;
              int root = sqrt(num);
           if (isPrime(root) && (ll)root*root == num)
                     cout << "YES" << endl;
              else
                     cout << "NO"<<endl;
       }

}

void TPrimeFast() // O(N+loglog(N)) (much faster)//Accepted
{
       int size;
       cin >> size;
       vector<bool> isPrime = sieve();
      
       for (int i = 0; i < size; i++)
       {
              ll num;
              cin >> num;
              int root = sqrt(num);
           if (isPrime[root] && (ll)root*root == num)
                     cout << "YES" << endl;
              else
                     cout << "NO"<<endl;
       }

}
/*Rated:900*/
/*https://codeforces.com/contest/26/problem/A*/
void almostPrime()//O(N^2)N=3000
{
       
       int n ,ans=0;
       cin>>n;
       vector<bool> isPrime = sieve(3000);
       for (int i = 0; i<=n ; i++)
       {
              int ctr = 0;
              for (int j = 0; j<=i;j++)
              {
                  if(isPrime[j] and i%j==0)
                         ctr++;
              }
              if(ctr==2)
                     ans++;
       }
       cout << ans;
}



/*https://codeforces.com/group/yg7WhsFsAp/contest/419146/problem/P14*/
void nearlyLickyNumber()
{
       ll num,ctr=0;
       cin >> num;
       while(num>0)
       {
              int lstDigit = (num % 10);
              if(lstDigit==4 or lstDigit==7)
                     ctr++;

              num /= 10;
       }
       if(ctr==4 or ctr == 7)
              cout << "YES";
       else
              cout << "NO";
}

vector<int> allPrimes;
void coustomSieve(ll n = 1e5)
{
       vector<bool> isPrime(n, true);
       isPrime[0] = isPrime[1] = false;
     

       coustomSieve(n);
       vector<ll> ans;

       for (ll i = 0; i <allPrimes.size() ;i++)
       {
              ans.push_back(allPrimes[i]);
              ll sum = allPrimes[i];
              for (ll j = i+1; j < allPrimes.size();j++)
              {
                     sum += allPrimes[j];
                     if(sum<n)
                     {
                            ans.push_back(allPrimes[j]);
                     }
                     else if(sum==n)
                     {
                            ans.push_back(allPrimes[j]);
                            break;
                     }
                     else
                     {
                            ans.clear();
                            break;
                     }

              }
              if(sum==n)
                     break;
       }
       cout << ans.size()<<endl;
       copy(ans.begin(), ans.end(),ostream_iterator<int>(cout," "));

       
       
}

signed main()
{
       //TPrimeSlow();
       //TPrimeFast();
       // almostPrime();
       // nearlyLickyNumber();
       bachgoldProblem();
}






