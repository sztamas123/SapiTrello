#include <stdio.h>
#include "functions.h"
int main() {
    User* u = createUser("Tamas");
    User* u2 = createUser("Jon");
    Table* t = createTable("First");
    addUserToTable(u, t);
    addUserToTable(u2, t);
    Card* card = createCard("Card1");
    Card* card2 = createCard("Cardd2");
    printf("\n");
    addUserToCard(u2, card);
    addUserToCard(u, card2);

    addCardToTable(card, t);
    addCardToTable(card2, t);
    changeStatusDoing(card);
    changeStatusDone(card2);
    printTable(t);
    printf("\n");
    printCard(card);







    return 0;
}
