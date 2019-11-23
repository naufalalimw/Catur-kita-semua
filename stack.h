#ifndef STACK_H
#define STACK_H

#include "boolean.h"
#include "listlinier.h"

/* MODUL STACK
Deklarasi stack yang diimplementasi dengan tabel kontigu alokasi statik
dan ukuran sama
TOP adalah alamat elemen puncak*/

#define MaxElStack 100

typedef struct {
    char PrevPieces, NextPieces;
    int PrevTeam, NextTeam;
    coordinat PrevCoor, NextCoor;
} infotypeStack;

typedef int addressStack;

typedef struct {
    infotypeStack T[MaxElStack + 1];
    addressStack TOP;
} Stack;

#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* Definisi stack S kosong : S.TOP = Nil */
/* S.TOP = jumlah element stack */
/* S.T[S.TOP-1] = element paling atas */


/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyStack (Stack *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyStack (Stack S);
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
boolean IsFullStack (Stack S);
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */

/* ********** Operator Dasar Stack ********* */
void PushStack (Stack *S, infotypeStack X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/*F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
void PopStack (Stack *S, infotypeStack *X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

#endif