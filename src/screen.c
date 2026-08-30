    #include "rogue.h"

    int screen_setup(){
        
        
        
        initscr();
        raw();
        keypad(stdscr, TRUE);
        noecho();

        srand(time(NULL));

        return 1;
    }

    int print_game_interface(Level * level){

        mvprintw(25, 0, "    Dungeon Level:%d", level->level);
        printw("    Character Level: %d", level->user->playerLevel );
        printw("    Gold: %d",level->user->gold);
        printw("    HP: %d(%d)",level->user->HP,level->user->maxHP);
        printw("    Attack: %d", level->user->attack);
        printw("    AC: %d", level->user->AC);
        printw("    Exp: %d", level->user->XP);
        printw("    Potions: %d(%d)", get_potion_count(level->user), level->user->inventoryCapacity);
        printw("    [P] Use Potion");
        return 1;
    }

    void game_over_screen( Game *game){

        Level *level;
        Player *player;
        int aliveMonsters;

        level = game->levels[game->currentLevel-1];
        player =level->user;

        aliveMonsters= count_alive_monsters(level->monsters,level->numberOfMonsters,0);

        clear();

        mvprintw(5,10, "YOU DIED");

        mvprintw(7,10, "Character Level: %d", player->playerLevel);
        mvprintw(8,10, "Dungeon Level: %d", level->level);
        mvprintw(9,10, "Remaining monsters: %d", aliveMonsters);
        mvprintw(10,10, "Gold Collected: %d", player->gold);


        mvprintw(11,10, "Press any key to return to the main menu.");

        refresh();
        getch();

    }