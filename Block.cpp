#include "Block.h"
#include "sha256.h"
#include <sstream>
#include <sys/time.h>
#include <iomanip>

/*
Block Constructor:
Input:
    - Current Index of Blockchain
    - 

*/
Block::Block(int currentIndex, const string currentData) {
    blockIndex = currentIndex; 
    blockData = currentData;
    blockNonce = -1;
    blockTime = time(nullptr);
    gettimeofday(&mineStart, NULL);
}


/*
Function to mine Blocks

*/
void Block::MineBlock(int mineDifficulty) {
    char cstr[mineDifficulty + 1];
    for (int i = 0; i < mineDifficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[mineDifficulty] = '\0';

    string str(cstr);

    do {
        // 
        blockNonce++;
        blockHash = calculateHash();
    } while (blockHash.substr(0, mineDifficulty) != str);

    cout << "Block mined: " << blockHash << endl;
    // gettimeofday(&mineEnd, NULL);
}


/*  
    calculateHash loads block data into stringstream,
    and returns data encrypted with SHA-256
*/
inline string Block::calculateHash() const {
    stringstream blockData;
    blockData << blockIndex << blockTime << blockData << blockNonce << prevBlockHash;

    return sha256(blockData.str());
}


/*


*/
string Block::getTime(){
    // double mineTime = double(mineEnd - mineStart) / double(CLOCKS_PER_SEC);
    // int mineTime = Block::mineEnd - Block::mineStart;
    double mineTime = (mineEnd.tv_sec - mineStart.tv_sec) * 1e6;
    mineTime = (mineTime + (mineEnd.tv_usec - mineStart.tv_usec)) * 1e-6;
    stringstream ss;
    ss << setprecision(5) << mineTime;
    string ts = ss.str();
    return ts;
}