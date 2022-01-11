///you need to remember number of creatures in rooms. CREATE A COUNT
#include <time.h>
#include "stdbool.h"
void changeRoomRandom(int creatureIndexVal, struct Creature * creatures);

int creaturesRoom(struct Creature creature){
    return creature.creatureDetails[1];
}

int wheresPC(struct Creature * creatures){
    for (int i = 0; i < *numOfCreatures; i++){
        if (creatures[i].creatureDetails[0] == 0)
            return creatures[i].creatureDetails[1];
    }
}

char* checkCreatureType(struct Creature creature){
    if (creature.creatureDetails[0] == 0){
        return "pc";
    }
    else if (creature.creatureDetails[0] == 1){
        return "animal";
    }
    else {
        return "npc";
    }
}

int roomStateIntVal(struct Room currentRoom){
    return currentRoom.roomDetails[0];
}

bool creaturePreference(struct Creature currentCreature, struct Room currentRoom){
    if (!strcmp("pc", checkCreatureType(currentCreature)))
    {
        return false;
    }
    if (!strcmp("animal", checkCreatureType(currentCreature))){
        return 0 == roomStateIntVal(currentRoom);
    }
    else if (!strcmp("npc", checkCreatureType(currentCreature))){
        return 2 == roomStateIntVal(currentRoom);
    }
    else {
        printf("you had an error in your Creature Preferences function.\n");
        exit(-22);
    }
}

bool creatureRepulsion(struct Creature currentCreature, struct Room currentRoom){
    if (!strcmp("pc", checkCreatureType(currentCreature)))
    {
        return false;
    }
    if (!strcmp("animal", checkCreatureType(currentCreature))){
        return 2 == roomStateIntVal(currentRoom);
    }
    else if (!strcmp("npc", checkCreatureType(currentCreature))){
        return 0 == roomStateIntVal(currentRoom);
    }
    else {
        printf("you had an error in your Creature Repulsion function.\n");
        exit(-22);
    }
}

bool isPC(struct Creature currentCreature){
    if (currentCreature.creatureDetails[0] == 0){
        return true;
    }
    else {
        return false;
    }
}

bool ifAnimal(struct Creature currentCreature){
    return !strcmp("animal", checkCreatureType(currentCreature));
}

bool ifNPC(struct Creature currentCreature){
    return !strcmp("npc", checkCreatureType(currentCreature));
}

bool roomIsAtCap(int neighborNum, int creatureIndexVal, struct Creature * creatures){
    int numOfCreaturesInRoom = 0;
    int triedRoom = room[creatures[creatureIndexVal].creatureDetails[1]].roomDetails[neighborNum];
    for (int i = 0; i < *numOfCreatures; i++){
        if (triedRoom == creatures[i].creatureDetails[1]){
            numOfCreaturesInRoom++;
        }
        if (numOfCreaturesInRoom >= 10){
            printf("Room %d is full. %d will have to try another room\n", triedRoom, creatureIndexVal);
            return true;
        }
    }
    return false;
}

void creatureLeavesHouse(struct Creature * creature, int creatureIndexNum){
    creature[creatureIndexNum].creatureDetails[1] = -1;
    printf("%d is done with your crap and left the house.\n", creatureIndexNum);
}

void incrementRespect(){
    respect++;
}

void decrementRespect(){
    respect--;
}

void badResponse(int creatureIndexVal, struct Room currentRoom, struct Creature * creatures){

    if (ifAnimal(creatures[creatureIndexVal])){
        printf("animal %d growls at you\n", creatureIndexVal);
    }
    else if (ifNPC(creatures[creatureIndexVal])){
        printf("npc %d grumbles at you\n", creatureIndexVal);
    }
    if (creatureRepulsion(creatures[creatureIndexVal], currentRoom)){
        changeRoomRandom(creatureIndexVal, creatures);
    }
    decrementRespect();
}

void goodResponse(struct Creature currentCreature, int creatureIndexVal){
    if (!strcmp("animal", checkCreatureType(currentCreature))){
        printf("animal %d licks your face\n", creatureIndexVal);
    }
    else if (!strcmp("npc", checkCreatureType(currentCreature))){
        printf("npc %d smiles at you\n", creatureIndexVal);
    }
    incrementRespect();
}

