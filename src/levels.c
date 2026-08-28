
#include "rogue.h"

Level * create_level(int level){
    
    Level * newLevel;
    newLevel = malloc(sizeof(Level));

    newLevel-> level = level;
    newLevel-> numberOfRooms =3;
    newLevel-> rooms= room_maker();
    newLevel->tiles = save_level_coordinates();
    add_monsters(newLevel);

    newLevel->user=player_maker();

    return newLevel;

}



Room ** room_maker(){

    int n;
    Room ** rooms;
    rooms = malloc(sizeof(Room)*6);
    
    for (n = 0; n < 6; n++)
    {
         rooms[n] = create_room( n);
        draw_room(rooms[n]);
    }
    
   

    connect_doors(rooms[0]->doors[3] , rooms[2]-> doors[1]);
    connect_doors(rooms[0]->doors[1] , rooms[2]-> doors[3]);


    return rooms;


}

char ** save_level_coordinates(){

    int x,y;
    char ** map_cords;
    map_cords = malloc(sizeof(char *) * 25);

    for (y=0;y<25;y++){

        map_cords[y] = malloc(sizeof(char) *100);
        for (x=0;  x< 100; x++){

            map_cords[y][x] = mvinch(y,x);
        }
    }

    return map_cords;

}


