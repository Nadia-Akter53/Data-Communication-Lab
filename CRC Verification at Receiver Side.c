#include <stdio.h>
#include <string.h>

#define MAX 100

char received[MAX], divisor[MAX];
int recLen, divisorLen;

void xorOperation(char temp[], int start) {
    for (int i = 0; i < divisorLen; i++) {
        temp[start + i] = (temp[start + i] == divisor[i]) ? '0' : '1';
    }
}

int verifyCRC() {
    char temp[MAX];
    strcpy(temp, received);

    for (int i = 0; i <= recLen - divisorLen; i++) {
        if (temp[i] == '1') {
            xorOperation(temp, i);
        }
    }

    // Check if remainder is all 0
    for (int i = recLen - divisorLen + 1; i < recLen; i++) {
        if (temp[i] != '0')
            return 0;  // Error detected
    }

    return 1; // No error
}

int main() {
    printf("Enter the received data stream (codeword): ");
    scanf("%s", received);
    recLen = strlen(received);

    printf("Enter the divisor (polynomial bit stream): ");
    scanf("%s", divisor);
    divisorLen = strlen(divisor);

    if (verifyCRC())
        printf("\nNo error detected. Data is correct.\n");
    else
        printf("\nError detected in received data!\n");

    return 0;
}
