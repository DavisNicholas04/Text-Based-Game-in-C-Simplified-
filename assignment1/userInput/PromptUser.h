#include <stdlib.h>
#include "stdio.h"
#include "string.h"
#include "Room.h"
#include "StringPrompts.h"
#include "Creature.h"

int * numOfRooms;
int * numOfCreatures;
struct Room * room;
int respect;

int userInsertsNumOfRooms(){
    PromptUserForNumOfRooms();
	int numOfRoomsInput;
	scanf("%d", &numOfRoomsInput);
    numOfRooms = malloc(numOfRoomsInput);
    *numOfRooms = numOfRoomsInput;
	return numOfRoomsInput;
}

void iterateAndDetailRooms(struct Room * currentRoom){
    int numOfRoomDetails = 5;
    for (int i = 0; i < numOfRoomDetails; i++)
        scanf("%d", &currentRoom->roomDetails[i]);
}

struct Room * userInsertsDetailsOfRooms() {
    struct Room *room = malloc(*numOfRooms * sizeof(struct Room));
    for (int j = 0; j < *numOfRooms; j++) {
        PromptUserForRoomDetails(j);
        iterateAndDetailRooms(&room[j]);
    }
    return room;
}


int userInsertsNumOfCreatures(){
    PromptUserForNumOfCreatures();
    int numOfCreaturesInput;
    scanf("%d", &numOfCreaturesInput);
    numOfCreatures = malloc(numOfCreaturesInput);
    *numOfCreatures = numOfCreaturesInput;
    return numOfCreaturesInput;
}

void iterateAndDetailCreatures(struct Creature * currentCreature){
    int numOfCreatureDetails = 2;
    for (int i = 0; i < numOfCreatureDetails; i++)
        scanf("%d", &currentCreature->creatureDetails[i]);
}

 struct Creature * userInsertsDetailsOfCreatures() {
    struct Creature *creature = malloc(*numOfCreatures * sizeof(struct Creature));
    for (int j = 0; j < *numOfCreatures; j++) {
        PromptUserForCreatureDetails(j);
        iterateAndDetailCreatures(&creature[j]);
    }
    return creature;
}


