#include <stdio.h>
#include <stdlib.h>
#include "converter.h"

int CharToInt (char * X){
    if (*X == 'a'){
        return 97;
    }else if (*X == 'b'){
        return 98;
    }else if (*X == 'c'){
        return 99;
    }else if (*X == 'd'){
        return 100;
    }else if (*X == 'e'){
        return 101;
    }else if (*X == 'f'){
        return 102;
    }else if (*X == 'g'){
        return 103;
    }else if (*X == 'h'){
        return 104;
    }
}

char IntToChar (int X){
    if (X == 97){
        return 'a';
    }else if (X == 98){
        return 'b';
    }else if (X == 99){
        return 'c';
    }else if (X == 100){
        return 'd';
    }else if (X == 101){
        return 'e';
    }else if (X == 102){
        return 'f';
    }else if (X == 103){
        return 'g';
    }else if (X == 104){
        return 'h';
    }
}