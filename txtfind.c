#include <stdio.h>
#include <string.h>

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
    bzero(s, MAX_LINE);
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

int substring(char *str1, char *str2) {
    size_t str1Len = strlen(str1);
    size_t str2Len = strlen(str2);
    if (str2Len > str1Len) return 0;
    char strTemp[str2Len];
    bzero(strTemp, str2Len);
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
    if (sLen > tLen + 1 || sLen < tLen) return 0;
    size_t i = 0;
    size_t j = 0;
    size_t flag = 99;
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

void print_lines(char *str,int lastLine) {
    char line[MAX_LINE];
    for (int i = 2; i < lastLine; i++) {
        getLine(line, i);
        if (substring(line, str)) {
            printf("%s\n", line);
        }
    }
}

void print_similar_words(char *str,int lastLine) {
    char currentWord[WORD];
    char line[MAX_LINE];
    bzero(line, MAX_LINE);
    int index = 0;
    for (int i = 2; i < lastLine; ++i) {
        index = getLine(line, i);
        for (int j = 0; j < index; ++j) {
            bzero(currentWord, WORD);
            getWord(currentWord, i, j);
            if (similar(currentWord, str)) {
                printf("%s\n", currentWord);
            }
        }
    }
}

int main() {
    bzero(arr, LINES * MAX_LINE);
    int lastLine=addToArr();
    char s[MAX_LINE];
    char searchWord[WORD];
    char option[1];
    getWord(searchWord, 0, 0);
    getLine(s, 2);
    getWord(option, 0, 1);
    if (option[0] == 'a') {
        print_lines(searchWord,lastLine);
    }
    if (option[0] == 'b') {
        print_similar_words(searchWord,lastLine);
    }
    return 0;
}
