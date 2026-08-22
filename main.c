#include <stdio.h>
#include<ncurses.h>
#include<stdlib.h>

#define esc 27 //Macro for the esc key in ASCII

typedef struct Player
{
    int xcord;
    int ycord;
    int HP;
    //Room * room;
} Player ;

typedef struct Room
{
  int xcord; //Top corner position of the room
  int ycord;
  int width;
  int height;
  //Monster ** monsters;
  //Items ** items;  
} Room ;




int screen_setup();
Room ** map_maker();
Player * player_maker(); //Promising a function that return a pointere to the struct Player, I think.
int handle_input(int input, Player * user);
int player_move(int y, int  x, Player* user );
int check_move( int tempY, int tempX, Player* user);
Room * create_room(int y, int x, int height, int width);
int draw_room(Room *room);

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

Room ** map_maker(){

    Room ** rooms;
    rooms = malloc(sizeof(Room)*6);
    
    
    rooms[0] = create_room( 13,13,6,8);
    draw_room(rooms[0]);
    rooms[1] = create_room(40, 40, 14, 4);
    draw_room(rooms[1]);
    rooms[2]= create_room(20, 10, 8, 12);
    draw_room(rooms[2]);

    return rooms;


}

Room * create_room(int y, int x, int height, int width){
    
    Room * newRoom;
    newRoom = malloc(sizeof(Room));

    newRoom ->ycord =y;
    newRoom ->xcord=x;
    newRoom ->height =height;
    newRoom ->width = width;

    return newRoom;

}


int draw_room(Room *room){

    
    
    for ( int y = room ->ycord +1; y < room-> ycord + room->height -1; y++ ){
        mvprintw(y, room ->xcord, "|" );
        mvprintw(y,room ->xcord + room -> width -1, "|");
        for ( int x = room ->xcord +1; x < room-> xcord + room->width -1; x++ ){
            mvprintw(y, x, ".");
        }


    }

    for ( int x = room ->xcord; x < room-> xcord + room->width; x++ ){
        mvprintw(room->ycord, x, "-");
        mvprintw(room->ycord+ room-> height-1, x, "-");

    }

    return 1;

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