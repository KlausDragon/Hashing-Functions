
// CPSC 2150 Bonus Assignment

#include "hash_function.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <string>

using std::cout, std::endl, std::string;

const string EMPTY = string("");

// the hashing function takes a key k and the size of the table m
int hash_fct(const string& k, int m) {
   int s = 0;
   for (size_t i = 0; i < k.length(); i++) {
      s = (2167 * s + k[i] ) % m;  // prevent overflow
   }
   return s;
}

void hashProcessor(int size, int loadFactor){
   // LINEAR Case (i): when our new key is inside the table
   // initializing array T
   string TL[size];
   for(int n = 0; n < size; n++){
      TL[n] = EMPTY;
   }

   int i = 0, counter_1, total_1 = 0;
   while(i != loadFactor){
      string newKey = getKey();
      if(!searchL(newKey, TL, size, counter_1)){
        insertL(newKey, TL, size);
        i++;
      }
   }
   counter_1 = 0;
   for(int n = 0; n < size; n++){
      if(TL[n] != EMPTY){
         searchL(TL[n], TL, size, counter_1);
         total_1 = total_1 + counter_1;
      }
   }
   float average_1 = total_1 / (double)loadFactor;
   cout << "\n" << "Average comparisons when key is in the Linear table: " << average_1;
   if(loadFactor == 1000){ 
      cout << " (LF 0.5), Expected: 1.5" << ", Delta = ";
      (1.5 > average_1) ? cout << 1.5 - average_1 << "\n" : cout << average_1 - 1.5 << "\n";
   }
   else if(loadFactor == 400){
      cout << " (LF 0.2), Expected: 1.1" << ", Delta = ";
      (1.1 > average_1) ? cout << 1.1 - average_1 << "\n" : cout << average_1 - 1.1 << "\n";
   }
   else if(loadFactor == 1599){
      cout << " (LF 0.8), Expected: 3" << ", Delta = ";
      (3.0 > average_1) ? cout << 3.0 - average_1 << "\n" : cout << average_1 - 3.0 << "\n";
   }
   
   // LINEAR Case (ii): when our new key is not inside the table
   // initializing array TL_2
   string TL_2[loadFactor]; // or [loadFactor * size]
   for(int n = 0; n < loadFactor; n++){
      TL_2[n] = EMPTY;
   }

   int j = 0, counter_2, total_2 = 0;
   while(j != loadFactor){
      string newKey = getKey();
      if(!searchL(newKey, TL, size, counter_2)){
        insertL(newKey, TL_2, loadFactor);
        j++;
      }
   }
   counter_2 = 0;
   for(int n = 0; n < loadFactor; n++){
      searchL(TL_2[n], TL, size, counter_2);
      total_2 = total_2 + counter_2;
   }
   float average_2 = total_2 / (double)loadFactor;
   cout << "Average comparisons when key is not in the Linear table: " << average_2;
   if(loadFactor == 1000){ 
      cout << " (LF 0.5), Expected: 2.5" << ", Delta = ";
      (2.5 > average_2) ? cout << 2.5 - average_2 << "\n" : cout << average_2 - 2.5 << "\n";
   }
   else if(loadFactor == 400){
      cout << " (LF 0.2), Expected: 1.2" << ", Delta = ";
      (1.2 > average_2) ? cout << 1.2 - average_2 << "\n" : cout << average_2 - 1.2 << "\n";
   }
   else if(loadFactor == 1599){
      cout << " (LF 0.8), Expected: 13" << ", Delta = ";
      (13.0 > average_2) ? cout << 13.0 - average_2 << "\n" : cout << average_2 - 13.0 << "\n";
   }

   // QUADRATIC Case (i): when our new key is inside the table
   // initializing array TQ
   string TQ[size];
   for(int n = 0; n < size; n++){
      TQ[n] = EMPTY;
   }

   int k = 0, counter_3, total_3 = 0;
   while(k != loadFactor){
      string newKey = getKey();
      if(!searchQ(newKey, TQ, size, counter_3)){
        insertQ(newKey, TQ, size);
        k++;
      }
   }
   counter_3 = 0;
   for(int n = 0; n < size; n++){
      if(TQ[n] != EMPTY){
         searchQ(TQ[n], TQ, size, counter_3);
         total_3 = total_3 + counter_3;
      }
   }
   float average_3 = total_3 / (double)loadFactor;
   cout << "Average comparisons when key is in the Quadratic table: " << average_3;
   if(loadFactor == 1000){ 
      cout << " (LF 0.5), Expected: 1.4" << ", Delta = ";
      (1.4 > average_3) ? cout << 1.4 - average_3 << "\n" : cout << average_3 - 1.4 << "\n";
   }
   else if(loadFactor == 400){ 
      cout << " (LF 0.2), Expected: 1.1" << ", Delta = ";
      (1.1 > average_3) ? cout << 1.1 - average_3 << "\n" : cout << average_3 - 1.1 << "\n";
   }
   else if(loadFactor == 1599){ 
      cout << " (LF 0.8), Expected: 2.2" << ", Delta = ";
      (2.2 > average_3) ? cout << 2.2 - average_3 << "\n" : cout << average_3 - 2.2 << "\n";
   }
   
   // QUADRATIC Case (ii): when our new key is not inside the table
   // initializing array TQ_2
   string TQ_2[loadFactor];
   for(int n = 0; n < loadFactor; n++){
      TQ_2[n] = EMPTY;
   }

   int l = 0, counter_4, total_4 = 0;
   while(l != loadFactor){
      string newKey = getKey();
      if(!searchQ(newKey, TQ, size, counter_4)){
        insertQ(newKey, TQ_2, loadFactor);
        l++;
      }
   }
   counter_4 = 0;
   for(int n = 0; n < loadFactor; n++){
      searchQ(TQ_2[n], TQ, size, counter_4);
      total_4 = total_4 + counter_4;
   }
   float average_4 = total_4 / (double)loadFactor;
   cout << "Average comparisons when key is not in the Quadratic table: " << average_4;
   if(loadFactor == 1000){ 
      cout << " (LF 0.5), Expected: 2.1" << ", Delta = ";
      (2.1 > average_4) ? cout << 2.1 - average_4 << "\n" : cout << average_4 - 2.1 << "\n";
   }
   else if(loadFactor == 400){ 
      cout << " (LF 0.2), Expected: 1.2" << ", Delta = ";
      (1.2 > average_4) ? cout << 1.2 - average_4 << "\n" : cout << average_4 - 1.2 << "\n";
   }
   else if(loadFactor == 1599){ 
      cout << " (LF 0.8), Expected: 6.4" << ", Delta = ";
      (6.4 > average_4) ? cout << 6.4 - average_4 << "\n" : cout << average_4 - 6.4 << "\n";
   }

   cout << "\n" << "=============================================================================================================" << "\n";
}

