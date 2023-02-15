#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<conio.h>

#define ROZMIAR 10

int fib(int n); // prototype

int main()
{
    srand(time(NULL));
    int stan=1;
    while(stan)
    {
        int choice;
        printf("-------------------------------------------------------------------------------------------\n");
        printf("Select the number of the program to run: \n");
        printf("1. Cash register\n");
        printf("2. Two triangles (inverted) with a given width\n");
        printf("3. Triangle for letters\n");
        printf("4. Create a password with n characters\n");
        printf("5. Create an array, fill with random [-100,100], flip it half\n");
        printf("6. It reads 8 characters (0 or 1) and then prints the decimal value\n");
        printf("7. Invert even bits (bit operations) and print a new value\n");
        printf("8. The program draws numbers [-3.0,3.0], writes min,max in each 10\n");
        printf("9. LIFO & FIFO queue service\n");
        printf("10. Calculation of the n-th word Fib recursively - depth of calls\n");
        printf("11. Delete the specified instance in text\n");
        printf("12. Generation of letters and checking if there is another (random) character\n");
        printf("13. Combine two sorted ascending arrays into one ascending array\n");
        printf("14. Calculation of the nth word of the string (1+1/4+1/9+...+1/(n^2))\n");
        printf("0. EXIT\n");
        printf("-------------------------------------------------------------------------------------------\n");
        printf("\n");

        sleep(1);
        printf("Your choice ---> ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0: {
                exit(0);
                };
            case 1: {
                int kwota;
                printf("Enter the amount to spend: ");
                scanf("%d",&kwota);
                fiskalna(kwota);
                printf("\n");
                sleep(3);
                    };
            break;
            case 2: {
                int rozmiar;
                printf("Enter size: ");
                scanf("%d",&rozmiar);
                trojkaty(rozmiar);
                printf("\n");
                sleep(3);
            }
            break;
            case 3: {
                int wartosc=1,temp,zm_1,licznik=0;
                char litera,znak=64;
                printf("Enter the LARGE letter on which the triangle will end: ");
                while(wartosc==1)
                {
                    scanf("%c",&litera);
                    if(litera>=65 && litera<=90)
                        break;
                    else
                    {
                        if(licznik%2==0)
                        printf("Enter the LARGE letter!\n");
                        licznik++;
                    }
                }
                //      A       //
                //     ABA      //
                trojkat_litery(litera);
                printf("\n");
                sleep(3);
            }
            break;
            case 4: {
                int liczba;
                printf("How many characters in your password: ");
                scanf("%d",&liczba);
                haslo(liczba);
                sleep(3);
                printf("\n");
            }
            break;
            case 5: {
                int rozmiar;
                printf("Enter the size of an array: ");
                scanf("%d",&rozmiar);
                odwrot_polowa(rozmiar);
                sleep(3);
                printf("\n");
            }
            break;
            case 6: {
                nabinarny();
                sleep(3);
                printf("\n");
            }
            break;
            case 7: {
                unsigned int liczba;
                printf("Enter the number: ");
                scanf("%d",&liczba);
                bity_odwrocenie(liczba);
                sleep(3);
                printf("\n");
            }
            break;
            case 8: {
                zwraca_wsk();
                sleep(3);
                printf("\n");
            }
            break;
            case 9: {
                int tab[ROZMIAR]={0}, main_choice;
                int b=1,licznik=0;
                printf("\n*LIFO (1)\n*FIFO (2)\nChoosing -> ");
                scanf("%d",&main_choice);
                if(main_choice==1 || main_choice==2)
                while(b)
                {
                printf("\nSelect what you wanna do: \n");
                printf("1. Read stack\n");
                printf("2. Add an element to the stack\n");
                printf("3. Remove an element from the stack\n");
                printf("0. EXIT\n\n");
                int wybor;

                scanf("%d",&wybor);
                if(wybor==0)
                    break;
                while(wybor!=1 && wybor!=2 && wybor!=3)
                {
                    printf("WRONG CHOICE!\n");
                    scanf("%d",&wybor);
                }
                if(wybor==1)
                czytaj_stos(tab);
                else if(wybor==2)
                {
                    if(licznik<10)
                    {
                        doloz_stos(tab,licznik);
                        licznik++;
                    }
                    else
                        printf("Stack overflowed!\n");
                }
                else if(wybor==3)
                {
                    if(licznik>0)
                    {
                        zabierz_stos(tab,licznik,main_choice);
                        licznik--;
                    }
                    else
                        printf("There is nothing to remove!\n");
                }
                }
                else
                    printf("\nWrong choice\n");
                sleep(3);
                printf("\n");
            }
            break;
            case 10: {
                printf("Enter the element of Fibbonaci you want to get: ");
                int n, wynik;
                scanf("%d",&n);
                wynik=fib(n);
                printf("\n%d element of Fib is %d\n",n,wynik);
                sleep(3);
                printf("\n");
            }
            break;
            case 11: {
                char tekst[200], lancuch[100],*wsk,*wsk_1;
                printf("\nEnter the text: ");
                fgets(tekst,sizeof(tekst),stdin);

                printf("\nEnter the string you want to delete: ");
                scanf("%s",lancuch);
                wyrzucenie_lancuch(tekst,lancuch);
                sleep(3);
                printf("\n");
            }
            break;
            case 12: {
                int n,i=0;
                printf("\nHow long the string should be: ");
                scanf("%d",&n);
                char S_1[n+1],S_2[4],literka=rand()%26+97;
                while(i<n)
                {
                    S_1[i]=rand()%26+97;
                    if(i<3)
                    S_2[i]=literka;
                    i++;
                    if(i==n)
                        S_1[i]='\0';
                    else if(i==3)
                        S_2[i]='\0';

                }
                printf("S_1 -> %s\nS_2 -> %s\n",S_1,S_2);
                i=0;
                spr_nap(S_1,S_2);

                sleep(3);
                printf("\n");
            }
            break;
            case 13: {
                int rozmiar_1,rozmiar_2,i=0;
                printf("Enter the size of 1 array: ");
                scanf("%d",&rozmiar_1);
                printf("Enter the size of 2 array: ");
                scanf("%d",&rozmiar_2);
                int tab1[rozmiar_1],tab2[rozmiar_2];
                //zerowanie tablic
                while(i<rozmiar_1)
                {
                    tab1[i]=0;
                    i++;
                }
                i=0;
                while(i<rozmiar_2)
                {
                    tab2[i]=0;
                    i++;
                }

                i=0;
                printf("\nFilling 1 array: \n");
                while(i<rozmiar_1)
                {
                    int liczba,a=0,licznik=0;
                    scanf("%d",&liczba);
                    while(liczba>tab1[a] && licznik<rozmiar_1)
                    {
                        a++;
                        licznik++;
                    }
                    if(licznik==rozmiar_1)
                        {
                            tab1[i]=liczba;
                            i++;
                        }
                    else
                        printf("It should be ascending!\n");

                }
                i=0;
                printf("\nFilling 2 array: \n");
                while(i<rozmiar_2)
                {
                    int liczba,a=0;
                    int licznik=0;
                    scanf("%d",&liczba);
                    while(liczba>tab2[a] && licznik<rozmiar_2)
                    {
                        a++;
                        licznik++;
                    }
                    if(licznik==rozmiar_2)
                        {
                            tab2[i]=liczba;
                            i++;
                        }
                    else
                        printf("It should be ascending!\n");

                }
                sort(tab1,tab2,rozmiar_1,rozmiar_2);
                sleep(3);
                printf("\n");
            }
            break;
            case 14: {
                szereg();
                sleep(3);
                printf("\n");
            }
            break;
            default: {
                printf("\nWRONG CHOICE\n\n");
                sleep(1);}
            break;
        }
        system("cls");
    }
}

