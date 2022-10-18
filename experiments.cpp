// Name: Ali Abbasimoghaddasi
// Student Number: 100319686

#include "hash_function.h"
#include <ctime>
#include <cmath>
#include <string>
#include <iostream>

int main() {
   
   // for random key purposes
   srand(time(0));

   float loadFactor[] = {0.5, 0.2, 0.8}; // {(0.5 * size), (0.2 * size), (0.8 * size)}

   for(int i = 0; i < 3; i++){
      hashProcessor(1999, round(loadFactor[i] * 1999));
   }

   return 0;
}
