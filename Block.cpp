#include "Block.h"
#include "sha256.h"
#include <sstream>
#include <sys/time.h>
#include <iomanip>

/*

*/
Block::Block(int currentIndex, const string currentData) {
    blockIndex = currentIndex; 
    blockData = currentData;
    blockNonce = -1;
    blockTime = time(nullptr);
    gettimeofday(&mineStart, NULL);
}


/*

*/
void Block::MineBlock(int difficulty) {
    char cstr[difficulty + 1];
    for (int i = 0; i < difficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[difficulty] = '\0';

    string str(cstr);

    do {
        blockNonce++;
        blockHash = calculateHash();
    } while (blockHash.substr(0, difficulty) != str);

    cout << "Block mined: " << blockHash << endl;
    gettimeofday(&mineEnd, NULL);
}


/*  
    CalculateHash encrypts block data with SHA256
    through a stringstream
*/
inline string Block::calculateHash() const {
    stringstream blockData;
    blockData << blockIndex << blockTime << blockData << blockNonce << prevBlockHash;

    return sha256(blockData.str());
}


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