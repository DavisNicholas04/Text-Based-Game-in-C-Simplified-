#include "userInput/InputData.h"
#include "gameFuctions/PlayGame.h"
int main() {

    struct Room *room;
    struct Creature *creature;
    int numOfRooms;

    room = userInputRoom();
    creature = userInputCreature();
    size
    play(room, creature);
    free(room);
    free(creature);
}