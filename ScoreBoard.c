#include "boolean.h"
#include "ScoreBoard.h"
#include <stdio.h>
 
typedef struct {
  char name[3];
  int score;
}Player;

void addToScoreboard()
{
    FILE *scoreboardfile = fopen("scoreboard.csv", "a");
    Player player;
    int index,i;
    
 
    printf("Name: ");
    scanf("%s", &player.name);
    printf("Score: ");
    scanf("%d", &player.score);

    fprintf(scoreboardfile, "%s %d", player.name, player.score);
    fclose(scoreboardfile);
 
}

void showScoreboard(Player *player)
{
    FILE *scoreboardfile = fopen("scoreboard.csv", "r");
    int i,j,temp;
    i = 1;
 
    
    while ((i<100) && (!feof(scoreboardfile)))
    {
        fscanf(scoreboardfile, "%s %d", &player->name, &player->score);
        printf("name: %s, score: %d\n", player->name, player->score);
        i++;
    }
    fclose(scoreboardfile);
}


