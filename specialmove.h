#ifndef MOVE_H
#define MOVE_H

#include "boolean.h"
#include "game.h"
#include "array.h"
#include "listlinier.h"
#include "move.h"


void castling(List L, TabChar T, coordinat KingCoor, coordinat RooksCoor);
/* melakukan castling*/

boolean Iscastling (List L, TabChar T, coordinat KingCoor, coordinat RooksCoor); 
// mengecek apakah castling bisa dilakukan apa tidak

boolean isEnpassant(List L, Stack S, coordinat pawn);
// mengecek apakah bisa melakukan enpassant

void Enpassant(List L,Stack S, coordinat pawn);
//melakukan gerakan en passant

void Promotion(List L, TabChar T, coordinat pawn);
//promosi jika pion bisa sampai pucuk
#endif








