void play(struct Room * room, struct Creature * creature){
    printf("Rooms:\n");
    for (int j = 0; j < room; j++)
    for(int i = 0; i < 5; i++)
    printf("%i ", room[j].roomDetails[i]);

}


