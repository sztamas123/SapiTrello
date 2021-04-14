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

void createCard(char* description){
    Card card;
    //User* user = NULL;
    card.description = (char*)calloc(50,sizeof(char));
    card.status = (char*)calloc(15,sizeof(char));
    card.description = description;
    card.status = "TO DO";
    card.id = 0;
    CARDS[cardCount] = card;
    cardCount++;
}

void createTable(char* tableName){
    Table table;
    table.name = (char*)calloc(50,sizeof(char));
    strcpy(table.name, tableName);
    table.users = (User*)calloc(50,sizeof(User));
    table.cards = (Card*)calloc(50,sizeof(Card));
    table.numberOfUsers = 0;
    table.numberOfCards = 0;
    TABLES[tableCount] = table;
    tableCount++;
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

void addUserToCard(char* user, char* card){
    int i;
    for (i = 0; i < userCount; ++i) {
        if(strcmp(USERS[i].username, user) == 0){
            break;
        }
    }
    for (int j = 0; j < cardCount; ++j) {
        if(strcmp(CARDS[j].description, card) == 0){
            CARDS[j].user = USERS[i];
            CARDS[j].id = 1;
            break;
        }
    }
}
//hiba
void addUserToTable(char* user, char* tablename) {
    int i;
    for (i = 0; i < userCount; ++i) {
        if (strcmp(USERS[i].username, user) == 0) {
            break;
        }
    }
    for (int j = 0; j < tableCount; ++j) {
        if (strcmp(TABLES[i].name, tablename) == 0) {
            TABLES[j].users[TABLES[j].numberOfUsers] = USERS[i];
            TABLES[j].numberOfUsers++;
            break;
        }
    }
}
//hiba
void addCardToTable(char* card, char* tablename){
    int i;
    for (i = 0; i < cardCount; ++i) {
        if (strcmp(CARDS[i].description, card) == 0) {
            break;
        }
    }
    for (int j = 0; j < tableCount; ++j) {
        if (strcmp(TABLES[i].name, tablename) == 0) {
            TABLES[j].cards[TABLES[j].numberOfCards] = CARDS[i];
            TABLES[j].numberOfCards++;
            break;
        }
    }
}

void printTable(char* tablename){
    for (int s = 0; s < tableCount; ++s) {
        if(strcmp(TABLES[s].name, tablename) == 0){
            printf("Table details: \n");
            printf("Name: %s", TABLES[s].name);
            printf("Nr. of users: %i\n", TABLES[s].numberOfUsers);
            printf("Users: \n");
            for(int i = 0;i < TABLES[s].numberOfUsers ; i++){
                printf("Name: %s ", TABLES[s].users[i].username);
                printf("Id: %i ", TABLES[s].users[i].id);
                printf(",");
            }
            printf("\n");
            printf("Number of cards on this table: %i", TABLES[s].numberOfCards);
            printf("\n");

            for (int i = 0; i < TABLES[s].numberOfCards; ++i) {
                printf("Card description: %s ", TABLES[s].cards[i].description);
                printf("\n");
                printf("Card status: %s", TABLES[s].cards[i].status);
                printf("\n");
                printf("User working on this card: %s", TABLES[s].cards[i].user.username );
            }
            printf("\n");
        }
    }
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
            CARDS[i].status = "DOING";
        }
    }
}

void changeStatusDone(char* card){
    for (int i = 0; i < cardCount; ++i) {
        if(strcmp(CARDS[i].description, card) == 0){
            CARDS[i].status = "DONE";
        }
    }
}

void changeStatusTodo(char* card){
    for (int i = 0; i < 100; ++i) {
        if(strcmp(CARDS[i].description, card) == 0){
            CARDS[i].status = "TO DO";
        }
    }
}

void printCard(char* description){
    int i;
    for (i = 0; i < cardCount; ++i) {
        if(strcmp(CARDS[i].description, description) == 0){
            printf("Card description: %s \n", CARDS[i].description);
            printf("Card status: %s \n", CARDS[i].status);
            if(CARDS[i].id == 1)
                printf("User working on this card: %s \n", CARDS[i].user.username);
            break;
        }
    }
}

void changeCardName(char* oldName, char* newName){
    for (int i = 0; i < cardCount; ++i) {
        if(strcmp(CARDS[i].description, oldName) == 0){
            CARDS[i].description = newName;
            break;
        }
    }
}

void removeCard(char* cardName, char* tableName){
    int i, z;
    for (i = 0; i < tableCount; ++i) {
        if (strcmp(TABLES[i].name, tableName) == 0) {
            break;
        }
    }
    for (int z = 0; z < TABLES[i].numberOfCards; ++z) {
        if(strcmp(TABLES[i].cards[z].description, cardName) == 0){
            break;
        }
    }
    for (int j = z; j < TABLES[i].numberOfCards - 1; ++j) {
        TABLES[i].cards[j] = TABLES[i].cards[j+1];
    }
    free(TABLES[i].cards);
    cardCount--;
}