#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>


typedef struct {
    char name[50];
    float expense;
} amounts;


int main() {

    int mode;
    int quantity;
    int i;
    int WriteNow;

    FILE *fptr = fopen("list.txt", "wx");
    if (fptr == NULL) {
        
        printf("No New Data file will be created due to existing.");
        fclose(fptr);

    } else {

        printf("New Data file has been created.\n");
        printf("Would you like to write it there now? (1 for Yes) \n");
        scanf("%d", &WriteNow);
        
        if (WriteNow == 1) {

            printf("Provide The number of expense \n\n");
            scanf("%d", &quantity);

            amounts *ptr = malloc(quantity * sizeof(amounts));
    
            for (i = 0; i < quantity; i++)
            {
            printf("Enter %d Name :  ", i+1);
            scanf("%s", ptr[i].name);

            printf("Enter %d Expense : ", i+1);
            scanf("%f", &ptr[i].expense);
            }

            for (i = 0; i < quantity; i++) {
                FILE *fptr = fopen("list.txt", "a");

                fptr = fopen("list.txt", "a");
                fprintf(fptr, "%s expense : %.2f \n", ptr[i].name, ptr[i].expense);
                
                fclose(fptr);
            }
        } else {
            printf("Oke\n");
        }
    }

    printf("What would you like to do \n");


    printf("Read The Existing Expense List : enter 1 \n");
    printf("Input New Expense : enter 2 \n ");
    scanf(" %d", &mode);

    if (mode == 1)
    {
    
        char myString[200];
        FILE *fptr = fopen("list.txt", "r");

        if (fptr == NULL){
            printf("No Existing file to read.");
            fclose(fptr);
        } else {

            while(fgets(myString, 200, fptr)) {
                printf("%s \n", myString);
            }
            fclose(fptr);
        }

        

    

    } 
    else {
        
    printf("Provide The number of expense");
    scanf("%d", &quantity);

    amounts *ptr = malloc(quantity * sizeof(amounts));
    
    for (i = 0; i < quantity; i++)
    {
        printf("Enter %d Name : ", i+1);
        scanf("%s", ptr[i].name);

        printf("Enter %d Expense : ", i+1);
        scanf("%f", &ptr[i].expense);
    }

    for (i = 0; i < quantity; i++) {
        FILE *fptr = fopen("list.txt", "a");

        fptr = fopen("list.txt", "a");
        fprintf(fptr, "%s expense : %.2f \n", ptr[i].name, ptr[i].expense);
        
        fclose(fptr);
    }
    
    char myString[200];
    FILE *fptr = fopen("list.txt", "r");

    while(fgets(myString, 200, fptr)) {
        printf("%s \n", myString);
    }


    fclose(fptr);

    
    
    
    free(ptr); 

    }
}    