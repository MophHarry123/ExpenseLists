#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>


typedef struct {
    char name[50];
    float expense;
} amounts;

void CleanUp() {
    FILE *fptr = fopen("list.txt", "w");
    fclose(fptr);

    printf("\n History cleared.");
}

void ReadList() {
        char myString[200];
        FILE *fptr = fopen("list.txt", "r");

        if (fptr == NULL){
            printf("No Existing file to read. \n");
        } else {

            while(fgets(myString, 200, fptr)) {
                printf("%s \n", myString);
            }
            fclose(fptr);
        }
    }

void AddingNewList(amounts*ptr, int n, int times) {

    
    for (times = 0; times < n; times++)
    {
        printf("Enter %d Name : ", times+1);
        scanf("%s", ptr[times].name);

        printf("Enter %d Expense : ", times+1);
        scanf("%f", &ptr[times].expense);
    }
}

void WritingNewList(amounts*ptr,int n, int times) {
 
    for (times = 0; times < n; times++) {
        FILE *fptr = fopen("list.txt", "a");

        fptr = fopen("list.txt", "a");
        fprintf(fptr, "%s expense : %.2f \n", ptr[times].name, ptr[times].expense);
        
        fclose(fptr);
    } 
}

int main() {

    int mode;
    int quantity;
    int i;
    int WriteNow;
    int YesNo;
    int YesNo2;

    FILE *fptr = fopen("list.txt", "wx");
    if (fptr == NULL) {
        
        printf("No New Data file will be created due to existing. \n");
        fclose(fptr);

    } else {

        printf("New Data file has been created.\n");
        printf("Would you like to write it there now? (1 for Yes) \n");
        scanf("%d", &WriteNow);
        
        if (WriteNow == 1) {

            printf("Provide The number of expense \n\n");
            scanf("%d", &quantity);

            amounts *ptr = malloc(quantity * sizeof(amounts));
            
            AddingNewList(ptr, quantity, i);
            WritingNewList(ptr, quantity, i);
            
        } else {
            printf("Oke\n");
        }
    }

    printf("What would you like to do \n");
    printf("Read The Existing Expense List : enter 1 \n");
    printf("Input New Expense : enter 2 \n ");

    scanf("%d", &mode);

    if (mode == 1)
    {
        ReadList();
        printf("Would you like to clean it up?  \n");
        printf("1 = Yes | 2 = No  \n");
        scanf("%d \n", &YesNo2);

        if (YesNo2 == 1) {
            CleanUp();
        } else {
            printf("Procceding");
        }
    } 
    else {

    printf("Would you like to clear previous data? (1 = Yes/ 2= N) \n");
    scanf("%d", &YesNo);

    if (YesNo == 1) {
        CleanUp();
    } else {
        printf("Oke. Procceding. \n");
    }
        
    printf("Provide The number of expense");
    scanf("%d", &quantity);

    amounts *ptr = malloc(quantity * sizeof(amounts));
    AddingNewList(ptr, quantity, i);
    WritingNewList(ptr, quantity, i);
    ReadList();
    free(ptr); 

    }
}    