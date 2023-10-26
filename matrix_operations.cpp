//Lab 6: Matrix Manipulation
//Owen Deines
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <vector>
using namespace std;
static int maxSize = 100;

vector<vector<int>> addMatrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2);


vector<vector<int>> multiplyMatrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2);

vector<vector<int>> subtractMatrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2);




int main() {
	cout << "Owen Deines" << endl;
	cout << "Lab 6: Matrix Manipulation" << endl;
	ifstream infile;

	infile.open("matrix_input.txt");
	int count = 0;
	int N = maxSize;
	if (infile.is_open()) 
	{
		int x;
		int Aflag = 0;
		int Bflag = 0;
		
		infile >> x;
		N = x;
		count++;
		infile >> x;
			
			
				
		vector<vector<int>> matrix1(N, vector<int>(N, 0));
		vector<vector<int>> matrix2(N, vector<int>(N, 0));
		while (count < N) {
			if (Aflag == 0) {
				cout << "Matrix A:" << endl;
				Aflag++;
			}
			if (count <= (N * N)) {
				for (int k = 0; k < N; ++k) {
					for (int y = 0; y < N; ++y) {
						matrix1[k][y] = x;
						cout << matrix1[k][y] << " ";
						if (count != N * N) {
							infile >> x;
						}
						count++;
					}
					cout << endl;
				}
				
			}
			infile >> x;
			if (Bflag == 0) {
				cout << "Matrix B:" << endl;
				Bflag++;
			}
			if (count > (N * N)) {
				
				for (int k = 0; k < N; ++k) {
					for (int y = 0; y < N; ++y) {
						matrix2[k][y] = x;
						cout << matrix2[k][y] << " ";
						infile >> x;
						count++;
					}
					cout << endl;
				}
				
			}
			
			
		}
		
		infile.close();
		
		vector<vector<int>> resultMatrix = addMatrices(matrix1, matrix2);

		
		cout << "Matrix Sum (A + B):" << endl;
		for (int k = 0; k < N; ++k) {
			for (int y = 0; y < N; ++y) {
				cout << resultMatrix[k][y] << " ";
			}
			cout << endl;
		}

		vector<vector<int>> resultMatrix2 = multiplyMatrices(matrix1, matrix2);

		cout << "Matrix Product (A * B):" << endl;
		for (int k = 0; k < N; ++k) {
			for (int y = 0; y < N; ++y) {
				cout << resultMatrix2[k][y] << " ";
			}
			cout << endl;
		}

		vector<vector<int>> resultMatrix3 = subtractMatrices(matrix1, matrix2);

		cout << "Matrix Difference (A - B):" << endl;
		for (int k = 0; k < N; ++k) {
			for (int y = 0; y < N; ++y) {
				cout << resultMatrix3[k][y] << " ";
			}
			cout << endl;
		}
	}
	
	
	
}

vector<vector<int>> addMatrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
	int rows = matrix1.size();
	int cols = matrix1[0].size();
	vector<vector<int>> result(rows, vector<int>(cols, 0));
	for (int k = 0; k < rows; ++k) {
		for (int y = 0; y < cols; ++y) {
			result[k][y] = matrix1[k][y] + matrix2[k][y];
		}
	}
	return result;
}

vector<vector<int>> multiplyMatrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
	int rows1 = matrix1.size();
	int cols1 = matrix1[0].size();
	int cols2 = matrix2[0].size();
	vector<vector<int>> result(rows1, vector<int>(cols2, 0));

	for (int i = 0; i < rows1; ++i) {
		for (int y = 0; y < cols2; ++y) {
			for (int k = 0; k < cols1; ++k) {
				result[i][y] += matrix1[i][k] * matrix2[k][y];
			}
		}
	}

	return result;
}

vector<vector<int>> subtractMatrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
	int rows = matrix1.size();
	int cols = matrix1[0].size();
	vector<vector<int>> result(rows, vector<int>(cols, 0));

	for (int k = 0; k < rows; ++k) {
		for (int y = 0; y < cols; ++y) {
			result[k][y] = matrix1[k][y] - matrix2[k][y];
		}
	}

	return result;
}
