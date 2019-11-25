#ifndef MOVE_H
#define MOVE_H

#include "boolean.h"
#include "game.h"
#include "array.h"
#include "listlinier.h"

boolean isAlly (int team1, int team2);

boolean isPieces (char pieces);

boolean isCheckMate (List L, TabChar T, int team);

boolean isKingDead (List L);

boolean isPiecesMove (List L, TabChar T, char pieces, coordinat CurrCoor);

boolean isEOPKing (List L, TabChar T, char pieces, coordinat CurrCoor, int horizontal, int vertical);

void whitepawnsPath (List L, TabChar T, Path *PL, coordinat CurrCoor);

void whitepawnsPathToKing (List L, TabChar T, Path *PL, coordinat CurrCoor);

void blackpawnsPath (List L, TabChar T, Path *PL, coordinat CurrCoor);

void blackpawnsPathToKing (List L, TabChar T, Path *PL, coordinat CurrCoor);

void rooksPath (List L, TabChar T, Path *PL, coordinat CurrCoor);

void rooksPathToKing (List L, TabChar T, Path *PL, coordinat CurrCoor);

void horsesPath (List L, TabChar T, Path *PL, coordinat CurrCoor);

void bishopsPath (List L, TabChar T, Path *PL, coordinat CurrCoor);

void bishopsPathToKing (List L, TabChar T, Path *PL, coordinat CurrCoor);

void queesPath (List L, TabChar T, Path *PL, coordinat CurrCoor);

void queesPathToKing (List L, TabChar T, Path *PL, coordinat CurrCoor);

void kingsPath (List L, TabChar T, Path *PL, coordinat CurrCoor);

void posMove (List L, addressList P, TabChar T, Path *PL);

void posMoveToKing (List L, addressList P, TabChar T, Path *PL);

#endif