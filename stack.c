#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "stack.h"

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyStack (Stack *S){
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
	Top(*S) = 0;
}
/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyStack (Stack S)
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
{
	return (Top(S) == 0);
}
boolean IsFullStack (Stack S)
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */
{
	return (Top(S) == MaxElStack);
}

/* ********** Operator Dasar Stack ********* */
void PushStack (Stack *S, infotypeStack X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/*F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
{
	Top(*S)++;
	InfoTop(*S) = X;
}
void PopStack (Stack *S, infotypeStack *X)
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
	(*X) = InfoTop(*S);
	Top(*S)--;
}
