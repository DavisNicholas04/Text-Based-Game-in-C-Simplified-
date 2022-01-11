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

void YouLose(){
    printf("%s\n", "You lose.\nThanks for playing");
}

void YouWin(){
    printf("%s\n", "You win!\nThanks for playings");
}

void helpMsg(){
    printf("This is room game.\nCommands: look, clean, dirty, north, south, east, west.\nin addition you can "
           "also make creatures carry out commands by typing in a creatures identifier(represented by a number) followed by a "
           "colon and then the command you wish for the creature to carry out(NO SPACES).\n"
           "to see this message again, type help.\ntype exit to leave the game.\n");
}