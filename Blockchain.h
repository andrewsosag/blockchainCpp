#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include "Block.h"

/*
Blockchain Class:
    - Constructs blockchain using vector of Blocks
    - 
    - 
*/
class Blockchain {
public:
    // Public Blockchain Functions
    Blockchain(); // constructor
    void addBlock(Block); // function to add new blocks to blockchain
    Block getLastBlock() const; // function retrieves last block in blockchain

private:
    // Immutable Blockchain Data
    int mineDifficulty; // set starting mining difficulty
    std::vector<Block> chain; // vector of Blocks to dynamically create blockchain
};

#endif