/*
Blockchain in C++ using Proof of Work
by Andrew Sosa Guaita

This program implements a simple blockchain 
using object-oriented principles in C++.

In this implementation, each block is represented by
an object of the Block class, which contains a set
of immutable data fields. The blockchain is contructed
with a vector of Block objects, and keeps track of an 
increasing mining difficulty that determines the time it 
takes to mine new blocks.

Block data is encrypted using the SHA-256 algorithm, which
generates a 256-bit hash value that serves as a digital 
fingerprint of the data. Any small changes in the block data 
will generate an entirely different hash, ensuring
the integrity of each block.

For more information on blockchains and proof-of-work, see the
original Bitcoin paper by Satoshi Nakamoto (https://bitcoin.org/bitcoin.pdf).
*/

#include "Blockchain.h"

int main() {
    int blocksToMine = 10; // number of Blocks to mine
    Blockchain bChain = Blockchain(); // create Blockchain object

    std::string blockNumber;
    // Start mining blocks
    for (int i = 1; i <= blocksToMine; i++) {
        std::cout << "Mining block " << std::to_string(i) << "..." << std::endl;
        // Create new block
        blockNumber = "Block #" + std::to_string(i);
        Block currentBlock = Block(i, blockNumber);

        // Mine new block and add to blockchain
        bChain.addBlock(Block(i, blockNumber));

        // Output Public Block Data to Terminal
        std::cout << "Block " + std::to_string(i) + " Data:" << std::endl;
        std::cout << currentBlock.getHash() << std::endl;
        
    }

    return 0;
}

