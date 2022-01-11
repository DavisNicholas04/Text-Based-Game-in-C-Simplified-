#include "userInput/InputData.h"
#include "gameFuctions/PlayGame.h"
int main() {
    //struct timespec seed;
    srand(time(0));

//    for(int i = 0; i < 10; i++)
//    printf("%d\n", (rand() % 4) + 1);
    struct Creature *creature;
    struct Creature *PC;
    int startingValue = 40;
    respect = startingValue;

    room = userInputRoom();
    creature = userInputCreature();
    play(creature);
    free(room);
    free(creature);
    free(numOfRooms);
}