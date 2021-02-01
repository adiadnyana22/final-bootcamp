struct User {
    char name[25];
    char preference[30];
} user;

struct Ingredient {
    char name[100];
    int qty;
    Ingredient *next, *prev;
} *headGlobalIng, *tailGlobalIng;

struct Recipe {
    char name[100];
    char description[255];
    char instruction[1000];
    Ingredient *headIngredient, *tailIngredient;
    Recipe *next, *prev;
} *headRecipe, *tailRecipe;