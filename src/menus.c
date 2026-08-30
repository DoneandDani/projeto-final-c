#include "rogue.h"






int main_menu(int nItems, char * choices[]){ //Here I'm taking advantage of ncurses libraries for menus.

    int n;
    MENU *menu;  
    ITEM ** items = malloc(sizeof(*items)*nItems);
    ITEM * currentItem;
    int indexValue; 

    for (n =0; n<nItems; n++){

        items[n] =new_item(choices[n], "");

    }
    items[n] =(ITEM*)NULL;

    menu = new_menu((ITEM**)items);
    post_menu(menu);
    refresh();

    while (true){

        int choice = getch();
        switch (choice)
        {
        case  KEY_DOWN:
            menu_driver(menu, REQ_DOWN_ITEM);
            break;
        case  KEY_UP:
            menu_driver(menu, REQ_UP_ITEM);
            break;
        case  10: //ENTER
            currentItem= current_item(menu);
            indexValue =item_index(currentItem);
            close_menu(nItems,menu,items );
            return indexValue;
            break;
        
        default:
            break;
        }
    }

}

void close_menu(int nItems, MENU *menu, ITEM ** items){

    int n;
    unpost_menu(menu);
    free_menu(menu);

    for ( n = 0; n < nItems; n++){

        free_item(items[n]);
    }
    
}

void menu_loop(){

    int choice;
    

    Game game;
    game.currentLevel=0;

    while (true)
    {
        if(game.currentLevel ==0){

            char *choices[]= {"Start Game", "Close Game"};

            choice = main_menu(2, choices);

            switch (choice)
            {
            case 0: // START GAME
                main_game_loop(&game);
                clear();
                break;
            case 1: // QUIT GAME
                return;
                break;
            
            default:
                break;
            }
        }else{

            char *choices[]= {"Continue", "Close Game"};

            choice = main_menu(2, choices);

            switch (choice)
            {
            case 0: // START GAME
                main_game_loop(&game);
                clear();
                break;
            case 1: // QUIT GAME
                return;
                break;
            
            default:
                break;
            }
        }

    }
    
}