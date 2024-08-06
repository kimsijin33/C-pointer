#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    //char text[5] = "ABCD";
    std::string text = "ABCD";
    //char* str[100];
    std::vector<std::string> str(100);
    int len = strlen(text);
    int str_num = sizeof(str) / sizeof(str[0]);

    /*printf("%s\n", text);
    printf("%lu\n", strlen(text));
    printf("%ld\n", sizeof(str));
    printf("%ld\n", sizeof(str[0]));
    printf("%ld\n", sizeof(str) / sizeof(str[0]));
    printf("%d\n", str_num);*/

    std::cout << text << "\n";
    std::cout << text.length() << "\n";
    std::cout << sizeof(str)) << "\n";
    std::cout << sizeof(str[0])) << "\n";
    std::cout << sizeof(str) / sizeof(str[0])) << "\n";
    std::cout << str_num << "\n";

    for (int j = 0; j < str_num; j++) {
        str[j] = (char*)malloc(len + 1);
        strcpy(str[j], text);
        printf("%s\n", str[j]);
        for (int i = len - 1; i >= 0; --i) {
            printf("%c", str[j][i]);
        }
        printf("\n");
        free(str[j]);
    }

    return 0;
}
