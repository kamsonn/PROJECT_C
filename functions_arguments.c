// You can take the value of log, sin, cos
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int main(int arg,char* argv[])
{
    if(arg==2)
    {
    char funkcja[10]="\0",zmienna[10]="\0",*wsk,*w,*w1,*w2;
    int i=0;
    w2=wsk=argv[1];
    w=strchr(wsk,'(');
    w1=strchr(wsk,')');
    if(w!=NULL && w1!=NULL)
    {
        while(*w2!='(')
        {
            funkcja[i]=*w2;
            w2++;
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
	float wartosc;
	wartosc=atof(zmienna);
        if(strcmp(funkcja,"log")==0)
        {
	if(wartosc>0)
	{
            printf("Value of ln for %s is -> %f\n",zmienna,log(wartosc));
        }
	else
	printf("We do not count the logarithm from a negative number!\n");
	}
	else if(strcmp(funkcja,"sin")==0)
	printf("Value of sinus for %s is -> %f\n",zmienna,sin(wartosc));
    	else if(strcmp(funkcja,"cos")==0)
	printf("Value of cosinus for %s is -> %f\n",zmienna,cos(wartosc));
	else
		printf("We do not count value for this function!\n");
    }
	else
        printf("Error in writing!\n");
    return 0;
    }
    else
        {printf("Wrong amount of arguments!\n");}
        return 0;
}
