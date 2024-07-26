#include "../IMPORTME.cpp"


vector<int> sumBigInts(vector<int>n1,vector<int>n2) //Complexity: O(max(n, m)).
{

  /*
    I take two vectors and return a vector that is the sum of the two vectors
    how i do that it's very simply addition if i have 4482 + 653 what will do 
    reverse the two numbers so it become 2844 + 356 now start from first and add
    the corresponding digits (2+3=5)(8+5=13 carry=1)(4+6=10+[the carry]=11 carry=1)
    (4 has no corresponding digit so just push it) now i have 5 3 1 5
     reverse it so i have 5135  that's our answer done !
   */

    int carry = 0 , sum = 0 , output = 0;
    vector<int> result;

    reverse(n1.begin() , n1.end());
    reverse(n2.begin() , n2.end());

    vector<int>& longer =  (n1.size() >= n2.size()) ? n1 : n2;
    vector<int>& shorter = (n1.size() < n2.size()) ? n1 : n2;

    for (int i = 0; i < shorter.size(); i++) {
        sum = n1[i] + n2[i] + carry;
        output = sum % 10;
        carry = sum / 10;
        result.push_back(output);
    }

    for (int i = shorter.size(); i < longer.size(); i++) {
        sum = longer[i] + carry;
        output = sum % 10;
        carry = sum / 10;
        result.push_back(output);
    }

    if (carry != 0) {
        result.push_back(carry);
    }

    if (result.empty()) {
        result.push_back(0);
    }

    reverse(result.begin(), result.end());

    return result;
}

string sumBigInts(string s1 , string s2) //Complexity: O(max(n, m)).
{
       /*The same steps but on strings */
       int carry = 0, sum = 0 , output = 0;
       string result;
       if(s1.size()>s2.size())
              swap(s1,s2);
       reverse(s1.begin(),s1.end());
       reverse(s2.begin(),s2.end());

       for(int i = 0 ; i<s1.size() ; i++)
       {
              if(not isdigit(s1[i]) or not isdigit(s2[i]))
                     throw runtime_error("strigns must be digits");
              int d1 = s1[i]-'0' , d2 = s2[i]-'0';
              sum = d1 + d2 + carry;
              output = sum %10;
              carry = sum / 10;
              result.push_back((output+'0'));
       }

       for(int i = s1.size() ; i<s2.size() ; i++)
       {
              if(not isdigit(s2[i]))
                     throw runtime_error("strigns must be digits");
              int d2 = s2[i]-'0';
              sum = d2 + carry;
              output = sum %10;
              carry = sum / 10;
              result.push_back((output+'0'));
       }
       if(carry != 0)
       {
              result.push_back((carry+'0'));
       }
       if(result.empty())
              result.push_back('0');
       reverse(result.begin(), result.end());
       return result;
}


vector<int> bigFactorial(int n) // Complexity: O(𝑛^2 * log𝑛)
{
       /*
         the idea is simple you just need to loop from the 2 to the number
         you want it's factorial and inside the loop multiply each digit 
         by that number note that carry will be multiple digits so you need
         to loop throw it's digits and add them one by one to the final result
       */

       if(n<0)
       throw invalid_argument("the number must be positive");

       vector<int> result(1,1);
       int carry = 0 , mult=0;
       for (int num = 2; num <= n;num++)
       {
              for (int curDigit = 0; curDigit < result.size();curDigit++)
              {
                     mult = result[curDigit] * num + carry;
                     result[curDigit] = mult %10;
                     carry = mult / 10;
              }
              while(carry>0)
              {
                     result.push_back(carry%10);
                     carry /= 10;    
              }
       }
       reverse(result.begin(),result.end());
       return result;
       
       
}

signed main()
{
     vector<int> ans =  bigFactorial(100);
     for (int i = 0; i < ans.size(); i++)
     {
            cout << ans[i];
     }
}