void creatureReacts(struct Room currentRoom, struct Creature * creature, int currentRoomNum, int creatureIndexVal){
    bool isCreaturePreference = creaturePreference(creature[creatureIndexVal], currentRoom);
    bool isCreatureRepulsion = creatureRepulsion(creature[creatureIndexVal], currentRoom);
    bool creatureIsNotPC = !isPC(creature[creatureIndexVal]);
    bool creatureIsInCurrentRoom = creature[creatureIndexVal].creatureDetails[1] == currentRoomNum;
    //end set up//
    if (!isCreaturePreference & creatureIsNotPC & creatureIsInCurrentRoom) {
        badResponse(creatureIndexVal, currentRoom, creature);
    }
    else if (isCreaturePreference & creatureIsNotPC & creatureIsInCurrentRoom) {
        goodResponse(creature[creatureIndexVal], creatureIndexVal);
    }
}

void roomReact(struct Room currentRoom, struct Creature * creature, int currentRoomNum){
    for (int i = 0; i < *numOfCreatures; i++){
        creatureReacts(currentRoom, creature, currentRoomNum, i);
    }
    printf("Your respect value is currently %d\n", respect);
}

void cleanRoom(struct Creature * creatures, int creatureIndexVal){

    if (creatures[creatureIndexVal].creatureDetails[1] == -1){
        printf("that creature is in the McDonalds drive through not in this house\n");
        return;
    }
    if (creatures[creatureIndexVal].creatureDetails[1] != wheresPC(creatures)){
        printf("%d can't clean a room they're not in", creatureIndexVal);
    }

    if (room[wheresPC(creatures)].roomDetails[0] != 0)
        room[wheresPC(creatures)].roomDetails[0]--;
    else if (room[wheresPC(creatures)].roomDetails[0] == 0) {
        printf("This room is already clean, you can't clean it more clean freak\n");
        return;
    }
    else {
        printf("you messed up in the cleanRoom function\n");
        return;
    }

    if (creatures[creatureIndexVal].creatureDetails[0] == 0){ //pc
        printf("You just cleaned the room\n");
        roomReact(room[wheresPC(creatures)], creatures, wheresPC(creatures));
    }
    else {
        printf("You made %d clean the room\n", creatureIndexVal);
        for (int i = 0; i < 2; i++)
            creatureReacts(room[wheresPC(creatures)], creatures, wheresPC(creatures), creatureIndexVal);
        roomReact(room[wheresPC(creatures)], creatures, wheresPC(creatures));
    }
}

void dirtyRoom(struct Creature * creatures, int creatureIndexVal){

    if (creatures[creatureIndexVal].creatureDetails[1] == -1){
        printf("that creature is in the McDonalds drive through not in this house\n");
        return;
    }

    if (creatures[creatureIndexVal].creatureDetails[1] != wheresPC(creatures)){
        printf("%d can't dirty a room they're not in", creatureIndexVal);
    }

    if (room[wheresPC(creatures)].roomDetails[0] != 2)
        room[wheresPC(creatures)].roomDetails[0]++;
    else if (room[wheresPC(creatures)].roomDetails[0] == 2) {
        printf("This room is already dirty, you can't dirty it more you pig\n");
        return;
    }
    else {
        printf("you messed up in the dirtyRoom function\n");
        return;
    }

    if (creatures[creatureIndexVal].creatureDetails[0] == 0){ //pc
        printf("You just dirtied the room\n");
        roomReact(room[wheresPC(creatures)], creatures, wheresPC(creatures));
    }
    else {
        printf("You made %d dirty the room\n", creatureIndexVal);
        for (int i = 0; i < 2; i++)
            creatureReacts(room[wheresPC(creatures)], creatures, wheresPC(creatures), creatureIndexVal);
        roomReact(room[wheresPC(creatures)], creatures, wheresPC(creatures));
    }
}

void changeToHalfDirty(struct Creature * creatures, int creatureIndexValue){
    struct Room currentRoom = room[creaturesRoom(creatures[creatureIndexValue])];
    if (currentRoom.roomDetails[0] == 0){
        dirtyRoom(creatures, creatureIndexValue);
    }
    else if(currentRoom.roomDetails[0] == 2){
        cleanRoom(creatures,creatureIndexValue);
    }
}

