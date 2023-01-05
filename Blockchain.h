#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include "Block.h"

using namespace std;
/*
Blockchain Class:
    - Creates blockchain using vector of Blocks
    - Keeps track of mining difficulty
    - 
*/


class Blockchain {
public:
    Blockchain();
    void addBlock(Block);
    Block getLastBlock() const;
    // function that calculates time to mine each block

private:
    int difficulty;
    vector<Block> chain;
};

#endif