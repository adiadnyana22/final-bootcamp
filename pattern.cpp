#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "model.h"
#include "controller.h"
#include "view.h"

int main(){
    printf("Masukkan Nama Anda : ");
    scanf("%s", user.name);
    printf("Pilih Preference :\n");
    puts("1. Kering");
    puts("2. Basah");
    puts("3. Minuman");
    puts("4. Dessert");
    printf(">> ");
    int pref;
    scanf("%d", &pref);
    if(pref == 1){
        strcpy(user.preference, "Kering");
    } else if(pref == 2){
        strcpy(user.preference, "Basah");
    } else if(pref == 3){
        strcpy(user.preference, "Minuman");
    } else if(pref == 4){
        strcpy(user.preference, "Desert");
    }
    int globalFlag = 1;
    while(globalFlag == 1){
        Main_Screen(user.name);
        // printf("%s\n", user.preference);
        int menu;
        scanf("%d", &menu);
        if(menu == 1){
            Home_Page();
            int menuHome;
            scanf("%d", &menuHome);
            if(menuHome == 1){
                printPreference(user.preference);
                getchar();
                getchar();
            } else if(menuHome == 2){
                char rcpName[30];
                printf("Enter the name of the recipe : ");
                scanf("%s", rcpName);
                searchPreference(rcpName, user.preference);
                getchar();
                getchar();
            }
        } else if(menu == 2){
            Cook_Book();
            int menuCB;
            scanf("%d", &menuCB);
            if(menuCB == 1){
                // system("cls || clear");
                printRecipe();
                // printf("Press any key to exit\n");
                getchar();
                getchar();
                // scanf("%d", &menuCB);
            } else if(menuCB == 2){
                char rcpName[30];
                printf("Enter the name of the recipe : ");
                scanf("%s", rcpName);
                searchRecipe(rcpName);
                getchar();
                getchar();
            } else if(menuCB == 3){
                char inName[30];
                int inDesc;
                char inIns[200];
                printf("Recipe Name : ");
                scanf("%s", inName);
                printf("Select Recipe Descripion : \n");
                puts("1. Kering");
                puts("2. Basah");
                puts("3. Minuman");
                puts("4. Dessert");
                printf(">> ");
                scanf("%d", &inDesc);
                getchar();
                printf("Write Intruction (End with #) : \n");
                scanf("%[^#]", inIns);
                getchar();
                char jenis[30];
                if(inDesc == 1){
                    strcpy(jenis, "Kering");
                } else if(inDesc == 2){
                    strcpy(jenis, "Basah");
                } else if(inDesc == 3){
                    strcpy(jenis, "Minuman");
                } else if(inDesc == 4){
                    strcpy(jenis, "Dessert");
                }
                Recipe *tempRcp = pushRecipe(inName, jenis, inIns);
                int flagIns = 1;
                // printf("%s", inIns);
                while(flagIns == 1){
                    int ingQty;
                    char ingName[50];
                    printf("Ingredient Name : ");
                    scanf("%s", &ingName);
                    printf("Quantity : ");
                    scanf("%d", &ingQty);
                    pushIngridientRecipe(tempRcp, ingName, ingQty);
                    printf("Add More Ingredient (yes / no) ? ");
                    char moreIng[5];
                    scanf("%s", moreIng);
                    if(strcmp(moreIng, "no") == 0){
                        flagIns = 0;
                        break;
                    }
                }
            }
        } else if(menu == 3){
            Kitchen();
            int menuKitchen;
            scanf("%d", &menuKitchen);
        } else if(menu == 4){
            Pantry();
            int menuPantry;
            scanf("%d", &menuPantry);
            if(menuPantry == 1){
                printIngredient();
                getchar();
                getchar();
            } else if(menuPantry == 2){
                printf("Ingredient Name : ");
                char tempIngName[30];
                scanf("%s", tempIngName);
                searchIngredient(tempIngName);
                getchar();
                getchar();
            } else if(menuPantry == 3){
                printf("Ingredient Name : ");
                char tempIngName[30];
                scanf("%s", tempIngName);
                printf("Quantity : ");
                int tempIngQty;
                scanf("%d", &tempIngQty);
                pushIngridient(tempIngName, tempIngQty);
            } else if(menuPantry == 4){
                printf("Ingredient Name : ");
                char tempIngName[30];
                scanf("%s", tempIngName);
                popIngridient(tempIngName);
            }
        } else if(menu == 5){
            Profile();
            int menuProfile;
            scanf("%d", &menuProfile);
            if (menuProfile == 1){
                preference_screen();
                int prefChange;
                scanf("%d", &prefChange);
                if(prefChange == 1){
                    strcpy(user.preference, "Kering");
                } else if(prefChange == 2){
                    strcpy(user.preference, "Basah");
                } else if(prefChange == 3){
                    strcpy(user.preference, "Minuman");
                } else if(prefChange == 4){
                    strcpy(user.preference, "Desert");
                }
            } else if(menuProfile == 2){
                settings();
                int nameChange;
                scanf("%d", &nameChange);
                if(nameChange == 1){
                    printf("New Name : ");
                    scanf("%s", user.name);
                }
            }
        } else if(menu == 6){
            globalFlag = 0;
            break;
        }
    }

    return 0;
}