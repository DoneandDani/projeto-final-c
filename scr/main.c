#include "rogue.h"

int main(){
    
    
    int userInput;
    Coordinates *newCords;
    
    Level * level;

    screen_setup();
    level = create_level(1);
    print_game_interface(level);
    

    
    //Main game loop, ends when user pressess the esc key
    while ((userInput =getch()) != esc){
        print_game_interface(level);
        newCords= handle_input(userInput, level-> user);
        check_move(newCords, level);
        move_monster(level);
        move(level->user->coordinates->y,level->user->coordinates->x);
    }
    
    refresh();
    

    endwin();
    return 0;
    
}


