#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include "Block.h"

using namespace std;

/*
Blockchain Class:
    - Constructs blockchain using immutable vector of Blocks
    - Keeps track of increasing mining mineDifficulty
    // IMPLEMENT FUNCTIONS FOR RETRIEVING PUBLIC BLOCK DATA
*/
class Blockchain {
public:
    // Public Blockchain Functions
    Blockchain(); // constructor
    void addBlock(Block); // function to add new blocks to blockchain
    Block getLastBlock() const; // function retrieves last block in blockchain
    // function that calculates time to mine each block

private:
    // Immutable Blockchain Data
    int mineDifficulty;
    vector<Block> chain; // vector of Blocks to dynamically create blockchain
};

#endif