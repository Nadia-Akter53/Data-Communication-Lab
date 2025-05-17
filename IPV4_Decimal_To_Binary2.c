#include<stdio.h>
#include<string.h>
char* ToBin(char ch[]);
int main()
{

    printf("Enter Decimal Ip : ");
    char ip[10];
    char tem[9];
    scanf(" %[^\n]", ip);

    char*token = strtok(ip, ".");

    // token e ekhon first value ta ase mane ip : 123.4.5.66
    // so first value holo 123
    // but token e eta string hishabe ase, so amdr integer e convert korte hobe

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


char *ToBin(char ch[])
{
    int n = atoi(ch);

    static char bin[9];
    for(int i=0; i<8; i++)
    {
        bin[i]='0';
    }

    bin[8]='\0';
    int k=7;

    int rem;
    for(int i=n; i!=0; i=i/2)
    {

        rem = i%2;
        bin[k--]= rem+'0';


    }

    return bin ;

}
