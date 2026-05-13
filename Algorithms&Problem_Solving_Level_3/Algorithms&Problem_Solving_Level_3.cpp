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
			arr[r][c] = RandomNamber(1, 100);
		}
	}
}
void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	for (short r = 0; r <Rows ; r++)
	{
		for (short c = 0; c < Cols; c++)
		{
			cout << setw(3) << arr[r][c] << "   ";
		}
		cout << "\n";
	}
}

//#2
int SumRow(int arr[3][3], short RowNumber, short Cols) {
	int sum = 0;
	for (short j = 0; j < Cols; j++)
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
void FillOneDimantionalFromTowDimantionl(int arr1[3], int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++)
	{
		arr1[i] = SumRow(arr, i, Cols);
	}
}
void PrintOneDimantionalArray(int arr[3], int Length) {
	for (short i = 0; i < Length; i++)
	{
		cout << setw(3) << arr[i] << "   ";
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
	int arr1[3];
	cout << endl << endl;
	FillOneDimantionalFromTowDimantionl(arr1, arr, 3, 3);
	PrintOneDimantionalArray(arr1, 3);





	system("pause>0");
}


