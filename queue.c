#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "queue.h"

/* ********* Prototype ********* */
boolean IsEmptyQueue (Queue Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */
    return ((Head(Q) == 0) && (Tail(Q) == 0));
}
boolean IsFullQueue (Queue Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
    return ((((Tail(Q) - Head(Q)) % MaxElQueue(Q)) + 1) == MaxElQueue(Q));
}
int NBElmtQueue (Queue Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    if (IsEmptyQueue(Q)){
        return 0;
    } else{
    return (((Tail(Q) - Head(Q)) % MaxElQueue(Q)) + 1);
    }
}
/* *** Kreator *** */
void CreateEmptyQueue (Queue * Q, int Max){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    (*Q).T = (infotypeQueue *) malloc (sizeof(infotypeQueue) * (Max + 1));

    if ((*Q).T != NULL){
        MaxElQueue(*Q) = Max;
        Head(*Q) = 0;
        Tail(*Q) = 0;
    }
    else{
        MaxElQueue(*Q) = 0;
    }
}
/* *** Destruktor *** */
void DeAlokasiQueue(Queue * Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
    MaxElQueue(*Q) = 0;
    free((*Q).T);
}
/* *** Primitif Add/Delete *** */
void AddQueue (Queue * Q, infotypeQueue X){
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
    if (Tail(*Q) == 0){
        Tail(*Q) = 1;
        Head(*Q) = 1; 
    }
    else{
        Tail(*Q) = (Tail(*Q) % MaxElQueue(*Q)) + 1;
    }
    InfoTail(*Q) = X;
}
void DelQueue (Queue * Q, infotypeQueue * X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
    (*X) = InfoHead(*Q);
    if ((Head(*Q) == 1) && (Tail(*Q) == 1)){
        Head(*Q) = 0;
        Tail(*Q) = 0;
    }
    else{
        Head(*Q) = (Head(*Q) % MaxElQueue(*Q)) + 1;
    }
}