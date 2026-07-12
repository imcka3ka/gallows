#include <stdio.h>
#include <string.h>

#include "./utils.h"

char* takeWord(void){
    FILE *file = fopen("wordlist.txt", "r");

    char word[100] = {0};
    static char wordlist[100][100] = {0};

    int i;
    for(i = 0; fgets(word, sizeof(word), file); i++){
        word[strcspn(word, "\r\n")] = '\0';
        strcpy(wordlist[i], word);
    }
    
    return wordlist[9];
    

}

void clearBuffer(void){
    int garbage;
    while ((garbage = getchar()) != '\n' && garbage != EOF);
}

void updateStr(char* word_to_guess, char* hidden_word, char character){
    for(int i = 0; i < strlen(word_to_guess); i++){
        if(word_to_guess[i] == character) hidden_word[i] = character;
    }
}

void mainFrame(char* hidden_word,int attempts){
    printf("\nRemaining Attempts:\t%d\n", MAX_ATTEMPTS - attempts);
    printf("\nWord to guess:\t%s\n", hidden_word);
    
}

void clearScreen(void){
    printf("\033[2J\033[3J\033[H");
}