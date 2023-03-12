#include <iostream>

#include "tensor.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Usage: fashio_mnist <test> <model>";
		return -1;
	}
    Tensor check_model( argv[2], argv[1], 28, 28);
    
	std::cout << check_model.result << endl;

	return 0;
}