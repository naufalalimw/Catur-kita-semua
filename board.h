#ifndef BOARD_H
#define BOARD_H

#include "boolean.h"
#include "array.h"
#include "listlinier.h"

void NewBoard (List *L);

void BoardPos (List L, TabChar *T);

void PrintBoard (TabChar T);

#endif