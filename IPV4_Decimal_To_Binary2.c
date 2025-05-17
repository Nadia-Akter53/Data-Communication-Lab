#include<stdio.h>

char * ToBin(char ip[]);
int main()
{

    char ip[100];
    printf("Enter : ");
    scanf(" %[^\n]", ip);

    char *token = strtok(ip, ".");






     int first_oc = atoi(token);
    if(first_oc >=0 && first_oc<=127)
    {

        printf("Class A\n");
    }else if(first_oc >=128 && first_oc<=192)
    {
        printf("Class B\n");
    }



    while(token!=NULL)
    {
        printf("%s ",ToBin(token));
        token = strtok(NULL,".");


    }



}

char * ToBin(char ip[])
{

    static char bin[9];
    int n= atoi(ip);

    for(int i=0; i<8; i++)
    {
        bin[i]= '0';
    }
    bin[8]='\0';

    int rem ;
    int k=7;
    for(int i=n; i!=0; i=i/2)
    {
        rem = i%2;
        bin[k--]= rem+'0';
    }
    return bin;



}