void changeRoom(char direction, int creatureIndexVal, struct Creature * creatures){
    //finds the appropriate number to insert into the roomDetails so that the corresponding room direction can be assigned
    char dir[] = {'n', 's', 'e', 'w'};
    int i = 0;
    for (int x = 0; x < 4; x++){
        if (direction == dir[x])
            i = x + 1;
    }
    if (roomIsAtCap(i, creatureIndexVal, creatures)){
        return;
    }
    creatures[creatureIndexVal].creatureDetails[1] = room[creatures[creatureIndexVal].creatureDetails[1]].roomDetails[i];
    printf("creature %d went to room %d\n", creatureIndexVal, creatures[creatureIndexVal].creatureDetails[1]);
    if (creatureRepulsion(creatures[creatureIndexVal], room[creatures[creatureIndexVal].creatureDetails[1]])){
        changeToHalfDirty(creatures, creatureIndexVal);
    }
}

void changeRoomRequest(char direction, int creatureIndexVal, struct Creature * creatures){

    if (creatures[creatureIndexVal].creatureDetails[1] != wheresPC(creatures)){
        printf("you can't change the room of an animal in a different room.");
    }

    if (creatures[creatureIndexVal].creatureDetails[1] == -1){
        printf("that creature is in the McDonalds drive through not in this house\n");
        return;
    }

    switch(direction){
        case 'n':
            if (room[creatures[creatureIndexVal].creatureDetails[1]].roomDetails[1] == -1) {
                printf("there is no door in that direction\n");
                break;
            }
            changeRoom(direction, creatureIndexVal, creatures);
            break;
        case 's':
            if (room[creatures[creatureIndexVal].creatureDetails[1]].roomDetails[2] == -1) {
                printf("there is no door in that direction\n");
                break;
            }
            changeRoom(direction, creatureIndexVal, creatures);
            break;
        case 'e':
            if (room[creatures[creatureIndexVal].creatureDetails[1]].roomDetails[3] == -1) {
                printf("there is no door in that direction\n");
                break;
            }
            changeRoom(direction, creatureIndexVal, creatures);
            break;
        case 'w':
            if (room[creatures[creatureIndexVal].creatureDetails[1]].roomDetails[4] == -1) {
                printf("there is no door in that direction\n");
                break;
            }
            changeRoom(direction, creatureIndexVal, creatures);
            break;
        default: printf("that is not a valid direction command\n");
    }
}

char roomDirection(int roomDirectionIndex){
    switch (roomDirectionIndex){
        case 1:
            return 'n';
        case 2:
            return 's';
        case 3:
            return 'e';
        case 4:
            return 'w';
        default:
            printf("error in roomDirection function");
    }
}

void changeRoomRandom(int creatureIndexVal, struct Creature * creatures){
    int roomTried[3] = {-1, -1, -1};
    int toRoom;
    for(int i = 0; true; i++) {
        //toRoom = (rand() % 5);
        toRoom = (rand() % 4) + 1;
        if (toRoom == roomTried[0] || toRoom == roomTried[1] || toRoom == roomTried[2]) {
            i--;
            continue;
        }
        else if (roomIsAtCap(toRoom, creatureIndexVal, creatures) || room[wheresPC(creatures)].roomDetails[toRoom] == -1) {
            if (i == 3){
                creatureLeavesHouse(creatures, creatureIndexVal);
                break;
            }
            roomTried[i] = toRoom;
            continue;
        } else {
//            int choosesFromNeighborRooms = room[currentCreature.creatureDetails[1]].roomDetails[toRoom];
//            currentCreature.creatureDetails[1] = choosesFromNeighborRooms;
            changeRoomRequest(roomDirection(toRoom), creatureIndexVal, creatures);
            //printf("creature %d went to room %d", creatureIndexVal, toRoom);
//            if (room[choosesFromNeighborRooms].roomDetails[0] != creaturePreference(creatures[creatureIndexVal])){
//                changeToHalfDirty(room[choosesFromNeighborRooms].roomDetails[0], creatures, currentCreature);
//            }
            break;
        }
    }
}

int indexOfPC (struct Creature * creatures){
    for (int i = 0; i < *numOfCreatures; i++){
        if (creatures[i].creatureDetails[0] == 0)
            return i;
    }
}

char* roomStateStringVal(struct Room currentRoom){
    switch (roomStateIntVal(currentRoom)) {
        case 0:
            return "clean";
        case 1:
            return "half-dirty";
        case 2:
            return "dirty";
        default:
            return "Ya done messed up in the roomStateStringVal";
    }
}

