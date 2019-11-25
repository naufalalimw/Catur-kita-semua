#ifndef SPECIALMOVE_H
#define SPECIALMOVE_H

#include "boolean.h"
#include "game.h"
#include "array.h"
#include "stack.h"
#include "listlinier.h"
#include "move.h"


void castling(List L, TabChar T, coordinat KingCoor, coordinat RooksCoor);
/* melakukan castling*/

boolean isCastling (List L, TabChar T, coordinat KingCoor, coordinat RooksCoor); 
// mengecek apakah castling bisa dilakukan apa tidak

boolean isPromotion (List L, int team);

boolean isEnPassant (Stack *S, List L, int *team);

void promotion (Stack *S, List *L, List *M, TabChar *T, Path *PL, int *team);

void enPassant (Stack *S, List *L, List *M, TabChar *T, Path *PL, int *team);



#endif

