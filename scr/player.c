#include "rogue.h"


Player * player_maker(){

    Player *initPlayer;
    initPlayer= malloc(sizeof(Player)); //Dynamically allocated the size in memory necessary for the newPlayer pointer based on the size of Player,
    initPlayer-> coordinates =malloc(sizeof(Coordinates));
    // as I don't know beforehand how big it's going to be (+ I'll constantly add changes to the Player struct itself).
    initPlayer-> coordinates->x =14; //Acessing the coordinates in the Player struct and changing their values
    initPlayer-> coordinates->y =6;
    initPlayer->HP= 5;
    initPlayer->attack=1;
    initPlayer->gold=0;
    initPlayer->maxHP=20;
    initPlayer->XP=0;

    mvprintw(initPlayer-> coordinates->y, initPlayer-> coordinates->x, "@");
    move(initPlayer-> coordinates->y, initPlayer-> coordinates->x);
    
    return initPlayer;
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
            return 0;

    }

    return newCors;
}

int player_move(Coordinates *newCords, Player* user, char **level ){

    char buffer[8];
    

    sprintf(buffer, "%c", level[user->coordinates->y][user->coordinates->x]);

    mvprintw(user->coordinates->y, user->coordinates->x, buffer);

    user->coordinates->y =newCords->y;
    user->coordinates->x =newCords->x;

    mvprintw(user->coordinates->y, user->coordinates->x, "@"); //Printing the Player 'avatar' on the screen
    move(user->coordinates->y, user->coordinates->x);          //moves the cursor back to the place of the avatar, since by default mvprintw moves it a space foward.

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
            move(user->coordinates->y,user->coordinates->x);
            break;

    }



}