//// TODO: Reassemble
// November 2025
// Juncu Marin MN-251
// Laborator nr.5: Utilizarea sirurilor de caractere

#include <stdio.h>
#include <string.h>

// Sarcina 40: Scrieți un program C pentru a sorta cuvintele în ordine alfabetică, dintr-un șir dat.
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

// Sarcina 39: Scrieți un program C pentru a elimina toate spațiile goale suplimentare din șirul dat.
//// TODO: FIX
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

// Sarcina 38: Scrieți un program C pentru a tăia atât caracterele de spații albe de început, cât și cele de sfârșit din șirul dat.
void trim(char str[]) {
    int start = 0;
    int end;
    int j = 0;

    while (str[start] == ' ') {
        start++;
    }

    end = strlen(str);
    while (end > start && str[end - 1] == ' ') {
        end--;
    }

    for (int i = start; i < end; i++) {
        str[j] = str[i];
        j++;
    }

    str[j] = '\0';
}

// Sarcina 9: Scrieți un program C pentru a număra numărul total de vocale dintr-un șir.
int countVowels(char str[]) {
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || 
            (str[i] >= 'A' && str[i] <= 'Z')) 
        {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
                str[i] == 'o' || str[i] == 'u' ||
                str[i] == 'A' || str[i] == 'E' || str[i] == 'I' ||
                str[i] == 'O' || str[i] == 'U')
            {
                count++;
            }
        }
    }

    return count;
}

// Sarcina 10: Scrieți un program C pentru a număra numărul total de consoane dintr-un șir.
//// TODO: Restructure
int countConsonants(char str[]) {
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (!(c == 'a' || c == 'e' || c == 'i' ||
                  c == 'o' || c == 'u' ||
                  c == 'A' || c == 'E' || c == 'I' ||
                  c == 'O' || c == 'U'))
            {
                count++;
            }
        }
    }

    return count;
}

// Sarcina 11: Scrieți un program C pentru a număra numărul total de cuvinte dintr-un șir.
int countWords(char str[]) {
    int count = 0;
    int inWord = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            if (inWord == 0) {
                count++;
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
    }

    return count;
}

// Sarcina 6: Scrieți un program C pentru a converti dintr-un șir, literele majuscule în litere mici.
void toLower(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}

// Sarcina 5: Scrieți un program C pentru a converti dintr-un șir, literele minuscule în majuscule.
void toUpper(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
}

// Sarcina 24: Scrieți un program C pentru a elimina toate aparițiile unui caracter din șir.
void deleteChosen(char chosen, char str[]) {
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != chosen) {
            str[j] = str[i];
            j++;
        }
    }

    str[j] = '\0';
}

// Sarcina 25: Scrieți un program C pentru a elimina toate caracterele ce se repetă dintr-un șir dat.
void deleteNonUnic(char str[]) {
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        int count = 0;

        for (int k = 0; str[k] != '\0'; k++) {
            if (str[k] == str[i]) {
                count++;
            }
        }

        if (count == 1) {
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
        printf("1 - Sortarea alfabetica a sirului\n");
        printf("2 - Eliminarea spațiilor\n");
        printf("3 - Eliminarea spațiilor de la inceput si sfarsit\n");
        printf("4 - Cantitatea vocalelor\n");
        printf("5 - Cantitatea consoanelor\n");
        printf("6 - Cantitatea cuvintelor\n");
        printf("7 - Transformarea in minuscule\n");
        printf("8 - Transformarea in majuscule\n");
        printf("9 - Stergerea unui caracter\n");
        printf("10 - Stergerea caracterelor ce se repeta\n");
        printf("0 - Iesire\n");
        printf("\nAlegeti optiunea: ");

        scanf("%d", &select);
        getchar();

        if (select == 0) {
            printf("Program terminat.\n");
            break;
        }

        char str[101];

        printf("Introduceti un sir de caractere: ");
        fgets(str, sizeof(str), stdin);

        str[strcspn(str, "\n")] = '\0';

        printf("Sirul introdus: %s\n", str);

        if (select == 1) {
            sort(str);
            printf("Sirul sortat: %s\n", str);
        } 
        
        else if (select == 2) {
            deleteSpaces(str);
            printf("Sirul fara spatii: %s\n", str);
        }

        else if (select == 3) {
            trim(str);
            printf("Sirul fara spatii la inceput si sfarsit: %s\n", str);
        }

        else if (select == 4) {
            int vowels = countVowels(str);
            printf("Numarul total de vocale: %d\n", vowels);
        }

        else if (select == 5) {
            int consonants = countConsonants(str);
            printf("Numarul total de consoane: %d\n", consonants);
        }

        else if (select == 6) {
            int words = countWords(str);
            printf("Numarul total de cuvinte: %d\n", words);
        }

        else if (select == 7) {
            toLower(str);
            printf("Sirul nou: %s\n", str);
        }

        else if (select == 8) {
            toUpper(str);
            printf("Sirul nou: %s\n", str);
        }

        else if (select == 9) {
            char chosen;
            printf("Introduceti caracterul spre eliminare: ");
            scanf("%c", &chosen);
            deleteChosen(chosen, str);
            printf("Sirul cu caracterul '%c' eliminat: %s\n", chosen, str);
        }

        else if (select == 10) {
            deleteNonUnic(str);
            printf("Sirul nou: %s\n", str);
        }
        
        else {
            printf("Optiune invalida. Incercati din nou.\n");
        }
    }

    return 0;
}
