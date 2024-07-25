/* NOTES
binary left shift 
5 = 00000101   
5<<2 = 00010100 adding zero to the binary format
now 5 become 20 so the left shift 
(shifted number = mainNUm * 2^numberOfShifts)5*2^2=20
---------------------
binary right shift
20>>2 = 5 (20=00010100) after the right shift(00000101)
(shifted number =mainNUm / 2^numberOfShifts)20/2^2= 5 
*/
#include "../IMPORTME.cpp" 


bool isOdd(ll n)
{
       // (num & 1)=>  (00101 & 00001 = (even 0) or (odd 1))
       try{
       if(n<0)
              throw invalid_argument("Index must be positive");
       }
       catch(const invalid_argument& e)
       {
              cerr << e.what() << endl;
       }
       if(n&1) return true;
       return false;
}
bool isPowerOfTwo(ll n)
{
       // always the number that is power of two 
       // and operator with number that is power of two -1 
       // will give 0 like 16 & 15 = 0 
       try{
       if(n<0)
              throw invalid_argument("Index must be positive");
       }
       catch(const invalid_argument& e)
       {
              cerr << e.what() << endl;
       }
       if(n&(n-1)) 
       return false;
       return true;
}

int countBits(ll n)
{
       // we will use simple hack to solve the problem
       // if i make n & n-1 suppose n=9 so 9 & 8 = 8 so on
       // 8 & 7 = 0 so we have 2 bits = 1 the main idea
       //  is to do this(n&n-1) and count how many times you do
       //  this operation before reach 0 that's your answer
       try{
       if(n<0)
              throw invalid_argument("Index must be positive");
       }
       catch(const invalid_argument& e)
       {
              cerr << e.what() << endl;
              return 0;
       }

       int ans = 0;
       while(n>0)
       {
              n = n & (n - 1);
              ans++;
       }
       return ans;
}

bool getIthBit(ll n , int index)
{
       // 4 = 00100  get 2nd indexed bit 
       // 1<<2 = 100 & 00100 = 1 the 2nd bit (as true or false)
       try{

       if(index<0 or n<0)
              throw invalid_argument("Index must be positive");
      
       }
       catch(const invalid_argument &e)
       {
              cerr << e.what() << endl;
              return false;
       }
       return bool(n & (1 << index));
}
void setIthBit(ll &n , int index , bool seterValue=0)
{
       // i have 5 = 00101 set 2d bit to zero
       // 00101 & ~(100) == 00101 & 011
       // set 2nd bit to one 00101 | 100 
      try{
      if(index<0 or n<0)
             throw invalid_argument("Index must be positive");
      }
      catch(const invalid_argument&e)
      {
          cerr<<e.what()<<endl;
          return;
      }
       if(seterValue)
      {
        n |= (1 << index);
      }
      else
      {
        n &= ~(1<<index);
      }
}
void clearFirstNBits(ll &n , int endPos)
{
       // EndPos NOT Indexed (Start From 1)
       // i have 15 = 01111  index = 2 now 15 will be  
       // 01100(12) clear first two bits done how to do that
       // -1 =1111111 because we store it two's complement
       // -1<<index = 1111100 & n  that's it !
       try{
       if(endPos<0 or n<0)
              throw invalid_argument("endPos must be positive");
       
       }
       catch(const invalid_argument&e)
       {
              cerr<<e.what()<<endl;
              return;
       }
       n = n & (-1 << endPos);
}
void clearRangeOfBits(ll &n , int startPos , int endPos )
{
       // endPos and startPos NOT Indexed (Start From 1)
       // the main idea is try to generate sequence like that
       // 111110000011111 and that will be 2^(endPos-startPos)-1
       // that is create 00000011111100000 and  simple Not to it
       try{
       if(endPos<startPos or endPos == 0 or startPos ==0 or n<0)
              throw invalid_argument(" Your Arguments Not valid");
       }
       catch(const invalid_argument&e)
       {
              cerr<<e.what()<<endl;
              return;
       }
        if(endPos==startPos)
              n = n & (1 << startPos);
       else
       {
           ll mask = ll(pow(2, ((endPos+1) - startPos))) - 1;
           n &= ~mask;

       }
       
}
void setRangeOfBits(ll &n , int startPos , int endPos , bool seterValue=0)
{
       // this function is a combination between some of 
       // the prev functions so there is no explain
       try{
       if(endPos<startPos or endPos == 0 or startPos ==0 or n<0)
              throw invalid_argument(" Your Arguments Not valid");
       }
       catch(const invalid_argument&e){
              cerr<<e.what()<<endl;
              return;
       }
       if(startPos == endPos)
       {
              if(seterValue)
                     n = n | (1 << startPos);
              else
               n = n & (1 << startPos);
       }
       else
       {
              ll mask = ll(pow(2, ((endPos+1) - startPos))) - 1;
              if(seterValue)
              {
                 n |= mask;
              }
              else
              {
                
                n &= ~mask;

              }
       }


}

ll convertToDecimal(string bin)
{
       // i have base start from 1 = 10^0 and increase it 
       // base*=2 if the cur bit is 1 i will add the 
       // base whenever i rech the end i will return the answer
   
       ll base = 1 , ans=0 , size = bin.size()-1;
       for (int i = size; i >= 0; i--)
       {
              if (bin[i]=='1')
              {
                     ans += base;
              }
              if(bin[i]!='0' and bin[i] != '1')
              throw invalid_argument("Bin number must be 0 or 1 only and as string ");
               base *= 2;
       }
             
       
       return ans;
}
ll convertToBinary(ll n)
{
       // i have base start from 1 = 10^0 and increase it 
       // base*=10 if the most right bit is 1 i will add the 
       // base whenever i rech the end i will return the answer
       try{
       if(n<0)
              throw invalid_argument("Given Number must be positive");
       }
       catch(const invalid_argument& e)
       {
              cerr << e.what() << endl;
              return 0;
       }
       ll base = 1,ans=0;
       while(n>0)
       {
              int lastBit = (n & 1);
              ans += base * lastBit;
              base *= 10;
              n >>= 1;
       }
       return ans;
}

string convertToBinaryStringVersion(ll n)
{
       // i have base start from 1 = 10^0 and increase it 
       // base*=10 if the most right bit is 1 i will add the 
       // base whenever i rech the end i will return the answer
       try{
       if(n<0)
              throw invalid_argument("Index must be positive");
       }
       catch(const invalid_argument& e)
       {
              cerr << e.what() << endl;
              return 0;
       }
       string ans;
       while(n>0)
       {
             if(n & 1)
                    ans += '1';
              else
                     ans += '0';
              n >>= 1;
       }
       reverse(ans.begin(), ans.end());
       return ans;
}


signed main()
{
       faster();
       // isOdd();
       // isPowerOfTwo();
       // countBits();
       // getIthBit();
       // setIthBit();
       // clearFirstNBits();
       // clearRangeOfBits();
       // setRangeOfBits();
       // convertToDecimal();
       // convertToBinary();
       // convertToBinaryStringVersion();
}