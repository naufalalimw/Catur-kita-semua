#include "boolean.h"
#include "ScoreBoard.h"
#include <stdio.h>

typedef struct {
  char name[3];
  int score;
}Player;

int main() {
  Player p;

  showScoreboard(&p);
  addToScoreboard();

  return 0;
}