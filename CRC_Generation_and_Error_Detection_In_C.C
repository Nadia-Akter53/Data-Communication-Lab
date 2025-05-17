#include <stdio.h>
#include <string.h>

#define MAX 100

char data[MAX], divisor[MAX], temp[MAX], remainder[MAX], codeword[MAX];
int dataLen, divisorLen;

void xorOperation(int start) {
    for (int i = 0; i < divisorLen; i++) {
        temp[start + i] = (temp[start + i] == divisor[i]) ? '0' : '1';
    }
}

void crcGenerate() {
    strcpy(temp, data);
    // Append zeros
    for (int i = 0; i < divisorLen - 1; i++) {
        temp[dataLen + i] = '0';
    }
    temp[dataLen + divisorLen - 1] = '\0';

    // Perform division
    for (int i = 0; i <= dataLen - 1; i++) {
        if (temp[i] == '1') {
            xorOperation(i);
        }
    }

    // Extract remainder
    for (int i = 0; i < divisorLen - 1; i++) {
        remainder[i] = temp[dataLen + i];
    }
    remainder[divisorLen - 1] = '\0';

    // Generate codeword
    strcpy(codeword, data);
    strcat(codeword, remainder);
}

int checkReceived(char received[]) {
    char checkTemp[MAX];
    strcpy(checkTemp, received);

    for (int i = 0; i <= strlen(received) - divisorLen; i++) {
        if (checkTemp[i] == '1') {
            for (int j = 0; j < divisorLen; j++) {
                checkTemp[i + j] = (checkTemp[i + j] == divisor[j]) ? '0' : '1';
            }
        }
    }

    // Check if remainder is all 0
    for (int i = strlen(received) - divisorLen + 1; i < strlen(received); i++) {
        if (checkTemp[i] != '0')
            return 0;  // Error detected
    }

    return 1; // No error
}

int main() {
    char received[MAX];

    printf("Enter the data bits: ");
    scanf("%s", data);
    dataLen = strlen(data);

    printf("Enter the divisor (polynomial): ");
    scanf("%s", divisor);
    divisorLen = strlen(divisor);

    crcGenerate();

    printf("\nCRC Remainder: %s", remainder);
    printf("\nTransmitted Codeword: %s\n", codeword);

    printf("\nEnter the received codeword: ");
    scanf("%s", received);

    if (checkReceived(received))
        printf("\nNo error detected. Transmission successful.\n");
    else
        printf("\nError detected in received codeword!\n");

    return 0;
}
