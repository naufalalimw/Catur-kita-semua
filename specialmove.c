#include <stdio.h>
#include <stdlib.h>
#include "specialmove.h"

void castling(List L, TabChar T, coordinat KingCoor, coordinat RooksCoor)
{
    addressList KingP, RooksP;
    char KingPieces, RooksPieces;

    KingPieces = T.TI[KingCoor.ver][KingCoor.hor];
    RooksPieces = T.TI[RooksCoor.ver][RooksCoor.hor];
    KingP = SearchList(L,KingPieces,KingCoor);
    RooksP = SearchList(L,RooksPieces,RooksCoor);

    if (Team(KingP) == black)
    {
        Horizontal(KingP) = Horizontal(KingP) + 2;
        Horizontal(RooksP) = Horizontal(RooksP) - 2;
    } else if (Team(KingP) == white)
    {
        Horizontal(KingP) = Horizontal(KingP) + 2;
        Horizontal(RooksP) = Horizontal(RooksP) - 2;
    }

    BoardPos(L,&T);
    PrintBoard(T);

}

boolean isCastling (List L, TabChar T, coordinat KingCoor, coordinat RooksCoor)
{
    addressList KingP, RooksP;
    char KingPieces, RooksPieces, bhorsepieces, whorsepieces ,bmenpieces ,wmenpieces;
    coordinat bhorse,whorse, bmen, wmen;

    KingPieces = T.TI[KingCoor.ver][KingCoor.hor];
    RooksPieces = T.TI[RooksCoor.ver][RooksCoor.hor];
    KingP = SearchList(L,KingPieces,KingCoor);
    RooksP = SearchList(L,RooksPieces,RooksCoor);

    if (((Info(KingP)=='K') || (Info(KingP)=='k')) && ((Info(RooksP)=='R') || (Info(RooksP)=='r')) )
    {
        if ((KingCoor.hor == 101) && (KingCoor.ver == 8) && (RooksCoor.hor == 104) && (RooksCoor.ver == 8) && (Team(KingP) == black))
        {
            bhorse = KingCoor; bhorse.hor = Horizontal(KingP)+2;
            bmen = KingCoor; bmen.hor = Horizontal(KingP)+1;
            bmenpieces = T.TI[bmen.ver][bmen.hor]; bhorsepieces = T.TI[bhorse.ver][bhorse.hor];
            return((Info(SearchList(L,bmenpieces,bmen))== ' ') && (Info(SearchList(L,bhorsepieces,bhorse))==' '));
        } else if ((KingCoor.hor == 100) && (KingCoor.ver == 1) && (RooksCoor.hor == 104) && (RooksCoor.ver == 1))
        {
            whorse = KingCoor; whorse.hor = Horizontal(KingP)+2;
            wmen = KingCoor; wmen.hor = Horizontal(KingP)+1;
            wmenpieces = T.TI[wmen.ver][wmen.hor]; whorsepieces = T.TI[whorse.ver][whorse.hor];
            return((Info(SearchList(L,wmenpieces,bmen))== ' ') && (Info(SearchList(L,whorsepieces,whorse))==' '));
        } else
        {
            return false;
        }
    }
}

boolean isPromotion (List L, int team){
    addressList P; boolean found;

    P = First(L); found = false;
    while ((P != Nil) && (!found)){
        if (team == white){
            if ((Info(P) == 'p') && (Vertical(P) == 7)){
                found = true;
            }
        }else if (team == black){
            if ((Info(P) == 'P') && (Vertical(P) == 2)){
                found = true;
            }
        }
        P = Next(P);
    }
    return found;
}

void promotion (Stack *S, List *L, List *M, TabChar *T, Path *PL, int *team){
    addressList P, NextP; addressPath PP;
    coordinat coor, CurrCoor, NextCoor;
    int i, choice; char pieces;

    CreateEmptyList(M);

    if (*team == white){
        P = First(*L);
        while (P != Nil){
            coor.hor = Horizontal(P);
            coor.ver = Vertical(P);
            if ((isPiecesMove(*L,*T,Info(P),coor)) && (Team(P) == *team) && (Info(P) == 'p') && (Vertical(P) == 7)){
                InsVFirstList(M,Info(P),Team(P),coor);
            }
            P = Next(P);
        }
    }else if (*team == black){
        P = First(*L);
        while (P != Nil){
            coor.hor = Horizontal(P);
            coor.ver = Vertical(P);
            if ((isPiecesMove(*L,*T,Info(P),coor)) && (Team(P) == *team) && (Info(P) == 'P') && (Vertical(P) == 2)){
                InsVFirstList(M,Info(P),Team(P),coor);
            }
            P = Next(P);
        }
    }

    printf("Buah catur yang dapat dipromosi :\n");
    printTurn(*M);
    printf("Pilih buah catur yang ingin dipromosikan : "); scanf("%d", &choice);
    i = 1;

    P = First(*M);
    while (i != choice+1){
        P = Next(P);
        i++;
    }

    printf("Buah catur hasil promosi :\n");
    printf("1. Ratu\n");
    printf("2. Menteri\n");
    printf("3. Kuda\n");
    printf("4. Benteng\n");
    printf("Pilih buah catur hasil promosi : "); scanf("%d", &choice);

    NextCoor = Coor(P);

    if (*team == white){
        NextCoor.ver++;
    }else if (*team == black){
        NextCoor.ver--;
    }

    NextP = SearchListCoordinat(*L,NextCoor);
    
    if (*team == white){
        if (choice == 1){
            DelP(L,Info(P),Coor(P));
            DelP(L,kosong,NextCoor);
            InsVLastList(L,'q',Team(P),NextCoor);
            InsVLastList(L,kosong,Team(NextP),Coor(P));
        }else if (choice == 2){
            DelP(L,Info(P),Coor(P));
            DelP(L,kosong,NextCoor);
            InsVLastList(L,'b',Team(P),NextCoor);
            InsVLastList(L,kosong,Team(NextP),Coor(P));
        }else if (choice == 3){
            DelP(L,Info(P),Coor(P));
            DelP(L,kosong,NextCoor);
            InsVLastList(L,'h',Team(P),NextCoor);
            InsVLastList(L,kosong,Team(NextP),CurrCoor);
        }else if (choice == 4){
            DelP(L,Info(P),Coor(P));
            DelP(L,kosong,NextCoor);
            InsVLastList(L,'r',Team(P),NextCoor);
            InsVLastList(L,kosong,Team(NextP),CurrCoor);
        }
    }else if (*team == black){
        if (choice == 1){
            DelP(L,Info(P),Coor(P));
            DelP(L,kosong,NextCoor);
            InsVLastList(L,'Q',Team(P),NextCoor);
            InsVLastList(L,kosong,Team(NextP),Coor(P));
        }else if (choice == 2){
            DelP(L,Info(P),Coor(P));
            DelP(L,kosong,NextCoor);
            InsVLastList(L,'B',Team(P),NextCoor);
            InsVLastList(L,kosong,Team(NextP),Coor(P));
        }else if (choice == 3){
            DelP(L,Info(P),Coor(P));
            DelP(L,kosong,NextCoor);
            InsVLastList(L,'H',Team(P),NextCoor);
            InsVLastList(L,kosong,Team(NextP),CurrCoor);
        }else if (choice == 4){
            DelP(L,Info(P),Coor(P));
            DelP(L,kosong,NextCoor);
            InsVLastList(L,'R',Team(P),NextCoor);
            InsVLastList(L,kosong,Team(NextP),CurrCoor);
        }
    }
    
    BoardPos(*L,T);
    PrintBoard(*T);

}