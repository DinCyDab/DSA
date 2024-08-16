#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Battlefield Size
#define BF_SIZE 5

//To Be Implemented:
//Ship size might become 2x2 or 2x3, better make this multidimensional array
//Removing Ship from the battlefield logic
//Changing Ship's location on the battlefield logic
//Scanf for the user's input: row, col, pos
//Might be better if we use letters for row eg. A-0, A-1, A-2
//Gameplay
//Enemy side

typedef struct{
    char ship_model_number;
    int ship_size;
    int* x_location;    //Holder for the ship's current row location when placed
    int* y_location;    //Holder for the ship's current col location when placed
    bool is_available;
}ship_info_t;

void putShip(char battlefield[BF_SIZE][BF_SIZE], int row, int col, char pos, ship_info_t* ship);
void initializeBattlefield(char battlefield[BF_SIZE][BF_SIZE]);
void printShipLocation(char battlefield[BF_SIZE][BF_SIZE]);
ship_info_t addShipInfo(char ship_model_number, int ship_size);
void initializeShipLocation(int* x_location, int* y_location, int ship_size);
void freeAllocation(ship_info_t* ship, int ship_count);
void removeShip(char battlefield[BF_SIZE][BF_SIZE]); //Still not implemented
void changeShipLocation(); //Still not implemented

int main(){
    char battlefield[BF_SIZE][BF_SIZE];
    initializeBattlefield(battlefield);

    //For simplicity, only 2 for now
    int ship_count = 2;
    ship_info_t ship[ship_count];
    ship[0] = addShipInfo('1', 2);
    ship[1] = addShipInfo('2', 4);

    //'h' for Horizontal
    //'v' for Vertical
    putShip(battlefield, 0, 0, 'h', &ship[0]);
    putShip(battlefield, 0, 3, 'v', &ship[1]);

    printShipLocation(battlefield);

    freeAllocation(ship, ship_count);

    return 0;
}

void putShip(char battlefield[BF_SIZE][BF_SIZE], int row, int col, char pos, ship_info_t* ship){
    //Check if the ship is already in the battlefield
    if(ship->is_available == false){
        printf("Ship is already in the battlefield\n");
        return;
    }

    //Get the remaining space to put the ship: battlefield - row or col, depends on the position ('h' or 'v')
    int remaining_space;
    switch(pos){
        case 'h':
            remaining_space = BF_SIZE - col;
            break;
        case 'v':
            remaining_space = BF_SIZE - row;
            break;
        default:
            printf("Invalid position\n");
            return;
    }
    if(remaining_space < ship->ship_size){
        printf("Cannot add ship in this location...\n");
        return;
    }
    
    //Check for any overlapping
    for(int i = 0; i < ship->ship_size; i++){
        if ((pos == 'h' && battlefield[row][col + i] != '-') || 
            (pos == 'v' && battlefield[row + i][col] != '-')) {
            printf("Cannot add ship in this location...\n");
            return;
        }
    }

    //Add the ship's location inside the battlefield
    for(int i = 0; i < ship->ship_size; i++){
        switch(pos){
            case 'h':
                battlefield[row][col + i] = ship->ship_model_number;
                ship->x_location[i] = row;
                ship->y_location[i] = col + i;
                break;
            case 'v':
                battlefield[row + i][col] = ship->ship_model_number;
                ship->x_location[i] = row + i;
                ship->y_location[i] = col;
                break;
        }
    }
    ship->is_available = false;
}

//Basic adding of ship info
ship_info_t addShipInfo(char ship_model_number, int ship_size){
    ship_info_t ship;
    ship.ship_model_number = ship_model_number;
    ship.x_location = (int*)malloc(sizeof(int) * ship_size);
    ship.y_location = (int*)malloc(sizeof(int) * ship_size);
    ship.ship_size = ship_size;
    ship.is_available = true;
    initializeShipLocation(ship.x_location, ship.y_location, ship.ship_size);
    return ship;
}

void initializeShipLocation(int* x_location, int* y_location, int ship_size){
    for(int i = 0; i < ship_size; i++){
        x_location[i] = -1;
        y_location[i] = -1;
    }
}

void initializeBattlefield(char battlefield[BF_SIZE][BF_SIZE]){
    for(int i = 0; i < BF_SIZE; i++){
        for(int j = 0; j < BF_SIZE; j++){
            battlefield[i][j] = '-';
        }
    }
}

//Print the battlefield with the ship's location
void printShipLocation(char battlefield[BF_SIZE][BF_SIZE]){
    printf("Ship's location:\n ");
    for(int i = 0; i < BF_SIZE; i++){
        printf("  %d", i);
    }
    printf("\n");

    for(int i = 0; i < BF_SIZE; i++){
        printf("%d ", i);
        for(int j = 0; j < BF_SIZE; j++){
            printf("[%c]", battlefield[i][j]);
        }
        printf("\n");
    }
}

void freeAllocation(ship_info_t* ship, int ship_count){
    for(int i = 0; i < ship_count; i++){
        free(ship[i].x_location);
        free(ship[i].y_location);
    }
}