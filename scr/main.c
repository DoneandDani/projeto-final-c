#include "rogue.h"

int main(){
    
    Player * user; //user is declared as a pointer to the struct Player
    int userInput;
    Coordinates *newCords;
    
    Level * level;

    screen_setup();
    level = create_level(1);

    
    user = player_maker();
    //Main game loop, ends when user pressess the esc key
    while ((userInput =getch()) != esc){
        newCords= handle_input(userInput, user);
        check_move(newCords, user, level->tiles);
    }
    
    refresh();
    

    endwin();
    return 0;
    
}


int screen_setup(){
    initscr();
    printw("Hello world!");
    raw();
    keypad(stdscr, TRUE);
    noecho();

    srand(time(NULL));

    return 1;
}

