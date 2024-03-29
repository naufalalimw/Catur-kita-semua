/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi addressList dengan pointer */
/* char adalah integer */

#ifndef listlinier_H
#define listlinier_H

#include "boolean.h"

#define Nil NULL
#define black 200
#define white 150
#define kosong ' '

typedef struct {
	int hor;
	int ver;
} coordinat;

typedef struct tElmtlist *addressList;
typedef struct tElmtlist { 
	char info;
	int team;
	coordinat coor;
	addressList next;
} ElmtList;
typedef struct {
	addressList First;
} List;

typedef struct tElmtPath *addressPath;
typedef struct tElmtPath {
	coordinat coor;
	addressPath next;
} ElmtPath;
typedef struct {
	addressPath First;
} Path;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan addressList P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */
#define Info(P) (P)->info
#define Team(P) (P)->team
#define Coor(P) (P)->coor
#define Horizontal(P) (P)->coor.hor
#define Vertical(P) (P)->coor.ver
#define Next(P) (P)->next
#define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (List L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
void CreateEmptyPath (Path *PL);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
addressList AlokasiList (char pieces, int team, coordinat coor);
/* Mengirimkan addressList hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressList tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
addressPath AlokasiPath (coordinat coor);
/* Mengirimkan addressList hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressList tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokasiList (addressList *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressList P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressList SearchList (List L, char pieces, coordinat coor);
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan addressList elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
addressList SearchListPieces (List L, char pieces);
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan addressList elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
addressList SearchListCoordinat (List L, coordinat coor);
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan addressList elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstList (List *L, char pieces, int team, coordinat coor);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVFirstPath (Path *PL, coordinat coor);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLastList (List *L, char pieces, int team, coordinat coor);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, char *X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, char *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstList (List *L, addressList P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressList P sebagai elemen pertama */
void InsertFirstPath (Path *PL, addressPath PP);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressList P sebagai elemen pertama */
void InsertAfterList (List *L, addressList P, addressList Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLastList (List *L, addressList P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, addressList *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, char pieces, coordinat coor);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressList P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, addressList *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, addressList *Pdel, addressList Prec);
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfoList (List L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintInfoPath (Path PL);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmt (List L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
int NbElmtPath (Path PL);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
char Max (List L);
/* Mengirimkan nilai info(P) yang maksimum */
addressList AdrMax (List L);
/* Mengirimkan addressList P, dengan info(P) yang bernilai maksimum */
char Min (List L);
/* Mengirimkan nilai info(P) yang minimum */
addressList AdrMin (List L);
/* Mengirimkan addressList P, dengan info(P) yang bernilai minimum */
float Average (List L);
/* Mengirimkan nilai rata-rata info(P) */

/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L);
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

void Konkat1 (List *L1, List *L2, List *L3);
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

#endif