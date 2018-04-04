#include <cstdint>
#include <vector>
#include "Block.h"

class Blockchain
{
public:
	Blockchain();

	void AddBlock(Block bNew);
private:
	uint32_t m_nDifficulty;
	std::vector<Block> m_vChain;

	Block GetLastBlock() const;
};