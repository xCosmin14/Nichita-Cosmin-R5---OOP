#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main() {
    FILE* fptr;
    fptr = fopen("TextFile1.txt", "r");

    char linie[16]; 
    long long suma_totala = 0; 


    while (fgets(linie, 16, fptr)) {
        int lungime = strlen(linie);
        long long numar_curent = 0;
        int putere = 1;

        for (int i = lungime - 1; i >= 0; i--) 
            if (linie[i] >= '0' && linie[i] <= '9') {
                int cifra = linie[i] - '0';

                numar_curent += cifra*putere;
                putere *= 10;
            }

        suma_totala += numar_curent;
    }
    
    fclose(fptr);
    printf("Suma numerelor din fisier este: %lld\n", suma_totala);
}
