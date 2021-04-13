//
// Created by tamas on 09.04.2021.
//
#include <string.h>
#include "functions.h"

User* USERS;
Card* CARDS;
Table* TABLES;
int userCount = 0;
int cardCount = 0;
int tableCount = 0;

void init(){
    USERS = (User*) calloc(100,sizeof(User));
    CARDS = (Card*) calloc(100,sizeof(Card));
    TABLES = (Table*) calloc(100,sizeof(Table));
}

void createUser(char* uname){
    User user;
    user.username = (char*)calloc(50,sizeof(char));
    strcpy(user.username,uname);
    user.id = userCount + 1;
    USERS[userCount] = user;
    userCount++;
}

Card* createCard(char* description){
    Card* card = (Card*)calloc(1,sizeof(Card));
    card->user = (User*)calloc(1,sizeof(User));
    card->description = (char*)calloc(50,sizeof(char));
    card->status = (char*)calloc(15,sizeof(char));
    CARDS[cardCount].description = description;
    CARDS[cardCount].status = "TO DO";
    cardCount++;
}

void printUser(char* unam){
    for (int i = 0; i < userCount; ++i) {
        if(strcmp(USERS[i].username, unam) == 0){
            printf("Name: %s ", USERS[i].username);
            printf("\n");
            printf("ID: %i ", USERS[i].id);
            printf("\n");
            break;
        }
    }

}

Table* createTable(char* tableName){
    Table* table = (Table*)calloc(1,sizeof(Table));
    table->name = (char*)calloc(50,sizeof(char));
    strcpy(table->name, tableName);
    table->users = (User*)calloc(50,sizeof(User));
    table->cards = (Card*)calloc(50,sizeof(Card));
    table->numberOfUsers = (int*)calloc(100,sizeof(int));
    table->numberOfCards = (int*)calloc(100,sizeof(int));
    table->numberOfUsers = 0;
    table->numberOfCards = 0;
}

void addUserToTable(User* user, Table* table){
    table->users[table->numberOfUsers].username = user->username;
    table->users[table->numberOfUsers].id = user->id;
    table->numberOfUsers++;
}

void addCardToTable(Card* card, Table* table){
    table->cards[table->numberOfCards].description = card->description;
    table->cards[table->numberOfCards].status = card->status;
    table->cards[table->numberOfCards].id = card->id;
    table->numberOfCards++;
}

void printTable(Table* table){
    printf("Table details: ");
    printf("\n");
    printf("Name: %s", table->name);
    printf("\n");
    printf("Nr. of users: %i", table->numberOfUsers);
    printf("\n");
    printf("Users: ");
    printf("\n");
    for(int i = 0;i < table->numberOfUsers ; i++){
        printf("Name: %s ", table->users[i].username);
        printf("Id: %i ", table->users[i].id);
        printf(",");
    }


    printf("\n");
    printf("Number of cards on this table: %i", table->numberOfCards);
    printf("\n");

    for (int i = 0; i < table->numberOfCards; ++i) {
        printf("Card description: %s ", table->cards[i].description);
        printf("\n");
        printf("Card status: %s", table->cards[i].status);
        printf("\n");
        // printf("User working on this card: %s", table->cards[i].user->username ); nem megy ez a sor

    }
    printf("\n");

}


void getCardStatus(char* card){
    for (int i = 0; i < cardCount; ++i) {
        if(strcmp(CARDS[i].description, card) == 0){
            printf("Status of the card: %s/n", CARDS[i].status);
        }
    }
}
void changeStatusDoing(char* card){
    for (int i = 0; i < cardCount; ++i) {
        if(strcmp(CARDS[i].description, card) == 0){
            strcpy(CARDS[i].status, "DOING");
            //CARDS[i].status = "DOING";
        }
    }
}

void changeStatusDone(char* card){
    for (int i = 0; i < cardCount; ++i) {
        if(strcmp(CARDS[i].description, card) == 0){
            strcpy(CARDS[i].status, "DONE");
        }
    }
}

void changeStatusTodo(char* card){
    for (int i = 0; i < 100; ++i) {
        if(strcmp(CARDS[i].description, card) == 0){
            strcpy(CARDS[i].status, "TO DO");
        }
    }
}

void addUserToCard(char* user, char* card){
    User tempUser;
    for (int i = 0; i < userCount; ++i) {
        if(strcmp(USERS[i].username, user) == 0){
            strcpy(tempUser.username, USERS[i].username);
            tempUser.id = USERS[i].id;
        }
    }
    for (int i = 0; i < cardCount; ++i) {
        if(strcmp(CARDS[i].description, card) == 0){
            strcpy(CARDS[i].user->username, tempUser.username);
            CARDS[i].user->id = tempUser.id;
        }
    }
}


void printCard(char* description){
    int i;
    for (i = 0; i < cardCount; ++i) {
        if(strcmp(CARDS[i].description, description) == 0){
            printf("Card description: %s \n", CARDS[i].description);
            printf("Card status: %s \n", CARDS[i].status);
            //printf("User working on this card: %s \n", CARDS[i].user->username); //ha ures sigsegv
            break;
        }
    }
}
