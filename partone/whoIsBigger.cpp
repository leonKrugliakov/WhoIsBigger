//*****************************************************************************************************
//
//		File:				whoIsBigger.cpp
//		
//		Student:			Leon Krugliakov
//
//		Assignment:	 		Assignment #1 Part 1
//
//		Course Name:		Data Structures I
//
//		Course Number:		COSC 3050 - 01
//
//		Due:				August 31, 2020 
//
//
//		This program takes in four different data types of user input
//		such as ints, doubles, chars, and c strings. Then the program
//		computes which input was the largest and outputs the result to
//		the user.
//
//		Other files required: 
//		
//*****************************************************************************************************

#include <iostream>
#include <typeinfo>

using namespace::std;

//*****************************************************************************************************

void getData(int& intInput1, int& intInput2);

//*****************************************************************************************************

void getData(double& doubleInput1, double& doubleInput2);

//*****************************************************************************************************

void getData(char& charInput1, char& charInput2);

//*****************************************************************************************************

void getData(char charInputs1[], char charInputs2[]);

//*****************************************************************************************************

char* findBigger(char input1[], char input2[]);

//*****************************************************************************************************

template <typename T>
T findBigger(T input1, T input2);

//*****************************************************************************************************

template <typename T>
void displayBiggest(T biggest, T input1, T input2);

//*****************************************************************************************************

int main()
{
	int intInput1,
		intInput2;
	double doubleInput1,
		doubleInput2;
	char charInput1,
		charInput2;
	char charInputs1[81],
		charInputs2[81];

	getData(intInput1, intInput2);

	getData(doubleInput1, doubleInput2);

	getData(charInput1, charInput2);

	getData(charInputs1, charInputs2);

	displayBiggest(findBigger(intInput1, intInput2), intInput1, intInput2);

	displayBiggest(findBigger(doubleInput1, doubleInput2), doubleInput1, doubleInput2);

	displayBiggest(findBigger(charInput1, charInput2), charInput1, charInput2);

	displayBiggest(findBigger(charInputs1, charInputs2), charInputs1, charInputs2);

	system("pause");

	return 0;
}

//*****************************************************************************************************

void getData(int& intInput1, int& intInput2) 
{
	cout << "Integers: " << "\t";
	cin >> intInput1 >> intInput2;
	cout << endl;
}

//*****************************************************************************************************

void getData(double& doubleInput1, double& doubleInput2) 
{
	cout << "Doubles: " << "\t";
	cin >> doubleInput1 >> doubleInput2;
	cout << endl;
}

//*****************************************************************************************************

void getData(char& charInput1, char& charInput2) 
{
	cout << "Chars: " << "\t";
	cin >> charInput1 >> charInput2;
	cout << endl;
}

//*****************************************************************************************************

void getData(char charInputs1[], char charInputs2[]) 
{
	cout << "C-Strings: " << "\t";
	cin.ignore();
	cin.getline(charInputs1, 81);
	cin.getline(charInputs2, 81);
	cout << endl;
}

//*****************************************************************************************************

char* findBigger(char input1[], char input2[])
{
	char * bigger = input1;

	if (strcmp(input1, input2) < 0)
	{
		bigger = input2;
	}

	return bigger;
}

//*****************************************************************************************************


template <typename T>
T findBigger(T input1, T input2)
{
	T bigger = input1;

	if (input1 < input2) 
	{
		bigger = input2;
	}

	return bigger;
}

//*****************************************************************************************************

template <typename T>
void displayBiggest(T biggest, T input1, T input2) 
{
	cout << "The user entered: " << input1 << "\t" << input2 << endl;
	cout << "The biggest: " << typeid(biggest).name() << " is: " << biggest << endl << endl;
}

//*****************************************************************************************************

/*
Integers:       75
6

Doubles : 89.35
123.4

Chars : z
a

C - Strings : apple pie
peach pie

The user entered : 75    6
The biggest : int is : 75

The user entered : 89.35 123.4
The biggest : double is : 123.4

The user entered : z     a
The biggest : char is : z

The user entered : apple pie     peach pie
The biggest : char * is : peach pie

Integers:       6
75

Doubles:        123.4
89.35

Chars:  a
z

C-Strings:      peach pie
apple pie

The user entered: 6     75
The biggest: int is: 75

The user entered: 123.4 89.35
The biggest: double is: 123.4

The user entered: a     z
The biggest: char is: z

The user entered: peach pie     apple pie
The biggest: char * is: peach pie

*/