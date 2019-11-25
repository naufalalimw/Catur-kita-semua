#ifndef GAME_H
#define GAME_H

#include "boolean.h"
#include "board.h"
#include "move.h"
#include "specialmove.h"
#include "array.h"
#include "queue.h"
#include "stack.h"
#include "listlinier.h"

void NewGame (Queue *Q, Stack *S, List *L, List *M, TabChar *T, Path *PL);

void command (Queue *Q, Stack *S, List *L, List *M, TabChar *T, Path *PL, int *team, int *whiteScore, int *blackScore);

void piecesMove (List L, List *M, TabChar T, int *team);

void turn (Stack *S, List L, List *M, TabChar *T, Path *PL, int *team, int *whiteScore, int *blackScore);

void printTurn (List M);

void printPosMove (Path PL);

void movement (Stack *S, List *L, addressList CurrP, Path PL, addressPath PP, int *whiteScore, int *blackScore);

void getScore(char NextPieces, int *score);

#endif