#include <stdio.h>
#include<ncurses.h>
#include<stdlib.h>

#define esc 27 //Macro for the esc key in ASCII

typedef struct Player
{
    int xcord;
    int ycord;
    int HP;
} Player ;



int screen_setup();
int map_maker();
Player * player_maker(); //Promising a function that return a pointere to the struct Player, I think.
int handle_input(int input, Player * user);
int player_move(int y, int  x, Player* user );
int check_move( int tempY, int tempX, Player* user);


int main(){
    
    Player * user; //user is declared as a pointer to the struct Player
    int userInput;

    screen_setup();
    map_maker();
    user = player_maker();
    //Main game loop, ends when user pressess the esc key
    while ((userInput =getch()) != esc){
        handle_input(userInput, user);
    }
    
    refresh();
    

    endwin();
    return 0;
    
}


int screen_setup(){
    initscr();
    printw("Hello world!");
    raw();
    keypad(stdscr, TRUE);
    noecho();

    return 1;
}

int map_maker(){

    mvprintw(13,13,"---------");
    mvprintw(14,13,"|.......|");
    mvprintw(15,13,"|.......|");
    mvprintw(16,13,"|.......|");
    mvprintw(17,13,"---------");

    return 0;


}

Player * player_maker(){

    Player *initPlayer;
    initPlayer= malloc(sizeof(Player)); //Dynamically allocated the size in memory necessary for the newPlayer pointer based on the size of Player,
                                       // as I don't know beforehand how big it's going to be (+ I'll constantly add changes to the Player struct itself).
    initPlayer-> xcord =14; //Acessing the coordinates in the Player struct and changing their values
    initPlayer-> ycord =14;
    initPlayer->HP= 5;

    player_move(14,14, initPlayer );
    
    return initPlayer;
}


int handle_input(int input, Player * user){
    int tempY;
    int tempX;

    switch (input)
    {
        case KEY_UP:
            tempY = user->ycord -1;
            tempX = user->xcord;
            
            break;

        case KEY_DOWN:
            tempY = user->ycord +1;
            tempX = user->xcord;
            
            break;
        
        case KEY_LEFT:
            tempY = user->ycord ;
            tempX = user->xcord -1;
            
            break;
        
        case KEY_RIGHT:
            tempY = user->ycord;
            tempX = user->xcord +1;
            
            break;

        default:
            break;

    }
    check_move(tempY,tempX,user);

}

int player_move(int y, int  x, Player* user ){

    mvprintw(user->ycord, user->xcord, ".");

    user->ycord =y;
    user->xcord =x;

    mvprintw(user->ycord, user->xcord, "@"); //Printing the Player 'avatar' on the screen
    move(user->ycord, user->xcord);          //moves the cursor back to the place of the avatar, since by default mvprintw moves it a space foward.

}

// Check what is at next position. Will get updated later but for now just makes sure the Avatar can't move through walls.
int check_move( int tempY, int tempX, Player* user){

    int tempP;
    switch (mvinch(tempY,tempX)) //Function from Ncurses that checks what character the cursor is on
    {
        case '.':
            player_move(tempY,tempX, user);
            break;
        default:
            move(user->ycord,user->xcord);
            break;

    }



}