#include "matrixChain.h"

int main()
{
	MatrixChain chain(100);
	chain.printDimensions();
	Matrix k = chain.dynamicChain();
	return 0;
}
