//#include "../IMPORTME.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void getAllDivisors()// O(sqrt(N))
{
       deque<int> divisors;
       int n;
       cin >> n;
       for (int i = 1; i * i <= n; i++)
       {
              if(n%i==0)
              {
                     divisors.push_back(i);
                     if(i!=n/i)
                            divisors.push_front(n/i);
              }
       }
       auto it = divisors.begin();
       advance(it,divisors.size()/2);
       copy(it, divisors.end(), ostream_iterator<int>(cout, " "));
       copy(divisors.begin(), it, ostream_iterator<int>(cout, " "));
}

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


/*https://codeforces.com/group/yg7WhsFsAp/contest/419146/problem/P18*/
vector<ll> allPrimes;
void coustomSieve(ll n = 1e4)
{
       vector<bool> isPrime(n, true);
       isPrime[0] = isPrime[1] = false;

       for (ll i = 2; i <=n ;i++)
       {
              if(isPrime[i])
              {
                     allPrimes.push_back(i);
                     for (ll j = i * i; j<=n ; j+=i)
                     {
                            isPrime[j] = false;
                     }
              }
       } 
}
vector<ll> ans;
bool bachgoldProblem(int n,ll sum=0)
{
       if(sum==n)
       {
              return true;
       }
       for (int i =0; i <allPrimes.size() ;i++)
       {
              if(sum+allPrimes[i]<=n)
              {
                     ans.push_back(allPrimes[i]);
                     sum += allPrimes[i];
                     if(bachgoldProblem(n,sum))
                            return true;
                     sum -= allPrimes[i];
                     ans.pop_back();  
              }      

       }
       return false;
}

void bachgoldProblemSolution()
{
       int n;
       cin >> n;
       coustomSieve(n);
       bachgoldProblem(n);
       cout << ans.size()<<endl;
       copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
}


/*https://codeforces.com/group/yg7WhsFsAp/contest/419146/problem/P21*/
vector<ll> allComposites;
void generateComposites(ll n = 1e8) {
    vector<bool> isComposite(n + 1, false);

    for (ll i = 2; i <= n; ++i) {
        if (!isComposite[i]) { 
            for (ll j = i * 2; j <= n; j += i) {
                isComposite[j] = true; 
            }
        }
    }
    for (ll i = 4; i <= n; ++i) {
        if (isComposite[i]) {
            allComposites.push_back(i);
        }
    }
}
void equationSolution()
{
       int n;
       cin >> n;
       generateComposites(1e8);
       int left = 0, right = allComposites.size()-1;
       while(left<right)
       {
              if(allComposites[right]-allComposites[left]==n)
              {
                     cout << allComposites[right] << " " << allComposites[left];
                     return;
              }
              else if(allComposites[right]-allComposites[left]>n)
              {
                     left++;
              }
              else
                     right--;
       }
       cout << -1;
}

/*https://codeforces.com/group/yg7WhsFsAp/contest/419146/problem/P23*/

void DivisorCount()//O(n*Log(n))
{
       int n;
       cin >> n;
       vector<int> divisors(n+1,0);
       for (int i = 1; i <=n ; i++)
       {
              for (int j = i; j <=n ; j+=i) divisors[j]++;
       }
       long long ans = 0;
       for(int i =1;i<=n;i++) ans += divisors[i];

       cout << ans;
}


signed main()
{
       //TPrimeSlow();
       //TPrimeFast();
       // almostPrime();
       // nearlyLickyNumber();
       //bachgoldProblemSolution();
       // equationSolution();
       //  copy(allComposites.begin(), allComposites.end(), ostream_iterator<int>(cout, " "));
       // factorise(6);
       // getAllDivisors();
       int q;
       cin >> q;
       while (q--)
       {
             cout<< sumOfDivisors();
       }
       
}






