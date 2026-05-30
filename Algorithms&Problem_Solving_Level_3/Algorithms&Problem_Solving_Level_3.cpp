#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

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
void MaltplyMatrixs(int arrMatrix1[3][3], int  arrMatrix2[3][3], 
	                int MatrixResults[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			MatrixResults[i][j] = arrMatrix1[i][j] * arrMatrix2[i][j];
		}		
	}
}


//#9
void PrintMiddleRowMatrix(int Matrix1[3][3], short Rows, short Cols) {
	short MiddleRows = Rows / 2;

		for (short j = 0; j <Cols; j++)
		{
			printf("%0*d  ", 2, Matrix1[MiddleRows][j]);
		}		
}
void PrintMiddleColMatrix(int Matrix1[3][3], short Rows, short Cols) {
	short MiddleCols = Cols / 2;
		for (short j = 0; j < Rows; j++)
		{
			printf("%0*d  ", 2, Matrix1[j][MiddleCols]);
		}
}

//#10
int SumOfMatrix(int Matrix1[3][3], short Rows, short Cols) {
	int sum = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			sum += Matrix1[i][j];
		}
	}
	return sum;
}



//#11
bool AreEqualSumMatrices(int Matrix1[3][3], int Matrix2[3][3] , short Rows, short Cols) {
	return (SumOfMatrix(Matrix1, Rows, Cols) == SumOfMatrix(Matrix2, Rows, Cols));
}

//#12
bool AreTypicalMatrix(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] != Matrix2[i][j])
				return false;
		}
	}
	return true;
}

//#13
bool IsMatrixIdentity(int Matrix[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols;j++)
		{

			if (i != j && Matrix[i][j] != 0)
				return false;
			else if (i == j && Matrix[i][j] != 1)
			return false;

		}
	}
	return true;
}

//#14
bool IsScaral(int Matrix[3][3], short Rows, short Cols) {

	int FirstDiagElemement = Matrix[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Rows; j++)
		{
			if (i == j && Matrix[i][j] != FirstDiagElemement)
				return false;
			else if (i != j && Matrix[i][j] != 0)
				return false;
		}
	}
	return true;
}


//#15
int ReadPostiveNumber() {
	int Num = 0;
	do
	{
		cout << "\nEnter the number ? ";
		cin >> Num;
	} while (Num <= 0);
	return Num;
}
int CountNumberInMatrix(int Matrix[3][3], int Number, short Rows, short Cols) {
	short counter = 0;
	for (short i = 0; i < Rows; i++)
		for (short j = 0; j < Cols; j++)
			if (Matrix[i][j] == Number)
				counter++;
	return counter;
}


//#16
bool IsSparseMatrix(int Matrix[3][3], short Rows, short Cols) {
	short MatrixSize = (Rows * Cols);
	return (CountNumberInMatrix(Matrix, 0, Rows, Cols) > (MatrixSize / 2));
}

//#17
bool IsNumberInMatrix(int Matrix[3][3],int Number, short Rows, short Cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] == Number)
				return true;
		}
	}
	return false;
}


//#18
void PrintIntersectedNumbers(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols) {
	int Number=0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Number = Matrix1[i][j];
			if (IsNumberInMatrix(Matrix1, Number, Rows, Cols))
				cout <<setw(3) << Number << "   ";
		}
	}
	cout << endl;
}

//#19
int MaxNumberInMatrix(int Matrix[3][3], short Rows, short Cols) {
	int Max = Matrix[0][0];
		
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] > Max)
				Max = Matrix[i][j];
		}
	}
	return Max;
}
int MinNumberInMatrix(int Matrix[3][3], short Rows, short Cols) {
	int Min = Matrix[0][0];
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] < Min)
				Min = Matrix[i][j];
		}
	}
	return Min;
}

//#20
bool IsPalindromeMatrix(int Matrix[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols / 2; j++)
		{
			if (Matrix[i][j] != Matrix[i][Cols - 1 - j])
				return false;
		}
	}
	return true;
}

//#21
void PrintFibonacciUsingLoop(short Number) {
	int prev1 = 0, prev2 = 1;
	int FibNumber = 0;
	for (short i = 0; i < Number; i++)
	{
		FibNumber = prev1 + prev2;
		cout << FibNumber << "   ";
		prev2 = prev1;
		prev1 = FibNumber;
	}
}

