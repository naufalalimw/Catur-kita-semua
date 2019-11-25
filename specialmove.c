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

boolean isEnpassant(List L, Stack S, coordinat pawn)
// mengecek apakah bisa melakukan enpassant
{
    addressList centralpawn, rightside, leftside;
    char curpawn, rpawn, lpawn;
    coordinat leftpawn, rightpawn;

    //koordinat
    leftpawn = curpawn; leftpawn.hor--;
    rightpawn = curpawn; rightpawn.hor++;

    //karakter/bidak
    curpawn = T.TI[pawn.ver][pawn.hor];
    rpawn = T.TI[rightpawn.ver][rightpawn.hor];
    lpawn = T.TI[leftpawn.ver][leftpawn.hor];

    //adrress list
    centralpawn = SearchList(L,curpawn,pawn);
    rightside = SearchList(L,rpawn,rightpawn);
    leftpawn = SearchList(L,lpawn,leftpawn);

    if (Team(centralpawn) == black)
    {
        if ((info(rightside)=='p') || (info(leftside)=='p'))
        {
            return//masukin stack true or false
        }
    }else if (Team(centralpawn)==white)
    {
        if ((info(rightside)=='P') || (info(leftside)=='P') )
        {
            return//masukin bagian stacknya
        }  
    }
}

void Enpassant(List L, Stack S, coordinat pawn)
//melakukan gerakan en passant
{
    addressList centralpawn, rightside, leftside;
    char curpawn, rpawn, lpawn;
    coordinat leftpawn, rightpawn;

    //koordinat
    leftpawn = curpawn; leftpawn.hor--;
    rightpawn = curpawn; rightpawn.hor++;

    //karakter/bidak
    curpawn = T.TI[pawn.ver][pawn.hor];
    rpawn = T.TI[rightpawn.ver][rightpawn.hor];
    lpawn = T.TI[leftpawn.ver][leftpawn.hor];

    //adrress list
    centralpawn = SearchList(L,curpawn,pawn);
    rightside = SearchList(L,rpawn,rightpawn);
    leftpawn = SearchList(L,lpawn,leftpawn);

    if (isEnpassant(L,S,pawn))
    {
        if (Team(centralpawn)==black)
        { 
            if (info(rightside)=='p')
            {
                Horizontal(centralpawn)++;
                Vertical(centralpawn)--;
                DealokasiList(&rightside)
            } else if (info(leftside)=='p')
            {
                Horizontal(centralpawn)--;
                Vertical(centralpawn)--;
                DealokasiList(&leftside);
            }
        } else if (Team(centralpawn)==white)
        {
            if (info(rightside)=='p')
            {
                Horizontal(centralpawn)++;
                Vertical(centralpawn)++;
                DealokasiList(&rightside)
            } else if (info(leftside)=='p')
            {
                Horizontal(centralpawn)--;
                Vertical(centralpawn)++;
                DealokasiList(&leftside);
            }
        }   
    } 
}

void Promotion(List L, TabChar T, coordinat coorpawn)
{
    char pawnpieces;
    addressList PawnP;
    char promosi;

    pawnpieces = T.TI[coorpawn.ver][coorpawn.hor];
    PawnP = SearchList(L,pawnpieces,coorpawn);

    if (isPiecesMove(L,T,pawnpieces,coorpawn))
    {
        if ((Team(PawnP)==black) && (Vertical(PawnP)==2))
        {
            // tolong man ini jalanin maju
            printf('Pion sudah sampai di ujung, silakan masukan perubahan pada pion');
            scanf("%c\n", &promosi);
            info(PawnP) = promosi;
        } else if ((Team(PawnP)==white) && (Vertical(PawnP)==7))
        {
            // tolong man ini jalanin maju
            printf('Pion sudah sampai di ujung, silakan masukan perubahan pada pion');
            scanf("%c\n", &promosi);
            info(PawnP) = promosi;
        }
    }
}
