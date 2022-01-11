#include "PromptUser.h"

struct Room * roomDetails(){
    userInsertsNumOfRooms();
    struct Room * roomPointer = userInsertsDetailsOfRooms();
    return roomPointer;
}

struct Creature * creatureDetails(){
    userInsertsNumOfCreatures();
    struct Creature * creaturePointer = userInsertsDetailsOfCreatures();
    return creaturePointer;
}

 struct Room * userInputRoom(){
     return roomDetails();
}

struct Creature * userInputCreature(){
    return creatureDetails();
}