#include <stdio.h>
#include <stdlib.h>
#include "Main.h"

// Tomer's Part !!!!!!!!!!!!!!!!!!!!!!!!!!

//	passing on the relevant row values and modify flagArray[existValue] = '0';
void callCheckRow(char* soduko[], int array[], int row)
{
	for (int j = 0; j < 9; j++)
		if (soduko[row][j] != '.') array[soduko[row][j]-1] = 0;
}

//	passing on the relevant col values and modify flagArray[existValue] = '0';
void callCheckCol(char* soduko[], int array[], int col)
{
	for (int i = 0; i < 9; i++)
		if (soduko[i][col] != '.') array[soduko[i][col]-1] = 0;
}

//	passing on the relevant subGrid values and modify flagArray[existValue] = '0';
void callCheckSubGrid(char* soduko[], int array[], int row, int col)
{
	int rowSubgrid = (row / 3) * 3;
	int colSubGrid = (col / 3) * 3;
	int i, j;
	for (i = rowSubgrid; i < rowSubgrid + 3; i++)
	{
		for (j = colSubGrid; j < colSubGrid + 3; j++)
			if (soduko[i][j] != '.') array[soduko[i][j]-1] = 0;
	}
}

int checkPossibleNumForCell(char* soduko, int row, int col)
{
	int cnt = 0, k; 
	char returnValue;
	void callCheckRow(char*, int, int);
	void callCheckRow(char*, int, int);
	void callCheckSubGrid(char*, int, int, int);

	//	allocate a 9cell array initiated by 'ones':
	int flagArray[9] = { 1,1,1,1,1,1,1,1,1 };
	callCheckRow(soduko, flagArray, row);
	callCheckCol(soduko, flagArray, col);
	callCheckSubGrid(soduko, flagArray, row, col);

	//	count all 'one' values at flagArray[];
	//	if cnt == 1 => find the value and return its index; ow => return 0;
	for (k = 0; k < 9; k++)
	{
		cnt += flagArray[k];
		if (flagArray[k] == 1) returnValue = k + 1;
	}
	if (cnt == 1) return returnValue;
	else return 0;
}

//	This funcion checks the status of the soduko martix; if soduko[9][9] is still not full => will return 0, ow => will return 1;
int sodukoStatus(char* soduko[])
{
	int i, j; 
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (soduko[i][j] == '.') return 0;
			else continue;
		}
	}
	return 1;
}

//	This function solves the soduko if possible, ow => will output an appropriate impossible message
char* callSolver(char soduko)
{
	char* solverOutput; int assigningWasMade = 0;
	int sodukoStatus(char); int solved = 0;
	do
	{
		//	going over the matrix from top-left side and start filling it
		int i, j; checkPossibleNumForCell;
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				if (soduko[i][j] != '.') continue;
				else
				{
					//				check possibilities for that cell
					checkPossibleNumForCell(soduko, i, j);

					//				check if cell has deterministic value; 
					//				if yes => assign soduko[][] = returnValue; ow => continue;
					if (checkPossibleNumForCell != 0)
					{
						soduko[i][j] = checkPossibleNumForCell;
						assigningWasMade = 1;
					}
					else continue;
				}
			}
		}
		if (solved = assigningWasMade && sodukoStatus(soduko)) break;
	} while (assigningWasMade);

	//	one step before returning to caller; here we will deter whether the soduko was solved or not;
	switch (solved = assigningWasMade && sodukoStatus(soduko))
	{
	case 0:
	{
		printf("Sudoku	puzzle	is	too	hard	for	me	to	solve\n");
		break;
	}
	case 1:
		return soduko[9][9];
	}
	return 0;
}


//	char *solution = 0;
//
//	return solution;
//}