void printNeighbors(struct Creature * creatures){
    if (room[wheresPC(creatures)].roomDetails[1] != -1)
        printf("%d to the north ", room[wheresPC(creatures)].roomDetails[1]);
    if (room[wheresPC(creatures)].roomDetails[2] != -1)
        printf("%d to the south ", room[wheresPC(creatures)].roomDetails[2]);
    if (room[wheresPC(creatures)].roomDetails[3] != -1)
        printf("%d to the east ", room[wheresPC(creatures)].roomDetails[3]);
    if (room[wheresPC(creatures)].roomDetails[4] != -1)
        printf("%d to the west ", room[wheresPC(creatures)].roomDetails[4]);
    printf("\n");
}

void look(struct Creature * creatures, int creatureIndexVal){
    if (creatures[creatureIndexVal].creatureDetails[1] == -1){
        printf("that creature is in the McDonalds drive through not in this house\n");
        return;
    }

    if (wheresPC(creatures) == creatures[creatureIndexVal].creatureDetails[1]) {

        char * state = roomStateStringVal(room[wheresPC(creatures)]);
        printf("Room %d, %s, neighbors: ", wheresPC(creatures), state);
        printNeighbors(creatures);

        for (int i = 0; i < *numOfCreatures; i++) {
            if (wheresPC(creatures) == creatures[i].creatureDetails[1] && i != creatureIndexVal) {
                if (isPC(creatures[i])){
                    printf("%s, ", checkCreatureType(creatures[creatureIndexVal]));
                } else {
                    printf("%s %d, ", checkCreatureType(creatures[i]), i);
                }
            }
        }
    }
    else {
        printf("%d is not in this room", creatureIndexVal);
    }
    printf("\n");
}

void gameOverCheck(){
    if (respect <= 0){
        YouLose();
        exit(0);
}  else if (respect > 80) {
        YouWin();
        exit(0);
    }
}



void play(struct Creature * creature){
    //seeding srand for changeRoomRandom();
    helpMsg();
    bool gameContinue = true;
    char * command;
    char input[8] = {0};
    char* firstWord;
    char* secondWord;
    int creatureIndexVal = -1;
    bool twoWordCommand = false;

    while (gameContinue){
        input[0] = '\0';
        input[1] = '\0';
        input[2] = '\0';
        input[3] = '\0';
        input[4] = '\0';
        input[5] = '\0';
        input[6] = '\0';
        input[7] = '\0';
        scanf("%s", input);
        firstWord = strtok(input, ":");
        secondWord = strtok(NULL, ":");
        twoWordCommand = false;
        command = firstWord;
        if (secondWord != NULL){
            twoWordCommand = true;
            command = secondWord;
            sscanf(firstWord, "%d", &creatureIndexVal);
        }
        if (!strcmp(command, "exit") && !twoWordCommand){
            gameContinue = false;
        }
        else if (!strcmp(command, "look")){
            if (!twoWordCommand)
                look(creature, indexOfPC(creature));
            else
                look(creature, creatureIndexVal);
        }
        else if (!strcmp(command, "clean")){
            if (!twoWordCommand)
                cleanRoom(creature, indexOfPC(creature));
            else
                cleanRoom(creature, creatureIndexVal);;
        }
        else if (!strcmp(command, "dirty")){
            if (!twoWordCommand)
                dirtyRoom(creature, indexOfPC(creature));
            else
                dirtyRoom(creature, creatureIndexVal);
        }
        else if (!strcmp(command, "north")){
            if (!twoWordCommand)
                changeRoomRequest('n', indexOfPC(creature), creature);
            else
                changeRoomRequest('n', creatureIndexVal, creature);
        }
        else if (!strcmp(command, "south")){
            if (!twoWordCommand)
                changeRoomRequest('s', indexOfPC(creature), creature);
            else
                changeRoomRequest('s', creatureIndexVal, creature);
        }
        else if (!strcmp(command, "east")){
            if (!twoWordCommand)
                changeRoomRequest('e', indexOfPC(creature), creature);
            else
                changeRoomRequest('e', creatureIndexVal, creature);
        }
        else if (!strcmp(command, "west")){
            if (!twoWordCommand)
                changeRoomRequest('w', indexOfPC(creature), creature);
            else
                changeRoomRequest('w', creatureIndexVal, creature);
        }
        else if (!strcmp(command, "help") && !twoWordCommand){
            helpMsg();
        }
        gameOverCheck();
    }
    printf("Thanks for playing\n");
}