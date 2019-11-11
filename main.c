#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "boolean.h"
#include "array.h"
#include "listlinier.h"

void PosisiAwal (List * L){
    addressList P;
    char X;
    infotypeList Pos;

    for (int i = 1;i <= 8;i++){
        for (int j = 1;j <= 8;j++){
            Pos.hor = i;
            Pos.ver = j;
            if ((i == 1) && (j == 1)){
                X = 'r';
            }else if ((i == 1) && (j == 2)){
                X = 'h';
            }else if ((i == 1) && (j == 3)){
                X = 'b';
            }else if ((i == 1) && (j == 4)){
                X = 'k';
            }else if ((i == 1) && (j == 5)){
                X = 'q';
            }else if ((i == 1) && (j == 6)){
                X = 'b';
            }else if ((i == 1) && (j == 7)){
                X = 'h';
            }else if ((i == 1) && (j == 8)){
                X = 'r';
            }else if (i == 2){
                X = 'p';
            }else if ((i >= 3) && (i <= 6)){
                X = 'x';
            }else if (i == 7){
                X = 'P';
            }else if ((i == 8) && (j == 1)){
                X = 'R';
            }else if ((i == 8) && (j == 2)){
                X = 'H';
            }else if ((i == 8) && (j == 3)){
                X = 'B';
            }else if ((i == 8) && (j == 4)){
                X = 'Q';
            }else if ((i == 8) && (j == 5)){
                X = 'K';
            }else if ((i == 8) && (j == 6)){
                X = 'B';
            }else if ((i == 8) && (j == 7)){
                X = 'H';
            }else if ((i == 8) && (j == 8)){
                X = 'R';
            }
            InsVFirstList(L, X, Pos);
        }
    }
}

void PosisiPapan (TabChar * T1, List * L){
    addressList P;
    char X;
    infotypeList Pos;

    P = First(*L);
    while (P != Nil){
        X = Info(P);
        Pos.hor = Horizontal(P); 
        Pos.ver = Vertical(P);
        (*T1).TI[Pos.hor][Pos.ver] = X;
        P = Next(P);
    }
}

void PrintPapan (TabChar T1){
    for (int i = 0;i <= 8; i++){
        if (i > 0){
            printf("%d ", i);
        }
        for (int j = 1;j <= 8;j++){
            if ((i == 0) && (j == 1)){
                printf("    a   b   c   d   e   f   g   h");
            }else if ((i > 0) && (j < 8)){
                printf("| ");
                if (T1.TI[i][j] != 'x'){
                    printf("%c ", T1.TI[i][j]);
                }else{
                    printf("  ");
                }
            }else if ((i > 0) && (j == 8)){
                printf("| ");
                if (T1.TI[i][j] != 'x'){
                    printf("%c ", T1.TI[i][j]);
                }else{
                    printf("  ");
                }
                printf("|");
            }
        }
        printf("\n");
    }
}


int main (){
    TabChar T1;
    List L;

    CreateEmptyList(&L);
    PosisiAwal(&L);
    PosisiPapan(&T1,&L);
    PrintPapan(T1);
}