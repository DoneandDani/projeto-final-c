
#include "rogue.h"

Level * create_level(int level){
    
    Level * newLevel;
    newLevel = malloc(sizeof(Level));

    newLevel-> level = level;
    newLevel-> numberOfRooms =6;
    newLevel-> rooms= room_maker();
    connect_doors(newLevel);
    newLevel->tiles = save_level_coordinates();
    
    newLevel->user=player_maker();
    place_player(newLevel->user, newLevel-> rooms);

    add_monsters(newLevel);

    return newLevel;

}


Room ** room_maker(){

    int n;
    Room ** rooms;
    rooms = malloc(sizeof(Room)*6);
    
    for (n = 0; n < 6; n++)
    {
         rooms[n] = create_room( n, 4);
        draw_room(rooms[n]);
    }
    

    //connect_doors(rooms[0]->doors[3] , rooms[2]-> doors[1]);
    //pathfinding(rooms[0]->doors[3] , rooms[1]-> doors[1]);
    //connect_doors(rooms[0]->doors[1] , rooms[2]-> doors[3]);


    return rooms;


}


void connect_doors(Level * level){

    int randRoom,randDoor;
    int r,d;
    int count;

    for ( r = 0; r < level->numberOfRooms; r++){

        for ( d = 0; d < level->rooms[r]->nOfDoors; d++){

            if (level->rooms[r]->doors[d]->connected ==1){
                continue;
            }
            
            count =0;
            while (count < 10){

                randRoom = rand() % level->numberOfRooms;
                randDoor = rand() % level->rooms[randRoom]->nOfDoors;

                if (level->rooms[randRoom]->doors[randDoor]->connected ==1 || randRoom ==r ){
                    count++;
                    continue;
                }

                pathfinding(&level->rooms[randRoom]->doors[randDoor]->coordinates,&level->rooms[r]->doors[d]->coordinates);
                
                level->rooms[randRoom]->doors[randDoor]->connected =1;
                level->rooms[r]->doors[d]->connected =1;
                break;
        }
            
        }
        
        
    }
    

}


char ** save_level_coordinates(){

    int x,y;
    char ** map_cords;
    map_cords = malloc(sizeof(char *) * 25);

    for (y=0;y<max_height;y++){

        map_cords[y] = malloc(sizeof(char) *100);
        for (x=0;  x< max_width; x++){

            map_cords[y][x] = mvinch(y,x);
        }
    }

    return map_cords;

}


