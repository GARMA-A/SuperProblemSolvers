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
/****************************/
/**************************************************/
////    Sudoku Solver     ////
bool isSafe(vector<vector<char>>&sudokuBoard,int no , int i , int j)
{
       for(int k = 0 ; k<9 ; k++)
       {
              if(sudokuBoard[i][k]==(no+'0') or sudokuBoard[k][j]==(no+'0'))
              {
                     return false;
              }
       }

       int x = (i / 3) * 3 , y = (j / 3) *3;
       for(int l = x ; l<x+3 ; l++)
       {
              for(int m = y ; m<y+3 ; m++)
              {
                     if(sudokuBoard[l][m]==(no+'0'))
                     {
                            return false;
                     }

              }
       }
       return true;
}



bool sodukoSolver(vector<vector<char>>&sudokuBoard , int i=0 , int j=0)
{
      // https://leetcode.com/problems/sudoku-solver/description/
       if(i==9)
       {
          return true;
       }
       if(j==9)
       {
              return sodukoSolver(sudokuBoard ,i+1 ,0);
       }
       if(sudokuBoard[i][j]!='.')
       {
              return sodukoSolver(sudokuBoard ,i,j+1);
       }
       for(int no = 1 ; no<=9 ; no++)
       {
              if(isSafe(sudokuBoard,no , i , j))
              {
                     sudokuBoard[i][j] = (no+'0');
                     if(sodukoSolver(sudokuBoard ,i,j+1))
                            return true;
                     sudokuBoard[i][j] = '.';
                     
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
       // cin>>sizeOfTheBoard;
       // board.resize(sizeOfTheBoard, string(sizeOfTheBoard, '.'));
       // nQueens();
       /***********************/
       vector<vector<char>> sudokuBoard = 
              {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
               {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
               {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
               {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
               {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
               {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
               {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
               {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
               {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

       sodukoSolver(sudokuBoard,0,0);
}