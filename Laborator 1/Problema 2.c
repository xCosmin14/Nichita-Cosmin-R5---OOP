#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int my_strcmp(char a[], char b[]) {
    int i = 0;

    while (a[i] && b[i]) {
        if (a[i] != b[i]) return a[i] - b[i];
        i++;
    }

    return a[i] - b[i];
}

int main() {
    char text[255];
    char* words[128];
    int count = 0;

    scanf("%[^\n]", text);
    char* token = strtok(text, " ");

    while (token != NULL) {
        words[count++] = token;
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < count - 1; i++)
        for (int j = i + 1; j < count; j++) {
            int len1 = strlen(words[i]);
            int len2 = strlen(words[j]);

            if (len1 < len2 || (len1 == len2 && my_strcmp(words[i], words[j]) > 0))
            {
                char* temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    

    for (int i = 0; i < count; i++)    
        printf("%s\n", words[i]);
}