/*NOTES
you need to read the notes of first 10 problems file
to understand this advanced BitWise problems ....
now let's get started
*/
#include "../IMPORTME.cpp"

int unique2NPlus1Seq(vector<int>seq)
{
       // unique 2N+1 Sequence is sequence of numbers that have 
       // only one element is unique the rest are apear twice
       // the main idea to solve this problem is xor 5^5 = 0 
       // any number xor with itself give 0 this the first rule and 
       // 5^0 = 5 any number xor with zero give that number itself
       // so if i have 1^8^3^4^1^3^8 = 4 that is it done 
       int size = seq.size() ,ans =0;
       for (int i = 0; i < size; i++)
       {
              ans ^= seq[i];
       }
       return ans;
}
pair<int,int> unique2NPlus2Seq(vector<int>seq)
{
       // the only difference here is that i have now two unique
       // number in seq size = 2N+2 tha main idea here is that after 
       // xor all numbers 1^2^3^4^2^3  = 1^4 (the two unique numbers)
       // i'm try to catch first bit =1 and from it seperate two sets
       // setA (contain one unique number) , setB(contain other unique number)
       // from here make xor to all setA to get that unique number and xor
       // to setB to get other unique number 
       int size = seq.size() ,ans =0;
       for (int i = 0; i < size; i++)
       {
              ans ^= seq[i];
       }
       int pos = 0;
       int temp = ans;
       while(temp&1 == 0)
       {
              pos++;
              temp >>= 1;
       }
       int setA = 0, setB = 0 , mask = 1<<pos;
       for (int i = 0; i < size; i++)
       {
              if((seq[i]&mask) >0 )
              {
                     setA ^= seq[i];

              }
              else
              {
                     setB ^= seq[i];
              }

       }
       return {setA, setB};

}
int unique3NPlus1Seq(vector<int>seq)
{
       // here i have again sequence of numbers but i have one 
       // unique number and other numbers apear 3 times for each
       // seq = 5,2,5,3,5,2,2 like that so the idea very simple sum  
       // the bits of all numbers and subt from each pos the smallest
       // sum 101+010+101+011+101+010+010 =(344)=(011 = 3) done !
       // int == 32 bit that is my colum number
       vector<int> sumArr(32, 0);
       for(int num : seq)
              for(int i = 0 ; i<32 ; i++) 
              {
                     int ithBit = num & (1 << i);
                     if(ithBit)
                            sumArr[i]++;
                     sumArr[i] %= 3;
              }
       int ans = 0;
       for(int i = 0; i <32;i++)
       {
              ans += (sumArr[i] * (1 << i));
       }
       return ans;
}

vector<string> generateAllSubsequences(string str)
{
       //str = "abc" i want(" ","a","b","c","ab","ac","cb","abc") 
       // i have rows and columns like 2D array the rows is the total
       // number of permutations i have or (2^sizeOfTheString) the 
       // columns is (sizeOfTheString) if i have "abc" rows=2^3=8 and
       // columns = 3 now i will generate 000---all the way to-->111
       // and check if cur bit=1 add the letter else dont add it
       int size = str.size();
       vector<string> ans;
       for (int i = 0; i < (1 << size);i++) //2^size number of sequences
       {
             string temp = "";
           for (int j = 0; j < size; j++)
              if (i & (1 << j))
                temp += str[j];
           ans.push_back(temp);
       }
       return ans;
}

int travellingSalesMan(vector<vector<int>>&dist,int setOfBits , int startingNode)
{
       //The traveling salesman problem is a famous problem
       // in which we need to find the shortest or least expensive
       // path in order to pass through all the points and return
       // to the point from which we started   A  B  C  D 
       // must start with A and end with A   A[0,20,42,25]
       //  the shortest path is              B[20,0,30,34]
       //  A → B → D → C → A: cost 85        C[42,30,0,10]
       //                                    D[25,34,10,0]
       //base case:
       int numberOfCities = dist.size();
       if(setOfBits ==(1<<numberOfCities)-1)
       {
           // return to the startingCity
              return dist[startingNode][0];
       }
       // otherwise try all possible options
       int ans = INT_MAX;
       for (int choice = 0;choice < numberOfCities;choice++)
       {
              //need to check if city visited already
              if((setOfBits & (1<<choice))==0) // not visited
              {
                     int subProb = dist[startingNode][choice] +
                     travellingSalesMan(dist, setOfBits | (1 << choice), choice);
                     ans = min(ans, subProb); // get smallest cost
              }
       }
       return ans;
       // if you dont understand read this part 
       // i have set of cities thats binary format start
       // from 0000 -> 1111 if i have 4 nodes and check if 
       // i reached 1111 the base case and if not run the for loop and
       // take node that is not taken before untill rech the base case
       // then return the cur cost and the parent function will added also
       // and ans will keep the min answer with me 
}




signed main()
{
       faster();
     
       // unique2NPlus1Seq();
       // unique2NPlus2Seq();
       // unique3NPlus1Seq();
       // generateAllSubsequences();
       
       // vector<vector<int>> dist = {
       //     {0, 20, 42, 25},
       //     {20, 0, 30, 34},
       //     {42, 30, 0, 10},
       //     {25, 34, 10, 0}
       // };
       // right answer = 85
       // travellingSalesMan(dist, 1, 0);
}







