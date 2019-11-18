/* File : array.c */

/* NIM				: 18218021 */
/* Nama				: Muhamad Ilman Sukarsa */
/* Tanggal			: 11 September 2019 */
/* Topik praktiktum	: Pra Praktikum 2 - ADR Point */
/* Deskripsi		: Array */

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmptyTab (TabChar *T){
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
    (*T).Neff = 0;
}

/* *** Selektor INDEKS *** */
/* *** Menghasilkan sebuah elemen *** */
ElType GetElmtTab (TabChar T, IdxType i, IdxType j){
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
    return (T.TI[i][j]);
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabChar Tin, TabChar *Tout){
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
    int i, j;
    for (i = 1; i <= IdxMax; i++){
        for (j = 1;j <= IdxMax; j++){
            (Tout->TI[i][j] = Tin.TI[i][j]);
        }
    };
}
void SetElTab (TabChar *T, IdxType i, IdxType j, ElType v){
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
    (T)->TI[i][j] = v;
}