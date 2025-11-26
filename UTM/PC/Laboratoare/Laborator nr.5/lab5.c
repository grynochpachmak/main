// November 2025
// Juncu Marin MN-251
// Laborator nr.5: Utilizarea sirurilor de caractere

#include <stdio.h>
#include <string.h>

void sort(char str[]) {
    int n = strlen(str);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

void deleteSpaces(char str[]) {
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            str[j] = str[i];
            j++;
        }
    }

    str[j] = '\0';
}

int main(void) {

    while (1) {
        int select;

        printf("\n\nMeniu:\n");
        printf("1 - Sortarea sirului\n");
        printf("2 - Eliminarea spațiilor\n");
        printf("0 - Iesire\n");
        printf("\nAlegeti optiunea: ");

        scanf("%d", &select);
        getchar();

        if (select == 1) {
            char str[101];

            printf("Introduceti un sir de caractere: ");
            fgets(str, sizeof(str), stdin);

            str[strcspn(str, "\n")] = '\0';

            printf("Sirul introdus: %s\n", str);

            sort(str);

            printf("Sirul sortat: %s\n", str);
        } 
        
        else if (select == 2) {
            char str[101];

            printf("Introduceti un sir de caractere: ");
            fgets(str, sizeof(str), stdin);

            str[strcspn(str, "\n")] = '\0';

            printf("Sirul introdus: %s\n", str);

            deleteSpaces(str);

            printf("Sirul fara spatii: %s\n", str);
        }
        
        else if (select == 0) {
            printf("Program terminat.\n");
            break;
        }
        
        else {
            printf("Optiune invalida. Incercati din nou.\n");
        }
    }

    return 0;
}
