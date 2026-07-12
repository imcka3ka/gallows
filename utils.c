#include <stdio.h>
#include <string.h>

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

char* contains(char* str, char character){
    
}