void fiskalna(int kwota)
{
    // mam kwota 503zl to najpierw sprawdzam ile razy sie 200 zmiesci, potem 100, 50, ...
    int i=1;
    int poczatek=500;
    printf("Wydajemy w banknotach: \n");
    while(kwota>0)
    {
        if(kwota>=poczatek && kwota>10)
        {
            printf("(%d). Banknot %dzl\n",i,poczatek);
            kwota-=poczatek;
            i++;
        }
        else
        {
            if(poczatek>200)
            {
                poczatek=200;
                continue;
            }
            if(poczatek>100)
            {
                poczatek=100;
                continue;
            }
            if(poczatek>50)
            {
                poczatek=50;
                continue;
            }
            if(poczatek>20)
            {
                poczatek=20;
                continue;
            }
            if(poczatek>10)
            {
                poczatek=10;
                continue;
            }
        }
        if(kwota<10 && kwota>0)
        {
            while(kwota>0)
            {
                if(kwota>=5)
                {
                    poczatek=5;
                    printf("(%d). Moneta %dzl\n",i,poczatek);
                    kwota-=5;
                }
                if(kwota>=2)
                {
                    poczatek=2;
                    printf("(%d). Moneta %dzl\n",i,poczatek);
                    kwota-=2;
                    continue;
                }
                if(kwota>=1)
                {
                    poczatek=1;
                    printf("(%d). Moneta %dzl\n",i,poczatek);
                    kwota-=1;
                    continue;
                }
            }

        }
    }
}
void trojkaty(int rozmiar)
{
    int a,i=0, temp=rozmiar,k=rozmiar;
    while(k>=0)
    {
    while(a>0)
    {
        printf(" ");
        a--;
    }
    while(rozmiar>i)
    {
        printf("%d",rozmiar);
        rozmiar--;
    }
    printf(" ");
    while(rozmiar>=0)
    {
        printf("%d",rozmiar);
        rozmiar--;
    }
    rozmiar=temp;
    i++;
    a=i;
    k--;
    printf("\n");
    }
}
void trojkat_litery(char litera)
{
    int temp;
    int a=0,i=0,b=0;
    char znak=64;
            temp=litera-65;
            while(temp>=0)
            {
                while(a<=temp)
                {
                    printf(" ");
                    a++;
                }
                while(b<=i)
                {
                    znak++;
                    printf("%c",znak);
                    b++;
                }
                while(b>1)
                {
                    znak--;
                    printf("%c",znak);
                    b--;
                }
                while(a>0)
                {
                    printf(" ");
                    a--;
                }
                temp--;
                i++;
                b=0;
                printf("\n");
                a=0;
                znak=64;
            }
}
void haslo(int ile)
{

    char male[]="abcdefghijklmnoprstuwxyz";
    char duze[]="ABCDEFGHIJKLMNOPRSTUWXYZ";
    char cyfry[]="1234567890";
    char znaki[]="!@#$%^&*_()+-=";

    int i=0,losowa;
    char haslo[ile+1];
    while(i<ile)
    {
        i++;
        if(i==ile)
            haslo[i]='\0';
    }

    i=0;
    while(i<ile)
    {
        // niech najpierw wybierze czy z malych, duzych czy cyfr bedzie wybierac
        losowa=rand()%4;
        switch(losowa)
        {
            // Teraz losuje z wybranego zestawu dowolny znak i wstawia na miejsce danego indeksu
            case 0: haslo[i]=male[rand()%(strlen(male))];
            break;
            case 1: haslo[i]=duze[rand()%(strlen(duze))];
            break;
            case 2: haslo[i]=cyfry[rand()%(strlen(cyfry))];
            break;
            case 3: haslo[i]=znaki[rand()%(strlen(znaki))];
            break;
        }
        i++;
    }
    printf("Twoje haslo: %s\n\n",haslo);
}
void odwrot_polowa(int rozmiar)
{
    float tab[rozmiar];
    int i=0;
    printf("\nPrzed zamiana:\n");
    while(i<rozmiar)
    {
        tab[i]=rand()/(1.0+RAND_MAX)*200-100;
        printf("element [%d] = %+-2.2f\n",i,tab[i]);
        i++;
    }
    int nieparzysta=0;
    printf("\nPo zamianie:\n");
    if(rozmiar%2!=0)
        {
        nieparzysta=1;
        rozmiar++;
        }
    float temp_1, temp_2;
    i=0;
    while(i<rozmiar/2)
    {
        if(nieparzysta==1 && i==rozmiar/2-1)
        break;
        temp_1=tab[i+rozmiar/2];
        temp_2=tab[i];
        tab[i+rozmiar/2]=temp_2;
        tab[i]=temp_1;
        i++;
    }
    i=0;
    if(nieparzysta==1)
        rozmiar--;
    while(i<rozmiar)
    {
        printf("element [%d] = %+-2.2f\n",i,tab[i]);
        i++;
    }
}
void nabinarny()
{
    int licznik=0,i=1,suma=0,iloczyn=1;
    char znaki[9]="\0";
    printf("\nNastepuje wczytywanie kolejnych cyfr liczby binarnej:\n");
    while(licznik<=7)
    {
        scanf("%c",&znaki[licznik]);
        if(znaki[licznik]==48 || znaki[licznik]==49)
        {
            licznik++;
        }
    }
    // robienie z niej binarnej W U2
    if(znaki[0]==49)
        suma=-128;
    int temp=1,zm=6,zm_1=6;
    while(temp<=7)
    {
        zm=zm_1;
        if(znaki[temp]==49)
        {
            while(zm>0)
            {
                iloczyn*=2;
                zm--;
            }
            suma+=iloczyn;
            iloczyn=1;
        }
        zm_1--;
        temp++;
    }
    printf("Jezeli wprowadzimy ciag : %s, otrzymamy wartosc %d\n",znaki,suma);
}
void bity_odwrocenie(unsigned int liczba)
{
    // moja maska to binarnie 0101...0101 -> na dziesietny to 1431655765
    int maska=0,i=0,iloczyn=1;
    while(i<=32)
    {
        if(i%2==0)
        {
            int a=i;
            while(a>0)
            {
                iloczyn*=2;
                a--;
            }
            maska+=iloczyn;
            iloczyn=1;
        }
        i++;
    }
    printf("liczba przed odwrotem %d po odwrocie %d\n",liczba,liczba^maska);
}
void zwraca_wsk()
{
    float tab[100],*last,*first,min,max,*wsk,*wsk_1;
    int i=0,n=1;
    while(i<100)
    {
        tab[i]=rand()/(1.0+RAND_MAX)*6-3;
        i++;
    }
    // mozna bez wskaznika ale zrobmy z :)
    first=tab;
    max=min=*tab;
    last=tab+99;
    i=0;
    while(i<10)
    {
        while(n<=10)
        {
            if(*first<min)
                {
                    min=*first;
                    wsk=first;
                }
            if(*first>max)
                {
                    max=*first;
                    wsk_1=first;
                }
            first++;
            n+=1;
        }
        n=1;
        printf("elementy od %d do %d min = %.4f adres %p, max = %.4f adres %p\n",i*10,i*10+9,min,wsk,max,wsk_1);
        max=min=*tab;
        i++;
    }
    first=tab;
    while(first!=last)
    {
        if(*first<min)
            {
                min=*first;
                wsk=first;
            }
        if(*first>max)
            {
                max=*first;
                wsk_1=first;
            }
        first++;
    }
    printf("\nNajwiekszy i Najmniejszy w calej tablicy: %.4f oraz %.4f\n",min,max);
}
void czytaj_stos(int *wsk)
{
    int i=0;
    while(i<ROZMIAR)
    {
        printf("%d ",*wsk);
        i++;
        wsk++;
    }
    printf("\n");
}
void doloz_stos(int *wsk,int n)
{
    printf("\nJaki element chcesz dolozyc: ");
    int element;
    scanf("%d",&element);
    wsk+=n;
    *wsk=element;
    printf("\n");
}
void zabierz_stos(int *wsk,int n, int main_choice)
{
    if(main_choice==1)
    {
        wsk=wsk+n-1;
        *wsk=0;
    }
    else if(main_choice==2)
    {
        int temp,*wsk_pomocniczy;
        wsk_pomocniczy=wsk;
        wsk_pomocniczy++;
        while(*wsk!=0)
        {
            *wsk=*wsk_pomocniczy;
            wsk++;
            wsk_pomocniczy++;
        }
    }
}

