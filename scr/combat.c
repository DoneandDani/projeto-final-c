#include "rogue.h"

int combat(Player *player, Monster *monster, int initiative){

    if (initiative== 1){

        monster->health -=player->attack;
        if (monster->health > 0){
            player->HP -=monster->attack;
            
        } else {

            kill_monster(monster);
            player->XP++;
        }
        
    }
    else{
        player->HP -=monster->attack;
        if (player->HP > 0){
            monster->health -=player->attack;
            
        }

    }
    return 1;

}