//#22
void PrintFibonacciUsingRecurssion(short Number, int Prev1, int Prev2)
{
	int FibNumber = 0;
	if (Number > 0)
	{
		FibNumber = Prev1 + Prev2;
		cout << FibNumber << "   ";
		Prev2 = Prev1;
		Prev1 = FibNumber;
		PrintFibonacciUsingRecurssion(Number - 1, Prev1, Prev2);
	}
}


//#23
string ReadString() {
	string S1;
	cout << "Please Enter Your String?\n";
	getline(cin, S1);
	return S1;
}
void PrintFirstLetterOfEachWord(string S1) {
	bool IsFirstLetter = true;

	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ' && IsFirstLetter)
			cout << S1[i] << endl;

		IsFirstLetter = (S1[i] == ' ' ? true : false);
	}

}


//#24
string UpperFirstLetterOfEachWord(string S1) {
	bool IsFirstLetter = true;
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ' && IsFirstLetter) {
			S1[i] = toupper(S1[i]);
		}

		IsFirstLetter = (S1[i] == ' ' ? true : false);
	}
	return S1;
}

//#25
string LowerFirstLetterOfEachWord(string S1)
{
	bool isFirstLetter = true;
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ' && isFirstLetter)
		{
			S1[i] = tolower(S1[i]);
		}
		isFirstLetter = (S1[i] == ' ' ? true : false);
	}
	return S1;
}

//#26
string UpperAllString(string S1) {
	for (short  i = 0; i < S1.length(); i++)
	{
		S1[i] = toupper(S1[i]);
	}
	return S1;
}
string LowerAllString(string S1) {
	for (short  i = 0; i < S1.length(); i++)
	{
		S1[i] = tolower(S1[i]);
	}
	return S1;
}


//#27
char ReadChar() {
	char Ch1;
	cout << "Please Enter a Character?\n";
	cin >> Ch1;
	return Ch1;
}
char InvertLetterCase(char Ch1) {
	return (isupper(Ch1) ? tolower(Ch1) : toupper(Ch1));
}

//#28
string InvertAllLettersCase(string S1) {
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = InvertLetterCase(S1[i]);
	}
	return S1;
}

//#29
enum enWhatToCout { SmallLetters = 0, CaptalLetters = 1, All = 3 };
short CountLettres(string S1, enWhatToCout WhatToCount = enWhatToCout::All) {
	short counter = 0;

	if (WhatToCount == enWhatToCout::All)
		return S1.length();


	for (short i = 0; i < S1.length(); i++)
	{
		if(WhatToCount == enWhatToCout::SmallLetters && islower(S1[i]))
			counter++;

		if (WhatToCount == enWhatToCout::CaptalLetters && isupper(S1[i]))
			counter++;
	}
	return counter;
}

short SmallLetterCount(string S1) {
	short cout = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (islower(S1[i]))
			cout++;
	}
	return cout;
}
short CaptalLetterCount(string S1) {
	short cout = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (isupper(S1[i]))
			cout++;
	}
	return cout;
}

//#30 & #31
short FindcountLetter(string S1, char Ch1, bool MatchCase = true) {
	short count = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (MatchCase) {
			if (S1[i] == Ch1)
				count++;
		}
		else
		{
			if (tolower(S1[i]) == tolower(Ch1))
				count++;
		}
	}
	return count;
}


//#32
bool IsVowels(char Ch1) {
	string VowalCh = "aeiou";
	for (short i = 0; i < VowalCh.length(); i++)
	{
		if (VowalCh[i] == tolower(Ch1))
			return true;
	}
	return false;
}
bool IsVowels_Perfect(char Ch1) {
	Ch1 = tolower(Ch1);
	return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'u') || (Ch1 == 'o'));
}

//#33
short CountVowels(string Str) {
	short count = 0;
	for (short  i = 0; i < Str.length(); i++)
	{
		if (IsVowels_Perfect(Str[i]))
			count++;
	}
	return count;
}

