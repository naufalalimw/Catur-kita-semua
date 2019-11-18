#ifndef GAME_H
#define GAME_H

#include "boolean.h"
#include "converter.h"
#include "board.h"
#include "move.h"
#include "array.h"
#include "queue.h"
#include "listlinier.h"

void NewGame (Queue *Q, List *L, List *M, TabChar *T);

void turn (List L, List *M, TabChar T, int team);

void printTurn (List M);

void posMove (List M, Path *PL, int choice);

#endif