int fib(int n)
{
    static int l_wywolan=1;
    static int glebokosc=0;
    int i=0;
    printf("%d",glebokosc);
    while(i<glebokosc)
    {
        printf(".");
        i++;
    }
    if(n==0 || n==1)
        {
            printf(", Zwracam f(%d), liczba wywolan -> %d\n",n,l_wywolan);
            l_wywolan++;
            glebokosc--;
            return n;
        }
    printf(", Obliczam f(%d)=f(%d)+f(%d), liczba wywolan -> %d\n",n,n-1,n-2,l_wywolan);
    l_wywolan++;
    glebokosc++;
    return fib(n-1)+fib(n-2);
}
void wyrzucenie_lancuch(char *tekst,char *lancuch)
{
    char* wsk,wsk_1;
    wsk=tekst;
    wsk_1=strstr(tekst,lancuch);
    if(wsk_1!=NULL)
    {
        while(wsk!=wsk_1 || wsk==wsk_1)
        {

            if(wsk==wsk_1)
            {
                wsk=wsk+strlen(lancuch);
                if(*wsk==' ')
                wsk++;
                wsk_1=strstr(wsk,lancuch);
                if(wsk_1==NULL)
                {
                    while(*wsk!=0)
                    {
                        printf("%c",*wsk);
                        wsk++;
                    }
                    return 0;
                }
            }
            else
            {
                printf("%c",*wsk);
                wsk++;
            }
        }
    }
    else
    printf("\nNie ma nic do usunieca -> %s\n",tekst);
}
void spr_nap(char *S_1,char *S_2)
{
    if(strstr(S_1,S_2)!=NULL)
    {
        char *wsk;
        int i=0;
        wsk=S_1;
        while(strstr(wsk,S_2)!=NULL)
        {
            printf("%d wystapienie, posiada indeks: %d\n",i,strstr(wsk,S_2)-S_1);
            wsk=strstr(wsk,S_2)+3;
            i++;
        }
    }
    else
    printf("Brak %s w naszym %s",S_2,S_1);
}
void sort(int *tab1,int *tab2,int wart1,int wart2)
{
    int licz=0,*wsk1,*wsk2,licznik1=0,licznik2=0;
    wsk1=tab1;
    wsk2=tab2;
    if(wart1>=wart2)
    {
        while(licz<wart1)
        {
            if(licznik1<wart1)
            {
            if(licznik2<wart2)
            {
            if(*wsk1>*wsk2)
            {
                printf("%d ",*wsk2);
                licznik2++; // oznacza ze juz wypisalem kolejny element z drugiej tablicy
                wsk2++;

            }
            else if(*wsk1==*wsk2)
            {
                printf("%d %d ",*wsk1,*wsk2);
                wsk1++;
                wsk2++;
                licz++;
                licznik1++;
                licznik2++;
            }
            else if(*wsk1<*wsk2)
            {
                printf("%d ",*wsk1);
                wsk1++;
                licznik1++;
                licz++;
            }
            }
            else
            {
                printf("%d ",*wsk1);
                wsk1++;
                licz++;
            }
            }
            else
            {
                printf("%d ",*wsk2);
                wsk2++;
                licz++;
            }
        }
    }
    else
    {
        while(licz<wart2)
        {
            if(licznik2<wart2)
            {
            if(licznik1<wart1)
            {
            if(*wsk1>*wsk2)
            {
                printf("%d ",*wsk2);
                licznik2++; // oznacza ze juz wypisalem kolejny element z drugiej tablicy
                wsk2++;
                licz++;
            }
            else if(*wsk1==*wsk2)
            {
                printf("%d %d ",*wsk1,*wsk2);
                wsk1++;
                wsk2++;
                licz++;
                licznik1++;
                licznik2++;
            }
            else if(*wsk1<*wsk2)
            {
                printf("%d ",*wsk1);
                wsk1++;
                licznik1++;

            }
            }
            else
            {
                printf("%d ",*wsk2);
                wsk2++;
                licz++;
            }
            }
            else
            {
                printf("%d ",*wsk1);
                wsk1++;
                licz++;
            }
        }
    }
}
void szereg()
{
    int licznik=0,i=1,n; // 1/(1^1)+ 1/(2^2) +...+1/(n^2)
    double suma=0.0,wartosc=1.0,potega=pow(10.0,-8.0);
    printf("\nPodaj ktory wyraz chcesz otrzymac: ");
    scanf("%d",&n);

    while(wartosc>=potega)
    {
        if(i<=n)
        {
        wartosc=1/(pow(i,2));
        if(wartosc<potega)
        {
            printf("Przeszlo za zakres. Dodajemy tylko do pewnej dokladnosci (1e-8): \n");
            break;
        }
        i++;
        suma+=wartosc;
        licznik++;
        }
        else
            break;
    }

    printf("\nLiczba zsumowanych wyrazow: %d, ich suma %.10f\n",licznik,suma);
}

