// Program checks the number of occurences the entered letter in string

#include<stdio.h>
#include<string.h>
#include<time.h>

//ciekawe czy to widzisz

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
    printf("Random character string: %s\n",losuj_wyraz);
    printf("Entered letter: %c\n",*argv[1]);

    char *wsk;
    wsk=strchr(losuj_wyraz,*argv[1]);
    int occurances=1;
    if(wsk==NULL)
    {
        printf("\nNo letter %c in %s\n",*argv[i],losuj_wyraz);
        return 0;
    }
    while(wsk!=NULL)
    {
        printf("Letter %c occures %d time with index %d\n",*argv[1],occurances,wsk-losuj_wyraz);
        wsk++;
        occurances++;
        wsk=strchr(wsk,*argv[1]);
    }
    }
    else
        printf("\nWrong amount of arguments!\n");
    return 0;
}
