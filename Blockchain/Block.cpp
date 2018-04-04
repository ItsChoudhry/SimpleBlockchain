#include "Block.h"
#include "sha256.h"

Block::Block(uint32_t nIndexIn, const std::string & sDataIn): m_nIndex(nIndexIn), m_sData(sDataIn)
{
	m_nNonce = -1;
	m_tTime = time(nullptr);
}

std::string Block::GetHash()
{
	return m_sHash;
}

void Block::MineBlock(uint32_t nDifficulty)
{
	char* cstr = new char[nDifficulty + 1];

	for (uint32_t i = 0; i < nDifficulty; ++i)
	{
		cstr[i] = '0';
	}
	cstr[nDifficulty] = '\0';

	std::string str(cstr);

	do
	{
		m_nNonce++;
		m_sHash = CalculateHash();

		std::cout << "Block mined..." << m_sHash << "\n";
	} while (m_sHash.substr(0, nDifficulty) != str);
	{
		std::cout << "Block mined" << m_sHash << "\n";
	}

}

inline std::string Block::CalculateHash() const
{
	std::stringstream ss;
	ss << m_nIndex << m_tTime << m_sData << m_nNonce << m_PHash;
	return sha256(ss.str());
}
