#include "Block.h"
#include "sha256.h"
#include <sstream>
#include <sys/time.h>
#include <iomanip>

/*
Block Constructor:
Input:
    - Current Index of Blockchain
    - Current block data
*/
Block::Block(int currentIndex, const string currentData) {
    // Set Index and Data
    blockIndex = currentIndex; 
    blockData = currentData;
    blockNonce = -1; // set starting nonce
    blockTime = time(nullptr); // record time of block creation
    gettimeofday(&mineStart, NULL);
}


/*
Function to mine Blocks using Proof of Work
    - Nonce is continually increased
    - New hash is created with each nonce until
    the new hash contains correct amount of 
    leading zeroes for current mineDifficult
*/
void Block::MineBlock(int mineDifficulty) {
    // Create string of leading zeroes for current mineDifficulty
    char cstr[mineDifficulty + 1];
    for (int i = 0; i < mineDifficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[mineDifficulty] = '\0';
    string str(cstr);

    // Loop until correct hash is found
    do {
        // Continually increase nonce
        blockNonce++;
        // Calculate hash with new nonce value
        blockHash = calculateHash();
    // Exit loops once hash contains correct number of leading zeroes
    } while (blockHash.substr(0, mineDifficulty) != str);

    // Output publicly hash of new block
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