#include<stdlib.h>
#include<stdio.h>

//#define dim 2
#define size 200
int inv_matrix(int n,float a[size][size],float a_inv[size][size]);


// inverse matrix
int inv_matrix(int n,float a[size][size],float a_inv[size][size]){

        int i,j,k;
        float ratio;
		 for(i=0;i<n;i++)
		 {
			  for(j=0;j<n;j++)
			  {
				   if(i==j)
				   {
				    	a[i][j+n] = 1;
				   }
				   else
				   {
				    	a[i][j+n] = 0;
				   }
			  }
		 }
		 for(i=0;i<n;i++)
		 {
			  if(a[i][i] == 0.0)
			  {
				   exit(0);
			  }
			  for(j=0;j<n;j++)
			  {
				   if(i!=j)
				   {
					    ratio = a[j][i]/a[i][i];
					    for(k=1;k<=2*n;k++)
					    {
					     	a[j][k] = a[j][k] - ratio*a[i][k];
					    }
				   }
			  }
		 }
		 for(i=0;i<n;i++)
		 {
			  for(j=n;j<2*n;j++)
			  {
			   	a[i][j] = a[i][j]/a[i][i];
			   	a_inv[i][j] = a[i][j];
			  }
		 }
		 return a_inv;
}


//solution
int main (){
int n = 2;
float a_inv[size][size];


float a[size][size]={{4,7},{2,6}};

for(int r=0;r<n;r++){
			    //  x[r][j] = 0;
			      for(int c=n;c<2*n;c++){
                 
                    printf("%e\t",a[r][c]);
			      }

			  

			  printf("\n");
}
    printf("\n");
inv_matrix(n,a, a_inv);
printf("the inverse matrix is:\n");
for(int r=0;r<n;r++){
			    //  x[r][j] = 0;
			      for(int c=n;c<2*n;c++){
                 
                    printf("%e\t",a_inv[r][c]);
			      }

			  

			  printf("\n");
}

return 0;
}
