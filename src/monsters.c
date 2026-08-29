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
        return create_monster('g',(rand()%3)+2 ,(rand()% 4)+1,1,10,2);
        break;
    case 3:
        return create_monster('w',6 ,(rand() % 4) + 1+ (rand() % 4) + 1,2,6,1);
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
    newMonster->isAlive=1;
    newMonster->pathfinding=pathfinding;

    sprintf(newMonster->stringBuffer,"%c", symbol);

    return newMonster;
}

int set_starting_cords( Monster * monster, Room * room){

    monster->mCords=malloc(sizeof(Coordinates));

    monster->mCords->y = (rand() % (room->height-2)) + room->coordinates.y+1;
    monster->mCords->x = (rand() % (room->width-2)) + room->coordinates.x+1;

}

int  move_monster(Level *level){

    int n;
    for (n=0; n <level->numberOfMonsters; n++){

        if (level->monsters[n] ->isAlive==0)
        {
            continue;
        }
        
        if (level->monsters[n]->pathfinding == 1){
            pathfinding_random(level->monsters[n]->mCords);
        }
        else{
            
            pathfinding_seek(level->monsters[n]->mCords, level->user->coordinates);
            
        }

        
    }
}


Monster * get_monster(Coordinates *coordinates, Monster **monsters){

    int n;
    for (n=0; n< 6;n++){
        if ((coordinates->y== monsters[n]->mCords->y) && (coordinates->x== monsters[n]->mCords->x)) {
            return monsters[n];
           
        }
    }
    return NULL;
}

int kill_monster(Monster * monster){

    monster->isAlive=0;
    return 1;

}



int pathfinding_random(Coordinates *coordinates){

    int randomValue;
    randomValue = rand() % 5;
    switch (randomValue) // Case 0 ->UP Case 1 ->Down Case 2 ->LEFT Case 3 ->RIGHT Case 4-> Nothing
    {
    case 0:
        if (mvinch(coordinates->y -1, coordinates->x) == '.'){
            coordinates->y =coordinates->y -1;
        }
        break;
    case 1:
        if (mvinch(coordinates->y +1, coordinates->x) == '.'){
            coordinates->y =coordinates->y +1;
        }
        break;
    case 2:
        if (mvinch(coordinates->y, coordinates->x -1) == '.'){
            coordinates->x =coordinates->x -1;
        }
        break;
    case 3:
        if (mvinch(coordinates->y, coordinates->x +1) == '.'){
            coordinates->x =coordinates->x +1;
        }
        break;
    case 4:
        
        break;
    
    
    default:
        break;
    }

}


int pathfinding_seek(Coordinates *start, Coordinates *destination){

    
    if ((abs((start->x-1) - destination->x) < abs(start->x - destination->x)) && (mvinch(start->y, start->x-1)== '.')){
        
        start->x =start->x-1;


    } else if ((abs((start->x+1) - destination->x) < abs(start->x - destination->x)) && (mvinch(start->y, start->x+1)== '.')){
        
        start->x =start->x +1;


    } else if ((abs((start->y+1) - destination->y) < abs(start->y - destination->y)) && (mvinch(start->y+1, start->x)== '.')){
        
        start->y =start->y +1;
    
    } else if ((abs((start->y-1) - destination->y) < abs(start->y - destination->y)) && (mvinch(start->y-1, start->x)== '.')){
        
        start->y =start->y -1;
    
    } else{

    }
    return 1;
}

void draw_monster(Monster *monster){

    if (monster->isAlive==1){
        mvprintw(monster->mCords->y, monster->mCords->x, monster->stringBuffer);
    }

}