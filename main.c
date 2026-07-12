#include <stdio.h>
#include <string.h>

#include "./utils.h"

int main(void){
    int attempts = 0;
    char wordlist[100][50] = {0};

    char* word_to_guess =  takeWord(wordlist);
    int len = strlen(word_to_guess);

    char hidden_word[len + 1];
    memset(hidden_word, '_', len); 
    hidden_word[len] = '\0';

    char input = ' ';
    while(1){

        mainFrame(hidden_word, attempts);

        if(strcmp(hidden_word, word_to_guess) == 0){
            printf("\nCongratz!!. You won.\n");
            break;
        }

        if(attempts == MAX_ATTEMPTS){
            printf("\nI'm sorry, you lost\n");
            break;
        }

        printf("Type a letter: ");
        input = getchar();
        clearBuffer();

        if(strchr(word_to_guess, input) == NULL){
            printf("The character isn't in the word\n");
            attempts++;
            clearScreen();
            continue;
        } else {
            updateStr(word_to_guess, hidden_word, input);
        }

        clearScreen();
    }
    return 0;
}