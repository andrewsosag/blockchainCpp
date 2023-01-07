#include "Blockchain.h"

/*
Blockchain Constructor:
    - Places first block in first position
    - Sets starting mining difficulty
*/
Blockchain::Blockchain() {
    chain.__emplace_back(Block(0, "Genesis Block"));
    mineDifficulty = 5;
}

/*
Function adds new Blocks to Blockchain
    - Retrieves 
*/
void Blockchain::addBlock(Block current) {
    current.prevBlockHash = getLastBlock().getHash();
    current.MineBlock(mineDifficulty);
    chain.push_back(current);
}

// Function returns last block on Blockchain
Block Blockchain::getLastBlock() const {
    return chain.back();
}

