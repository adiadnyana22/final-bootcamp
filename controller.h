// #include "model.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

Ingredient *createIngridient(const char *name, int qty){
    Ingredient *newNode = (Ingredient *) malloc(sizeof(Ingredient));
    strcpy(newNode->name, name);
    newNode->qty = qty;
    newNode->next = newNode->prev = NULL;
    
    return newNode;
}

void pushIngridient(const char *name, int qty){
    Ingredient *temp = createIngridient(name, qty);
    if(!headGlobalIng){
        headGlobalIng = tailGlobalIng = temp;
    } else {
        temp->prev = tailGlobalIng;
        tailGlobalIng->next = temp;
        tailGlobalIng = temp;
    }
}

void popHeadIngridient(){
    if (!headGlobalIng){
        return ;
    } else if(headGlobalIng == tailGlobalIng){
        free(headGlobalIng);
        headGlobalIng = NULL;
    } else {
        Ingredient *candidateHead = headGlobalIng->next;
        candidateHead->prev = NULL;
        headGlobalIng->next = NULL;
        free(headGlobalIng);
        headGlobalIng = candidateHead;
    }
}

void popTailIngridient(){
    if (!headGlobalIng){
        return ;
    } else if(headGlobalIng == tailGlobalIng){
        free(headGlobalIng);
        headGlobalIng = NULL;
    } else {
        Ingredient *candidateTail = tailGlobalIng->prev;
        candidateTail->next = NULL;
        tailGlobalIng->prev = NULL;
        free(tailGlobalIng);
        tailGlobalIng = candidateTail;
    }
}

void popIngridient(const char *name){
    if (!headGlobalIng){
        return;
    } else if(strcmp(headGlobalIng->name, name) == 0){
        popHeadIngridient();
    } else if(strcmp(tailGlobalIng->name, name) == 0){
        popTailIngridient();
    } else {
        Ingredient *curr = headGlobalIng;
        while(curr && strcmp(curr->name, name) != 0){
            curr = curr->next;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        curr->prev = NULL;
        curr->next = NULL;
        free(curr);
        curr = NULL;
    }
}

void searchIngredient(const char *name){
    Ingredient *curr = headGlobalIng;
    while(curr && strcmp(curr->name, name) != 0){
        curr = curr->next;
    }
    if(curr){
        printf("%s\t%d\n", curr->name, curr->qty);
    } else {
        printf("No Items !\n");
    }
}

void printIngredient(){
    printf("Name\tQty\n");
    Ingredient *curr = headGlobalIng;
    while(curr){
        printf("%s\t%d\n", curr->name, curr->qty);
        curr = curr->next;
    }
}

Recipe *createRecipe(const char *name, const char *description, const char *instruction){
    Recipe *newNode = (Recipe *) malloc(sizeof(Recipe));
    strcpy(newNode->name, name);
    strcpy(newNode->description, description);
    strcpy(newNode->instruction, instruction);
    newNode->headIngredient = newNode->tailIngredient = NULL;
    newNode->next = newNode->prev = NULL;

    return newNode;
}

Recipe *pushRecipe(const char *name, const char *description, const char *instruction){
    Recipe *temp = createRecipe(name, description, instruction);
    if(!headRecipe){
        headRecipe = tailRecipe = temp;
    } else {
        temp->prev = tailRecipe;
        tailRecipe->next = temp;
        tailRecipe = temp;
    }

    return temp;
}

void searchRecipe(const char *name){
    Recipe *curr = headRecipe;
    while(curr && strcmp(curr->name, name) != 0){
        curr = curr->next;
    }
    if(curr){
        printf("Name : %s\nDescription : %s\nInstruction :\n%s\nIngredient :\n", curr->name, curr->description, curr->instruction);
        Ingredient *currIng = curr->headIngredient;
        int count = 1;
        while (currIng){
            printf("%d. %s x%d\n", count++, currIng->name, currIng->qty);
            currIng = currIng->next;
        }
    } else {
        printf("No Items !\n");
    }
}

void printRecipe(){
    Recipe *curr = headRecipe;
    while(curr){
        // curr = curr->next;
        printf("Name : %s\nDescription : %s\nInstruction :\n%s\nIngredient :\n", curr->name, curr->description, curr->instruction);
        Ingredient *currIng = curr->headIngredient;
        int count = 1;
        while (currIng){
            printf("%d. %s x%d\n", count++, currIng->name, currIng->qty);
            currIng = currIng->next;
        }
        printf("\n ----- \n");
        curr = curr->next;
    }
}

void pushIngridientRecipe(Recipe *rcp, const char *name, int qty){
    Ingredient *temp = createIngridient(name, qty);
    if(!rcp->headIngredient){
        rcp->headIngredient = rcp->tailIngredient = temp;
    } else {
        temp->prev = rcp->tailIngredient;
        rcp->tailIngredient->next = temp;
        rcp->tailIngredient = temp;
    }
}

void printPreference(const char *pref){
    Recipe *curr = headRecipe;
    while(curr){
        if(strcmp(curr->description, pref) == 0){
            // curr = curr->next;
            printf("Name : %s\nDescription : %s\nInstruction :\n%s\nIngredient :\n", curr->name, curr->description, curr->instruction);
            Ingredient *currIng = curr->headIngredient;
            int count = 1;
            while (currIng){
                printf("%d. %s x%d\n", count++, currIng->name, currIng->qty);
                currIng = currIng->next;
            }
            printf("\n ----- \n");
        }
        curr = curr->next;
    }
}

void searchPreference(const char *name, const char *pref){
    Recipe *curr = headRecipe;
    while(curr && strcmp(curr->name, name) != 0 && strcmp(curr->description, pref) != 0){
        curr = curr->next;
    }
    if(curr){
        printf("Name : %s\nDescription : %s\nInstruction :\n%s\nIngredient :\n", curr->name, curr->description, curr->instruction);
        Ingredient *currIng = curr->headIngredient;
        int count = 1;
        while (currIng){
            printf("%d. %s x%d\n", count++, currIng->name, currIng->qty);
            currIng = currIng->next;
        }
    } else {
        printf("No Items !\n");
    }
}