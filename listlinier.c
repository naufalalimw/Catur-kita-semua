/* Muhamad Ilman Sukarsa */
#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"


/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (List L){
/* Mengirim true jika list kosong */
    addressList Pdummy;

    Pdummy = First(L);
    Pdummy = Next(Pdummy);
    return (Pdummy == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    addressList Pdummy;
    coordinat coor;
    coor.hor = 48; coor.ver = 0;

    Pdummy = AlokasiList('X',0,coor);
    if (Pdummy != Nil){
        First(*L) = Pdummy;
    }else{
        First(*L) = Nil;
    }
    
}
void CreateEmptyPath (Path *PL){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    First(*PL) = Nil;
}

/****************** Manajemen Memori ******************/
addressList AlokasiList (char pieces, int team, coordinat coor){
/* Mengirimkan addressList hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressList tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    addressList P;

    P = (addressList) malloc (sizeof(ElmtList));
    if (P != Nil){
        Info(P) =  pieces;
        Team(P) = team;
        Horizontal(P) = coor.hor;
        Vertical(P) = coor.ver;
        Next(P) = Nil;
        return P;
    }else{
        return Nil;
    }
}
addressPath AlokasiPath (coordinat coor){
/* Mengirimkan addressList hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressList tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    addressPath PP;

    PP = (addressPath) malloc (sizeof(ElmtPath));
    if (PP != Nil){
        Horizontal(PP) = coor.hor;
        Vertical(PP) = coor.ver;
        Next(PP) = Nil;
        return PP;
    }else{
        return Nil;
    }
}
void DealokasiList (addressList *P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressList P */
    free(*P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressList SearchList (List L, char pieces, coordinat coor){
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan addressList elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    addressList P;
    boolean found;

    P = First(L);

    found = false;
    while ((P != Nil) && (!found)){
        if ((Info(P) == pieces) && (Horizontal(P) == coor.hor) && (Vertical(P) == coor.ver)){
            found = true;
        }else{
        P = Next(P);
        }
    }
    return P;
}
addressList SearchListPieces (List L, char pieces){
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan addressList elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    addressList P;
    boolean found;

    P = First(L);

    found = false;
    while ((P != Nil) && (!found)){
        if (Info(P) == pieces){
            found = true;
        }else{
        P = Next(P);
        }
    }
    return P;
}
addressList SearchListCoordinat (List L, coordinat coor){
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan addressList elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    addressList P;
    boolean found;

    P = First(L);

    found = false;
    while ((P != Nil) && (!found)){
        if ((Horizontal(P) == coor.hor) && (Vertical(P) == coor.ver)){
            found = true;
        }else{
        P = Next(P);
        }
    }
    return P;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstList (List *L, char pieces, int team, coordinat coor){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    addressList P;
    P = AlokasiList(pieces, team, coor);
    if (P != Nil){
        InsertFirstList(L, P);
    }
}
void InsVFirstPath (Path *PL, coordinat coor){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    addressPath PP;
    PP = AlokasiPath(coor);
    if (PP != Nil){
        InsertFirstPath(PL, PP);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLastList (List *L, char pieces, int team, coordinat coor){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    addressList P;
    P = AlokasiList(pieces, team, coor);
    if (P != Nil){
        InsertLastList(L, P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, char *X){
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
    addressList P, Prec;
    P = First(*L);
    (*X) = Info(P);
    Prec = Next(P);
    First(*L) = Prec;
    DealokasiList(&P);
}
void DelVLast (List *L, char *X){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    addressList P;
    DelLast(L, &P);
    (*X) = Info(P);
    DealokasiList(&P);
}
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstList (List *L, addressList P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressList P sebagai elemen pertama */
    addressList Pdummy;

    Pdummy = First(*L);
    Next(P) = Next(Pdummy);
    Next(Pdummy) = P;
}
void InsertFirstPath (Path *PL, addressPath PP){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressList P sebagai elemen pertama */
    Next(PP) = First(*PL);
    First(*PL) = PP;
}
void InsertAfterList (List *L, addressList P, addressList Prec){
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
void InsertLastList (List *L, addressList P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    addressList Last;
    Last  = First(*L);
    if (Last == Nil){
        InsertFirstList(L, P);
    }
    else{
        while (Next(Last) != Nil){
            Last = Next(Last);
        }
        InsertAfterList(L, P, Last);
    }
}
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, addressList *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
    (*P) = First(*L);
    First(*L) = Next(First(*L));
}
void DelP (List *L, char pieces, coordinat coor){
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressList P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    addressList P1, P2, prec;

    P1 = SearchList(*L,pieces,coor);

    if (P1 != Nil){
        if (P1 == First(*L)){
            DelVFirst(L, &pieces);
        }
        else{
            P2 = First(*L);
            while (P1 != P2){
                prec = P2;
                P2 = Next(P2);
            }
            if (P1 == P2){
                DelAfter(L, &P2, prec);
                DealokasiList(&P2);
            }
        }
    }
}
void DelLast (List *L, addressList *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
    addressList Last;
    (*P) = First(*L);
    Last = Nil;
    while (Next(*P) != Nil){
        Last = (*P);
        (*P) = Next(*P);
    }
    if (Last == Nil){
        DelFirst (L,P);
    }
    else{
        DelAfter(L, P, Last);
    }
}
void DelAfter (List *L, addressList *Pdel, addressList Prec){
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    (*Pdel) = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Next(*Pdel) = Nil;
}
/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfoList (List L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    addressList P;
    P = First(L);
    if (P == Nil) {
        printf("[]");
    }
    else {
        printf("[");
        while (Next(P) != Nil) {
            printf("%c,", Info(P));
            P = Next(P);
        }
        printf("%c]", Info(P));
    }  
}
void PrintInfoPath (Path PL){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    addressPath PP;
    PP = First(PL);
    if (PP == Nil) {
        printf("[]");
    }
    else {
        printf("[");
        while (Next(PP) != Nil) {
            printf("%d,", Vertical(PP));
            PP = Next(PP);
        }
        printf("%d]", Vertical(PP));
    }  
}
int NbElmt (List L){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    addressList P;
    int count = 0;

    P = First(L); P = Next(P);
    while (P != Nil){
        count++;
        P = Next(P);
    }
    return count;
}

int NbElmtPath (Path PL){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    addressPath PP;
    int count = 0;

    PP = First(PL);
    while (PP != Nil){
        count++;
        PP = Next(PP);
    }
    return count;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
char Max (List L){
/* Mengirimkan nilai Info(P) yang maksimum */
    addressList P;
    char maks;

    P = First(L);
    maks = Info(P);
    P = Next(P);
    while(P != Nil){
        if (Info(P) >= maks){
            maks = Info(P);
        }
        P = Next(P);
    }
    return maks;
}
addressList AdrMax (List L){
/* Mengirimkan addressList P, dengan info(P) yang bernilai maksimum */
	addressList P;
	boolean found;
	
	P = First(L);
	found = false;
	while ((P != Nil) && (!found)){
		if (Info(P) == Max(L)){
			found = true;
		}else{
			P = Next(P);
		}
	}
	return P;
}
char Min (List L){
/* Mengirimkan nilai info(P) yang minimum */
	addressList P;
    char min;

    P = First(L);
    min = Info(P);
    P = Next(P);
    while(P != Nil){
        if (Info(P) <= min){
            min = Info(P);
        }
        P = Next(P);
    }
    return min;
}
addressList AdrMin (List L){
/* Mengirimkan addressList P, dengan info(P) yang bernilai minimum */
	addressList P;
	boolean found;
	
	P = First(L);
	found = false;
	while ((P != Nil) && (!found)){
		if (Info(P) == Min(L)){
			found = true;
		}else{
			P = Next(P);
		}
	}
	return P;
}
float Average (List L){
/* Mengirimkan nilai rata-rata info(P) */
	float avg; 
	float sum = 0, count = 0;
	addressList P;
	
	P = First(L);
	while (P != Nil){
		sum += Info(P);
		count++;
		P = Next(P);
	}
	avg = sum/count;
	return (avg);
}
/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L){
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
   addressList PrevP, CurrP, NextP;

    CurrP = First(*L);
    PrevP = Nil;
    NextP = Nil;

    while(CurrP != Nil){
        NextP = Next(CurrP);
        Next(CurrP) = PrevP;
        PrevP = CurrP;
        CurrP = NextP;
    }
    First(*L) = PrevP;
}
void Konkat1 (List *L1, List *L2, List *L3){
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
addressList P;
    P = First(*L1);
    CreateEmptyList(L3);
    First(*L3) = First(*L1);
    if (P != Nil) {
        while (Next(P) != Nil) {
            P = Next(P);
        }
        Next(P) = First(*L2);
    }else{
        First(*L3) = First(*L2);
    }
    CreateEmptyList(L1);
    CreateEmptyList(L2);
}
