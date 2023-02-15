// program sprawdza ilosc wystapienia wpisanej przez nas litery w wylosowanym lanuchu znakow

#include<stdio.h>
#include<string.h>
#include<time.h>

int main(int arg, char* argv[])
{
    if(arg==2)
    {
    srand(time(NULL));
    char losuj_wyraz[11]="\0";
    int i=0;
    while(i<10)
    {
        losuj_wyraz[i]=rand()%26 + 97;
        i++;
    }
    printf("Wylosowany lanuch znakow: %s\n",losuj_wyraz);
    printf("Podana litera: %c\n",*argv[1]);

    if(strchr(losuj_wyraz,*argv[1])!=NULL)
    {
        printf("literka %c wystepuje pierwszy raz pod indeksem %d\n",*argv[1],strchr(losuj_wyraz,*argv[1])-losuj_wyraz);
    }
    }
    else
        printf("Nie wystarczajaca ilosc argumentow!\n");
    return 0;
}
