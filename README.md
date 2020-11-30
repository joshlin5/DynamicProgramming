# Dynamic Programming
In this assignment, you will implement the dynamic programming solution to the matrix chain multiplication problem.

All the information you need regarding dynamic programming can be found in your textbook (Algorithm Design and Applications, Chapter 12).

### Step 1 - Setup
You can create your own `main.cpp` file for debugging your implementation.
Other than that your implementation will be limited to `matrixChain.cpp`. You should always be able to compile everything with something simple like: `c++ *.cpp -o main`

Take your time to understand the structure of these files.
- `matrixChain.h` is a class that stores the actual chain of matrices.
- `chain` stores the matrices (each Matrix is a bidimensional vector) while `dimensions` stores the sizes of these matrices.
- as we have seen in class, the matrix at position i in `chain` has number of rows = `dimensions[i]` and number of columns = `dimensions[i+1]`.

The constructor of the class `ChainMatrix` takes as input an integer `num` that indicate the number of matrices to be generated. By calling the constructor a sequence of `num` matrices will be generated with random sizes. `#define NUM ...` indicates the maximum value for each entry of a matrix. `#define SIZE ...` indicates the maximum size for the dimension of a matrix.

Two functions are already implemented the constructor `MatrixChain` and `generate_matrix`. These are creating the vector of dimensions and the matrices for you. They use a random function so that the matrix will change every time. You can decide to create the matrices manually at first, for testing your algorithm under simpler conditions, or you can change the parameters `num`, `NUM` and `SIZE` to create smaller matrices


### Step 3 - Dynamic programming approach, minimum number of steps

As a firs step let's implement function `DynamicChain`. Here you should implement the algorithm discussed in class. This will compute the matrix N storing the minimum number of steps required for multiplying the chain of matrices.

Once completed, print the last value computed in the matrix (the one telling you the optimal solution).

### Step 4 - Dynamic programming approach, subdivision.

Let's extend the previous function now. Modify the algorithm so to compute the matrix K storing all the k values describing how to get to the optimal solution.
Once you have created the matrix K, return the matrix.

### Step 5 - Wrapping up and constructing the final main.cpp file

Create your final main.cpp file. Your main function should contain only the following code.

```c++
MatrixChain chain = MatrixChain(100);
chain.printDimensions();
Matrix K = chain.dynamicChain();

return 0;
```

Run your last experiment with parameters
```c++
#define NUM 100 //maximum value for a cell of the matrix
#define SIZE 100 //maximum dimension for rows/columns of a matrix
```

Update this README file, copy and paste the results printed by your program. This should contain, the list of dimensions as printed by the function `chain.printDimensions();` and the optimal solution as printed by `chain.dynamicChain();`

[UPDATE HERE]

{84,87,78,16,94,36,87,93,50,22,63,28,91,60,64,27,41,27,73,37,12,69,68,30,83,31,63,24,68,36,30,3,23,59,70,68,94,57,12,43,30,74,22,20,85,38,99,25,16,71,14,27,92,81,57,74,63,71,97,82,6,26,85,28,37,6,47,30,14,58,25,96,83,46,15,68,35,65,44,51,88,9,77,79,89,85,4,52,55,100,33,61,77,69,40,13,27,87,95,40,96}

Optimal Steps: 856383


### Step 5 BONUS - Complete the dynamic programming multiplication

Now that you have the matrix K we know what is the correct order for applying our matrix multiplications. So let's do this.

Start by implementing the function `Matrix multiply(Matrix a, Matrix b);` in `MatrixChain` that, given two matrices, returns their multiplication.

Then, modify function `dynamicChain()` again. This time, instead of returning K, use K for computing the matrix multiplications in the optimal sequence. Then, return the matrix obtained instead of returning K.
