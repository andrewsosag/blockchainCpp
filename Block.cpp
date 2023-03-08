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
Block::Block(int currentIndex, const std::string currentData) {
    // Set Block Index and Data
    blockIndex = currentIndex; 
    blockData = currentData;
    blockNonce = -1; // set starting nonce
    blockTime = time(nullptr); // record time of block creation
}


/*
Function to mine Blocks using Proof of Work
    - Nonce is incremented until hash created with 
        nonce contains correct amount of zeroes
*/
void Block::MineBlock(int mineDifficulty) {
    // Create string of leading zeroes for current mineDifficulty
    char cstr[mineDifficulty + 1];
    for (int i = 0; i < mineDifficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[mineDifficulty] = '\0';
    std::string str(cstr);

    // Loop until correct hash is found
    do {
        // Continually increase nonce
        blockNonce++;
        // Calculate hash with new nonce value
        blockHash = calculateHash();
    // Exit loops once hash contains correct number of leading zeroes
    } while (blockHash.substr(0, mineDifficulty) != str);

    // Output publicly hash of new block
    std::cout << "Block mined: " << blockHash << std::endl;
}


/*  
Function dumps block data into string and returns data encrypted with SHA-256
    - Any changes in block data will entirely change hash
*/
inline std::string Block::calculateHash() const {
    // Dump block data into string
    std::stringstream hashString;
    hashString << blockIndex << blockTime << blockData << blockNonce << prevBlockHash;
    
    // Return SHA-256 encrypted hash of string
    return sha256(hashString.str());
}