char* callChecker(char soduko[9][9])
{
	int i, j;
	int rowGrid = 3 * i;
	int colGrid = 3 * j;
	int sumRowChecker(char, int); void printRowDuplications(char);
	int sumColChecker(char, int); void printColDuplications(char);
	int sumSubGridChecker(char, int, int); void printSubGridDuplications(char);
	int isValid = rowChecker && colChecker && subGridChecker;

	//	going over the matrix and verify that each of the special templates' sum equals 45; This way we can identify duplication quickly;
	//	ow => there must be duplication

	//	check row's sum indication
	for (i = 0; i < 9; i++)
		sumRowChecker(soduko, i);
		
	//	check col's sum indication
	for (j = 0; j < 9; j++)
		sumColChecker(soduko, j);

	//	check subGrid's sum indication
	i = 0;
	for (rowGrid = 0; rowGrid < 9; i++)
	{
		j = 0;
		for (colGrid = 0; colGrid < 9; j++)
			sumSubGridChecker(soduko, rowGrid, colGrid);
	}

//	check if there was any error messages by now using 'isValid' function;
//	if yes => they were already been printed
//	ow => print success
	if (isValid) printf("No errors found in given Sudoku puzzle\n");
	else
	{
		if (!sumRowChecker)
			printRowDuplications(soduko);

		if (!sumColChecker)
			printRowDuplications(soduko);

		if (!sumSubGridChecker)
			printRowDuplications(soduko);
	}
}

//	char *solution = 0;
//
//	return solution;
//}

//After modifing the input and reviewing the soduko, needs to write the outputData to file again =>
//int writeDataToOutputFile(char* outputData){}


// Platform main() for checking the functions !!!!!!!!!!!!!!!!!!!!!!!!!!

int flag = 0;               /* 1 - Error, 0 - Success */

//int printNotValid(char *array, int type, int errorLocation);
//int check(char *array);
//void printUsage();


int main()
{
	int i, j;
	char* callSolver(char);
	char soduko[9][9] = {
						{'.','.','1','7','.','6','3','.','.'},
						{'.','.','3','4','.','2','8','.','.'},
						{'2','.','.','.','.','.','.','4','.'},
						{'.','9','.','1','.','3','.','4','.'},
						{'1','.','.','.','8','.','.','.','3'},
						{'.','4','.','6','.','7','.','9','.'},
						{'8','.','.','.','.','.','.','.','.'},
						{'.','.','6','2','.','1','4','.','.', },
						{'.','.','9','8','.','.','2','.','.'}
	};

	/* Printing the matrix */
	printf("\n -- sudoku before -- \n");
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
			printf("%c ", soduko[i][j]);
		printf("\n");
	}

	printf("\n -- sudoku after -- \n");
	callSolver(soduko);
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
			printf("%c ", soduko[i][j]);
		printf("\n");
	}

}

// Lior's Part !!!!!!!!!!!!!!!!!!!!!!!!!!

int main(int argc, char *argv[]) {

	FILE *infile;
	char *runMode, *inputFileName;
	char* data[11][11] = { 0 }; // TODO: need to add a #define ROWS/COLS in .h file

								//Not sure if you convert the txt into string at that point ??
								//Communal to both modes
								//char* getInputFileData(char* inputFilName)
								//{
								//	use the function f.gets to open the txt file and convert it to string
								//	return buffer of chars filled with input data
								//}

								// TODO: check if the arguments are givent at run time or needed inside the program
	runMode = argv[1];
	inputFileName = argv[2];
	// open the file from argv[1]
	// parse file to manegable format (without the seperations?, create structures?)
	// check running mode (argv[0]) and call the relevant function (0=>solver, 1=>checker)

	//before calling the functions we must parse the buffer into a 9X9 matrix named soduko[][]
	//this will save us to do it twice inside each function

	//switch (runMode)
	//{
	//case 0:
	//	callSolver(data);
	//	break;
	//case 1:
	//	callChecker(data);
	//	break;
	//}
	// reparse the data into the solutions style
	// write the reparsed-date into the output file (argv[2])
	getchar();
	return 0;
}



