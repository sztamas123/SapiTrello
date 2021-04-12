//
// Created by tamas on 09.04.2021.
//
#include <string.h>
#include "functions.h"

User USERS[100];
Card CARDS[100];
Table TABLES[25];
int userCount = 0;
int cardCount = 0;
int tableCount = 0;

User* createUser(char* username){
    User* user = (User*)calloc(1,sizeof(User));
    user->username = (char*)calloc(50,sizeof(char));
    srand(time(0));
    USERS[userCount].username = username;
    USERS[userCount].id = rand() % 100;
    userCount++;
}

void printUser(char* username){
    for (int i = 0; i < 100; ++i) {
        if(strcmp(USERS[i].username, username) == 0){
            printf("Name: %s ", USERS[i].username);
            printf("\n");
            printf("ID: %i ", USERS[i].id);
            printf("\n");
            break;
        }
        return;
    }

}

Table* createTable(char* tableName){
    Table* table = (Table*)calloc(1,sizeof(Table));
    table->name = (char*)calloc(50,sizeof(char));
    table->name = tableName;
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


Card* createCard(char* description){
    Card* card = (Card*)calloc(1,sizeof(Card));
    card->user = (User*)calloc(1,sizeof(User));
    card->description = (char*)calloc(50,sizeof(char));
    card->status = (char*)calloc(15,sizeof(char));
    card->id = (int*)calloc(100,sizeof(int));
    CARDS[cardCount].description = description;
    CARDS[cardCount].status = "TO DO";
    cardCount++;
}

void changeStatusDoing(Card* card){
    card->status = "DOING";
}

void changeStatusDone(Card* card){
    card->status = "DONE";
}

void changeStatusTodo(Card* card){
    card->status = "TO DO";
}

void getCardStatus(Card* card){
    printf("Status of the card: %s", card->status);
    printf("\n");
}


void addUserToCard(char* user, char* card){
    User* tempUser;
    for (int i = 0; i < 100; ++i) {
        if(strcmp(USERS[i].username, user) == 0){
            tempUser->username = USERS[i].username;
            tempUser->id = USERS[i].id;
        }
    }
    for (int i = 0; i < 100; ++i) {
        if(strcmp(CARDS[i].description, card) == 0 && CARDS[i].id == 0){
            CARDS[i].user->username = tempUser->username;
            CARDS[i].user->id = tempUser->id;
        }
    }
}

void printCard(char* description){
    for (int i = 0; i < 100; ++i) {
        if(strcmp(CARDS[i].description, description) == 0){
            printf("Card description: %s \n", CARDS[i].description);
            printf("Card status: %s \n", CARDS[i].status);
            printf("User working on this card: %s \n", CARDS[i].user->username);
            break;
        }
        return;
    }
}

