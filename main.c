#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void file_error(const char *message) {
    fprintf(stderr, "erreur fichier %s\n", message);
    exit(EXIT_FAILURE);
}

void choice_error(const char *message) {
    fprintf(stderr, "mauvaise insertion %s\n", message);
}

int main() {
    int choix;
    FILE *file;

    printf("Le primeur\n");
    printf("que faisons nous aujourd'hui\n");
    printf("1: inserer un nouveau fruit a notre catalogue.\n");
    printf("2: montrer le catalogue.\n");
    printf("votre choix: ");
    scanf("%d", &choix);

    file = fopen("database.txt", "a");
    if (file == NULL) {
        file_error("fichier introuvable.");
        return 1;
    }

    if (choix == 1) {
        int id;
        char nom[50];
        char couleur[50];

        printf("voulez vous rentrer un nouveau fruit?\n");
        printf("L'id du fruit: ");
        scanf("%d", &id);

        printf("quel est le nom de votre fruit? ");
        scanf("%s", nom);

        printf("quel est sa couleur? ");
        scanf("%s", couleur);

        fprintf(file, "%d %s %s\n", id, nom, couleur);

        fclose(file);
        return 0;
    } else if (choix == 2) {
        file = fopen("database.txt", "r");
        if (file == NULL) {
            printf("fichier introuvable");
            return 1;
        }
        printf("catalogue des fruits:\n");
        char ligne[100];
        while (fgets(ligne, sizeof(ligne), file) != NULL) {
            printf("%s", ligne);
        }
        fclose(file);
    } else {
        choice_error("choix non compris dans nos possibilites veuillez relancer le program et rentrer un choix valide.");
    }

    return 0;
}