//#34
void PrintVowels(string Str) {
		cout << "\nVowels in string are: ";
	for (short i = 0; i < Str.length(); i++)
	{
		if (IsVowels_Perfect(Str[i]))
			cout << Str[i] << "    ";
	}
	cout << endl;
}


//#35
void PrintEachWordInString(string Str) {
	cout << "\nYour string wrords are: \n\n";
	for (short i = 0; i < Str.length(); i++)
	{
		if (Str[i] != ' ')
			cout << Str[i];
		else
			cout << endl;
		
	}
}
void PrintEachWordInString_Perfect(string Str) {

	string sword;
	string delim = " ";
	short pos = 0;
	cout << "\nyour string wrords are: \n\n";
	while ((pos = Str.find(delim)) != std::string::npos) {
		sword = Str.substr(0, pos);
		if (sword != "")
			cout << sword << endl;

		Str.erase(0, pos + delim.length());
	}

	if (Str != "")
		cout << Str << endl;

}

//#36 
short CountWords(string Str) {
	string delim = " ";
	short pos = 0;
	short count = 0;
	string sWord;
	
	while ((pos = Str.find(delim)) != std::string::npos) {
		sWord = Str.substr(0, pos);
		if (sWord != "")
		{
		  count++;
		}
		Str.erase(0, pos+ delim.length());
	}
	if (Str != "")
		count++;

	return count;

}

//#37
vector <string> SplitString(string Str, string Delim) {

	vector <string> vString;
	int pos = 0;
	string sWord;
	
	// use find() function to get the position of the delimiters
	while ((pos = Str.find(Delim)) != std::string::npos) {
		sWord = Str.substr(0, pos);

		if (sWord != "")
			vString.push_back(sWord);

		Str.erase(0, pos + Delim.length());
	}

	if (Str != "")
		vString.push_back(Str);

	return vString;
}


//#38
string TrimLeft(string Str) {
	for (short i = 0; i < Str.length(); i++)
	{
		if (Str[i] != ' ')
			return (Str.substr(i , Str.length() - 1));
	}
	return "";
}
string TrimRight(string Str) {
	for (short i = Str.length() - 1; i >= 0; i--)
	{
		if (Str[i] != ' ')
			return (Str.substr(0 , i+1));
	}
	return "";
}
string Trim(string Str) {
	return (TrimLeft(TrimRight(Str)));
}


