#include "rogue.h"

void add_coordinates_YX(int ** frontier, int  frontier_count, int y, int x){

frontier[frontier_count][0]= y;
frontier[frontier_count][1]= x;


}

int pf_verify_cord(int y, int x){

    char temp_cord = mvinch(y,x);

    if (temp_cord == '.' || temp_cord=='-' || temp_cord=='|'){
        return 0;
    }
    else
        return 1;


}

int add_neighbors(int **frontier,int frontier_count, int *** came_from, int y, int x){

    //Up position
    if (y>0 && came_from[y-1][x][0]<0  && pf_verify_cord(y-1,x)){

        add_coordinates_YX(frontier, frontier_count,y-1,x);
        frontier_count++;
        came_from[y-1][x][0]=y;
        came_from[y-1][x][1]=x;
        
    }

    //Down Position
    if (y< (max_height-1) && came_from[y+1][x][0]< 0 && pf_verify_cord(y+1,x)){

        add_coordinates_YX(frontier, frontier_count,y+1,x);
        frontier_count++;
        came_from[y+1][x][0]=y;
        came_from[y+1][x][1]=x;
        
    }

    // Right position
    if (x< (max_width-1) && came_from[y][x+1][0]< 0 && pf_verify_cord(y,x+1)){

        add_coordinates_YX(frontier, frontier_count,y,x+1);
        frontier_count++;
        came_from[y][x+1][0]=y;
        came_from[y][x+1][1]=x;
        
    }
    
    //Left position
    if (x>0 && came_from[y][x-1][0]< 0 && pf_verify_cord(y,x-1)){

        add_coordinates_YX(frontier, frontier_count,y,x-1);
        frontier_count++;
        came_from[y][x-1][0]=y;
        came_from[y][x-1][1]=x;

    }

    
    return frontier_count;

}





void pathfinding(Coordinates *start, Coordinates *end ){

    int i ,j;
    int x,y;
    int tempY; //necessary to use because otherwise the last character of the path does not print.

    int ** frontier = malloc(sizeof(int*) * max_height * max_width);
    int *** came_from= malloc(sizeof(int**)* max_height);
    
    int frontier_index =0;
    int frontier_count =0;

    for ( i = 0; i < max_height *max_width; i++){
        
        frontier[i]=malloc(sizeof(int)*2);
        
    }

    for ( i = 0; i < max_height; i++){
        
        came_from[i]=malloc(sizeof(int*)*max_width);
        for ( j = 0; j < max_width; j++)
        {
            came_from[i][j] =malloc(sizeof(int)*2);
            came_from[i][j][0]=-1;
            came_from[i][j][1]=-1;
            
        }
        
        
    }
    // this part adds the coordinates of the inital position to the came_from vector. 
    came_from[start->y][start->x][0] = -9;
    came_from[start->y][start->x][1] = -9;

    add_coordinates_YX(frontier, frontier_count, start->y, start->x);
    frontier_count++;

    while (frontier_index < frontier_count){

        y=frontier[frontier_index][0];
        x=frontier[frontier_index][1];
        frontier_index++;

        if (y ==end->y && x ==end->x){

            break;
        }
        
        frontier_count = add_neighbors(frontier, frontier_count, came_from, y,x);
    }

    y=end->y;
    x=end->x;

    while (y != start->y || x !=start->x){
        
        tempY=y;
        y= came_from[tempY][x][0];
        x= came_from[tempY][x][1];
        mvprintw(y,x,"#");
        

        
    }
    


}