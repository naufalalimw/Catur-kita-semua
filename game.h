#ifndef GAME_H
#define GAME_H

#include "boolean.h"
#include "board.h"
#include "move.h"
#include "array.h"
#include "queue.h"
#include "stack.h"
#include "listlinier.h"

void NewGame (Queue *Q, Stack *S, List *L, List *M, TabChar *T, Path *PL);

void command (Stack *S, List *L, List *M, TabChar *T, Path *PL, int team, int *whiteScore, int *blackScore);

void turn (Stack *S, List L, List *M, TabChar *T, Path *PL, int team, int *whiteScore, int *blackScore);

void printTurn (List M);

void posMove (List L, List M, TabChar T, Path *PL, char *pieces, int *team, coordinat *CurrCoor, int choice);

void printPosMove (Path PL);

void movement (Stack *S, List *L, Path PL, char CurrPieces, int CurrTeam, coordinat CurrCoor, coordinat *NextCoor, int choice, int *whiteScore, int *blackScore);

void getScore(char NextPieces, int *score);

#endif