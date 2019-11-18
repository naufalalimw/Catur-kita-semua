#ifndef MOVE_H
#define MOVE_H

#include "boolean.h"
#include "converter.h"
#include "array.h"
#include "listlinier.h"

boolean isAlly (int team1, int team2);

boolean isPieces (char pieces);

boolean isPiecesMove (List L, TabChar T, char pieces, coordinat CurrCoor);

void whitepawnsPath (List L, TabChar T, Path *PL, coordinat CurrCoor);

void blackpawnsPath (List L, TabChar T, Path *PL, coordinat CurrCoor);

void rooksPath (List L, TabChar T, Path *PL, coordinat CurrCoor);

void horsesPath (List L, TabChar T, Path *PL, coordinat CurrCoor);

void bishopsPath (List L, TabChar T, Path *PL, coordinat CurrCoor);

void queesPath (List L, TabChar T, Path *PL, coordinat CurrCoor);

void kingsPath (List L, TabChar T, Path *PL, coordinat CurrCoor);

#endif