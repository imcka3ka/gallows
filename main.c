#include <stdio.h>
#include <string.h>

#include "./utils.h"

int main(void){
    char* word_to_guess =  takeWord();
    int len = strlen(word_to_guess);
    char hidden_word[len + 1];
    memset(hidden_word, '_', len); 
    hidden_word[len] = '\0';


    char input = ' ';
    while(strcmp(word_to_guess, hidden_word)){
        printf("Type a letter: ");
        input = getchar();
        clearBuffer();

        for(int i = 0; i < len; i++){
            if(word_to_guess[i] == input){
                hidden_word[i] = input;
            }
        }
    }
    return 0;
}