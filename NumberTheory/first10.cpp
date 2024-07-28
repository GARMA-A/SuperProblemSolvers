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
       //DONOT store in the array more than 10^6 elements this = 40MB memory
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
}