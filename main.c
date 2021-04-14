#include <stdio.h>
#include "functions.h"
int main() {
    int choice;
    srand(time(0));
    setbuf(stdout, 0);
    init();

    //Gyorsabb teszteles celjabol itthagyom ezeket

    createUser("User1");
    createUser("User2");
    createUser("User3");
    createTable("T");
    createCard("C++");
    createCard("Pascal");
    createCard("Java");
    addUserToCard("User1", "C++");
    addUserToCard("User2", "Java");
    addCardToTable("C++", "T");
    addCardToTable("Pascal", "T");
    addCardToTable("Java", "T");
    addUserToTable("User1", "T");
    addUserToTable("User2", "T");
    addUserToTable("User3", "T");
    changeCardName("C++", "C");



    while(1){
        system("clear");
        printf("Press 0. to exit.\n");
        printf("Press 1. to create a user.\n");
        printf("Press 2. to create a card.\n");
        printf("Press 3. to create a table.\n");
        printf("Press 4. to see a table.\n");
        printf("Press 5. to see a card.\n");
        printf("Press 6. to see details about an user.\n");
        printf("Press 7. to add user to a card.\n");
        printf("Press 8. to add user to a table.\n");
        printf("Press 9. to add card to a table.\n");
        printf("Press 10. to change card status to doing.\n");
        printf("Press 11. to change card status to done.\n");
        printf("Press 12. to change card status to to do.\n");
        printf("Press 13. to get current status of a card.\n");
        printf("Press 14. to delete a card from table.\n");
        printf("Press 15. to change card name.\n");



        scanf("%d", &choice);

        switch (choice) {
            case 0:
                exit(1);
                break;
            case 1:
                printf("Enter username.\n");
                char username[50];
                scanf("%s", username);
                createUser(username);
                break;
            case 2:
                printf("Enter card name.\n");
                char cname[50];
                scanf("%s", cname);
                createCard(cname);
                break;
            case 3:
                printf("Enter table name.\n");
                char table[50];
                scanf("%s", table);
                createTable(table);
                break;
            case 4:
                printf("Enter table name.\n");
                char t1[50];
                scanf("%s", t1);
                printTable(t1);
                break;
            case 5:
                printf("Enter the description of the card you are looking for.\n");
                char description[50];
                scanf("%s", description);
                printCard(description);
                break;
            case 6:
                printf("Enter the username u are looking for.\n");
                char unam[50];
                scanf("%s", unam);
                printUser(unam);
                break;
            case 7:
                printf("Enter the username of the user that you want to add.\n");
                char u1[50];
                scanf("%s", u1);
                printf("Enter card name.\n");
                char c1[50];
                scanf("%s", c1);
                addUserToCard(u1,c1);
                break;
            case 8:
                printf("Enter username of the user that you want to add.\n");
                char u2[50];
                scanf("%s", u2);
                printf("Enter table name.\n");
                char t2[50];
                scanf("%s", t2);
                addUserToTable(u2, t2);
                break;
            case 9:
                printf("Enter name of the card that you want to add.\n");
                char c2[50];
                scanf("%s", c2);
                printf("Enter table name.\n");
                char t3[50];
                scanf("%s", t3);
                addUserToTable(c2, t3);
                break;
            case 10:
                printf("Enter card name that you want to change to 'DOING'.\n");
                char cna[25];
                scanf("%s", cna);
                printf("Enter name of the table containing the card.\n");
                char t4[50];
                scanf("%s", t4);
                changeStatusDoing(cna, t4);
                break;
            case 11:
                printf("Enter card name that you want to change to 'DONE'.\n");
                char cnam[25];
                scanf("%s", cnam);
                printf("Enter name of the table containing the card.\n");
                char t5[25];
                scanf("%s", t5);
                changeStatusDone(cnam, t5);
                break;
            case 12:
                printf("Enter card name that you want to change to 'TO DO'.\n");
                char cnm[25];
                scanf("%s", cnm);
                printf("Enter name of the table containing the card.\n");
                char t6[25];
                scanf("%s", t6);
                changeStatusTodo(cnm, t6);
                break;
            case 13:
                printf("Enter card name.\n");
                char cn2[50];
                scanf("%s", cn2);
                getCardStatus(cn2);
                break;
            case 14:
                printf("Enter card name that you want to delete.\n");
                char cn3[50];
                scanf("%s", cn3);
                printf("Enter the name of the table containing the card.\n");
                char tn[50];
                scanf("%s", tn);
                removeCard(cn3, tn);
                break;
            case 15:
                printf("Enter card name that you want to change.\n");
                char cn4[50];
                scanf("%s", cn4);
                printf("Enter new name.\n");
                char nn[50];
                scanf("%s", nn);
                changeCardName(cn4, nn);
                break;
            default:
                printf("\nInvalid Choice :-(\n");
                system("pause");


        }
    }


    return 0;
}
