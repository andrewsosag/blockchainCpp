#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <iostream>

/*
Block Class
    - Contains private block data (accessible through get methods)
    - Contains function for mining blocks using Proof of Work
*/
class Block {
public:
    Block(int indexInput, const std::string dataInput); // constructor
    std::string prevBlockHash; // hash of previous block
    std::string getHash() { return blockHash;};
    std::string getBlockInfo; // returns public block information
    void MineBlock(int difficulty);
private:
    // Block Data (visible from blockchain, but immutable)
    int blockIndex;
    int blockNonce;
    std::string blockData;
    std::string blockHash;
    time_t blockTime; // time of mining

    std::string calculateHash() const; // return SHA256 hash of block data
};

#endif