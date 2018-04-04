#include <cstdint>
#include <iostream>
#include <time.h>
#include <vector>
#include <sstream>

class Block
{
public:
	std::string m_PHash;
	Block(uint32_t nIndexIn, const std::string& sDataIn);
	std::string GetHash();
	void MineBlock(uint32_t nDifficulty);

private:
	uint32_t m_nIndex;
	int64_t m_nNonce;
	std::string m_sData;
	std::string m_sHash;
	time_t m_tTime;

	std::string CalculateHash() const;
};