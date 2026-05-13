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
int SumRow(int arr[3][3], int Row, int Cols) {
	int Sum = 0;
	for (short i = 0; i < Cols; i++)
	{
		Sum += arr[Row][i];
	}
}

void PrintEachSumRows(int arr[3][3], short Rows, short Cols) {
	for (short r = 0; r <Rows ; r++)
	{
		printf("\nSum Row %d = %d", r + 1, SumRow(arr, r, Cols));
	}
		cout << endl;
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
	system("pause>0");
}


