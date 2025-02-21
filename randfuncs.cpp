#include "randfuncs.h"
#include <cstdlib>

int flip_coin() { 
    int rand_num = rand();
    return rand_num % 2; 
    }

int roll_dice(int sides) {
    int rand_num = rand();
    return (rand_num % sides) + 1; 
    }