#include <stdio.h>
#include <string.h>

#define arrLen 50
#define LINE 256
#define WORD 30

char *text;

int getLine(char s[]) {
    int sum = 0;
    for (size_t i = 0; i < strlen(s); i++) {
        if (s[i] == '\n') sum++;
    }
    return sum;
}

int getWord(char w[]) {
    int sum = 0;
    for (size_t i = 0; i < strlen(w); ++i) {
        if (w[i] == '\n' || w[i] == '\t' || w[i] == ' ') {
            sum++;
        }
    }
    return sum;
}

int substring(char *str1, char *str2) {
    size_t str1Len = strlen(str1);
    size_t str2Len = strlen(str2);
    if (str2Len > str1Len) return 0;
    char strTemp[str2Len];
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    while (i < str1Len) {
        if (str1[i] == str2[j]) {
            strTemp[k] = str1[i];
            k++;
            i++;
            j++;
            continue;
        }
        i++;
        j = 0;
        k = 0;
    }
    strTemp[str2Len] = '\0';
    if (strcmp(strTemp, str2) == 0) return 1;
    return 0;
}

int similar(char *s, char *t) {
    size_t sLen = strlen(s);
    size_t tLen = strlen(t);
    if (sLen > tLen + 1) return 0;
    size_t i = 0;
    size_t j = 0;
    size_t flag = 0;
    while (i < sLen) {
        if (j == tLen) {
            flag = i++;
            break;
        }
        if (s[i] != t[j]) {
            flag = i;
            break;
        }
        i++;
        j++;
    }
    char strTemp[tLen];
    i = 0;
    for (int k = 0; k < sLen; k++) {
        if (k == flag) continue;
        strTemp[i] = s[k];
        i++;
    }
    strTemp[tLen] = '\0';
    if (strcmp(strTemp, t) == 0) return 1;
    return 0;
}

void print_lines(char *str) {
    for (int i = 0; i < LINE; ++i) {
//        char *line = text[i];
//        if (substring(line, str)) {
//            printf("%s\n", line);
//        }
    }
}

void print_similar_words(char *str) {
    for (int i = 0; i < 5; ++i) {
        char word[30] = "";
        if (similar(str, word)) {
            printf("%s\n", word);
        }
    }
}

int main() {
//    int arr[arrLen];
//    for (int i = 0; i < arrLen; ++i) {
//        scanf("%d", &arr[i]);
//    }
    int i = substring("aagabahj", "aba");
    printf("answer %d\n", i);
    int j = similar("cat", "cat");
    printf("answer %d\n", j);
    char userInput;
    scanf("%c", &userInput);
    if (userInput == 'a') print_lines("cat");
    if (userInput == 'b') print_similar_words("cat");
    return 0;
}
