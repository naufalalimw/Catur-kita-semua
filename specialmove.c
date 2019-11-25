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

boolean isEnPassant (Stack *S, List L, int *team){
    List M;
    addressList P; coordinat NextCoor; infotypeStack XS;
    boolean found; int diffVer, diffHor;

    PopStack(S, &XS);
    diffVer = (XS.NextCoor.ver - XS.PrevCoor.ver);

    P = First(L);
    while (P != Nil){
        diffHor = (XS.NextCoor.hor - Horizontal(P));
        if (*team == white){
            if ((Info(P) == 'p') && (Vertical(P) == 5) && (diffVer == -2) && (diffHor >= -1) && (diffHor <= 1)){
                found = true;
            }
        }else if (*team == black){
            if ((Info(P) == 'P') && (Vertical(P) == 4) && (diffVer == 2) && (diffHor >= -1) && (diffHor <= 1)){
                found = true;
            }
        }
        P = Next(P);
    }

    PushStack(S, XS);

    return found;
}

void promotion (Stack *S, List *L, List *M, TabChar *T, Path *PL, int *team){
    addressList P, NextP; addressPath PP;
    coordinat coor,  CurrCoor, NextCoor; infotypeStack X;
    int i, choice; char pieces;

    CreateEmptyList(M);

    if (*team == white){
        P = First(*L);
        while (P != Nil){
            if ((Team(P) == *team) && (Info(P) == 'p') && (Vertical(P) == 7)){
                InsVFirstList(M,Info(P),Team(P),Coor(P));
            }
            P = Next(P);
        }
    }else if (*team == black){
        P = First(*L);
        while (P != Nil){
            if ((Team(P) == *team) && (Info(P) == 'P') && (Vertical(P) == 2)){
                InsVFirstList(M,Info(P),Team(P),Coor(P));
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

    posMove(*L,P,*T,PL);

    printf("Koordinat yang dapat dipilih :\n");
    printPosMove(*PL);
    printf("Pilih koordinat yang akan dipilih : "); scanf("%d", &choice);
    i = 1;

    PP = First(*PL);
    while (i != choice){
        PP = Next(PP);
        i++;
    }

    printf("Buah catur hasil promosi :\n");
    printf("1. Ratu\n");
    printf("2. Menteri\n");
    printf("3. Kuda\n");
    printf("4. Benteng\n");
    printf("Pilih buah catur hasil promosi : "); scanf("%d", &choice);

    NextCoor = Coor(PP);
    NextP = SearchListCoordinat(*L,NextCoor);
    
    if (*team == white){
        if (choice == 1){
            DelP(L,Info(P),Coor(P));
            DelP(L,Info(NextP),NextCoor);
            InsVLastList(L,'q',Team(P),NextCoor);
            InsVLastList(L,kosong,0,Coor(P));
        }else if (choice == 2){
            DelP(L,Info(P),Coor(P));
            DelP(L,Info(NextP),NextCoor);
            InsVLastList(L,'b',Team(P),NextCoor);
            InsVLastList(L,kosong,0,Coor(P));
        }else if (choice == 3){
            DelP(L,Info(P),Coor(P));
            DelP(L,Info(NextP),NextCoor);
            InsVLastList(L,'h',Team(P),NextCoor);
            InsVLastList(L,kosong,0,Coor(P));
        }else if (choice == 4){
            DelP(L,Info(P),Coor(P));
            DelP(L,Info(NextP),NextCoor);
            InsVLastList(L,'r',Team(P),NextCoor);
            InsVLastList(L,kosong,0,Coor(P));
        }
    }else if (*team == black){
        if (choice == 1){
            DelP(L,Info(P),Coor(P));
            DelP(L,Info(NextP),NextCoor);
            InsVLastList(L,'Q',Team(P),NextCoor);
            InsVLastList(L,kosong,0,Coor(P));
        }else if (choice == 2){
            DelP(L,Info(P),Coor(P));
            DelP(L,Info(NextP),NextCoor);
            InsVLastList(L,'B',Team(P),NextCoor);
            InsVLastList(L,kosong,0,Coor(P));
        }else if (choice == 3){
            DelP(L,Info(P),Coor(P));
            DelP(L,Info(NextP),NextCoor);
            InsVLastList(L,'H',Team(P),NextCoor);
            InsVLastList(L,kosong,0,Coor(P));
        }else if (choice == 4){
            DelP(L,Info(P),Coor(P));
            DelP(L,Info(NextP),NextCoor);
            InsVLastList(L,'R',Team(P),NextCoor);
            InsVLastList(L,kosong,0,Coor(P));
        }
    }
    BoardPos(*L,T);
    PrintBoard(*T);

    X.PrevPieces = Info(P); X.NextPieces = Info(NextP);
    X.PrevTeam = Team(P); X.NextTeam = Team(NextP);
    X.PrevCoor = Coor(P); X.NextCoor = Coor(NextP);
    PushStack(S, X);
}

void enPassant (Stack *S, List *L, List *M, TabChar *T, Path *PL, int *team){
    addressList P, NextP, PawnP; addressPath PP;
    coordinat coor,  CurrCoor, NextCoor; infotypeStack X, XS;
    int i, choice, diffHor, diffVer; char pieces;

    CreateEmptyList(M);

    PopStack(S, &XS);
    diffVer = (XS.NextCoor.ver - XS.PrevCoor.ver);

    P = First(*L);
    while (P != Nil){
        diffHor = (XS.NextCoor.hor - Horizontal(P));
        if (*team == white){
            if ((Info(P) == 'p') && (Vertical(P) == 5) && (diffVer == -2) && (diffHor >= -1) && (diffHor <= 1)){
                InsVFirstList(M,Info(P),Team(P),Coor(P));
            }
        }else if (*team == black){
            if ((Info(P) == 'P') && (Vertical(P) == 4) && (diffVer == 2) && (diffHor >= -1) && (diffHor <= 1)){
                InsVFirstList(M,Info(P),Team(P),Coor(P));
            }
        }
        P = Next(P);
    }

    P = First(*M);
    P = Next(P);

    NextCoor = Coor(P);
    diffHor = (XS.NextCoor.hor - Horizontal(P));
    PawnP = SearchListCoordinat(*L,XS.NextCoor);

    if (*team == white){
        if (diffHor == 1){
            NextCoor.hor++; NextCoor.ver++;
            NextP = SearchListCoordinat(*L,NextCoor);
            DelP(L,Info(P),Coor(P));
            DelP(L,Info(NextP),NextCoor);
            DelP(L,Info(PawnP),XS.NextCoor);
            InsVLastList(L,Info(P),Team(P),NextCoor);
            InsVLastList(L,kosong,0,Coor(P));
            InsVLastList(L,kosong,0,Coor(PawnP));
        }else if (diffHor == -1){
            NextCoor.hor--; NextCoor.ver++;
            NextP = SearchListCoordinat(*L,NextCoor);
            DelP(L,Info(P),Coor(P));
            DelP(L,Info(NextP),NextCoor);
            DelP(L,Info(PawnP),XS.NextCoor);
            InsVLastList(L,Info(P),Team(P),NextCoor);
            InsVLastList(L,kosong,0,Coor(P));
            InsVLastList(L,kosong,0,Coor(PawnP));
        }
    }else if (*team == black){
        if (diffHor == 1){
            NextCoor.hor++; NextCoor.ver--;
            NextP = SearchListCoordinat(*L,NextCoor);
            DelP(L,Info(P),Coor(P));
            DelP(L,Info(NextP),NextCoor);
            DelP(L,Info(PawnP),XS.NextCoor);
            InsVLastList(L,Info(P),Team(P),NextCoor);
            InsVLastList(L,kosong,0,Coor(P));
            InsVLastList(L,kosong,0,Coor(PawnP));
        }else if (diffHor == -1){
            NextCoor.hor--; NextCoor.ver--;
            NextP = SearchListCoordinat(*L,NextCoor);
            DelP(L,Info(P),Coor(P));
            DelP(L,Info(NextP),NextCoor);
            DelP(L,Info(PawnP),XS.NextCoor);
            InsVLastList(L,Info(P),Team(P),NextCoor);
            InsVLastList(L,kosong,0,Coor(P));
            InsVLastList(L,kosong,0,Coor(PawnP));
        }
    }
    BoardPos(*L,T);
    PrintBoard(*T);

    X.PrevPieces = Info(PawnP); X.NextPieces = Info(P);
    X.PrevTeam = Team(PawnP); X.NextTeam = Team(P);
    X.PrevCoor = Coor(PawnP); X.NextCoor = Coor(P);
    PushStack(S, X);
}