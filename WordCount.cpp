#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *file;
    int character_count = 0, word_count = 0;
    char ch;

    if (argc != 3) { // 检查参数数量是否正确
        printf("Usage: WordCount [-c|-w] filename\n");
        return 1;
    }

    if ((strcmp(argv[1], "-c") == 0) || (strcmp(argv[1], "-w") == 0)) {
        file = fopen(argv[2], "r"); // 打开文件

        if (!file) {
            perror("Error opening the file.\n");
            return 1;
        }

        while ((ch = fgetc(file)) != EOF) {
            if (ch == ' ' || ch == '\t' || ch == '\n') {
                if (word_count > 0)
                    word_count++;
            } else if (ch != ',' && ch != '#') {
                character_count++;
            }
        }

        fclose(file);

        if (strcmp(argv[1], "-c") == 0) {
            printf("Character count: %d\n", character_count);
        } else {
            printf("Word count: %d\n", word_count);
        }
    } else {
        printf("Invalid parameter. Use '-c' or '-w'.\n");
        return 1;
    }

    return 0;
}
