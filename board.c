#include <stdio.h>
#include <stdlib.h>
#include "board.h"

void NewBoard (List *L){
    addressList  P;
    char pieces;
    int team;
    coordinat coor;

    CreateEmptyList(L);
    for (int i = 1;i <= 8;i++){
        for (int j = 1;j <= 8;j++){
            coor.ver = i;
            coor.hor = IntToChar(j);
            if (i == 1){
                if (j == 1){
                    pieces = 'r';
                    team = white;
                }else if (j == 2){
                    pieces = 'h';
                    team = white;
                }else if (j == 3){
                    pieces = 'b';
                    team = white;
                }else if (j == 4){
                    pieces = 'k';
                    team = white;
                }else if (j == 5){
                    pieces = 'q';
                    team = white;
                }else if (j == 6){
                    pieces = 'b';
                    team = white;
                }else if (j == 7){
                    pieces = 'h';
                    team = white;
                }else if (j == 8){
                    pieces = 'r';
                    team = white;
                }
                InsVFirstList(L, pieces, team, coor);
            }else if (i == 2){
                pieces = 'p';
                team = white;
                InsVFirstList(L, pieces, team, coor);
            }else if (i == 7){
                pieces = 'P';
                team = black;
                InsVFirstList(L, pieces, team, coor);
            }else if (i == 8){
                if (j == 1){
                    pieces = 'R';
                    team = black;
                }else if (j == 2){
                    pieces = 'H';
                    team = black;
                }else if (j == 3){
                    pieces = 'B';
                    team = black;
                }else if (j == 4){
                    pieces = 'K';
                    team = black;
                }else if (j == 5){
                    pieces = 'Q';
                    team = black;
                }else if (j == 6){
                    pieces = 'B';
                    team = black;
                }else if (j == 7){
                    pieces = 'H';
                    team = black;
                }else if (j == 8){
                    pieces = 'R';
                    team = black;
                }
                InsVFirstList(L, pieces, team, coor);
            }
        }
    }
}

void BoardPos (List L, TabChar *T){
    int i, j;
    addressList  P;
    char pieces;
    coordinat coor;

    for (i = 1;i <= 8;i++){
        for (j = 1;j <= 8;j++){
            (*T).TI[i][j] = kosong;
        }
    }

    P = First(L);
    while (P != Nil){
        pieces = Info(P);
        coor.hor = CharToInt(&Horizontal(P));
        coor.ver = Vertical(P);
        (*T).TI[coor.ver][coor.hor] = pieces;
        P = Next(P);
    }
}

void PrintBoard (TabChar T){
    for (int i = 9;i >= 0; i--){
        if ((i < 9) && (i > 0)){
            printf("%d ", i);
        }
        for (int j = 1;j <= 8;j++){
            if ((i == 9) && (j == 1)){
                printf("    a   b   c   d   e   f   g   h");
            }else if ((i < 9) && (i > 0) && (j < 8)){
                printf("| %c ", T.TI[i][j]);
            }else if ((i < 9) && (i > 0) && (j == 8)){
                printf("| %c |", T.TI[i][j]);
            }else if ((i == 0) && (j == 1)){
                printf("    a   b   c   d   e   f   g   h");
            }
        }
        if ((i < 9) && (i > 0)){
            printf(" %d", i);
        }
        printf("\n");
    }
}