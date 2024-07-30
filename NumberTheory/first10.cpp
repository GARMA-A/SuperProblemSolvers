/*NOTES

Number theory is a significant field of science
that studies the relationships between numbers.
It explores how these relationships can generate 
equations that help improve our problem-solving
abilities.

*/



#include "../IMPORTME.cpp"


bool isPrime(ll n) // O(n^0.5)
{
/*
      We will use the fastest approach, which says:
      If I have a number N, we know that N^0.5 * N^0.5 = N.
      So, if there is a divisor of N greater than N^0.5, 
      there must be one less than or equal to N^0.5.
      This is a summary of the rule.Because of this,
       I will iterate from 2 to N^0.5 and check if there is a
       divisor.If there is a divisor, then the number is not prime.
       If there is no divisor, then the number is prime.
 */
     for (int i = 2; i * i < n;i++)
       if(n%i==0)
              return false;
     
      return true;
}

void sieve(ll n,vector<bool>&isPrime) //O (N*loglog(n)), 
{
       /*
              The Sieve of Eratosthenes is an efficient algorithm
              to find all prime numbers up to a given number,
              N. Start by creating a list of numbers from 2 to N.
              Begin with the first number in the list (2),
              and eliminate all its multiples. Move to the next number
              in the list and repeat the process for its multiples. 
              Continue this process until you've processed numbers 
              up to the square root of N. The remaining numbers in
              the list are all primes.       
       */
       isPrime.resize(n + 1, true);
       isPrime[0] = isPrime[1] = false;

       for(ll i = 2; i <= n; i++)
              if(isPrime[i])
                     for(ll j =i*i; j <= n; j+=i)
                            isPrime[j] = false;
              
       
}
void factorise(ll n) // O (N^0.5)
{
       // give me the factoriseation of anumber
       // factorisation mean how many prime numbers
       // the number contain like 8 = 2*4 = 2*2*2 so 2^3 is 
       // prime factorisation mean i have 3 of the prime 2 on it
       // i will loop untill the sqrt of n so either i will
       // find a prime number and stop on it or it will be one
       // and one not count with me

       for (int i = 2; i * i <= n;i++)
       {
              if(n%i == 0 )
              {
                     int ctr = 0;
                     while(n%i==0)
                     {
                            ctr++;
                            n /= i;
                     }
                     cout << i << "^" << ctr << ",";
              }
       }
       if(n!=1)
       {
              cout << n << "^" << 1 << " ";
       }
}


void preComputePrimeDivisors(ll n) // O(Nloglog(n))
{
    // factorise using sieve
    vector<ll> sieve(n + 1);
    for(ll i = 2 ; i <= n ; i++)
    {
       if (not sieve[i])
       {
              sieve[i] = i;
              for (ll j = i * i; j <= n;j+=i)
              {
                     // store smallest prime divisor for that number j
                     sieve[j] = ((sieve[j]<i and sieve[j]!=0)?sieve[j]:i);
              }
       }

    }
    ofstream newFile("sieve.txt");
    if (newFile.is_open())
    {
           newFile << "{" << " ";
           for (ll i = 0; i < n + 1; i++)
           {
                  newFile << sieve[i];
                  if(i<n-1) newFile << ", ";
                  if(i%8==0) newFile <<endl;
           }
           newFile << "}" << " ";
    }
    newFile.close();

}
void factoriseWithSieve(ll n , vector<ll>&sieve) // O (LogN)
{
    string s;
    while(n>1)
    {
           s += to_string(sieve[n]);
           if(n/sieve[n]!=1)
           s += '*';
           n /= sieve[n];
    }
    cout << s;
}



int mygcd(int a , int b) 
{

/*      a   b                         a   b
       20  12                         12  20  
           20%12=8                       12%20=12
       12   8                         20   12
            12%8 = 4                        20%12=8 
       8     4                        12    8   continue
             8%4 = 0
       4      0      return 4                  return 4
  
 */
       if (b==0)
              return a;
       return mygcd(b, a%b);
}



