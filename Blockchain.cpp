#include "Blockchain.h"

Blockchain::Blockchain() {
    chain.__emplace_back(Block(0, "Genesis Block"));
    difficulty = 5;
}

// 
void Blockchain::addBlock(Block current) {
    current.prevBlockHash = getLastBlock().getHash();
    
    current.MineBlock(difficulty);
    chain.push_back(current);
}

// Function returns last block on Blockchain
Block Blockchain::getLastBlock() const {
    return chain.back();
}

