#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    int i,l,w,h,surfaceArea,lowestArea,totalFeet,accumulatedSurfaceArea ;
    char copied[]="";
    char box[]="";
    accumulatedSurfaceArea=0;
    l=0;
    w=0;
    h=0;
    i=1;
    char word[]="2x3x4 2x3x4 2x3x4";


    char * token1 = strtok(word, " ");

    while( token1 != NULL )
    {

        printf( "Outer %s\n", token1 ); //printing each token
        strcpy(box,token1);//2*3*4
        printf("Box... %s\n", box);
        char * token = strtok(box, "x");
        while(token != NULL )
        {
            printf( " Inner %s\n", token ); //printing each token
            //printf( " I %s\n", i); //printing each token

            if(i==1)
            {
                l=atoi(token);
                //printf("\nAnd the L is %i...\n",i);
                i=i+1;
            }
            else if(i==2)
            {
                w=atoi(token);
                //printf("\nAnd the W is ... %i\n",i);
                i=i+1;
            }
            else if(i==3)
            {
                h=atoi(token);
                //printf("\nAnd the H is ... %i\n",i);
                i=1;
            }

            token = strtok(NULL, "x");
        }

        printf("Length ...%d width... %d height... %d",l,w,h);
        surfaceArea=2*l*w + 2*w*h + 2*h*l;
        if((l*w)<(w*h))
        {
            if((l*w)<(l*h))
            {
                lowestArea=l*w;
            }
        }
        else if((w*h)<(l*w))
        {
            if((w*h)<(l*h))
            {
                lowestArea=w*h;
            }
        }

        else if((l*h)<(l*w))
        {
            if((l*h)<(w*h))
            {
                lowestArea=l*h;
            }
        }
        token1 = strtok(NULL, " ");
        printf("\nLowest area ... %i\n",lowestArea);
        printf("\surface area ... %i\n",surfaceArea);
        totalFeet= surfaceArea+lowestArea;
        accumulatedSurfaceArea=accumulatedSurfaceArea+totalFeet;
        printf("\n First Accumulated area  ... %d\n ",accumulatedSurfaceArea);


    }
    printf("Accumulated surface area is probably...\n%d ",accumulatedSurfaceArea);
    return 0;
}
