#include "rogue.h"

int max_width = 100;
int max_height = 25;





int main(){

    screen_setup();
    menu_loop();    
    refresh();
    endwin();
    return 0;
    
}


