#include "rogue.h"


Player * player_maker(){

    Player *initPlayer;
    initPlayer= malloc(sizeof(Player)); //Dynamically allocated the size in memory necessary for the newPlayer pointer based on the size of Player,
    initPlayer-> coordinates =malloc(sizeof(Coordinates));
    // as I don't know beforehand how big it's going to be (+ I'll constantly add changes to the Player struct itself).
    initPlayer->HP= 20;
    initPlayer->attack=1;
    initPlayer->gold=0;
    initPlayer->maxHP=20;
    initPlayer->XP=0;
    initPlayer->AC =12;
    initPlayer->playerLevel =1;
    
    initPlayer->inventoryCapacity= 10;
    initPlayer->inventorySize=0;

    initPlayer->inventory =malloc(sizeof(Item *) * initPlayer->inventoryCapacity);
    
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

    if (newCors== NULL){
        return NULL;
    }

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
            free(newCors);
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
    Monster *monster;

    user= level->user;

    int tempP;
    switch (mvinch(newCords->y,newCords->x) & A_CHARTEXT) //Function from Ncurses that checks what character the cursor is on
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
            monster =get_monster(newCords,level->monsters, level->numberOfMonsters);
            if (monster != NULL){
                combat(user,monster,1);
            }
            break;
        case 'g':
            monster =get_monster(newCords,level->monsters,level->numberOfMonsters);
            if (monster != NULL){
                combat(user,monster,1);
            }
            break;
        case 'w':
            monster =get_monster(newCords,level->monsters,level->numberOfMonsters);
            if (monster != NULL){
                combat(user,monster,1);
            }
            break;  
        case 't':
            monster =get_monster(newCords,level->monsters,level->numberOfMonsters);
            if (monster != NULL){
                combat(user,monster,1);
            }
            break;
        case '$':
            player_move(newCords,user,level->tiles);
            pickup_item(user,level);
            break;
        case '!':
            player_move(newCords,user,level->tiles);
            pickup_item(user,level);
            break;
        case '<':
            player_move(newCords,user,level->tiles);
            return 2;
        default:
            break;

    }
    return 0;

}

void draw_player(Player *player ){

    mvprintw(player->coordinates->y,player->coordinates->x, "@" );
    move(player->coordinates->y,player->coordinates->x);


}

int player_level_up(Player *player){

    int newPlayerLevel;

    newPlayerLevel = (player->XP /10) +1;

    while (player->playerLevel<newPlayerLevel){

        player->playerLevel++;
        player->maxHP +=5;
        player->attack +=2;
        player->AC +=2;
    }

    return 1;

}
