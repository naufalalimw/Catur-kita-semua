#include <stdio.h>
#include <stdlib.h>
#include "converter.h"

int CharToInt (char * X){
    if (*X == 'a'){
        return 1;
    }else if (*X == 'b'){
        return 2;
    }else if (*X == 'c'){
        return 3;
    }else if (*X == 'd'){
        return 4;
    }else if (*X == 'e'){
        return 5;
    }else if (*X == 'f'){
        return 6;
    }else if (*X == 'g'){
        return 7;
    }else if (*X == 'h'){
        return 8;
    }
}

char IntToChar (int X){
    if (X == 1){
        return 'a';
    }else if (X == 2){
        return 'b';
    }else if (X == 3){
        return 'c';
    }else if (X == 4){
        return 'd';
    }else if (X == 5){
        return 'e';
    }else if (X == 6){
        return 'f';
    }else if (X == 7){
        return 'g';
    }else if (X == 8){
        return 'h';
    }
}