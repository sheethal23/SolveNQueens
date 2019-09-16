

#include "prog9.h"

/*************************************************************************************
 The main function calls solveNQueens routine.
**************************************************************************************/
int main() 
{
	while(N<9)
	{	
	solveNQueens(N);
	N++;
	}
	return 0;
}

/*************************************************************************************
void solveNQueens ( const unsigned& n ): This routine first creates a 2-d
vector of vectors of type bool for the given size n
**************************************************************************************/ 
void solveNQueens ( const unsigned& n )
{
        if(n>=1){}	
 	vector< vector<bool> > board;                             //2d vector
 	initBoard(board);
        if(N>0)
        {
 	        cout<<"Board Size = "<<N<<endl;
        } 
	if(solveNQueensUtil(board,0))
 	{
 		printBoard(board);                                                 //if a solution is found then the board gets printed.
	}
	else
	{
		cout<<"Solution does not exist."<<endl<<endl;                       //if solution is not found then this message gets printed.
	}
	
 }
 
/*******************************************************************************************
bool solveNqueensUtil ( vector < vector < bool > >& board, const unsigned& row ): This
recursive routine starts on the row number row and gets a random column
number col, between 0 and ( board.size ( ) – 1) from the RNG, and it checks if a
queen can be placed on the location (row, col)
********************************************************************************************/
bool solveNQueensUtil(vector < vector < bool > >& board, const unsigned& row) 
{
 	int col;
	if(row >= N)	
	  return true;
	for(unsigned i=0;i<=N+2;i++)
	{
		col= rand() %(board.size());
		if(isSafe(board, row, col))
		{
			board[row][col] = true;
			if(solveNQueensUtil(board, row+1))
			  return true;
			board[row][col] = false;
		}
	}
	return false;
}

/************************************************************************************************
• bool isSafe ( const vector < vector < bool > >& board, const int& row, const int& col ): This
routine checks if a queen can be placed in the row number row and the column
number col on the board. If the answer is yes, then it returns true.
*************************************************************************************************/
bool isSafe(const vector < vector < bool > >& board, const int& row, const int& col) 
{
	for(unsigned i=0;i<N;i++)
	{
		if(board[i][col])	
                return false;
	}
	for(unsigned i=0;i<N;i++)
	{
		for(unsigned j=0;j<N;j++)
		{
			if(board[i][j])
			{
				int x = abs(row-(int)i);
				int y = abs(col-(int)j);
				if(x == y)	
                                return false;
			}
		}
		
	}
	return true;
}

/***************************************************************************************
This function prints out the chess board after the puzzle is solved.
****************************************************************************************/
void printBoard(vector < vector < bool > >& board)
{
	for (unsigned a = 0; a <N; a++)
	{
		cout<<" "<<setfill('-')<<setw(5*N)<<" "<<"\n";
		unsigned k=1;
		for(k=1;k<=N;k++)
			{
			cout<<"|"<<"    ";
			}
			cout<<"|"<<endl;
			for( unsigned b=0; b<N; b++)
			{
				if(board[a][b])
				{
					cout<<"|"<<"  "<<"Q"<<" ";
				}
				else
				{
					cout<<"|"<<"  "<<" "<<" ";
				}
			}
			cout<<"|"<<"\n";
			for(k=1;k<=N;k++)
			{
				cout<<"|"<<"    ";
			}
			cout<<"|"<<endl;
	}
			cout<<" "<<setfill('-')<<setw(5*N)<<" "<<"\n";
			cout<<endl<<endl;
}

/***********************************************************************************************************
The initBoard function takes the board and initializes the board to false at every value. This function also 
initializes the random number generator
************************************************************************************************************/
void initBoard(vector< vector<bool> >& board) 
{
	srand(time(NULL));
	unsigned i=0;
	while(i<N)
	{
		vector <bool> row;
		i++;
		for(unsigned j=0;j<N;j++)
		row.push_back(false);                                        
                board.push_back(row);
	}
}
