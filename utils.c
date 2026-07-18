#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#include "./utils.h"

char* takeWord(char wordlist[100][50]){
    char word[50] = {0};
    srand(time(NULL));

    FILE *file = fopen("wordlist.txt", "r");

    int i;
    for(i = 0; fgets(word, sizeof(word), file); i++){
        word[strcspn(word, "\r\n")] = '\0';
        strcpy(wordlist[i], word);
    }

    int random_index = (rand() % i);

    fclose(file);
    
    return wordlist[random_index];
}

void clearBuffer(void){
    int garbage;
    while ((garbage = getchar()) != '\n' && garbage != EOF);
}

void updateStr(char* word_to_guess, char* hidden_word, char character){
    size_t len = strlen(word_to_guess);
    for(int i = 0; i < len; i++){
        if(word_to_guess[i] == character) hidden_word[i] = character;
    }
}

void mainFrame(char* hidden_word,int attempts, char already_typed_chars[]){
    printf("\nRemaining Attempts:\t%d\n", MAX_ATTEMPTS - attempts);
    printf("\n%s\n", HANGMAN_STAGES[attempts]);
    printf("\nWord to guess:\t%s\n", hidden_word);
    if(already_typed_chars[0] != '\0'){
        printf("Already typed characters: ");
        displayAlreadyTypedChars(already_typed_chars);
    }
}

void clearScreen(void){
    printf("\033[2J\033[3J\033[H");
}

int validateInput(int input){
    if(!isalpha(input)) return 0;
    else return 1;
}

void insertWrongChar(char already_typed_chars[], char* character){
    int index = strlen(already_typed_chars);
    already_typed_chars[index] = *character;
}

void displayAlreadyTypedChars(char already_typed_chars[]){
    for(int i = 0; already_typed_chars[i] != '\0'; i++){
        putchar(already_typed_chars[i]);
        putchar(' ');
    }
    putchar('\n');
}