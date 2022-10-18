// CPSC 2150 Bonus Assignment

#ifndef HASH_FUNCTION_H
#define HASH_FUNCTION_H

#include <string>

using std::string;

// the hashing function takes a key and the size of the table
// returns the hashed position into the table
int hash_fct(const std::string& key, int tableSize);

string getKey();

// a general function to process each load factors for hash searching and insertion all at once
void hashProcessor(int size, int loadFactor);

// to insert Linearly a given key x into the hash table T
void insertL(string x, string T[], int m);

// to test Linearly if a given key x is in the hash table T
bool searchL(string x, string T[], int m, int& counter);

// to insert Quadratically a given key x into the hash table T
void insertQ(string x, string T[], int m);

// to test Quadratically if a given key x is in the hash table T
bool searchQ(string x, string T[], int m, int& counter);

#endif