#include <stdio.h>
#include<ncurses.h>
#include<stdlib.h>

#define esc 27 //Macro for the esc key in ASCII

typedef struct Coordinates //Decided to create this struct to simplify future code. Got the idea from other similar projects online.
{
    int y;
    int x;
    //Maybe add stuff about the tile type, like traps and such
    
} Coordinates;

typedef struct Player
{
    Coordinates coordinates;
    int HP;
    //Room * room;
} Player ;

typedef struct Room
{
  //int ycord;
  //int xcord;
  Coordinates coordinates;
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

    newRoom ->coordinates.y =y;
    newRoom ->coordinates.x=x;
    newRoom ->height =height;
    newRoom ->width = width;

    return newRoom;

}


int draw_room(Room *room){

    
    
    for ( int y = room ->coordinates.y +1; y < room-> coordinates.y + room->height -1; y++ ){
        mvprintw(y, room ->coordinates.x, "|" );
        mvprintw(y,room ->coordinates.x + room -> width -1, "|");
        for ( int x = room ->coordinates.x +1; x < room-> coordinates.x + room->width -1; x++ ){
            mvprintw(y, x, ".");
        }


    }

    for ( int x = room ->coordinates.x; x < room-> coordinates.x + room->width; x++ ){
        mvprintw(room->coordinates.y, x, "-");
        mvprintw(room->coordinates.y+ room-> height-1, x, "-");

    }

    return 1;

}


Player * player_maker(){

    Player *initPlayer;
    initPlayer= malloc(sizeof(Player)); //Dynamically allocated the size in memory necessary for the newPlayer pointer based on the size of Player,
                                       // as I don't know beforehand how big it's going to be (+ I'll constantly add changes to the Player struct itself).
    initPlayer-> coordinates.x =14; //Acessing the coordinates in the Player struct and changing their values
    initPlayer-> coordinates.y =14;
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
            tempY = user->coordinates.y -1;
            tempX = user->coordinates.x;
            
            break;

        case KEY_DOWN:
            tempY = user->coordinates.y +1;
            tempX = user->coordinates.x;
            
            break;
        
        case KEY_LEFT:
            tempY = user->coordinates.y ;
            tempX = user->coordinates.x -1;
            
            break;
        
        case KEY_RIGHT:
            tempY = user->coordinates.y;
            tempX = user->coordinates.x +1;
            
            break;

        default:
            break;

    }
    check_move(tempY,tempX,user);

}

int player_move(int y, int  x, Player* user ){

    mvprintw(user->coordinates.y, user->coordinates.x, ".");

    user->coordinates.y =y;
    user->coordinates.x =x;

    mvprintw(user->coordinates.y, user->coordinates.x, "@"); //Printing the Player 'avatar' on the screen
    move(user->coordinates.y, user->coordinates.x);          //moves the cursor back to the place of the avatar, since by default mvprintw moves it a space foward.

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
            move(user->coordinates.y,user->coordinates.x);
            break;

    }



}