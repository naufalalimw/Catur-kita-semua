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
        command(Q,S,L,M,T,PL,team,&whiteScore,&blackScore);
    } while (!IsEmptyQueue(*Q) && (!isKingDead(*L)));
    printf("skor pemain putih : %d\n", whiteScore);
    printf("skor pemain hitam : %d", blackScore);   
}

void command (Queue *Q, Stack *S, List *L, List *M, TabChar *T, Path *PL, int team, int *whiteScore, int *blackScore){
    addressList P;
    infotypeStack X;
    char com[20];

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
        DelQueue(Q, &team);
        turn(S,*L,M,T,PL,team,whiteScore,blackScore);
    }else if (strcmp(com, "special_move") == 0){

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

void turn (Stack *S, List L, List *M, TabChar *T, Path *PL, int team, int *whiteScore, int *blackScore){
    addressList P;
    coordinat coor, CurrCoor, NextCoor;
    int choice; char pieces;

    CreateEmptyList(M);

    P = First(L);
    while (P != Nil){
        coor.hor = Horizontal(P);
        coor.ver = Vertical(P);
        if ((isPiecesMove(L,*T,Info(P),coor)) && (Team(P) == team)){
            InsVFirstList(M,Info(P),Team(P),coor);
        }
        P = Next(P);
    }

    printf("Buah catur yang dapat dipindahkan :\n");
    printTurn(*M);
    printf("Pilih buah catur yang ingin dipindahkan : "); scanf("%d", &choice);
    posMove(L,*M,*T,PL,&pieces,&team,&CurrCoor,choice);
    printf("Koordinat yang dapat dipilih :\n");
    printPosMove(*PL);
    printf("Pilih koordinat yang akan dipilih : "); scanf("%d", &choice);
    movement(S,&L,*PL,pieces,team,CurrCoor,&NextCoor,choice,whiteScore,blackScore);

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

void posMove (List L, List M, TabChar T, Path *PL, char *pieces, int *team, coordinat *CurrCoor, int choice){
    addressList P;
    int i = 1;

    CreateEmptyPath(PL);

    P = First(M);
    while (i != choice+1){
        P = Next(P);
        i++;
    }

    (*pieces) = Info(P);
    (*team) = Team(P);
    (*CurrCoor).hor = Horizontal(P);
    (*CurrCoor).ver = Vertical(P);

    if (Info(P) == 'P'){
        blackpawnsPath(L,T,PL,*CurrCoor);
    }else if (Info(P) == 'p'){
        whitepawnsPath(L,T,PL,*CurrCoor);
    }else if ((Info(P) == 'R') || (Info(P) == 'r')){
        rooksPath(L,T,PL,*CurrCoor);
    }else if ((Info(P) == 'H') || (Info(P) == 'h')){
        horsesPath(L,T,PL,*CurrCoor);
    }else if ((Info(P) == 'B') || (Info(P) == 'b')){
        bishopsPath(L,T,PL,*CurrCoor);
    }else if ((Info(P) == 'Q') || (Info(P) == 'q')){
        queesPath(L,T,PL,*CurrCoor);
    }else if ((Info(P) == 'K') || (Info(P) == 'k')){
        kingsPath(L,T,PL,*CurrCoor);
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

void movement (Stack *S, List *L, Path PL, char CurrPieces, int CurrTeam, coordinat CurrCoor, coordinat *NextCoor, int choice, int *whiteScore, int *blackScore){
    addressList P; addressPath PP;
    infotypeStack X;
    boolean found, eaten;
    int i = 1; char NextPieces; int NextTeam;

    PP = First(PL);
    while (i != choice){
        PP = Next(PP);
        i++;
    }

    (*NextCoor).hor = Horizontal(PP);
    (*NextCoor).ver = Vertical(PP);

    P = First(*L);
    found = false;
    while ((P != Nil) && (!found)){
        if ((Horizontal(P) == (*NextCoor).hor) && (Vertical(P) == (*NextCoor).ver)){
            found = true;
        }else{
            P = Next(P);
        }
    }

    NextPieces = Info(P);
    NextTeam = Team(P);

    if (isPieces(NextPieces)){
        DelP(L,CurrPieces,CurrCoor);
        DelP(L,NextPieces,*NextCoor);
        InsVLastList(L,CurrPieces,CurrTeam,*NextCoor);
        InsVLastList(L,kosong,0,CurrCoor);
    }else{
        DelP(L,CurrPieces,CurrCoor);
        DelP(L,NextPieces,*NextCoor);
        InsVLastList(L,CurrPieces,CurrTeam,*NextCoor);
        InsVLastList(L,NextPieces,NextTeam,CurrCoor);
    }

    X.PrevPieces = CurrPieces; X.NextPieces = NextPieces;
    X.PrevTeam = CurrTeam; X.NextTeam = NextTeam;
    X.PrevCoor = CurrCoor; X.NextCoor = (*NextCoor);
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