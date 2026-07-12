#define MAX_ATTEMPTS 6

char* takeWord(void);
void clearBuffer(void);
void updateStr(char* word_to_guess, char* hidden_word, char character);
void mainFrame(char* hidden_word,int attempts);
void clearScreen(void);