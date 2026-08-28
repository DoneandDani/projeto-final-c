#include "rogue.h"

Room * create_room(int grid){
    
    Room * newRoom;
    newRoom = malloc(sizeof(Room));

    switch (grid)
    {
    case 0:
        newRoom->coordinates.y=0;
        newRoom->coordinates.x=0;
        break;
    case 1:
        newRoom->coordinates.y=0;
        newRoom->coordinates.x=33;
        break;
    case 2:
        newRoom->coordinates.y=0;
        newRoom->coordinates.x=66;
        break;
    case 3:
        newRoom->coordinates.y=14;
        newRoom->coordinates.x=0;
        break;
    case 4:
        newRoom->coordinates.y=14;
        newRoom->coordinates.x=33;
        break;
    case 5:
        newRoom->coordinates.y=14;
        newRoom->coordinates.x=66;
        break;
    
    default:
        break;
    }

    newRoom->height =rand()% 7 +4;
    newRoom->width =rand()% 18 +4;

    newRoom->coordinates.y+=rand() % (9 - newRoom->height +1);
    newRoom->coordinates.x+= rand() % (29 - newRoom->width +1);


    newRoom->doors =malloc(sizeof(Coordinates)* 4);

    // Generating doors on the walls of rooms. Each value in the array door corresponds to one side of the room.
    //Top door
    newRoom->doors[0] = malloc(sizeof(Coordinates));
    newRoom-> doors[0]->x = rand() % (newRoom->width -2) + newRoom ->coordinates.x+ 1;
    newRoom-> doors[0]->y = newRoom ->coordinates.y;

    //Left door
    newRoom->doors[1] = malloc(sizeof(Coordinates));
    newRoom-> doors[1]->x = newRoom ->coordinates.x;
    newRoom-> doors[1]->y = rand() % (newRoom->height -2) + newRoom ->coordinates.y +1;

    //Right door
    newRoom->doors[2] = malloc(sizeof(Coordinates));
    newRoom-> doors[2]->x = newRoom ->coordinates.x + newRoom->width -1;
    newRoom-> doors[2]->y = rand() % (newRoom->height -2) + newRoom ->coordinates.y +1;

    //Bottom door
    newRoom->doors[3] = malloc(sizeof(Coordinates));
    newRoom-> doors[3]->x = rand() % (newRoom->width -2) + newRoom ->coordinates.x +1 ;
    newRoom-> doors[3]->y = newRoom ->coordinates.y + newRoom-> height -1;


    return newRoom;

}


int draw_room(Room *room){

    
    
    for ( int y = room ->coordinates.y +1; y < room-> coordinates.y + room->height -1; y++ ){
        mvprintw(y, room ->coordinates.x, "|" );
        mvprintw(y,room ->coordinates.x + room -> width -1, "|");
        for ( int x = room ->coordinates.x +1; x < room-> coordinates.x + room->width -1; x++ ){
            mvprintw(y, x, ".");
        }


    }

    for ( int x = room ->coordinates.x; x < room-> coordinates.x + room->width; x++ ){
        mvprintw(room->coordinates.y, x, "-");
        mvprintw(room->coordinates.y+ room-> height-1, x, "-");

    }

    mvprintw(room->doors[0]->y,room->doors[0]->x, "+");
    mvprintw(room->doors[1]->y,room->doors[1]->x, "+");
    mvprintw(room->doors[2]->y,room->doors[2]->x, "+");
    mvprintw(room->doors[3]->y,room->doors[3]->x, "+");


    return 1;

}

int connect_doors(Coordinates *door1 , Coordinates *door2){

    Coordinates cord_temp;
    Coordinates cord_previous;

    cord_temp.x = door1->x;
    cord_temp.y = door1->y;

    cord_previous =cord_temp;

    int counter =0;

    while (1){ //Algorithm that makes the tunnels between doors. The if else statments simulate a step in one direction and see if the distance
        // between the that new distance and the original one is smaller, if so, they make that simulated step occurs and update the coordinates.

        if ((abs((cord_temp.x-1) - door2->x) < abs(cord_temp.x - door2->x)) && (mvinch(cord_temp.y, cord_temp.x-1)== ' ')){
            cord_previous.x=cord_temp.x;
            cord_temp.x =cord_temp.x-1;


        } else if ((abs((cord_temp.x+1) - door2->x) < abs(cord_temp.x - door2->x)) && (mvinch(cord_temp.y, cord_temp.x+1)== ' ')){
            cord_previous.x=cord_temp.x;
            cord_temp.x =cord_temp.x +1;


        } else if ((abs((cord_temp.y+1) - door2->y) < abs(cord_temp.y - door2->y)) && (mvinch(cord_temp.y+1, cord_temp.x)== ' ')){
            cord_previous.y=cord_temp.y;
            cord_temp.y =cord_temp.y +1;
        
        } else if ((abs((cord_temp.y-1) - door2->y) < abs(cord_temp.y - door2->y)) && (mvinch(cord_temp.y-1, cord_temp.x)== ' ')){
            cord_previous.y=cord_temp.y;
            cord_temp.y =cord_temp.y -1;
        } else {
            if (counter ==0){
                cord_temp = cord_previous;
                counter++;
                continue;
            } else{
                return 0;

            }

        }
         mvprintw(cord_temp.y,cord_temp.x, "#");
        
    }
    return 1;
}


