#include "boolean.h"
#include <stdio.h>
#include <stdio.h>
 
typedef struct {
  char name[3];
  int score;
}Player;


void addToScoreboard();
/* Menerima masukan character dan integer yang akan di cetak
kedalam file eksternal. file eksternal berupa .csv yang dapat di akses
di fungsi lain.*/

void showScoreboard(Player *player);
/* Menampilkan character dan integer dari file eksternal 
berupa file.csv berurut sesuai urutan dalam file*/
