#include "PromptUser.h"
struct Room * roomDetails();
struct Creature * creatureDetails();

 struct Room * userInputRoom(){
     return roomDetails();
}
struct Creature * userInputCreature(){
    return creatureDetails();
}

 struct Room * roomDetails(){
    int numOfRooms = userInsertsNumOfRooms();
    struct Room * roomPointer = userInsertsDetailsOfRooms(numOfRooms);
    return roomPointer;
}

struct Creature * creatureDetails(){
    int numOfCreatures = userInsertsNumOfCreatures();
    struct Creature * creaturePointer = userInsertsDetailsOfCreatures(numOfCreatures);
    return creaturePointer;

}