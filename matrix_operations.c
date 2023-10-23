#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;
static int maxSize = 100;

//int matrixAdd();

//int matrixMult();

//int matrixSub();



int main() {
	ifstream infile;

	infile.open("C:\\Users\\owend\\Downloads\\matrix_input.txt");
	int count = 0;
	int matrix_size = 0;
	if (infile.is_open()) 
	{
		int x;
		while (infile >> x && count < 18)
		{
			cout << x << endl;
			if (count == 0) {
				matrix_size = x;
			}
		}

		

		infile.close();
	}
	else
	{
		cout << "ERROR" << endl;
	}

	cin.get();
}
