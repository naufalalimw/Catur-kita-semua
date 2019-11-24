#include <stdio.h>
#include <stdlib.h>
#include "board.h"

void NewBoard (List *L){
    addressList  P;
    char pieces;
    int team;
    coordinat coor;

    for (int i = 1;i <= 8;i++){
        for (int j = 97;j <= 104;j++){
            coor.ver = i;
            coor.hor = j;
            if (i == 1){
                if (j == 97){
                    pieces = 'r';
                    team = white;
                }else if (j == 98){
                    pieces = 'h';
                    team = white;
                }else if (j == 99){
                    pieces = 'b';
                    team = white;
                }else if (j == 100){
                    pieces = 'q';
                    team = white;
                }else if (j == 101){
                    pieces = 'k';
                    team = white;
                }else if (j == 102){
                    pieces = 'b';
                    team = white;
                }else if (j == 103){
                    pieces = 'h';
                    team = white;
                }else if (j == 104){
                    pieces = 'r';
                    team = white;
                }
            }else if (i == 2){
                pieces = 'p';
                team = white;
            }else if ((i >= 3) && (i <= 6)){
                pieces = ' ';
                team = 0;
            }else if (i == 7){
                pieces = 'P';
                team = black;
            }else if (i == 8){
                if (j == 97){
                    pieces = 'R';
                    team = black;
                }else if (j == 98){
                    pieces = 'H';
                    team = black;
                }else if (j == 99){
                    pieces = 'B';
                    team = black;
                }else if (j == 100){
                    pieces = 'Q';
                    team = black;
                }else if (j == 101){
                    pieces = 'K';
                    team = black;
                }else if (j == 102){
                    pieces = 'B';
                    team = black;
                }else if (j == 103){
                    pieces = 'H';
                    team = black;
                }else if (j == 104){
                    pieces = 'R';
                    team = black;
                }
            }
        InsVFirstList(L, pieces, team, coor);
        }
    }
}

void BoardPos (List L, TabChar *T){
    int i, j;
    addressList  P;
    char pieces;
    coordinat coor;

    P = First(L);
    while (P != Nil){
        pieces = Info(P);
        coor.hor = Horizontal(P);
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
        for (int j = 97;j <= 104;j++){
            if ((i == 9) && (j == 97)){
                printf("    a   b   c   d   e   f   g   h\n");
                printf("   --- --- --- --- --- --- --- ---");
            }else if ((i < 9) && (i > 0) && (j < 104)){
                printf("| %c ", T.TI[i][j]);
            }else if ((i < 9) && (i > 0) && (j == 104)){
                printf("| %c |", T.TI[i][j]);
            }else if ((i == 0) && (j == 97)){
                printf("    a   b   c   d   e   f   g   h");
            }
        }
        if ((i < 9) && (i > 0)){
            printf(" %d", i); printf("\n");
            printf("   --- --- --- --- --- --- --- ---");
        }
        printf("\n");
    }
}