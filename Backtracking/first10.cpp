#include "../IMPORTME.cpp"

string sub,mainstr;
void subsets(int i=0 , int j=0) //Comlexity O(2^n)
{
       if(j == mainstr.size())
       {
              cout << sub<<endl;
              return ;
       }
       sub.push_back(mainstr[j]);
       subsets(i+1,j+1);
       sub.pop_back();
       subsets(i , j+1);
}
/*******************************************/
string s, sb;
map<int,bool> taken;
void permutation()//Comlexity O(n * n!)
{
       if(s.size()==sb.size())
       {
              cout << sb << endl;
              return;
       }
       for(int i = 0; i < s.size(); i++)
       {
              if(not taken[i])
              {
                     sb.push_back(s[i]);
                     taken[i] = true;
                     permutation();
                     taken[i] = false;
                     sb.pop_back();
              }

       }

}
/*******************************************/

int n,l,r;
string brackets;
void generateBrackets()
{
       if(brackets.size()==n*2)
       {
              cout<<brackets<<endl;
              return;
       }
       if(r>l)
       {
            brackets += ')';
            l++;
            generateBrackets();
            l--;
            brackets.pop_back();
       }
       if(r<n)
       {
              brackets += '(';
              r++;
              generateBrackets();
              r--;
              brackets.pop_back();
       }   
}
/**************************************************/
////    N-Queens  Problem      ////

int sizeOfTheBoard;
vector<string> board;
bool canPlace(int curRow , int curColumn)
{
       /*check the column*/
       for (int i = 0; i <=curRow; i++)
              if(board[i][curColumn]=='Q')
                     return false;
       
       /***************/
       /*check the right diagonal*/
       int r = curRow , c = curColumn;
       while(r>=0 and c<sizeOfTheBoard)
       {
              if(board[r][c]=='Q')
                     return false;
              r--;
              c++;
       }
       /*check the up left diagonal*/
       r = curRow;
       c = curColumn;
       while (r>=0 and c>=0 )
       {
              if(board[r][c]=='Q')
                     return false;

              r--;
              c--;
       }
       /******************/
       return true;
}

bool nQueens(int row=0)
{
       if(row==sizeOfTheBoard)
       {
              for (int i = 0; i < sizeOfTheBoard;i++)
              {
                     for (int j = 0;  j < sizeOfTheBoard;j++)
                            cout << board[i][j] << " ";
                     cout << endl;
              }
              cout << "------------------" << endl;
       }

       for (int i = 0; i < sizeOfTheBoard;i++)
       {
              if(canPlace(row , i))
              {
                     board[row][i] = 'Q';
                     bool success = nQueens(row + 1);
                     if(success)
                     {
                            return true;
                     }
                     board[row][i] = '.';
              }
       }
       return false;
}


signed main()
{
       // cin >> mainstr;
       // subsets();
       // cin >> n;
       // generateBrackets();
       /*****************/
       cin>>sizeOfTheBoard;
       board.resize(sizeOfTheBoard, string(sizeOfTheBoard, '.'));
       nQueens();
}