#include <stdio.h>
#include <stdlib.h>


// Communal to both modes
//char* getInputFileData(char* inputFilName)
//{
//	use the function f.gets to open the txt file and convert it to string
//	return buffer string of chars filled with input data
//}
//	
// void parseCharIntoMatrix(char *data)
//{
//	parse the input data from a string into a 9X9 matrix called soduko[][], built from 'chars' & number 1-9;
//	Take into account only valid numbers 1-9, '.' sign and special 'chars' 
//}


//char* callSolver(char *soduko)
//{
//	assign another matrix of possibilties. what type of? stucture? string?
//	going over the matrix from top-left side. For each cell do:	
//	{
//		if num => continue to next cell
//		if dot => 
//		{
//			call int checkPossibleNumForCell(int *soduko, int row, int column)
//			{
//					go over the numbers from 1 to 9 and for each:
//					checkRow: whether the num is already there => break to num++, ow continue for next checking
//					checkCol: whether the num is already there => break to num++, ow continue for next checking
//					checkSubGrid: whether the num is already there => break to num++, ow continue for next checking
//					ow => assign num in the matching cell in possibilties matrix;
//					check possibilties matrix for the cell: 
//					if cell has one num => 
//					{
//						do the following:
//						update num in soduko[row][col]
//						go over the correspond row from 0 to row-1 and update numbers if possible
//						do the same for column & subgrid
//						do we need to check anything else ??
//					}
//					ow => continue to next cell;


//stop condition is met when we got to end of soduko matrix
//we then should check whether the possibilties matrix is equal to '0';
// if all cells are '0' => we succeeded in solving the martix
// ow => too hard


//	char *solution = 0;
//
//	return solution;
//}
//
//char* callChecker(char *data)
//{
//	going over the matrix from top-left side:


//	checking that the sum of each row equals '45'; This way we can identify duplication quickly;
//	if sum == '45' => continue to next row;
//	ow => check for duplication in the row by checkDuplicationRow (char *soduko, int row) :
//			for each cell from left to right go over the rest cells (right to it) and search for duplication
//			print the duplication error according to format; continue to next row
//
//	checking that the sum of each col equals '45'; 
//	if sum == '45' => continue to next col;
//	ow => check for duplication in the col by checkDuplicationCol (char *soduko, int col) :
//			for each cell from up to down go over the rest cells (down to it) and search for duplication
//			print the duplication error according to format; continue to next col
//	
//	checking that the sum of each subGrid from top-left side equals '45';
//	if sum == '45' => continue to next subGrid;
//	ow => check for duplication in the subGrid by checkDuplicationSubGrid(char *soduko, int subGrid) :
//			for each cell from left to right go over the rest cells (right to it) and search for duplication
//			print the duplication error according to format; continue to next subGrid
//
//	char *solution = 0;
//
//	return solution;
//}


//After modifing the input and reviewing the soduko, needs to write the outputData to file again =>
//int writeDataToOutputFile(char* outputData){}






int main(int argc, char *argv[]){
	
	FILE *infile;
	char *runMode, *inputFileName;
	char* data[11][11] = {0}; // TODO: need to add a #define ROWS/COLS in .h file

	// TODO: check if the arguments are givent at run time or needed inside the program
	runMode = argv[1]; 
	inputFileName = argv[2];
	// open the file from argv[1]
	// parse file to manegable format (without the seperations?, create structures?)
	// check running mode (argv[0]) and call the relevant function (0=>solver, 1=>checker)
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