// nCr == nCn-r
// Function to compute nCr
long long nCr(int n, int r) //Complexity O(r)
{
    if (r > n || r < 0) return 0;
    if (r == 0 || r == n) return 1;
    r = min(r, n - r); // nCr is the same as nC(n-r)
    long long result = 1, denominator = 1;
    for (int i = 1; i <= r; ++i) {
        result *= (n - r + i);
        denominator *= i;
        long long gcdvar = gcd(result, denominator);
        result /= gcdvar;
        denominator /= gcdvar;
    }
    return result;
}

// Function to compute nPr
long long nPr(int n, int r)//Complexity O(r)
{
    if (r > n || r < 0) return 0;
    long long result = 1;
    for (int i = 0; i < r; ++i) {
        result *= (n - i);
    }
    return result;
}

void pascalTriangle(vector<vector<int>> &table)
{
    /*    r0   r1   r2    r3  r4    r5 
      n | nC0  nC1  nC2  nC3  nC4   nC5 
        |--------------------------------
      0 |  1
      1 |  1    1
      2 |  1    2    1
      3 |  1    3    3    1
      4 |  1    4    6    4    1
      5 |  1    5    10   10   5    1
     */

       int n = table.size();
       for(int i= 0 ; i<n; i++ )
              for (int j = 0; j <= i;j++)
                     if(j==0 || j ==i)
                            table[i][j] = 1;
                     else
                            table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
}

int countBST(int n  ,map<int,int>dp={{0,0}}) // Complexity O(n^2)
{
   // if i have 3 nodes i can make 5 different binary trees
       if (n == 0 or n==1)
              return 1;
       if (dp[n]!=0)
              return dp[n];
       int ans = 0;
       for(int i = 1; i <= n; i++)
       {
              int x = countBST(i - 1 , dp);
              int y = countBST(n - i,dp);
              ans += x * y;
       }
       return dp[n]=ans;
}





signed main()
{
       // isPrime(100);
       /********************** */
       // ll n;
       // cin >> n;
       // vector<bool> isPrime(n+1,true);
       // sieve(n,isPrime);
       // for (int i = 0; i<n;i++)
       //        cout << isPrime[i] << " " << i << endl;
       /********************************/
       // factorise(99);

       /************************************************* */
       //Get the pre computed smallest prime numbers from the file we store it to
       /*******/
       // preComputePrimeDivisors(100);
       // past them here and disable the call of the function
       //DONOT store in the array more than 10^6 elements thiso = 40MB memory
       // vector<ll> getPreComputedSieve = {0,
       //                                   0, 2, 3, 2, 5, 2, 7, 2,
       //                                   3, 2, 11, 2, 13, 2, 3, 2,
       //                                   17, 2, 19, 2, 3, 2, 23, 2,
       //                                   5, 2, 3, 2, 29, 2, 31, 2,
       //                                   3, 2, 5, 2, 37, 2, 3, 2,
       //                                   41, 2, 43, 2, 3, 2, 47, 2,
       //                                   7, 2, 3, 2, 53, 2, 5, 2,
       //                                   3, 2, 59, 2, 61, 2, 3, 2,
       //                                   5, 2, 67, 2, 3, 2, 71, 2,
       //                                   73, 2, 3, 2, 7, 2, 79, 2,
       //                                   3, 2, 83, 2, 5, 2, 3, 2,
       //                                   89, 2, 7, 2, 3, 2, 5, 2,
       //                                   97, 2, 32};

       // cout << mygcd(20, 8);
  /********************************************/

       // vector<vector<int>> table(10 , vector<int>(10,0));
       // pascalTriangle(table);
       // for (int i=0; i<10; i++)
       // {
       //   for (int j=0; j<=i; j++)
       //          cout << table[i][j] << " ";
       //     cout << endl;
       // }
 /********************************* */
       cout << countBST(4
       );
}