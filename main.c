#include <stdio.h>
#include <string.h>

int main(void){
    char word_to_guess[] =  "russia";
    int len = strlen(word_to_guess);
    char hidden_word[len + 1];
    memset(hidden_word, '_', len); 
    hidden_word[len] = '\0';
    printf("%s\n%s\n", word_to_guess, hidden_word);
    return 0;
}