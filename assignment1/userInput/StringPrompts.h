void PromptUserForRoomDetails(int roomNumber){
    char prompt[] = "Please enter details for room ";
    printf("%s %d\n", prompt, roomNumber);
}

void PromptUserForCreatureDetails(int creatureNumber){
    char prompt[] = "Please enter details for Creature ";
    printf("%s %d\n", prompt, creatureNumber);
}

void PromptUserForNumOfRooms(){
    printf("%s\n", "Please enter the Number of Rooms");
}

void PromptUserForNumOfCreatures(){
    printf("%s\n", "Please enter the Number of Creatures");
}