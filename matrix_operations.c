#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <math.h>
using namespace std;
static int maxSize = 100;

//int matrixAdd();

//int matrixMult();

//int matrixSub();



int main() {
	ifstream infile;

	infile.open("C:\\Users\\owend\\Downloads\\matrix_input.txt");
	int count = 0;
	int N = maxSize;
	if (infile.is_open()) 
	{
		int x;
		while (infile >> x && count < (N * N * 2))
		{
			cout << x << endl;
			if (count == 0) {
				N = x;
				int *Array1 = (int*)malloc(N * sizeof(int));
				for (int i = 0; i < N; i++) {
					Array1[i] = 0;
				}
				if (Array1 == NULL) {
					printf("Memory allocation failed. Exiting...\n");
					return 1;
				}
				while (infile >> x && count < (N * N) - 1) {
					Array1[count] = x;
					count++;
				}


				int *Array2 = (int*)malloc(N * sizeof(int));
				for (int i = 0; i < N; i++) {
					Array2[i] = 0;
				}
				
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
