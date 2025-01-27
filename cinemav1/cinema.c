#include <stdio.h>
#include <stdlib.h>


int main() {
    int rowsNumber, chairsNumber,action;
    int currentRow,currentChair,nreservations=0;
    
    printf("Enter number of rows: ");
    scanf("%d",&rowsNumber);

    printf("Enter number of chairs: ");
    scanf("%d",&chairsNumber);

    // Using dynamic allocation to allocate matrix 
    int **cinema = (int**) calloc(rowsNumber,sizeof(int*));

    for(int i=0; i<rowsNumber; i++) {
        cinema[i] = (int*) calloc(chairsNumber,sizeof(int));
    }


    // Main program
    do {
        printf("Choose action:\n");
        printf("[0] Reservation\n");
        printf("[1] Delete reservation\n");
        printf("[2] Show room\n");
        printf("[3] Show reservations\n");
        printf("[4] Exit\n");
        printf("\n Action: ");
        scanf("%d", &action);
        
        // Using switch-case to select type of action
        switch(action) {

            case 0:
                // Do-while working until seat is reserved
                do {
                    // Do-While to control row selection
                    do {
                    printf("Select row: ");
                    scanf("%d", &currentRow);
                    if(currentRow < 0 || currentRow >= rowsNumber)
                        printf("Error: Wrong input of row number (exceeding the limit %d or negative)\n", rowsNumber);
                    } while(currentRow < 0 || currentRow >= rowsNumber);

                    // Do-While to control chairs selection
                    do {
                    printf("Select chair: ");
                    scanf("%d", &currentChair);
                    if(currentChair < 0 || currentChair >= chairsNumber)
                        printf("Error: Wrong input of row number (exceeding the limit %d or negative)\n", chairsNumber);
                    } while(currentChair < 0 || currentChair >= chairsNumber);

                    // Loading input in cinema matrix;
                    if(cinema[currentRow][currentChair] == 0) {
                        cinema[currentRow][currentChair] = 1;
                        printf("Sucess: New seat reserved.\n");
                        break;
                    } else {
                        printf("Error: Seat already reserved.\n");
                    }
                } while (1);
            break;

            case 1:
                // Do-while working until reservation is deleted
                do {
                    // Do-While to control row selection
                    do {
                    printf("Select row: ");
                    scanf("%d", &currentRow);
                    if(currentRow < 0 || currentRow >= rowsNumber)
                        printf("Error: Wrong input of row number (exceeding the limit %d or negative)\n", rowsNumber);
                    } while(currentRow < 0 || currentRow >= rowsNumber);

                    // Do-While to control chairs selection
                    do {
                    printf("Select chair: ");
                    scanf("%d", &currentChair);
                    if(currentChair < 0 || currentChair >= chairsNumber)
                        printf("Error: Wrong input of row number (exceeding the limit %d or negative)\n", chairsNumber);
                    } while(currentChair < 0 || currentChair >= chairsNumber);

                    // Loading input in cinema matrix;
                    if(cinema[currentRow][currentChair] == 1) {
                        cinema[currentRow][currentChair] = 0;
                        printf("Sucess: Reservation deleted.\n");
                        break;
                    } else {
                        printf("Error: Seat already free.\n");
                        break;
                    }
                } while (1);                 
            break;

            case 2:
                // Printing of room
                for(int i = 0; i<rowsNumber; i++) {
                    for(int j = 0; j< chairsNumber; j++) {
                        if(cinema[i][j] == 0) {
                            printf(" 0");
                        } else {
                            printf(" X");
                        }
                    }
                    printf("\n");
                }
            break;
            
            case 3:
                nreservations = 0;
                for(int i = 0; i<rowsNumber; i++) {
                    for(int j = 0; j<chairsNumber; j++) {
                        if(cinema[i][j] == 1) {
                            nreservations++;
                            printf("%d. Row: %d , Chair: %d\n",nreservations,i+1,j+1);
                        }
                        
                    }
                }
                if (nreservations == 0) {
                    printf("There was no reservations.\n");
                }
            break;
        }
    } while(action != 4);


    for(int i =0; i<rowsNumber; i++) 
        free(cinema[i]);
    free(cinema);
    return 0; 
}