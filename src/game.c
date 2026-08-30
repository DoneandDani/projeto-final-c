
#include "rogue.h"

void render_game(Game *game){

    int n,m;
    Level *level;

    level = game->levels[game->currentLevel-1];

    clear();
    print_game_interface(level);
    draw_level(level);

    for (n =0; n < level->numberOfItems; n++){

        draw_item(level->items[n]);

    }

    for (m =0; m < level->numberOfMonsters; m++){

        draw_monster(level->monsters[m]);
    }

    draw_player(level->user);

}



int main_game_loop( Game *game){

    int userInput =KEY_UP;
    int isStair;
    Coordinates *newCords;
    
    Level * level;

    if (game->currentLevel==0){
        game->levels[game->currentLevel] = create_level(1, NULL);
        game->currentLevel++;
    }

    level =game->levels[game->currentLevel-1]; 
    
    

    //Main game loop, ends when user pressess the esc key
    while (userInput  != esc){
        
        newCords = NULL;

        if (userInput == 'p' || userInput == 'P'){
            consume_potion(level->user);
        }
        else{
            newCords= handle_input(userInput, level-> user);

        }
        if (newCords !=NULL){
            isStair= check_move(newCords,level);
            free(newCords);
            if (isStair==2){
                
                

                if (game->currentLevel>=10){
                    //End
                }
                else{
                    
                    Player *player =level->user;
                    refresh();
                    int nextLevel =game->currentLevel +1;
                    
                    game->levels[nextLevel-1]= create_level(nextLevel, player);
                    

                    if (game->levels[game->currentLevel-1] ==NULL){

                        return -1;

                    }

                    game->currentLevel =nextLevel;
                    level = game->levels[nextLevel-1];
                    
                }
            }
        }

        move_monster(level);
        
        render_game(game);
        if (level->user->HP <=0 ){
            game_over_screen( game);
            game->currentLevel=0;
            return -1;
        }
        userInput=getch();
        

    }
    return 0;
}