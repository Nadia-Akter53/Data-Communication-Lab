#include <stdio.h>
#include <string.h>

int a_length(char array[]) {
    int count = 0;
    while (array[count] != '\0') {
        count++;
    }
    return count;
}

int main() {
    char data[100];
    printf("This is a program for even parity checking.\n");
    printf("Enter the data: \n");
    scanf("%s", data);

    int length = a_length(data);
    int count = 0;

    for (int i = 0; i < length; i++) {
        if (data[i] == '1') {
            count++;
        }
    }

    int c = length + 1;

    for (int i = c, j = c - 1; i > 0; i--, j--) {
        data[i] = data[j];
    }

    if (count % 2 == 0) {
        data[0] = '1';
        printf("After adding '1' at the front of the data:\n");
        printf("%s\n", data);
    } else {
        data[0] = '0';
        printf("After adding '0' at the front of the data:\n");
        printf("%s\n", data);
    }

    return 0;
}