// returns a string of random upper case letters
string getKey(){
   string s = EMPTY;
   for(int i = 0; i < 10; i++){
      char c = (rand() % 26) + 65;
      s = s + c;
   }
   return s;
}

// =================== Linear Probing ===================== //

void insertL(string x, string T[], int m){ 
   int i = hash_fct(x, m);
   for (int j = 0; j < m; j++) {
      if (T[i] == EMPTY) {
         T[i] = x;
         return;
      }
      else {
         i = (i + 1) % m;
      }
   }
}

bool searchL(string x, string T[], int m, int& counter) {
   int i = hash_fct(x, m);
   counter = 0;
   for (int j = 0; j < m; j++) {
      counter++;
      if (T[i] == x) {
         return true;
      }
      else if(T[i] == EMPTY){
         return false;
      }
      else{
         i = (i + 1) % m;
      }
   }
   return false;
}

// ==================================================== //

// =================== Quadratic Probing ===================== //

void insertQ(string x, string T[], int m){ 
   int i = hash_fct(x, m);
   for (int j = 0; j < m; j++) {
      if (T[i] == EMPTY) {
         T[i] = x;
         return;
      }
      else {
         i = (i + ((j + 1) * (j + 1))) % m;
      }
   }
}

bool searchQ(string x, string T[], int m, int& counter) {
   int i = hash_fct(x, m);
   counter = 0;
   for (int j = 0; j < m; j++) {
      counter++;
      if (T[i] == x) {
         return true;
      }
      else if(T[i] == EMPTY){
         return false;
      }
      else{
         i = (i + ((j + 1) * (j + 1))) % m;
      }
   }
   return false;
}

// ==================================================== //