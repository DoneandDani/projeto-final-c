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

        mvprintw(25, 0, "    Level:%d", level->level);
        printw("    Gold: %d",level->user->gold);
        printw("    HP: %d(%d)",level->user->HP,level->user->maxHP);
        printw("    Attack: %d", level->user->attack);
        printw("    Exp: %d", level->user->XP);
        printw("       ");
        return 1;
    }