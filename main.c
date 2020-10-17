/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int Som_Div(int valeur){
    int som=0;//som var local 
    for (int i=1 ; i<=valeur/2;i++){//i var local 
        if (valeur %i==0){
            som+=i;
        
        }
    }
  
    return som;
}
void is_Parfait(int valeur){
    int som=Som_Div(valeur);//som var local 
    if (som==valeur)
       printf("%d est parfait",valeur);
    else 
        printf("%d n'est pas parfait",valeur);
}

bool  is_Parfait2(int valeur){
    int som=Som_Div(valeur);//som var local 
    //return som==valeur; or 
    if (som==valeur)
      return 1;
    else 
        return 0;
}
int main()
    
{   int valeur=16;
    int som=Som_Div(valeur);
    printf("%d  est la som des div de %d \n",som,valeur);
    is_Parfait(valeur);
    if(is_Parfait2(valeur)==1)
         printf("%d est parfait",valeur);
    else 
        printf("%d n'est pas parfait",valeur);
    return 0;
}
//no variable global 