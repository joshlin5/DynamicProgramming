#include "matrixChain.h"

#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <vector>
#include <iostream>
#include <limits>

using namespace std;

MatrixChain::MatrixChain(int num) {
    dimensions = vector<int>(num + 1, 0);
    for (int i = 0; i < num + 1; i++) {
        int dim = rand() % SIZE + 1;
        dimensions[i] = dim;
    }

    for (int i = 0; i < num; i++) {
        generate_matrix(dimensions[i], dimensions[i + 1]);
    }
}

void MatrixChain::generate_matrix(int rows, int cols) {
    srand(time(0));

    Matrix matrix(rows, vector<int>(cols, 0));
    for (int j = 0; j < rows; j++) {//row
        for (int k = 0; k < cols; k++) {//
            matrix[j][k] = rand() % NUM + 1;
        }
    }
    chain.push_back(matrix);
}

Matrix MatrixChain::multiply(Matrix a, Matrix b) {
    //implement here the simple multiplication between two matrices
	 // debug for which matrixs are multiplying each other
	 //cout << "a size: " << a.size() << " " << a[0].size() << endl;
	 //cout << "b size: " << b.size() << " " << b[0].size() << endl;
	 Matrix result(a.size(), vector<int> (b[0].size()));
	 for (int i = 0; i < a.size(); i++){
		 for (int j = 0; j < b[0].size(); j++){
			result[i][j] = 0;
			for (int k = 0; k < a[0].size(); k++){
				result[i][j] += a[i][k] * b[k][j];
			}
		 }
	 }
	 // for debugging this function
	/*cout << "Result: " << endl;
	for (int i = 0; i < result.size(); i++){
		for (int j = 0; j < result[0].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}*/
	return result;
}

Matrix MatrixChain::mergeSort(Matrix k, int start, int end)
{
	Matrix leftHalf;
	Matrix rightHalf;
	int spilt = -1;
	if(end - start == 1){
		return multiply(chain[start], chain[end]);
	}
	else{
		spilt = k[start][end];
		//cout << "Spilting at: " << spilt << endl;
		if(spilt - start > 0){
			//cout << "Left merge" << endl;
			leftHalf = mergeSort(k, start, spilt);
		}
		else{
			leftHalf = chain[start];
			//cout << "Left: " << leftHalf.size() << " "<< leftHalf[0].size() << endl;
		}
		if(end - (spilt + 1) > 0){
			//cout << "Right merge" << endl;
			rightHalf = mergeSort(k, spilt + 1, end);
		}
		else
			rightHalf = chain[end];
		return multiply(leftHalf, rightHalf);
	}
}

Matrix MatrixChain::dynamicChain() {
    //implement here the optimal approach using the dynamic programming algorithm
    // for debug. prints out each matrix
	 /*for(int i = 0; i < chain.size(); i++){
		 cout << "Matrix " << i+1 << ":" << endl;
		 for(int a = 0; a < chain[i].size(); a++){
			 for(int b = 0; b <chain[i][a].size(); b++){
				cout << chain[i][a][b] << " ";
			 }
			 cout << endl;
		 }
	 }*/
		 
	 Matrix steps(chain.size(), vector<int> (chain.size()));
	 Matrix spilt(chain.size(), vector<int> (chain.size()));
	 int solution = -1;
    for (int i = 0; i < chain.size(); i++){
		steps[i][i] = 0;
		spilt[i][i] = 0;
    }
	 for (int b = 1; b < chain.size(); b++){
		for (int i = 0; i < chain.size() - b; i++){
			int j = i + b;
			steps[i][j] = std::numeric_limits<int>::max();
			for (int k = i; k < j; k++){
				int newStep = steps[i][k]+steps[k+1][j]+(dimensions[i]*dimensions[k+1]*dimensions[j+1]);
				// for debugging and printing out the steps and whats going on in these for loops
				//cout << "Comparing " << steps[i][j] << " and " << newStep << " at " << i << " " << j << " with k being " << k << endl;
				if (steps[i][j] > newStep)
				{
					spilt[i][j] = k;
				}
				steps[i][j] = min(steps[i][j], newStep);
				solution = steps[i][j];
			}
	 	}
	 }
	 cout << "Optimal Steps: " << solution << endl;
	 // for debugging and printing k
	 /*cout << "k values: " << endl;
	 for(int i = 0; i < spilt.size(); i++){
		for (int j = i + 1; j < spilt[i].size(); j++){
			cout << spilt[i][j] << " ";
		}
		cout << endl;
	 }*/
	 // prints out whats going into mergeSort
	 //cout << "start: " << 0 << " end: " << chain.size()-1 << endl;
	 // prints out where the first spilt is going to be at
	 //cout << "First spilt at " << spilt[0][chain.size()-1] << endl;
	 Matrix answer =  mergeSort(spilt, 0, chain.size() - 1);
	 // for debugging. prints out the matrix we get from multiplication
	 /*cout << "Answer Matrix:" << endl;
	 for(int a = 0; a < answer.size(); a++){
		 for(int b = 0; b < answer[a].size(); b++){
			 cout << answer[a][b] << " ";
		}
		cout << endl;
	}*/
	 return answer;
}
