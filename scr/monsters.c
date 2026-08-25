#include "rogue.h"

/*
Monster ideas and their planned stats:

1 Rat
    symbol: r
    levels: 1-2
    health: 2-3
    attack: 1d3 (damage will be a random number between 1 and 3 damage)
    speed: 1 (move 1 tile per game tick)
    AC: 7 (Armor class aka the number the player needs to roll to hit)
    pathfinding: 1 (random pathfinding aka moves randomly)

2 Goblin
    symbol: o
    levels: 1-3
    health: 2-4
    attack: 1d4
    speed: 1 
    AC: 10
    pathfinding: 2 (seeking)


3 Wolf
    symbol: d
    levels: 2-6
    health: 6
    attack: 2d4
    speed: 2 
    AC: 6
    pathfinding: 1     

4 Troll
    symbol: t
    level:4-6
    health: 28
    attack: 2d6
    speed: 1 
    AC: 4
    pathfinding: 1 


*/

int add_monsters( Level *level){

    level->monsters = malloc(sizeof(Monster *) *6);
    level-> numberOfMonsters =0;


    for (int x =0; x< level-> numberOfRooms; x++){

        if ((rand() %2 )== 0){

            level->monsters[level->numberOfMonsters] = select_monster( level->level);
            set_starting_cords(level->monsters[level->numberOfMonsters], level->rooms[x]);
            level->numberOfMonsters++;
        }
    }
}

Monster * select_monster(int level){

    int monster;

    switch (level)
    {
    case 1:
        monster = (rand() % 2) +1;
        break;
    case 2:
        monster = (rand() % 3) +1;
        break;
    case 3:
        monster = (rand() % 2) +2;
        break;
    case 4:
        monster =(rand() % 2) + 3;
        break;
    case 5:
        monster =(rand() % 2) + 3;
        break;
    case 6:
        monster =(rand() % 2) + 3;
        break;
    
    default:
        break;
    }
    switch (monster)
    {
    case 1:
        return create_monster('r',(rand()%2)+2 ,(rand()%3)+1,1,7,1  );
        break;
    case 2:
        return create_monster('o',(rand()%3)+2 ,(rand()% 4)+1,1,10,2);
        break;
    case 3:
        return create_monster('d',6 ,(rand() % 4) + 1+ (rand() % 4) + 1,2,6,1);
        break;
    case 4:
        return create_monster('t', 28,(rand() % 6) + 1 +(rand() % 6) + 1,1,4,1);
        break;
        
    default:
        break;
    }

}

Monster * create_monster(char symbol, int health, int attack, int speed, int AC, int pathfinding){

    Monster * newMonster;
    newMonster =malloc(sizeof(Monster));

    newMonster->symbol =symbol;
    newMonster->health=health;
    newMonster->attack=attack;
    newMonster->speed=speed;
    newMonster->AC=AC;
    newMonster->pathfinding=pathfinding;

    return newMonster;
}

int set_starting_cords( Monster * monster, Room * room){

    char buffer[8];

    monster->mCords.y = (rand() % (room->height-2)) + room->coordinates.y+1;
    monster->mCords.x = (rand() % (room->width-2)) + room->coordinates.x+1;

    sprintf(buffer,"%c", monster->symbol);

    mvprintw(monster->mCords.y,monster->mCords.x, buffer);

}