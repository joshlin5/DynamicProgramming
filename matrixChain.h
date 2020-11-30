#ifndef MATRIXCHAIN_H
#define MATRIXCHAIN_H

#include <iostream>
#include <vector>

#define NUM 100 //maximum value for a cell of the matrix
#define SIZE 100 //maximum dimension for rows/columns of a matrix

using namespace std;

typedef vector<vector<int> > Matrix;

class MatrixChain
{
protected:
    vector<Matrix> chain;
    vector<int> dimensions;

public:
    MatrixChain(int);
    Matrix multiply(Matrix a, Matrix b); //TODO - BONUS
    Matrix dynamicChain(); //TODO
	 Matrix mergeSort(Matrix k, int beginning, int end);
	
	// finds and returns the minimum between two numbers
	int min(int a, int b){
		if(a < b)
			return a;
		return b;
	}

    void printDimensions() {
        //print the dimensions generated
        cout << "{";
            for (int i = 0; i < dimensions.size() - 1; i++) {
                cout << dimensions[i] << ",";
            }
        cout << dimensions[dimensions.size() - 1] << "}" << endl;
    }

private:
    void generate_matrix(int, int);
};

#endif
