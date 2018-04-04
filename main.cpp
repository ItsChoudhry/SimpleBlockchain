#include "Blockchain.h"

int main()
{
	Blockchain bc = Blockchain();

	std::cout << "Mining......" << "\n";
	bc.AddBlock(Block(1, "Block 1 Data"));


}