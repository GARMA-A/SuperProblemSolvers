#include "../IMPORTME.cpp"

int fac(int n)
{
       if(n==0)
              return 1;
       return n*fac(n-1);
}
int fib(int n)
{
       if (n==1 or n==2) return 1;
       return fib(n - 1) + fib(n - 2);
}
bool isSorted(vector<int>&v , int size)
{
       if (size == 0 or size == 1) return true;
       if(v[size-2]>v[size-1]) return false;
       return isSorted(v,size-1);
}

void printInc(vector<int>&v , int size)
{
       // if i have 1,2,3,4
       // print 1,2,3,4

       if(size==0) return;
       printInc(v,size-1);
       cout <<v[size-1];
    
}
void printDec(vector<int>&v , int size)
{
       // if i have 1,2,3,4
       // print 4,3,2,1
       if(size==0) return;
       cout <<v[size-1];
        printDec(v,size-1);
      
    
}
int slowPow(int a , int n) // Complexity O(n)
{
       if(n==0)
       return 1;
       return a * slowPow(a, n - 1);
}
double fastPow(double x, long long  n) // complexity O(log(n))
{
  /*
     a^n = (a^(n/2))^2   so we can calc power of
     a^n/2  and multiply by a^n/2 this is much more faster

     4^16 = (4^8)^2 

     2^7 = (2^3)^2  that's actauly not equal to each other
     because (2^3)^2 = 2^6 and we have 2^7 so if it is 
     odd number we still need to multiply by 2 one more time
     to get 2^7
  
  */

        if(n == 0)
            return 1.0;

       if(n<0)
       {
              x = 1 / x;
              n = -n;
       }
       double result = fastPow(x, n/2);
       double resultsq = result*result;
       if(n&1)
              return x *resultsq;
       return resultsq;
        
}

int tiling(int n)
{
       /*
        i have a (board of height 4 and width n)
        i want to put on it a building blocks each one 
        of (height 1 and width 4) how many ways that i can 
        fill the board with this blocks
       
        */
       if(n<4)
              return 1;
       int ans = 0;
       return tiling(n-4) + tiling(n-1);
       
}

int binaryStrings(int n, bool prevIsOne = false)
{
       /*
       i need from you to calculate the number of ways 
       that i can represent different binary strings
       of size n but without two consecutive ones inside it
       if i have n=4
       0000,0001,0010,0100,0101,1000,1001,1010 
       size = 4 all binary strings without two consecutive
       ones on it  ->  ans=8
       */
       if(n==0)
               return 1;
       int ans=0;
       ans += binaryStrings(n - 1 ,false);
       if(not prevIsOne)
              ans += binaryStrings(n - 1 ,true);
       return ans;
}

int party(int n)
{
       /*
       there is a party and every one is invited 
       now each one is invited can go alone or can go 
       with any other invited one  i want from you to 
       calculate tha number of ways each friend can go
       alone or can go with any other invited one
       */
       if(n<2)
              return 1;
       return  party(n-1)+((n-1)*party(n-2));
}


void subsets(string s,string sub="")
{
       if(s.size()==0)
       {
              cout << sub<<endl;
              return;
       }
       subsets(s.substr(1), sub);
       subsets(s.substr(1), sub + s[0]);

}


signed main()
{
       // cout << fac(5);
       //cout << fib(7);
       // vector<int> v = {1, 2, 3,4};
       // cout << isSorted(v, 4 );
       // printInc(v, 4);
       // cout<<fastPow(12,4)<<endl;
       // cout<<slowPow(12, 4);
       // cout << tiling(4);
       // cout << binaryStrings(3);
       //cout<<party(3);
       // subsets("abc");
}