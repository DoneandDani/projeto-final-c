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
  Coordinates ** doors;

  //Monster ** monsters;
  //Items ** items;  
} Room ;





int screen_setup();
int print_game_interface(Level * level);

Room ** room_maker();
char ** save_level_coordinates();
Level * create_level(int level);

Player * player_maker(); //Promising a function that return a pointere to the struct Player, I think.
Coordinates * handle_input(int input, Player * user);
int player_move(Coordinates *newCords, Player* user, char **level );
int check_move(Coordinates *newCords, Level *level);

Room * create_room(int grid);
int draw_room(Room *room);
int connect_doors(Coordinates *door1 , Coordinates *door2);

int add_monsters(Level * level);
Monster * select_monster(int level);
Monster * create_monster(char symbol, int health, int attack, int speed, int AC, int pathfinding);
int set_starting_cords( Monster * monster, Room * room);
int  move_monster(Level *level);
int pathfinding_random(Coordinates *coordinates);
int pathfinding_seek(Coordinates *start, Coordinates *destination);
Monster * get_monster(Coordinates *coordinates, Monster **monsters);
int kill_monster(Monster * monster);

int combat(Player *player, Monster *monster, int initiative);

#endif 
