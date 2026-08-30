
#include "rogue.h"

Level * create_level(int level, Player *player){
    
    Level * newLevel;

    clear();
    refresh();

    
    newLevel = malloc(sizeof(Level));

    if (newLevel ==NULL){
        return NULL;
    } 

    newLevel-> level = level;
    newLevel-> numberOfRooms =6;

    newLevel-> rooms= room_maker();

    connect_doors(newLevel);
    place_stairs(newLevel);
    
    newLevel->tiles = save_level_coordinates();
    
    
    if (player == NULL){

        newLevel->user=player_maker();

        place_player(newLevel->user, newLevel-> rooms);

    }else{
        newLevel->user =player;
        place_player(newLevel->user, newLevel->rooms);
    }
  

    add_monsters(newLevel);

 
    add_items(newLevel);



    return newLevel;

}


Room ** room_maker(){

    int n;
    Room ** rooms;
    rooms = malloc(sizeof(*rooms)*6);
    
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
    map_cords = malloc(sizeof(char *) * max_height);

    for (y=0;y<max_height;y++){

        map_cords[y] = malloc(sizeof(char) *max_width);
        for (x=0;  x< max_width; x++){

            map_cords[y][x] = mvinch(y,x);
        }
    }

    return map_cords;

}

void draw_level(Level *level){

    int x,y,n;
    
    //Prints each tile of the map
    for (y=0;y<max_height;y++){

        
        for (x=0;  x< max_width; x++){

            mvaddch(y,x,level->tiles[y][x]);
        }
    }

    //then draw stairs

    mvaddch(level->staircords.y,level->staircords.x, '<');

    //then prints the monsters

    for (n =0; n<level->numberOfMonsters; n++){

        draw_monster(level->monsters[n]);
    }

    //then prints player

    draw_player(level->user);

    

}

int place_stairs(Level *level){

    int gridNumber;
    Room *room;

    do{
    
        gridNumber= rand() % level->numberOfRooms;

    } while( gridNumber ==3);

    room = level->rooms[gridNumber];

    level->staircords.y = room->coordinates.y +1 +rand() % (room->height-2);
    level->staircords.x = room->coordinates.x +1 +rand() % (room->width-2);




    return 1;


}