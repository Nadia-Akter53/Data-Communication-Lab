#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ToDec(char bin[]);

int main()
{
    char ip[100];
    printf("Enter binary IP ");
    scanf(" %[^\n]", ip);
    char ip_copy[100];
    strcpy(ip_copy, ip); 
    char *token = strtok(ip, ".");
    int first_oc = ToDec(token); 
   
   
   
    if(first_oc >= 0 && first_oc <= 127)
    {
        printf("Class A\n");
    }
    else if(first_oc >= 128 && first_oc <= 191)
    {
        printf("Class B\n");
    }
    else if(first_oc >= 192 && first_oc <= 223)
    {
        printf("Class C\n");
    }
    else if(first_oc >= 224 && first_oc <= 239)
    {
        printf("Class D (Multicast)\n");
    }
    else if(first_oc >= 240 && first_oc <= 255)
    {
        printf("Class E (Reserved)\n");
    }

    
    token = strtok(ip_copy, ".");
    int count = 0;
    int decimal_parts[4];

    while(token != NULL && count < 4)
    {
        decimal_parts[count++] = ToDec(token);
        token = strtok(NULL, ".");
    }

    if (count == 4)
    {
        printf("Decimal IP: %d.%d.%d.%d\n", decimal_parts[0], decimal_parts[1], decimal_parts[2], decimal_parts[3]);
    }
    else
    {
        printf("Invalid binary IP format.\n");
    }

    return 0;
}

int ToDec(char bin[])
{
    int dec = 0;
    for(int i = 0; bin[i] != '\0'; i++)
    {
        dec = dec * 2 + (bin[i] - '0');
    }
    return dec;
}
