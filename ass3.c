#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <string.h>

typedef struct dog {
    int barkingLevel;
    int size;
    char name[26];
    struct dog* next;
}dog;

typedef struct dog* pd;

typedef int bool;
#define true 1
#define false 0

/* Function to delete the entire linked list */
void deleteList(struct dog** head_ref)
{
    /* deref head_ref to get the real head */
    struct dog* current = *head_ref;
    struct dog* next;
    
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    
    /* deref head_ref to affect the real head back
     in the caller. */
    *head_ref = NULL;
}

/* Given a reference (pointer to pointer) to the head
 of a list and an int, push a new node on the front
 of the list. */
void push(struct dog** head_ref,char name[26], int size,int barkingLevel)
{
    /* allocate node */
    struct dog* new_node = (struct dog*) malloc(sizeof(struct dog));
    
    /* put in the data  */
    new_node->size  = size;
    strcpy(new_node->name, name);
    new_node->barkingLevel=barkingLevel;
    
    /* link the old list off the new node */
    new_node->next = (*head_ref);
    
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}



void insertNewdog(struct dog** head_ref){
    char name[26];
    int size;
    int barkinglevel;
    printf("==================================== \n"    );
    printf("1 \n");
    printf("Enter the dog's name : \n");
    scanf("%s", name);
    printf("Enter the dog's size : \n");
    scanf("%d", &size);
    printf("Enter the dog's barking level (10+ is strong) : \n");
    scanf("%d", &barkinglevel);
    push(head_ref,name,size,barkinglevel);
    printf("==================================== \n"    );

}

void deleteByName(struct dog** head_ref){
    char name[26];
    printf("==================================== \n"    );
    printf("2 \n");
    printf("Enter the dog's name : \n");
    scanf("%s", name);
    bool find = false;
    dog* tmp = *head_ref;
    dog* prev = tmp;
    while (tmp != NULL && (strcmp (tmp->name,name) != 0))  {
        prev = tmp;
        tmp = tmp->next;
    }
    
    if ((*head_ref) == tmp)
    {
        (*head_ref) = tmp->next ;
    }
    if (tmp != NULL)
    {
        prev->next = tmp->next;
        free(tmp);
    }
    
    if (tmp == NULL)
        printf("Sorry there is not such dog with that name \n");
    
    
}

void deleteBySize(struct dog** head_ref){
    int size;
    printf("==================================== \n"    );
    printf("2 \n");
    printf("Enter the dog's size : \n");
    scanf("%d", &size);
    dog* tmp = *head_ref;
    dog* prev = tmp;
    while (tmp != NULL && (tmp->size != size))  {
        prev = tmp;
        tmp = tmp->next;
    }
    
    if ((*head_ref) == tmp)
    {
        (*head_ref) = tmp->next ;
    }
    if (tmp != NULL)
    {
        prev->next = tmp->next;
        free(tmp);
    }
    
    if (tmp == NULL)
        printf("Sorry there is not such dog with that size \n");
    
    }

struct dog* sortListByLength(struct dog *head) {
    dog *tmpPtr;
    dog *tmpNxt;
    
    tmpPtr = head;
    tmpNxt = head->next;
    
    while(tmpNxt != NULL){
        while(tmpNxt != tmpPtr){
            if ((strlen(tmpNxt->name) <= strlen(tmpPtr->name))) {
                dog tmp = *tmpPtr;
                *tmpPtr = *tmpNxt;
                *tmpNxt = tmp;
                dog* ptrToNext = tmpNxt->next;
                tmpNxt->next = tmpPtr->next;
                tmpPtr->next = ptrToNext;
            }
        tmpPtr = tmpPtr->next;

    }

        tmpPtr = head;
        tmpNxt = tmpNxt->next;
}

    return tmpPtr ; // Place holder
}

struct dog* sortListByLex(struct dog *head) {
    dog *tmpPtr;
    dog *tmpNxt;
    
    tmpPtr = head;
    tmpNxt = head->next;
    
    while(tmpNxt != NULL){
        while(tmpNxt != tmpPtr){
            if ((strcmp(tmpPtr->name,tmpNxt->name)) > 0 ) {
                dog tmp = *tmpPtr;
                *tmpPtr = *tmpNxt;
                *tmpNxt = tmp;
                dog* ptrToNext = tmpNxt->next;
                tmpNxt->next = tmpPtr->next;
                tmpPtr->next = ptrToNext;
            }
            tmpPtr = tmpPtr->next;
            
        }
        
        tmpPtr = head;
        tmpNxt = tmpNxt->next;
    }
    
    return tmpPtr ; // Place holder
}

void menu(){
    printf("==================================== \n"    );
    printf("The menu: \n");
    printf("1. Insert new dog. \n");
    printf("2. Delete dog by name. \n");
    printf("3. Delete dog by size. \n");
    printf("4. Sort dogs by name length.\n");
    printf("5. Sort dogs by name order.\n");
    printf("6. Print dogs..\n");
    printf("7. Delete all dogs.\n");
    printf("8. Exit.\n");
    printf("Enter your choice :\n");
    printf("==================================== \n");
}

void printlink(struct dog* tmp){
    int count = 1;
    while (tmp != NULL){
        printf("%d", count);
        printf(") ");
        printf("%s" , tmp->name);
        printf(" with size ");
        printf("%d" , tmp->size);
        printf(" baraks");
        if (tmp->barkingLevel > 9) {
            printf(" WAF WAF! \n");
        }
        else
            printf(" waf waf! \n");
        tmp=tmp->next;
        count++;
        
        
    }
    //if (tmp == NULL)
    // printf("NULL");
        }


int main () {
    char choice;
    struct dog* head = NULL;
    do {
        menu();
        scanf(" %c", &choice);
        switch (choice){
            case '1':
            {
                insertNewdog(&head);
                break;
            }
            case '2':
            {
                deleteByName(&head);

                break;
            }
            case '3':
            {
                deleteBySize(&head);
                
                break;
            }
            case '4':
            {
                sortListByLength(head);
                
                break;
            }
            case '5':
            {
                sortListByLex(head);
                
                break;
            }
            case '6':
            {
                printlink(head);
                break;
            }
            case '7':
            {
                deleteList(&head);
                break;
            }
                
            case '8':
            {
                break;
            }
            default:
                printf("\n Wrong choice. Please enter again: \n");
                break;
        }
        
    }
    while (choice != '8');
    return 0;
}
