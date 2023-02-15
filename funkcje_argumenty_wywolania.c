#include<stdio.h>
#include<math.h>
#include<stdio.h>

int main(int arg,char* argv[])
{
    char funkcja[4]="\0",zmienna[10]="\0",*wsk,*w,*w1;
    int i=0;
    wsk=argv[1];
    w=strchr(wsk,'(');
    w1=strchr(wsk,')');
    if(w!=NULL && w1!=NULL)
    {
        while(i<3)
        {
            funkcja[i]=*wsk;
            wsk++;
            i++;
        }
        w++;
        i=0;
        while(w!=w1)
        {
            zmienna[i]=*w;
            w++;
            i++;
        }
        if(strstr(funkcja,"log")!=NULL)
        {
            printf("Wartosc loogarytmu naturalnego dla %s wynosi -> %f",zmienna,log(atof(zmienna)));
        }
    }
    else
        printf("Blad w zapisie!\n");
    return 0;
}
