#include <stdio.h>
#include <stdlib.h>
#include "specialmove.h"

void castling(List L, TabChar T, coordinat KingCoor, coordinat RooksCoor)
{
    addressList KingP, RooksP;
    char KingPieces, RooksPieces;


    KingCoor.hor = CharToInt(&KingCoor.hor);
    RooksCoor.hor = CharToInt(&RooksCoor.hor);
    KingPieces = T.TI[KingCoor.ver][KingCoor.hor];
    RooksPieces = T.TI[RooksCoor.ver][RooksCoor.hor];
    KingP = SearchList(L,KingPieces,KingCoor);
    RooksP = SearchList(L,RooksPieces,RooksCoor);

    if (Iscastling(L,T,KingCoor,RooksCoor))
    {
        if (Team(King) == 200)
        {
            Horizontal(KingP) = Horizontal(KingP) + 2;
            Horizontal(RooksP) = Horizontal (RooksP) - 2;
        } else if (Team(King)==100)
        {
            Horizontal(KingP) = Horizontal(KingP) - 2;
            Horizontal(RooksP) = Horizontal(RooksP) + 2;
        }
    }

}

boolean Iscastling (List L, TabChar T, coordinat KingCoor, coordinat RooksCoor)
{
    addressList KingP, RooksP;
    char KingPieces, RooksPieces, bhorsepieces, whorsepieces ,bmenpieces ,wmenpieces;
    coordinat bhorse,whorse,bmen,wmen;


    KingCoor.hor = CharToInt(&KingCoor.hor);
    RooksCoor.hor = CharToInt(&RooksCoor.hor);
    KingPieces = T.TI[KingCoor.ver][KingCoor.hor];
    RooksPieces = T.TI[RooksCoor.ver][RooksCoor.hor];
    KingP = SearchList(L,KingPieces,KingCoor);
    RooksP = SearchList(L,RooksPieces,RooksCoor);

    if (((Info(KingP)=='K') || (Info(KingP)=='k')) && ((Info(RooksP)=='R') || (Info(RooksP)=='r')) )
    {
        if ((KingCoor.hor == 5) && (KingCoor.ver == 8) && (RooksCoor.hor == 8) && (RooksCoor.ver == 8) && (Team(KingP)==200))
        {
            Coor(bhorse) = Coor(KingCoor); Horizontal(bhorse) = Horizontal(KingCoor+2);
            Coor(bmen) = Coor(KingCoor); Horizontal(bmen) = Horizontal(KingCoor+1);
            bmenpieces = T.TI[Vertical(bmen)][Horizontal(bmen)]; bhorse = T.TI[Vertical(bhorse)][Horizontal(bhorse)];
            return((Info(SearchList(L,bmenpieces,bmen))== ' ') && (Info(SearchList(L,bhorsepieces,bhorse))==' '));
        } else if ((KingCoor.hor == 4) && (KingCoor.ver == 1) && (RooksCoor.hor == 1) && (RooksCoor.ver == 1))
        {
            Coor(whorse) = Coor(KingCoor); Horizontal(whorse) = Horizontal(KingCoor-2);
            Coor(wmen) = Coor(KingCoor); Horizontal(wmen) = Horizontal(KingCoor-1);
            wmenpieces = T.TI[Vertical(wmen)][Horizontal(bmen)]; whorse = T.TI[Vertical(whorse)][Horizontal(whorse)];
            return((Info(SearchList(L,wmenpieces,bmen))== ' ') && (Info(SearchList(L,whorsepieces,whorse))==' '));
        } else
        {
            return false;
        }
    }
} 