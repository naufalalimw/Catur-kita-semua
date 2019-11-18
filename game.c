#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "game.h"

void NewGame (Queue *Q, List *L, List *M, TabChar *T){
    infotypeQueue team;
    int i, choice;

    CreateEmptyQueue(Q, 50);

    for (i = 1;i <= 25;i++){
        AddQueue(Q, white);
        AddQueue(Q, black);
    }

    NewBoard(L);
    BoardPos(*L,T);
    PrintBoard(*T);
    /*
    while (!IsEmptyQueue(*Q)){
        */
        DelQueue(Q,&team);
        turn(*L,M,*T,team);
        printf("Buah catur yang dapat dipindahkan :\n");
        printTurn(*M);
        printf("Pilih buah catur yang ingin dipindahkan :\n"); scanf("%d", &choice);

    /*
    }
    */
}

void turn (List L, List *M, TabChar T, int team){
    addressList P;
    coordinat coor;

    CreateEmptyList(M);

    P = First(L);
    while (P != Nil){
        coor.hor = Horizontal(P);
        coor.ver = Vertical(P);
        if ((isPiecesMove(L,T,Info(P),coor)) && (Team(P) == white)){
            InsVFirstList(M,Info(P),Team(P),coor);
        }
        P = Next(P);
    }
}

void printTurn (List M){
    addressList P;
    int i = 1;

    P = First(M);
    while (P != Nil){
        printf("%d. (%c,%d)\n", i, Horizontal(P), Vertical(P));
        i++;
        P = Next(P);
    }
}

void posMove (List M, Path *PL, int choice){
    addressList P; addressPath PP;
    int i = 1;

    CreateEmptyPath(PL);

    P = First(M);
    while (i != choice){
        P = Next(P);
        i++;
    }

    if (Info(P) == )
    
}