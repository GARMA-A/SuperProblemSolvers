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

void sieve(ll n,vector<bool>&isPrime) //O (N*loglogN), 
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


signed main()
{
       isPrime(100);
       /********************** */
       // ll n;
       // cin >> n;
       // vector<bool> isPrime(n+1,true);
       // sieve(n,isPrime);
       // for (int i = 0; i<n;i++)
       //        cout << isPrime[i] << " " << i << endl;
       /********************************/

}