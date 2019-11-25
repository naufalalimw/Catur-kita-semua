#ifndef SCRBRD_H
#define SCRBRD_H

#include "boolean.h"
#include <stdio.h>
 
void addToScoreboard();
/* Menerima masukan character dan integer yang akan di cetak
kedalam file eksternal. file eksternal berupa .csv yang dapat di akses
di fungsi lain.*/

void showScoreboard();
/* Menampilkan character dan integer dari file eksternal 
berupa file.csv berurut sesuai urutan dalam file*/

#endif
