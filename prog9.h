#ifndef H_PROG9           
#define H_PROG9

#include<stdio.h>
#include<iostream>		//Pre defined header files
#include<iomanip>
#include<vector>
#include<cstdlib> 
 
using std::cout;                //Appropriate using statementss used in the program
using std::cin;
using std::setw;
using std::setfill;
using std::vector;
using std::endl;

unsigned N=0;			//Declaring N as a global variable
 
/*************************************************************************************
void solveNQueens ( const unsigned& n ): This routine first creates a 2-d
vector of vectors of type bool for the given size n
**************************************************************************************/ 
void solveNQueens ( const unsigned& n );

/**************************************************************************************
bool solveNqueensUtil ( vector < vector < bool > >& board, const unsigned& row ): This
recursive routine starts on the row number row and gets a random column
number col, between 0 and ( board.size ( ) – 1) from the RNG, and it checks if a
queen can be placed on the location (row, col)
***************************************************************************************/
bool solveNQueensUtil ( vector < vector < bool > >& board, const unsigned& row );

/************************************************************************************************
• bool isSafe ( const vector < vector < bool > >& board, const int& row, const int& col ): This
routine checks if a queen can be placed in the row number row and the column
number col on the board. If the answer is yes, then it returns true.
*************************************************************************************************/
bool isSafe ( const vector < vector < bool > >& board, const int& row, const int& col );

/***************************************************************************************
This function prints out the chess board after the puzzle is solved.
****************************************************************************************/
void initBoard(vector< vector<bool> > &board);

/***********************************************************************************************************
The initBoard function takes the board and initializes the board to false at every value. This function also 
initializes the random number generator
************************************************************************************************************/
void printBoard(vector< vector<bool> > &board);

#endif                          //end of if.
