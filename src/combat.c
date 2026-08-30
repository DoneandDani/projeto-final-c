#include "rogue.h"

int combat(Player *player, Monster *monster, int initiative){

    if (initiative== 1){

        if (attack_roll(monster->AC) ==1){

            monster->health -=player->attack;

            if (monster->health <= 0){
            
                kill_monster(monster);
                player->XP+=monster->monsterXP;
                player_level_up(player);
            }
            
        }
    }
        
    else{
        
        if (attack_roll(player->AC) ==1){
            
            player->HP -=monster->attack;
            
        }

    }

    
    return 1;

}

int attack_roll(int AC){

    int roll;

    roll = (rand() % 20) +1;

    if (roll >=AC){

        return 1;

    }

    return 0;
}