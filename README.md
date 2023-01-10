# A Blockchain Using Proof of Work in C++
A simple blockchain written in C++

This is a simple blockchain written in C++, that
uses proof of work and SHA-256 to mimic a real blockchain

This program uses object oriented principles such as
encapsulation to make blockchain data visible but immutable

## Setup
1. Download all files except for README.md
2. Compile using "make"
```bash
make
```
3. Run using "./startMining"
```bash
./startMining
```
## Usage
1. After running the program, your computer will begin "mining" the first block
in the blockchain
2. Once the first block has been mined, important block data will be outputted to
the terminal (such as the hash of the block, and how long the mining process took)
3. Process will repeat for the desired amount of blocks

## How it Works

A blockchain is a decentralized, digital ledger that uses cryptography to secure its data. In a simple blockchain, each block contains a unique hash value that distinguishes it from other blocks in the chain.

To create a new block

1. A Blockchain is dynamically created using a vector of blocks, the mining difficulty is also set. These are made private so they are immutable.
```c++
class Blockchain{
private:
    int mineDifficulty;
    vector<Block> chain;
}
```
