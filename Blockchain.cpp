#include "Blockchain.h"


// Blockchain Constructor
Blockchain::Blockchain() {
    chain.__emplace_back(Block(0, "Genesis Block")); // place first block in first position
    mineDifficulty = 6; // set starting mining difficulty
}

/*
Function adds new Blocks to Blockchain
    - Stores hash of previous block in new Block
    - Mines new block using Proof of Work
    - Adds new Block to end of Blockchain
*/
void Blockchain::addBlock(Block current) {
    current.prevBlockHash = getLastBlock().getHash(); // store previous hash in new Block
    current.MineBlock(mineDifficulty); // mine new Block using Proof of Work
    chain.push_back(current); // add new Block to end of Blockchain
}

// Function returns latest Block on Blockchain
Block Blockchain::getLastBlock() const {
    return chain.back();
}

