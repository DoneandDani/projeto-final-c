#include "rogue.h"

int main(){
    
    printf("STARTING\n");
    fflush(stdout);


    int userInput;
    Coordinates *newCords;
    
    Level * level;

    screen_setup();

    printf("AFTER SCREEN SETUP\n");
    fflush(stdout);
    
    level = create_level(1);
    print_game_interface(level);
    

    
    //Main game loop, ends when user pressess the esc key
    while ((userInput =getch()) != esc){
        print_game_interface(level);
        newCords= handle_input(userInput, level-> user);
        if (newCords==NULL){
            continue;
        }
        check_move(newCords, level);
        move_monster(level);
        move(level->user->coordinates->y,level->user->coordinates->x);

        free(newCords);
    }
    
    

    endwin();

    printf("EXITING\n");
    return 0;
    
}


