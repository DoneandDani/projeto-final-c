
#include "rogue.h"

void render_game(Game *game){

    clear();
    print_game_interface(game->levels[game->currentLevel-1]);
    draw_level(game->levels[game->currentLevel-1]);
    
}



int main_game_loop( Game *game){

    int userInput =KEY_UP;
    Coordinates *newCords;
    
    Level * level;

    if (game->currentLevel==0){
        game->levels[game->currentLevel] = create_level(1);
        game->currentLevel++;
    }

    level =game->levels[game->currentLevel-1]; 
    
    

    //Main game loop, ends when user pressess the esc key
    while (userInput  != esc){
    
        newCords= handle_input(userInput, level-> user);
        check_move(newCords, level);
        move_monster(level);
        
        render_game(game);
        if (level->user->HP <=0 ){
            game->currentLevel=0;
            return -1;
        }
        userInput=getch();
        

    }
}