#include <iostream>
#include <iomanip>
using namespace std;

int RandomNamber(int From, int To) {
	return rand() % (To - From + 1) + From;
}

//#1
void FillMatrixWithRandomNumbers(int arr[3][3] , short Rows , short Cols) {
	for (short r = 0; r < Rows; r++)
	{
		for (short c = 0; c < Cols; c++)
		{
			arr[r][c] = RandomNamber(1, 10);
		}
	}
}
void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	for (short r = 0; r <Rows ; r++)
	{
		for (short c = 0; c < Cols; c++)
		{
			//cout << setw(3) << arr[r][c] << "   ";
			cout << setw(3);
			printf(" %0*d  ", 2, arr[r][c]);
			
		}
		cout << "\n";
	}
}

//#2
int SumRow(int arr[3][3], short RowNumber, short Cols) {
	int sum = 0;
	for (short j = 0; j <= Cols-1; j++)
	{
		sum += arr[RowNumber][j];
	}
	return sum;
}
void PrintEachSumRows(int arr[3][3], short Rows, short Cols) {
	for (short r = 0; r <Rows ; r++)
	{
		printf("\nSum Row %d = %d", r + 1, SumRow(arr, r, Cols));
	}
		cout << endl;
}

//#3 
void FillSumMatixRowsInArry(int arr1[3], int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++)
	{
		arr1[i] = SumRow(arr, i, Cols);
	}
}
void PrintRowsSumArray(int arr[3], int Length) {
	for (short i = 0; i < Length; i++)
	{
		cout << "sum row " << i+1<< " = " << arr[i] << endl;
	}
}


//#4
int SumCol(int arr[3][3], int rows, int colCurrunt) {
	int sum = 0;
	for (short i = 0; i < rows; i++)
	{
		sum += arr[i][colCurrunt];
	}
	return sum;
}
void PrintEachSumCols(int arr[3][3], short Rows, short Cols) {
	for (size_t i = 0; i < Cols; i++)
	{
		cout << "Sum col " << i + 1 << " = " << SumCol(arr, Rows, i) << endl;
	}
}

//#5
void FillSumMatixColsInArry(int arr2[3], int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Cols; i++)
	{
		arr2[i] = SumCol(arr, Rows, i);
	}
}
void PrintColsSumArray(int arr[3], int Length) {
	for (short i = 0; i < Length; i++)
	{
		cout << "sum col " << i+1<< " = " << arr[i] << endl;
	}
}


// #6
void FillMatrixWithOrderedNumbers(int arrOrder[3][3], short Rows, short Cols) {
	short Counter = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Counter++;
			arrOrder[i][j] = Counter;
		}
	}
}


//#7
void TransposedMatrix(int arrOrder[3][3], int arrTransposed[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Rows; j++)
		{
			arrTransposed[j][i] = arrOrder[i][j];
		}	
	}
}


//#8
void MaltplyMatrixs(int arrMatrix1[3][3], int  arrMatrix2[3][3], int MatrixResults[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			MatrixResults[i][j] = arrMatrix1[i][j] * arrMatrix2[i][j];
		}		
	}
}



int main()
{
	srand((unsigned)time(NULL));

   // #1 To #10

	//#1
	int arr[3][3];
	FillMatrixWithRandomNumbers(arr ,3,3);
	cout << "\n The following is a 3x3 random matrix:\n";
	PrintMatrix(arr, 3, 3);

	// #2
	cout << endl << "sum number for Each Rows";
	PrintEachSumRows(arr, 3, 3);


	// #3
	int arrRows[3];
	cout << endl << "Array of sum rows" << endl;
	FillSumMatixRowsInArry(arrRows, arr, 3, 3);
	PrintRowsSumArray(arrRows, 3);


	//#4 
	cout << endl << "Sum Cols from mantrix array " << endl;
	PrintEachSumCols(arr, 3, 3);

	// #5
	cout << endl << "Array of sum cols" << endl;
	int arrCols[3];
	FillSumMatixColsInArry(arrCols, arr, 3, 3);
	PrintColsSumArray(arrCols, 3);

	cout << "\n=============================================================================\n";

	// #6
	int arrOrder[3][3];
	cout << endl << "Order Array Of Matrix " << endl;
	FillMatrixWithOrderedNumbers(arrOrder, 3, 3);
	PrintMatrix(arrOrder, 3, 3);

	//#7
	int arrTransposed[3][3];
	cout << endl << "Transposed Array Of Matrix " << endl;
	TransposedMatrix(arrOrder, arrTransposed, 3, 3);
	PrintMatrix(arrTransposed, 3, 3);

	cout << "\n=============================================================================\n";
	//#8
	int arrMatrix1[3][3], arrMatrix2[3][3] , MatrixResults[3][3];

	FillMatrixWithRandomNumbers(arrMatrix1, 3, 3);
	cout << endl << "Matrix 1 Array Of Matrix " << endl;
	PrintMatrix(arrMatrix1, 3, 3);

	FillMatrixWithRandomNumbers(arrMatrix2, 3, 3);
	cout << endl << "Matrix 2 Array Of Matrix " << endl;
	PrintMatrix(arrMatrix2, 3, 3);

	MaltplyMatrixs(arrMatrix1, arrMatrix2, MatrixResults, 3, 3);
	cout << endl << "Maltply Two Array Of Matrix " << endl;
	PrintMatrix(MatrixResults, 3, 3);

	system("pause>0");
}


