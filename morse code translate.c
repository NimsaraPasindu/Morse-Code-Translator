#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Morse code array for letters A-Z and numbers 0-9
const char* morseCode[] = {
    ".-",   // A
    "-...", // B
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-..", // L
    "--",   // M
    "-.",   // N
    "---",  // O
    ".--.", // P
    "--.-", // Q
    ".-.",  // R
    "...",  // S
    "-",    // T
    "..-",  // U
    "...-", // V
    ".--",  // W
    "-..-", // X
    "-.--", // Y
    "--..", // Z
    "-----", // 0
    ".----", // 1
    "..---", // 2
    "...--", // 3
    "....-", // 4
    ".....", // 5
    "-....", // 6
    "--...", // 7
    "---..", // 8
    "----."  // 9
};

// Function to translate Morse code to English
char morseToChar(const char* morse) {
    for (int i = 0; i < 36; i++) {
        if (strcmp(morse, morseCode[i]) == 0) {
            if (i < 26) {
                return 'A' + i;
            } else {
                return '0' + (i - 26);
            }
        }
    }
    return '?'; // Unknown character
}

// Function to translate English to Morse code
const char* charToMorse(char ch) {
    if (isalpha(ch)) {
        return morseCode[toupper(ch) - 'A'];
    } else if (isdigit(ch)) {
        return morseCode[ch - '0' + 26];
    }
    return ""; // Empty string for unknown characters
}

int main() {
    char input[100];

    printf("Enter 'E' for English to Morse code translation or 'M' for Morse code to English translation: ");
    char choice;
    scanf(" %c", &choice);

    if (choice == 'E' || choice == 'e') {
        printf("Enter the English text (A-Z, 0-9): ");
        scanf(" %[^\n]", input);

        printf("Morse code translation: ");
        for (int i = 0; i < strlen(input); i++) {
            char ch = input[i];
            const char* morse = charToMorse(ch);
            printf("%s ", morse);
        }
        printf("\n");
    } else if (choice == 'M' || choice == 'm') {
        printf("Enter the Morse code (dots '.' and dashes '-'): ");
        scanf(" %[^\n]", input);

        printf("English translation: ");
        char* token = strtok(input, " ");
        while (token != NULL) {
            char ch = morseToChar(token);
            printf("%c", ch);
            token = strtok(NULL, " ");
        }
        printf("\n");
    } else {
        printf("Invalid choice. Please enter 'E' or 'M'.\n");
    }

    return 0;
}
