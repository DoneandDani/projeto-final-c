#ifndef ROGUE_H
#define ROGUE_H

#include <stdio.h>
#include<ncurses.h>
#include<stdlib.h>
#include<menu.h>


#include<time.h>


#define esc 27 //Macro for the esc key in ASCII

typedef struct Game
{
    struct Level  *levels[10];
    int currentLevel;
}Game;

typedef struct Coordinates //Decided to create this struct to simplify future code. Got the idea from other similar projects online.
{
    int y;
    int x;
    
    
} Coordinates;

typedef struct Level{

    int level;
    char ** tiles;
    int numberOfRooms;
    struct Room ** rooms;
    struct Monster ** monsters;
    int numberOfMonsters;
    struct Player * user;
    struct Item **items;
    int numberOfItems;

    Coordinates staircords;
    

}Level;


typedef struct Player
{
    Coordinates * coordinates;
    int HP;
    int attack;
    int AC; //AC = Armour class; It's the number the monsters have to roll to hit the player.
    int gold;
    
    int maxHP;
    int XP;

    struct Item **inventory;
    int inventorySize;
    int inventoryCapacity;

    int playerLevel;

} Player ;

typedef enum{GOLD, POTION} ItemType;


typedef struct Item
{
    ItemType type;
    char symbol;
    int value; //Flexible variable that represents different things for different items. For potions value is how much it heals, for gold is how much gold it is.
    int isPickedUp;

    Coordinates *coordinates;
    
}Item;


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

    int monsterXP;


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

// Main
int main_game_loop( Game *game);
void render_game(Game *game);

// Screen functions
int screen_setup();
int print_game_interface(Level * level);

// Map functions
Room ** room_maker();
char ** save_level_coordinates();
Level * create_level(int level, Player *player);
void connect_doors(Level * level);
void draw_level(Level *level);
int place_stairs(Level *level);

// Player functions
Player * player_maker(); //Promising a function that return a pointere to the struct Player, I think.
Coordinates * handle_input(int input, Player * user);
int player_move(Coordinates *newCords, Player* user, char **level );
int check_move(Coordinates *newCords, Level *level);
int place_player(Player *user, Room **rooms);
void draw_player(Player *player );
int player_level_up(Player *player);

// Room functions
Room * create_room(int grid, int nOfDoors);
int draw_room(Room *room);

// Monster functions
int add_monsters(Level * level);
Monster * select_monster(int level);
Monster * create_monster(char symbol, int health, int attack, int speed, int AC, int pathfinding, int monsterXP);
int set_starting_cords( Monster * monster, Room * room);
int  move_monster(Level *level);
int pathfinding_random(Coordinates *coordinates);
int pathfinding_seek(Coordinates *start, Coordinates *destination);
Monster * get_monster(Coordinates *coordinates, Monster **monsters, int numberOfMonsters);
int kill_monster(Monster * monster);
void draw_monster(Monster *monster);
int count_alive_monsters(Monster **monsters, int count, int index);

// Combat functions 
int combat(Player *player, Monster *monster, int initiative);
int attack_roll(int AC);

// New pathfinding functions (hell)
void add_coordinates_YX(int ** frontier, int  frontier_count, int y, int x);
int add_neighbors(int **frontier,int frontier_count, int *** came_from, int y, int x);
void pathfinding(Coordinates *start, Coordinates *end );
void add_coordinates_YX(int ** frontier, int  frontier_count, int y, int x);
int pf_verify_cord(int y, int x);

//Menus
int main_menu(int nItems, char * choices[]);
void close_menu(int nItems, MENU *menu, ITEM ** items);
void menu_loop();
void game_over_screen( Game *game);

//Inventory/Items

Item* create_item(ItemType type, int value);
int place_items(Item *item, Room *room);
int add_items(Level *level);
int draw_item(Item *item);
int get_item(Coordinates *coordinates, Item **items, int numberOfItems);
int add_inventory(Player *player, Item *item);
int pickup_item(Player *player, Level *level);
int remove_inventory(Player *player, int itemNumber);
int use_item(Player *player, Item *item);
int get_potion_count(Player *player);
int consume_potion(Player *player);


#endif 
