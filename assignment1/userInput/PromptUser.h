#include <stdlib.h>
#include "stdio.h"
#include "string.h"
#include "Room.h"
#include "StringPrompts.h"
#include "Creature.h"

int userInsertsNumOfRooms();
struct Room * userInsertsDetailsOfRooms();
struct Creature * userInsertsDetailsOfCreatures();
void iterateAndDetailRooms();
void iterateAndDetailCreatures();

int userInsertsNumOfRooms(){
    PromptUserForNumOfRooms();
	int numOfRoomsInput;
	scanf("%d", &numOfRoomsInput);
	return numOfRoomsInput;
}
struct Room * userInsertsDetailsOfRooms(int numOfRooms) {
    struct Room *room = malloc(numOfRooms * sizeof(struct Creature));
    for (int j = 0; j < numOfRooms; j++) {
        PromptUserForRoomDetails(j);
        iterateAndDetailRooms(&room[j]);
    }
    return room;
}

int userInsertsNumOfCreatures(){
    PromptUserForNumOfCreatures();
    int numOfCreaturesInput;
    scanf("%d", &numOfCreaturesInput);
    return numOfCreaturesInput;
}

 struct Creature * userInsertsDetailsOfCreatures(int numOfCreatures) {

    struct Creature *creature = malloc(numOfCreatures * sizeof(struct Creature));
    for (int j = 0; j < numOfCreatures; j++) {
        PromptUserForCreatureDetails(j);
        iterateAndDetailCreatures(&creature[j]);
    }
    return creature;
}

void iterateAndDetailRooms(struct Room * currentRoom){
    int numOfRoomDetails = 5;
    for (int i = 0; i < numOfRoomDetails; i++)
        scanf("%d", &currentRoom->roomDetails[i]);
}

void iterateAndDetailCreatures(struct Creature * currentCreature){
    int numOfCreatureDetails = 2;
    for (int i = 0; i < numOfCreatureDetails; i++)
        scanf("%d", &currentCreature->creatureDetails[i]);
}
