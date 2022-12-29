#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAX_LINE 256
#define LINES 250
#define WORD 30
char arr[LINES][MAX_LINE];

int addToArr() {
    int i = 0;
    int j = 0;
    int c;
    while ((c = fgetc(stdin)) != EOF) {
        if (c != '\n') {
            arr[i][j] = (char) c;
            j++;
        } else {
            i++;
            j = 0;
        }
    }
    return i;
}

int getLine(char s[], int i) {
    memset(s, 0, MAX_LINE);
    int j = 0;
    while (arr[i][j] != '\0') {
        s[j] = arr[i][j];
        j++;
    }
    return j;
}

int getWord(char w[], int line, int numWord) {
    int j = 0;
    int s = 0;
    if (numWord != 0) {
        while (j < MAX_LINE) {
            if (arr[line][j] != '\0' && arr[line][j] != '\n' && arr[line][j] != ' ' && arr[line][j] != '\t') {
                j++;
            } else {
                j++;
                s++;
            }
            if (s == numWord) {
                break;
            }
        }
    }
    s = 0;
    while (arr[line][j] != '\0' && arr[line][j] != '\n' && arr[line][j] != ' ' && arr[line][j] != '\t') {
        w[s] = arr[line][j];
        j++;
        s++;
    }
    return s;
}

size_t checkLen(const char *str) {
    int ptr = 0;
    size_t strLen = 0;
    while (str[ptr] != '\0') {
        strLen++;
        ptr++;
    }
    return strLen;
}

int substring(char *str1, char *str2) {
    size_t str1Len = checkLen(str1);
    size_t str2Len = checkLen(str2);
    if (str2Len > str1Len) return 0;
    for (size_t i = 0; i < str1Len; i++) {
        if (str1[i] == str2[0]) {
            if (strncmp(str1 + i, str2, str2Len) == 0) return 1;
        }
    }
    return 0;
}


int similar(char *s, char *t) {
    size_t sLen = strlen(s);
    size_t tLen = strlen(t);
    if (sLen > tLen + 1 || sLen < tLen) return 0;
    size_t i = 0;
    size_t j = 0;
    size_t flag = 99;
    while (i < sLen) {
        if (j == tLen) {
            flag = i;
            break;
        }
        if (s[i] != t[j]) {
            flag = i;
            break;
        }
        i++;
        j++;
    }
    if (flag == 99) {
        return 1;
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

void print_lines(char *str, int lastLine) {
    char *line = (char *) malloc(MAX_LINE * sizeof(char));
    memset(line, 0, MAX_LINE);
    for (int i = 2; i < lastLine; i++) {
        getLine(line, i);
        if (substring(line, str)) {
            printf("%s\n", line);
        }
    }
    free(line);
}

void print_similar_words(char *str, int lastLine) {
    char currentWord[WORD];
    char line[MAX_LINE];
    memset(line, 0, MAX_LINE);
    int index;
    for (int i = 2; i < lastLine; i++) {
        index = getLine(line, i);
        for (int j = 0; j < index; j++) {
            bzero(currentWord, WORD);
            getWord(currentWord, i, j);
            if (similar(currentWord, str)) {
                printf("%s\n", currentWord);
            }
        }
    }
}

int main() {
    memset(arr, 0, sizeof arr);
    int lastLine = addToArr();
    char s[MAX_LINE];
    char *searchWord=(char *) malloc(WORD * sizeof(char));
    memset(searchWord, 0, WORD);
    char *option=(char *) malloc(WORD * sizeof(char));
    getWord(searchWord, 0, 0);
    getLine(s, 2);
    getWord(option, 0, 1);
    if (option[0] == 'a') {
        print_lines(searchWord, lastLine);
    }
    if (option[0] == 'b') {
        print_similar_words(searchWord, lastLine);
    }
    free(searchWord);
    free(option);
    return 0;
}
