/*
Blockchain written in C++
by Andrew Sosa Guaita

Program implements a simple blockchain
using 2 classes "Block" and "Blockchain"




Block Class:

Program uses SHA256 Algorithm to encrypt block
data
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
        cout << "Time to Mine: " << currentBlock.getTime() << " seconds" << endl;
        
    }

    return 0;
}

