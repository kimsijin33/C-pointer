#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
    char text[4] = "ABCD";
    char* str[100];
    int i;
    int len = 0;
    int str_num = 0;

    //str[1] = (char*)malloc(strlen(text)+1);

    printf("%s\n", text);
    //printf("%s\n", str[1]);
    printf("%lu\n", strlen(text));

    len = strlen(text);
    printf("%ld\n", sizeof(str));
    printf("%ld\n", sizeof(str[0]));
    printf("%ld\n", sizeof(str) / sizeof(str[0]));
    str_num = sizeof(str) / sizeof(str[0]);
    printf("%d\n", str_num);
    // str 배열 숫자 만큼 반복 
    for (int j = 0; j < str_num; j++) {
        //메모리 동적할당
        //프로그램 실행 중에 메모리 할당한다.
        str[j] = (char*)malloc(strlen(text) + 1);
        strcpy_s(str[j], strlen(text)+1, text);
        //strcpy(str[j], text);
        printf("%s\n", str[j]);
        for (int i = len - 1; i >= 0; --i) {
            printf("%c", str[j][i]); // 왜 특수문자 삽입 되는지 확인해야, 메모리 등의 문제?, type ?
        }
        printf("\n");
        //프로그램 실행 중에 메모리를 해제한다.
        free(str[j]);
    }
    //free(str[1]);
    return 0;
}