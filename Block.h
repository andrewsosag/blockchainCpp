#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <iostream>

using namespace std;
/*
Block class keeps track of block data
    - 


*/

class Block {
public:
    Block(int indexInput, const string dataInput); // constructor takes in block index and data
    string prevBlockHash; // block contains hash of previous block
    string getHash() { return blockHash;};
    string getTime();
    // string getMineStart() {return mineStart};
    // string getMineEnd() {return mineEnd};
    void MineBlock(int difficulty);
private:
    // Encapsulated Block Data
    int blockIndex;
    int blockNonce;
    string blockData;
    string blockHash;
    time_t blockTime; // time of mining
    // clock_t mineStart, mineEnd; // time to mine
    struct timeval mineStart, mineEnd;

    string calculateHash() const; // return SHA256 hash of block data
};

#endif