#include "sudoku.h"   //do not remove or replace
#include <stdio.h>

/* Tasks : Implement each and every function indicated
           in sudoku.h.  You are not allowed to modify
		   the parameter list or the return type.  Other
		   constraints and requirements are indicated in 
		   the instructions in the pdf file.
		   
		   Complete the main program based on the 
		   comments indicated.
*/
int isInRange(int num)
{
    int retval = 0;
    if (num >= 1 && num <= 9)
    {
        retval = 1;
    }
    return retval;
}

int isInRange(int num)
{
    int retval = 0;
    if (num >= 1 && num <= 9)
    {
        retval = 1;
    }
    return retval;
}

void getInput(int aMatrix[][SIZE])
{
	int i, j, temp;

	for(i = 0; i < SIZE; i++)
		while (j < SIZE)
		{
			scanf("%d", &temp);
			if(isInRange(temp))
			{
				aMatrix[i][j] = temp;
				j++;
			}
		}
}

void displayRow(int aRow[])
{
	int col;

	for (col = 0; col < SIZE; col++)
	{
		printf("%d ", aRow[col]);
		if ((col + 1) % 3 == 0)
			printf("   ");
	}
	printf("\n");		
}

void displayAll(int aMatrix[][SIZE])
{
	int row;
	
	for(row = 0; row < SIZE; row++)
	{
		displayRow(aMatrix[row]);
		if ((row + 1) % 3 == 0)
			printf("\n");
	}	
}

int Search (int key, int A[], int size)
{
	int i, count = 0;

	for (i = 0; i < size; i++)
		if(A[i] == key)
			count++;

	return count;
}

int checkrow(int aData[])
{
    int i = 0, returnval = 1;
    while(returnval && i < SIZE)
	{
		if(Search(i + 1, aData, SIZE) != 1)
			returnval = 0;
		
		i++;
	}
    return returnval;
}

void displayRow(int aRow[])
{
	int col;

	for (col = 0; col < SIZE; col++)
	{
		printf("%d ", aRow[col]);
		if ((col + 1) % 3 == 0)
			printf("   ");
	}
	printf("\n");		
}

void displayAll(int aMatrix[][SIZE])
{
	int row;
	
	for(row = 0; row < SIZE; row++)
	{
		displayRow(aMatrix[row]);
		if ((row + 1) % 3 == 0)
			printf("\n");
	}	
}

int
main()
{   int aMatrix[SIZE][SIZE];
    /* you can add your own variables */

    /* call getInput().  It is encouraged that you use
       input redirection, so you do not need to keep 
       typing a set of values.  Modify file containing
       the input values to consider other test cases OR
       create other files of input values per test case.
    */

	/* call displayAll() to verify that you got the inputs 
	   correctly.  Note the expected format of the displayed
	   result.
	*/ 
	
	/* call function checkrow() multiple times in loop.
	   Note that checkrow() will check one row at a time.
	*/
	
	/* write your condition to execute the following only 
	   if all rows are still correct.  Call function
	   checkcol() mutiple times in a loop. checkcol() will
	   check one column at a time.
	*/
	
	/* write your condition to execute the following only 
	   if all rows and columns are still correct.  Call 
	   function checkbox() mutiple times as the function will
	   check one 3x3 box at a time.
	*/
	
	
	/* if the matrix is a correctly solved Sudoku puzzle, 
	   display "Sudoku!".  Otherwise display "Wrong Solution". 
	   While debugging, it is suggested that you include
	   in the display which row or column or box the  
	   wrong solution was [first] detected. 
	*/

    return 0;
}
