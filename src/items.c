#include "rogue.h"

Item* create_item(ItemType type, int value){

    Item *item;

    item =malloc(sizeof(Item));

    if (item == NULL){
        return NULL;
    }


    item->type =type;
    item->value =value;
    item->isPickedUp =0;

    item->coordinates=malloc(sizeof(Coordinates));

    if (item->coordinates == NULL){
        free(item);
        return NULL;

    }

    if (type ==GOLD){

        item-> symbol = '$';
    }

    
    if (type ==POTION){

        item-> symbol = '!';
    }

    return item;
}


int place_items(Item *item, Room *room){

    item->coordinates->y = room->coordinates.y +1+ rand() % (room->height -2);
    item->coordinates->x = room->coordinates.x +1+ rand() % (room->width -2);

    return 1;

}

int add_items(Level *level){

    int n;
    int gridNumber;
    Item *item;

    level->numberOfItems =10;

    level->items =malloc(sizeof(Item *) * level->numberOfItems);

    if (level->items == NULL){

        return -1;
    }

    for (n =0; n <level->numberOfItems; n++){

        gridNumber= rand() % level->numberOfRooms;
         

        if (rand () % 2 ==0){

            item=create_item(GOLD, (rand()% 20)+10);
        }
        else{

            item=create_item(POTION,20);

        }  
        if (item ==NULL){
            return -1;

        }

        place_items(item, level->rooms[gridNumber]);
        level->items[n] = item; 

    }
    
    return 1;
    
}

int draw_item(Item *item){

    if (item->isPickedUp ==0){

        mvprintw(item->coordinates->y,item->coordinates->x, "%c", item->symbol);
    }

    return 1;

}

//Checks if the position of some entity matches the position of the item and returns that item's number

int get_item(Coordinates *coordinates, Item **items, int numberOfItems){     

    int n;

    for (n =0; n<numberOfItems; n++){

        if (items[n]->isPickedUp ==0){

           if( items[n]->coordinates->y == coordinates->y && items[n]->coordinates->x == coordinates->x ){

            return n;
           }

        }

    }
    return -1;

}

int add_inventory(Player *player, Item *item){

    if (player->inventorySize >= player->inventoryCapacity){

        return -1;
    }

    player->inventory[player->inventorySize] =item;
    player->inventorySize++;

    return 1;

}

int pickup_item(Player *player, Level *level){

    int itemNumber;
    Item *item;

    itemNumber = get_item(player->coordinates, level ->items, level->numberOfItems);

    if (itemNumber ==-1){
        
        return 0;

    }

    item= level->items[itemNumber];

    if (item->type == GOLD){

        player->gold += item->value;
        item->isPickedUp =1;

        return 1;

    }

    if (item->type == POTION){

        if (add_inventory(player, item) ==1){

            item->isPickedUp =1;
            
            return 1;
        }
    }
    return 0;
}

int remove_inventory(Player *player, int itemNumber){

    int n;

    if (itemNumber <0 || itemNumber >= player->inventorySize){

        return -1;

    }

    for (n = itemNumber; n<player->inventorySize -1; n++){

        player->inventory[n] =player->inventory[n+1];
    }

    player->inventorySize--;

    return 1;


}

int use_item(Player *player, Item *item){

    // eventually I'd like to add other items to use, but right now it basically just has the logic for the use of the potion
    int newHP;

    if (item->type == POTION){

        newHP =player->HP + item->value;

        if (newHP > player->maxHP){

            player->HP = player->maxHP;

        }else{

            player->HP =newHP;
        }

        return 1;
    }

    return 0;
}

int get_potion_count(Player *player){

    int n;
    int potionCount =0;

    for (n =0; n < player->inventorySize;   n++){

        if (player->inventory[n]->type ==POTION){
            potionCount++;
        }
    }
    return potionCount;
}


int consume_potion(Player *player){

    int n;

    for (n =0; n < player->inventorySize; n++){

        if(player->inventory[n]->type == POTION){

            if (use_item(player, player->inventory[n])==1){

                remove_inventory(player, n);
                return 1;
            }
        }
    }
    return 0;
}