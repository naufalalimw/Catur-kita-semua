#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "game.h"

void NewGame (Queue *Q, Stack *S, List *L, List *M, TabChar *T, Path *PL){
    infotypeQueue team;
    int i, choice, whiteScore, blackScore;

    CreateEmptyQueue(Q, 50);
    CreateEmptyStack(S);
    CreateEmptyList(L);

    for (i = 1;i <= 25;i++){
        AddQueue(Q, white);
        AddQueue(Q, black);
    }
    
    /* masukin nama */
    whiteScore = 0;
    blackScore = 0;
    
    NewBoard(L);
    BoardPos(*L,T);
    PrintBoard(*T);
    do{
        command(Q,S,L,M,T,PL,&team,&whiteScore,&blackScore);
    } while ((!IsEmptyQueue(*Q)) && (!isKingDead(*L)) && (!isCheckMate(*L,*T,white)) && (!isCheckMate(*L,*T,black)));

    if (isKingDead(*L)){
        printf("skor pemain putih : %d\n", whiteScore);
        printf("skor pemain hitam : %d", blackScore);
    }else{
        if (!isCheckMate(*L,*T,white)){
            whiteScore += 20;
        }else if (!isCheckMate(*L,*T,black)){
            blackScore += 20;
        }
        printf("skor pemain putih : %d\n", whiteScore);
        printf("skor pemain hitam : %d", blackScore);
    }   
}

void command (Queue *Q, Stack *S, List *L, List *M, TabChar *T, Path *PL, int *team, int *whiteScore, int *blackScore){
    addressList P; 
    infotypeStack X;
    char com[20];
    addressList KingP, RookP; coordinat RookCoor;

    printf("Masukkan command (ketik 'help' untuk menampilkan command yang bisa dipilih) : ");
    scanf("%s", &com);

    while (strcmp(com, "help") == 0){
        printf("Command yang dapat dipilih :\n");
        printf("1. move\n"); printf("2. special_move\n"); printf("3. undo\n");
        printf("Masukkan command : ");
        scanf("%s", &com);
    }
    
    if (strcmp(com, "move") == 0){
        PrintBoard(*T);
        DelQueue(Q, team);
        turn(S,*L,M,T,PL,team,whiteScore,blackScore);
    }else if (strcmp(com, "special_move") == 0){
        DelQueue(Q, team);
        if (isPromotion(*L,*team)){
            promotion(S,L,M,T,PL,team);
        }
        
        /*
            - en passant
            - castling
            - promotion
        */

    }else if (strcmp(com, "undo") == 0){
        for (int i = 1;i <= 2;i++){
            PopStack(S, &X);
            DelP(L,' ',X.PrevCoor);
            DelP(L,X.PrevPieces,X.NextCoor);
            InsVLastList(L,X.PrevPieces,X.PrevTeam,X.PrevCoor);
            InsVLastList(L,X.NextPieces,X.NextTeam,X.NextCoor);
            BoardPos(*L,T);
        }
        PrintBoard(*T);
        AddQueue(Q, white);
        AddQueue(Q, black);
    }
}

void piecesMove(List L, List *M, TabChar T, int *team){
    addressList P;
    coordinat coor;

    CreateEmptyList(M);

    P = First(L);
    while (P != Nil){
        coor.hor = Horizontal(P);
        coor.ver = Vertical(P);
        if ((isPiecesMove(L,T,Info(P),coor)) && (Team(P) == *team)){
            InsVFirstList(M,Info(P),Team(P),coor);
        }
        P = Next(P);
    }
}

void turn (Stack *S, List L, List *M, TabChar *T, Path *PL, int *team, int *whiteScore, int *blackScore){
    addressList P; addressPath PP;
    coordinat coor, CurrCoor, NextCoor;
    int i, choice; char pieces;

    piecesMove(L,M,*T,team);

    printf("Buah catur yang dapat dipindahkan :\n");
    printTurn(*M);
    printf("Pilih buah catur yang ingin dipindahkan : "); scanf("%d", &choice);
    i = 1;

    P = First(*M);
    while (i != choice+1){
        P = Next(P);
        i++;
    }

    posMove(L,P,*T,PL);
    printf("Koordinat yang dapat dipilih :\n");
    printPosMove(*PL);
    printf("Pilih koordinat yang akan dipilih : "); scanf("%d", &choice);
    i = 1;

    PP = First(*PL);
    while (i != choice){
        PP = Next(PP);
        i++;
    }

    movement(S,&L,P,*PL,PP,whiteScore,blackScore);

    BoardPos(L,T);
    PrintBoard(*T);
}

void printTurn (List M){
    addressList P;
    int i = 1;

    P = First(M);
    while (P != Nil){
        if (Info(P) != 'X'){
            printf("%d. (%c,%d)\n", i, Horizontal(P), Vertical(P));
            i++;
        }
        P = Next(P);
    }
}

void printPosMove (Path PL){
    addressPath PP;
    int i = 1;

    PP = First(PL);
    while (PP != Nil){
        printf("%d. (%c,%d)\n", i, Horizontal(PP), Vertical(PP));
        i++;
        PP = Next(PP);
    }
}

void movement (Stack *S, List *L, addressList CurrP, Path PL, addressPath PP, int *whiteScore, int *blackScore){
    addressList NextP;
    infotypeStack X;
    boolean found, eaten;
    char CurrPieces, NextPieces; int CurrTeam, NextTeam; coordinat CurrCoor, NextCoor;

    NextCoor = Coor(PP);

    NextP = SearchListCoordinat(*L,NextCoor);

    NextPieces = Info(NextP);
    NextTeam = Team(NextP);

    CurrPieces = Info(CurrP);
    CurrTeam = Team(CurrP);
    CurrCoor = Coor(CurrP);

    if (isPieces(NextPieces)){
        DelP(L,CurrPieces,CurrCoor);
        DelP(L,NextPieces,NextCoor);
        InsVLastList(L,CurrPieces,CurrTeam,NextCoor);
        InsVLastList(L,kosong,0,CurrCoor);
    }else{
        DelP(L,CurrPieces,CurrCoor);
        DelP(L,NextPieces,NextCoor);
        InsVLastList(L,CurrPieces,CurrTeam,NextCoor);
        InsVLastList(L,NextPieces,NextTeam,CurrCoor);
    }

    X.PrevPieces = CurrPieces; X.NextPieces = NextPieces;
    X.PrevTeam = CurrTeam; X.NextTeam = NextTeam;
    X.PrevCoor = CurrCoor; X.NextCoor = NextCoor;
    PushStack(S, X);

    if (CurrTeam == white){
        getScore(NextPieces, whiteScore);
    }else if (CurrTeam == black){
        getScore(NextPieces, blackScore);
    }
}

void getScore(char NextPieces, int *score){
    if ((NextPieces == 'K') || (NextPieces == 'k')){
        (*score) += 10;
    }else if ((NextPieces == 'Q') || (NextPieces == 'q')){
        (*score) += 8;
    }else if ((NextPieces == 'B') || (NextPieces == 'b')){
        (*score) += 4;
    }else if ((NextPieces == 'H') || (NextPieces == 'h')){
        (*score) += 2;
    }else if ((NextPieces == 'R') || (NextPieces == 'r')){
        (*score) += 4;
    }else if ((NextPieces == 'P') || (NextPieces == 'p')){
        (*score) += 1;
    }
}