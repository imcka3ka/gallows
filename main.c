#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "./utils.h"

int main(void){
    int attempts = 0;
    char wordlist[100][50] = {0};

    char* word_to_guess =  takeWord(wordlist);
    int len = strlen(word_to_guess);

    char already_typed_chars[ALPHABET] = {0};

    char hidden_word[len + 1];
    memset(hidden_word, '_', len); 
    hidden_word[len] = '\0';

    char input = ' ';
    while(1){

        mainFrame(hidden_word, attempts, already_typed_chars);

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

        if(validateInput(input)){
            input = tolower(input);
            if(strchr(already_typed_chars, input) != NULL){
                printf("You already typed this character...\n");
                sleep(3);
                clearScreen();
                continue;
            }
        } else {
            printf("Invalid character. Try again\n");
            clearScreen();
            continue;
        }

        if(strchr(word_to_guess, input) == NULL){
            printf("The character isn't in the word\n");
            attempts++;
            insertWrongChar(already_typed_chars, &input);
            sleep(3);
            clearScreen();

            continue;
        } else {
            updateStr(word_to_guess, hidden_word, input);
        }

        clearScreen();
    }
    return 0;
}