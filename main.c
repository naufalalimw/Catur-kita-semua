#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "board.h"
#include "move.h"
#include "game.h"

int main(){
    List L, M; Path PL; TabChar T; addressList P, P2; addressPath PP; Queue Q;
    char pieces; int team, i = 1, X; coordinat coor, AfterCoor;

    NewGame(&Q,&L,&M,&T);
    /*

    CreateEmptyList(&M);

    P = First(L);
    while (P != Nil){
        coor.hor = Horizontal(P);
        coor.ver = Vertical(P);
        if ((Team(P) == white) && (isPiecesMove(T, Info(P), coor))){
            InsVFirstList(&M, Info(P), Team(P), coor);
        }
        P = Next(P);
    }

    scanf("%d", &X);

    P = First(M);
    i = 1;
    while (i != X){
        P = Next(P);
        i++;
    }
    
    CreateEmptyPath(&PL);

    coor.hor = Horizontal(P);
    coor.ver = Vertical(P);
    if (Info(P) == 'p'){
        whitepawnsPath(T, &PL, coor);
    }

    i = 1;
    PP = First(PL);
    while (PP != Nil){
        printf("%d. (%c,%d)\n", i, Horizontal(PP), Vertical(PP));
        i++;
        PP = Next(PP);
    }

    scanf("%d", &X);

    PP = First(PL);
    i = 1;
    while (i != X){
        PP = Next(PP);
        i++;
    }

    pieces = Info(P);
    team = Team(P);
    coor.hor = Horizontal(P);
    coor.ver = Vertical(P);

    AfterCoor.hor = Horizontal(PP);
    AfterCoor.ver = Vertical(PP);

    DelP(&L, Info(P), Team(P), coor);

    InsVFirstList(&L, pieces, team, AfterCoor);

    PrintInfoList(L);

    printf("\n");

    BoardPos(L, &T);
    PrintBoard(T);

    */
}
