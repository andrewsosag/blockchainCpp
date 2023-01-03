/*
Blockchain in C++, by Andrew Sosa Guaita

Program uses 2 classes "Block" and "Blockchain"
in order to implement a simple blockchain

Program uses SHA256 Algorithm to encrypt block
data
*/

#include "Blockchain.h"

int main() {
    // Amount of Blocks to Mine
    int blocksToMine = 10;
    
    string outputCurrentBlock;
    Blockchain bChain = Blockchain();

    // Mine intended amount of blocks
    for (int i = 1; i <= blocksToMine; i++) {
        // Output current block to terminal
        cout << "Mining block " << to_string(i) << "..." << endl;
        outputCurrentBlock = "Block " + to_string(i) + " Data";

        // Create new block
        Block currentBlock = Block(i, outputCurrentBlock);
        bChain.addBlock(Block(i, outputCurrentBlock));
        cout << "Time to Mine: " << currentBlock.getTime() << " seconds" << endl;

        // Add current block to blockchain
        
    }

    return 0;
}

