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
    // str �迭 ���� ��ŭ �ݺ� 
    for (int j = 0; j < str_num; j++) {
        //�޸� �����Ҵ�
        //���α׷� ���� �߿� �޸� �Ҵ��Ѵ�.
        str[j] = (char*)malloc(strlen(text) + 1);
        strcpy_s(str[j], strlen(text)+1, text);
        //strcpy(str[j], text);
        printf("%s\n", str[j]);
        for (int i = len - 1; i >= 0; --i) {
            printf("%c", str[j][i]); // �� Ư������ ���� �Ǵ��� Ȯ���ؾ�, �޸� ���� ����?, type ?
        }
        printf("\n");
        //���α׷� ���� �߿� �޸𸮸� �����Ѵ�.
        free(str[j]);
    }
    //free(str[1]);
    return 0;
}