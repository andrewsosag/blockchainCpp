/*
Blockchain in C++ using Proof of Work
    by Andrew Sosa Guaita

Program implements a simple blockchain
using 2 classes "Block" and "Blockchain"

Block data is encrypted using SHA-256 algorithm,
*/

#include "Blockchain.h"

int main() {
    int blocksToMine = 10; // number of Blocks to mine
    
    string outputCurrentBlock;
    Blockchain bChain = Blockchain(); // create Blockchain object

    // Start mining blocks
    for (int i = 1; i <= blocksToMine; i++) {
        cout << "Mining block " << to_string(i) << "..." << endl;
        Block currentBlock = Block(i, outputCurrentBlock);

        // Mine new block and add to blockchain
        bChain.addBlock(Block(i, outputCurrentBlock));

        // Output Public Block Data to Terminal
        outputCurrentBlock = "Block " + to_string(i) + " Data";
        
    }

    return 0;
}