//#39
string JoinString(vector <string> vString , string Delim) {
	string Str;
	for (string& S : vString)
		Str += S + Delim;

	return Str.substr(0, Str.length() - Delim.length());
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

	cout << "\n=============================================================================\n";
	//#9
	cout << endl << "Matrix 1  " << endl;
	PrintMatrix(arrMatrix1, 3, 3);

	cout << endl << "Matrix 1 Middle Row " << endl;
	PrintMiddleRowMatrix(arrMatrix1, 3, 3);
	cout << endl << "Matrix 1 Middle Col " << endl;
	PrintMiddleColMatrix(arrMatrix1, 3, 3);

	
	cout << "\n=============================================================================\n";
	//#10
	cout << endl << "Matrix 1  " << endl;
	PrintMatrix(arrMatrix1, 3, 3);
	cout << "\nSum of Matrix1 is: " << SumOfMatrix(arrMatrix1, 3, 3);




	// #11 To #20
	
	// #11
	cout << "\n=============================================================================\n";
	cout << endl << "Matrix 1 Array Of Matrix " << endl;
	PrintMatrix(arrMatrix1, 3, 3);

	cout << endl << "Matrix 2 Array Of Matrix " << endl;
	PrintMatrix(arrMatrix2, 3, 3);

	if(AreEqualSumMatrices(arrMatrix1, arrMatrix2, 3, 3))
		cout << "\nYES: both martices are equal.";
	else
		cout << "\nNo: martices are NOT equal.";

	cout << "\n=============================================================================\n";

	//#12
	cout << endl << "Matrix 1 Array Of Matrix " << endl;
	PrintMatrix(arrMatrix1, 3, 3);

	cout << endl << "Matrix 2 Array Of Matrix " << endl;
	PrintMatrix(arrMatrix2, 3, 3);

	if (AreTypicalMatrix(arrMatrix1, arrMatrix2, 3, 3))
		cout << "\nyes,Both Matrix Are Typical " << endl;
	else
		cout << "\nNo ,Matrix Are Not Typical" << endl;

	cout << "\n=============================================================================\n";
	
	// #13
	int Matrix[3][3] = { {1,0,0},{0,1,0},{0,0,1} };

	cout << endl << "Array Of Matrix " << endl;
	PrintMatrix(Matrix, 3, 3);

	if (IsMatrixIdentity(Matrix, 3, 3))
		cout << "\nYes, Matrix  Is Identity.";
	else
		cout << "\nNo , Matrix Is Not Identity.";

	cout << "\n=============================================================================\n";

	//#14
	cout << endl << "Array Of Matrix " << endl;
	PrintMatrix(Matrix, 3, 3);
	if (IsScaral(Matrix, 3, 3))
		cout << "\nMatrix is scaral\n";
	else
		cout << "\nMatrix is not scaral\n";


	cout << "\n=============================================================================\n";
	////#15
	//int Matrix1[3][3] = { {9,1,12},{0,9,1},{0,9,9} };
	//cout << "\nMatrix1:\n";
	//PrintMatrix(Matrix1, 3, 3);

	//int Number = ReadPostiveNumber();

	//cout << "\nNumber " << Number << " count in matrix is "
	//	<< CountNumberInMatrix(Matrix1, Number, 3, 3) << endl;


	cout << "\n=============================================================================\n";
	//#16
	int Matrix2[3][3] = { {2,0,12},{9,0,0},{0,0,9} };

	cout << "\nMatrix2:\n";
	PrintMatrix(Matrix2, 3, 3);

	if (IsSparseMatrix(Matrix2, 3, 3))
		cout << "\nYes: It is Sparse\n";
	else
		cout << "\nNo: It's NOT Sparse\n";


	cout << "\n=============================================================================\n";
	////#17
	//cout << "\nMatrix2:\n";
	//PrintMatrix(Matrix2, 3, 3);
	//int Number = ReadPostiveNumber();

	////Using Count is a slower method , this iteration on all elemet even find number
	//if (CountNumberInMatrix(Matrix2, Number, 3, 3) > 0)
	//	cout << "\nYes it is there.\n";
	//else
	//	cout << "\nNo: It's NOT there.\n";

	////This is faster mthod
	//if (IsNumberInMatrix(Matrix2, Number, 3, 3))
	//	cout << "\nYes it is there.\n";
	//else
	//	cout << "\nNo: It's NOT there.\n";


	cout << "\n=============================================================================\n";
	//#18
	int Matrix3[3][3] = { {77,5,12},{22,20,1},{1,0,9} };
	int Matrix4[3][3] = { {5,80,90},{22,77,1},{10,8,33} };

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix3, 3, 3);
	cout << "\nMatrix2:\n";
	PrintMatrix(Matrix4, 3, 3);

	cout << "\nIntersected Numbers are: \n\n";
	PrintIntersectedNumbers(Matrix3, Matrix4, 3, 3);

	cout << "\n=============================================================================\n";
	//#19
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix3, 3, 3);

	cout << "\nMinimum Number is: ";
	cout << MinNumberInMatrix(Matrix3, 3, 3);
	cout << "\n\nMax Number is: ";
	cout << MaxNumberInMatrix(Matrix3, 3, 3);

	cout << "\n=============================================================================\n";
	//#20
	int Matrix5[3][3] = { {1,2,1},{5,5,5},{7,3,7} };
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix5, 3, 3);

	if(IsPalindromeMatrix(Matrix5, 3, 3))
		cout << "\nYes: Matrix is Palindrome\n";
	else
		cout << "\nNo: Matrix is NOT Palindrome\n";



	// #21 To #30
	cout << "\n=============================================================================\n";
	//#21
	PrintFibonacciUsingLoop(10);

	cout << "\n=============================================================================\n";
	//#22
	PrintFibonacciUsingRecurssion(10 ,0,1);

	cout << "\n=============================================================================\n";
	//#23
	//PrintFirstLetterOfEachWord(ReadString());

	cout << "\n=============================================================================\n";
	////#24
	//string  S1 = ReadString();
	//cout << "\nString after conversion:\n";
	//S1 = UpperFirstLetterOfEachWord(S1);
	//cout << S1 << endl;

	cout << "\n=============================================================================\n";
	////#25
	//string S2 = ReadString();
	//cout << "\nString after conversion:\n";
	//S2 = LowerFirstLetterOfEachWord(S2);
	//cout << S2 << endl;

	cout << "\n=============================================================================\n";
	////#26
	//string S3 = ReadString();
	//cout << "\nString After Conversoin toUpper: \n";
	//cout << UpperAllString(S3) << endl;
	//cout << "\nString After Conversoin toLower: \n";
	//cout << LowerAllString(S3) << endl;

	cout << "\n=============================================================================\n";
	////#27
	//char Ch1 = ReadChar();
	//cout << "char after Invert \n";
	//Ch1 = InvertLetterCase(Ch1);
	//cout << Ch1 << endl;

	cout << "\n=============================================================================\n";
	////#28
	//string S4 = ReadString();
	//cout << "\nString after invert \n";
	//S4 = InvertAllLettersCase(S4);
	//cout << S4 << endl;

	cout << "\n=============================================================================\n";
	////#29
	//string S5 = ReadString();

	//cout << "\nString Length : " << S5.length() << endl;
	//cout << "Small Letter Count : " << SmallLetterCount(S5) << endl;
	//cout << "Captal Letter Count : " << CaptalLetterCount(S5) << endl;

	//cout << "\n\nMethod 2\n";
	//cout << "\nString Length = " << CountLettres(S5);
	//cout << "\nCapital Letters Count= " << CountLettres(S5,enWhatToCout::CaptalLetters);
	//cout << "\nSmall Letters Count= " << CountLettres(S5, enWhatToCout::SmallLetters);

	cout << "\n=============================================================================\n";
	////#30
	//string S6 = ReadString();
	//char Ch2 = ReadChar();
	//cout << "\n Letter \'" << Ch2 << "\' count= " << FindcountLetter(S6, Ch2) << endl;
	////#31
	//cout << "\nLetter \'" << Ch2 << "\' ";
	//cout << "Or \'" << InvertLetterCase(Ch2) << "\' ";
	//cout << " Count = " << FindcountLetter(S6, Ch2, false);


	// #31 to #40
	cout << "\n=============================================================================\n";

	////#32
	//char Ch3 = ReadChar();
	//if(IsVowels(Ch3))
	//	cout << "\nYES Letter \'" << Ch3 << "\' is vowel";
	//else
	//	cout << "\nNO Letter \'" << Ch3 << "\' is NOT vowel";

	//cout << "\nThe Perfcet Way\n";

	//if(IsVowels_Perfect(Ch3))
	//	cout << "\nYES Letter \'" << Ch3 << "\' is vowel";
	//else
	//	cout << "\nNO Letter \'" << Ch3 << "\' is NOT vowel";


	cout << "\n=============================================================================\n";
	////#33
	//string Str = ReadString();
	//cout << "\nNumber of vowels is: " << CountVowels(Str) << endl;


	cout << "\n=============================================================================\n";
	////#34
	//PrintVowels(Str);

	cout << "\n=============================================================================\n";
	////#35
	//PrintEachWordInString(Str);
	//PrintEachWordInString_Perfect(Str);

	cout << "\n=============================================================================\n";
	////#36
	//cout << "\nThe number of words in your string is: ";
	//cout << CountWords(Str) << endl;

	cout << "\n=============================================================================\n";
	////#37
	//vector<string> vString;
	//vString = SplitString(ReadString(), " ");

	//cout << "\nTokens = " << vString.size() << endl;

	//for (string& s : vString)
	//	cout << s << endl;


	cout << "\n=============================================================================\n";
	//#38
	string S1 = " Mohammed Abu-Hahdoud ";
	cout << "\nString      = " << S1;
	cout << "\n\nTrim Left = " << TrimLeft(S1);
	cout << "\nTrim Right  = " << TrimRight(S1);
	cout << "\nTrim        = " << Trim(S1);

	cout << "\n=============================================================================\n";
	//#39
	vector<string> vString = { "Mohammed","Faid","Ali","Maher" };

	cout << "\nVector after join: \n";
	cout << JoinString(vString, "@");

	system("pause>0");
}


