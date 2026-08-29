#ifndef ROGUE_H
#define ROGUE_H

#include <stdio.h>
#include<ncurses.h>
#include<stdlib.h>

#include<time.h>


#define esc 27 //Macro for the esc key in ASCII

typedef struct Level{

    int level;
    char ** tiles;
    int numberOfRooms;
    struct Room ** rooms;
    struct Monster ** monsters;
    int numberOfMonsters;
    struct Player * user;
    

}Level;

typedef struct Coordinates //Decided to create this struct to simplify future code. Got the idea from other similar projects online.
{
    int y;
    int x;
    //Maybe add stuff about the tile type, like traps and such
    
} Coordinates;

typedef struct Player
{
    Coordinates * coordinates;
    int HP;
    int attack;
    int gold;

    int maxHP;
    int XP;

} Player ;

typedef struct Monster
{
    char stringBuffer[2];
    char symbol;
    int health;
    int attack;
    int speed;
    int AC;
    int pathfinding;
    int isAlive;
    Coordinates * mCords;


}Monster;


typedef struct Room
{
  //int ycord;
  //int xcord;
  Coordinates coordinates;
  int width;
  int height;
  struct Door ** doors;
  int nOfDoors;  
  //Monster ** monsters;
  //Items ** items;  
} Room ;

typedef struct Door
{
    Coordinates coordinates;
    int connected;
}Door;


//Global variables (for display size)

extern int max_width;
extern int max_height;


// Screen functions
int screen_setup();
int print_game_interface(Level * level);

// Map functions
Room ** room_maker();
char ** save_level_coordinates();
Level * create_level(int level);
void connect_doors(Level * level);

// Player functions
Player * player_maker(); //Promising a function that return a pointere to the struct Player, I think.
Coordinates * handle_input(int input, Player * user);
int player_move(Coordinates *newCords, Player* user, char **level );
int check_move(Coordinates *newCords, Level *level);
int place_player(Player *user, Room **rooms);

// Room functions
Room * create_room(int grid, int nOfDoors);
int draw_room(Room *room);

// Monster functions
int add_monsters(Level * level);
Monster * select_monster(int level);
Monster * create_monster(char symbol, int health, int attack, int speed, int AC, int pathfinding);
int set_starting_cords( Monster * monster, Room * room);
int  move_monster(Level *level);
int pathfinding_random(Coordinates *coordinates);
int pathfinding_seek(Coordinates *start, Coordinates *destination);
Monster * get_monster(Coordinates *coordinates, Monster **monsters);
int kill_monster(Monster * monster);

// Combat functions 
int combat(Player *player, Monster *monster, int initiative);

// New pathfinding functions (hell)
void add_coordinates_YX(int ** frontier, int  frontier_count, int y, int x);
int add_neighbors(int **frontier,int frontier_count, int *** came_from, int y, int x);
void pathfinding(Coordinates *start, Coordinates *end );
void add_coordinates_YX(int ** frontier, int  frontier_count, int y, int x);
int pf_verify_cord(int y, int x);

#endif 
