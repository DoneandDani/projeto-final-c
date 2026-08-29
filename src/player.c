#include "rogue.h"


Player * player_maker(){

    Player *initPlayer;
    initPlayer= malloc(sizeof(Player)); //Dynamically allocated the size in memory necessary for the newPlayer pointer based on the size of Player,
    initPlayer-> coordinates =malloc(sizeof(Coordinates));
    // as I don't know beforehand how big it's going to be (+ I'll constantly add changes to the Player struct itself).
    initPlayer->HP= 5;
    initPlayer->attack=1;
    initPlayer->gold=0;
    initPlayer->maxHP=20;
    initPlayer->XP=0;

    
    
    return initPlayer;
}

int place_player(Player *user, Room **rooms){ //I'll hardcode the player to be generated in room 3 (bottom left),
                                          // later I might do it so that starting location is also random

    user->coordinates->y = rooms[3]->coordinates.y +1;
    user->coordinates->x = rooms[3]->coordinates.x +1;

}



Coordinates * handle_input(int input, Player * user){
    
    Coordinates *newCors;
    newCors = malloc(sizeof(Coordinates));

    switch (input)
    {
        case KEY_UP:
            newCors->y = user->coordinates->y -1;
            newCors->x = user->coordinates->x;
            
            break;

        case KEY_DOWN:
            newCors->y = user->coordinates->y +1;
            newCors->x = user->coordinates->x;
            
            break;
        
        case KEY_LEFT:
            newCors->y = user->coordinates->y ;
            newCors->x = user->coordinates->x -1;
            
            break;
        
        case KEY_RIGHT:
            newCors->y = user->coordinates->y;
            newCors->x = user->coordinates->x +1;
            
            break;

        default:
            return NULL;

    }

    return newCors;
}

int player_move(Coordinates *newCords, Player* user, char **level ){

    user->coordinates->y =newCords->y;
    user->coordinates->x =newCords->x;
}

// Check what is at next position. Will get updated later but for now just makes sure the Avatar can't move through walls.
int check_move(Coordinates *newCords, Level *level){

    Player * user;
    user= level->user;

    int tempP;
    switch (mvinch(newCords->y,newCords->x)) //Function from Ncurses that checks what character the cursor is on
    {
        case '.':
            player_move(newCords, user, level->tiles);
            break;
        case '#':
            player_move(newCords, user, level->tiles);
            break;
        case '+':
            player_move(newCords, user, level->tiles);
            break;
        case 'r':
            combat(user, get_monster(newCords, level->monsters), 1);
            break;
        case 'g':
            combat(user, get_monster(newCords, level->monsters), 1);
            break;
        case 'w':
            combat(user, get_monster(newCords, level->monsters), 1);
            break;
        case 't':
            combat(user, get_monster(newCords, level->monsters), 1);
            break;
        default:
    
            break;

    }

}

void draw_player(Player *player ){

    mvprintw(player->coordinates->y,player->coordinates->x, "@" );
    move(player->coordinates->y,player->coordinates->x);


}