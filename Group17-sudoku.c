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

void getInput(int aMatrix[][SIZE])
{
	int i, j, temp;

	for(i = 0; i < SIZE; i++)
        {
                j = 0;
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

int checkcol(int aMatrix[][SIZE], int nColInd)
{
        int i;
        int j = 0;
        int returnval = 1;
        int temp[9];

        for(i = 0; i < SIZE; i++)
                temp[i] = aMatrix[i][nColInd];

        while(returnval && j < SIZE)
	{
		if(Search(j + 1, temp, SIZE) != 1)
			returnval = 0;
		j++;
	}

    return returnval;
}

int checkbox(int aMatrix[][SIZE], int nRow, int nCol)
{

        int i = 0;
        int j = 0;
        int colMax = nCol + 3;
        int rowMax = nRow + 3;
        int returnval = 1;
        int temp[9];

        while (nRow < rowMax)
        {
                while(returnval && nCol < colMax)
                {
                        temp[i] = aMatrix[nRow][nCol];
                        nCol++;
                        i++;
                }
                nCol -= 3;
                nRow++;
        }

        while(j < SIZE && returnval)
        {
                if(Search(j + 1, temp, SIZE) != 1)
                        returnval = 0;
                j++;
        }

	
    return returnval;
}

int
main()
{   int aMatrix[SIZE][SIZE];
    /* you can add your own variables */
	int row, col, box, box_row, box_col; 
	int row_checker = 1, col_checker = 1, box_checker = 1;

    /* call getInput().  It is encouraged that you use
       input redirection, so you do not need to keep 
       typing a set of values.  Modify file containing
       the input values to consider other test cases OR
       create other files of input values per test case.
    */
	getInput(aMatrix);

	/* call displayAll() to verify that you got the inputs 
	   correctly.  Note the expected format of the displayed
	   result.
	*/ 
	displayAll(aMatrix);
	
	/* call function checkrow() multiple times in loop.
	   Note that checkrow() will check one row at a time.
	*/
	row = 0;
	while(row_checker && row < SIZE)
	{
		if(!checkrow(aMatrix[row]))
			row_checker = 0;
		else
			row++;
	}
	
	/* write your condition to execute the following only 
	   if all rows are still correct.  Call function
	   checkcol() mutiple times in a loop. checkcol() will
	   check one column at a time.
	*/
	if (row_checker)
	{
		col = 0;
		while(col_checker && col < SIZE)
		{
			if(!checkcol(aMatrix, col))
				col_checker = 0;
			else
				col++;
		}
	}
	/* write your condition to execute the following only 
	   if all rows and columns are still correct.  Call 
	   function checkbox() mutiple times as the function will
	   check one 3x3 box at a time.
	*/
	if(row_checker && col_checker)
	{
		box = 0;
		box_row = 0;
		box_col = 0;
		while(box_checker && box_row < SIZE)
		{
                        box_col = 0;
			while (box_checker && box_col < SIZE)
			{
				if(!checkbox(aMatrix, box_row, box_col))
					box_checker = 0;
				else
                                {
					box_col += 3;
                                        box++;
                                }
			}
			if(box_checker)
			{
				box_row += 3;
			}
		}	
	}

	/* if the matrix is a correctly solved Sudoku puzzle, 
	   display "Sudoku!".  Otherwise display "Wrong Solution". 
	   While debugging, it is suggested that you include
	   in the display which row or column or box the  
	   wrong solution was [first] detected. 
	*/
	if(row_checker && col_checker && box_checker)
		printf("Sudoku!");
	else
	{
		printf("Wrong Solution on: ");
		if(col_checker && box_checker)
			printf("Row %d", row + 1);
		else if (row_checker && box_checker)
			printf("Column %d", col + 1);
		else if (row_checker && col_checker)
			printf("Box %d", box + 1);
	}

        printf("\n");
	
    return 0;
}
