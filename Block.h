#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <iostream>

using namespace std;
/*
Block Class
    - contains immutable block data
    - contains function for encryption with SHA-256
    - contains function for mining blocks with Proof of Work
*/

class Block {
public:
    Block(int indexInput, const string dataInput); // constructor
    string prevBlockHash; // hash of previous block
    string getHash() { return blockHash;};
    string getTime();
    // string getMineStart() {return mineStart};
    // string getMineEnd() {return mineEnd};
    void MineBlock(int difficulty);
private:
    // Block Data (visible from blockchain, but immutable)
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