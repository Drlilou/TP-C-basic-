/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
float Aire(float rayon,float hauteur){
    return 2*3.14*rayon*hauteur;
}
float Volume(float rayon,float hauteur){
    return 3.14*rayon*rayon*hauteur;
}
int main()
{
    float H,R;
    printf("donner l'hauteur");
    
    H=scanf("%f",&H);
    printf("donner le rayon");
    R=scanf("%f",&R);
    
    printf("%f  est l' aire \t   le volume , il est : %f",Aire(R,H),Volume(R,H));

    return 0;
}
