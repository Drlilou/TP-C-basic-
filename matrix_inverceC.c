
#include<stdio.h>
#include<math.h>

float determinant(float[][25],float);
void cofactor(float[][25],float);
void transpose(float[][25],float[][25],float);
void inverse();

void matrix_output(float[][25],int,int);
void determinant_input();
void transpose_input();

void main()
{
	int a;char str;
	printf("--------------WELCOME TO MATRIX OPERTATION--------------\n");
	printf("::::1.Calculate Determinant of matrix::::\n");
	printf("::::2.Calculate Inverse of a matrix::::::\n");

	printf("::::3.Calculate Transpose of matrix::::::\n");
	printf("Enter any choices from 1 to 3::\t");
	scanf("%d",&a);
	switch (a)
	{
	
		case 1:
			 determinant_input();
			 break;
		case 2:
			inverse();
			break;
	
		case 3:
			transpose_input();
			break;
		default:
			printf("Invalid choice\n");
			printf("Do you want to Re-enter.\n");
			printf("Press Y to continue or Press N to exit.\t");
			scanf("%c",&str);
			if (str=='y'||str=='Y')
			{
				main();
			}
			break;

	}

}
void transpose_input()
{
	int i,j,n;float a[25][25],b[25][25];
	printf("Calculation of Matrix Transpose\n");
	printf("Enter the dimension of square Matrix:\t");
	scanf("%d",&n);
	printf("\nEnter the Matrix element of %dX%d matrix\n",n,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		scanf("%f",&a[i][j]);
	}
	for (i=0;i<n;i++)
    {
     for (j=0;j<n;j++)
       {
         b[i][j]=a[j][i];
        }
    }
    printf("The transpose of a matrix is:\n");
    matrix_output(b,n,n);

}
void determinant_input()
{
float a[25][25],k,d;
  int i,j;
  printf("\n Calculation of determinant of matrix\n\n");
  printf("Enter the order of the Square Matrix : ");
  scanf("%f",&k);
  printf("Enter the elements of %.0fX%.0f Matrix : \n",k,k);
  for (i=0;i<k;i++)
    {
     for (j=0;j<k;j++)
       {
        scanf("%f",&a[i][j]);
        }
    }
  d=determinant(a,k);
  printf("Determinant of matrix is %f",d);
}
void matrix_output(float dis[][25],int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%10f",dis[i][j]);
		}
		printf("\n");
	}
}

void inverse()

{
  float a[25][25],k,d;
  int i,j;
  printf("-------------------------------------------------------------\n");
  printf("-------------------------------------------------------------\n");
  printf("-------------------------------------------------------------\n");
  printf("\n  C Program to find inverse of Matrix\n\n");
  printf("Enter the order of the Matrix : ");
  scanf("%f",&k);
  printf("Enter the elements of %.0fX%.0f Matrix : \n",k,k);
  for (i=0;i<k;i++)
    {
     for (j=0;j<k;j++)
       {
        scanf("%f",&a[i][j]);
        }
    }
  d=determinant(a,k);
  printf("Determinant of the Matrix = %f",d);
  if (d==0)
   printf("\nInverse of Entered Matrix is not possible\n");
  else
   cofactor(a,k);
   printf("\n\n**** Thanks for using the program!!! ****");

}

//For calculating Determinant of the Matrix
float determinant(float a[25][25],float k)
{
  float s=1,det=0,b[25][25];
  int i,j,m,n,c;
  if (k==1)
    {
     return (a[0][0]);
    }
  else
    {
     det=0;
     for (c=0;c<k;c++)
       {
        m=0;
        n=0;
        for (i=0;i<k;i++)
          {
            for (j=0;j<k;j++)
              {
                b[i][j]=0;
                if (i != 0 && j != c)
                 {
                   b[m][n]=a[i][j];
                   if (n<(k-2))
                    n++;
                   else
                    {
                     n=0;
                     m++;
                     }
                   }
               }
             }
          det=det + s * (a[0][c] * determinant(b,k-1));
          s=-1 * s;
          }
    }

    return (det);
}

void cofactor(float num[25][25],float f)
{
 float b[25][25],fac[25][25];
 int p,q,m,n,i,j;
 for (q=0;q<f;q++)
 {
   for (p=0;p<f;p++)
    {
     m=0;
     n=0;
     for (i=0;i<f;i++)
     {
       for (j=0;j<f;j++)
        {
          if (i != q && j != p)
          {
            b[m][n]=num[i][j];
            if (n<(f-2))
             n++;
            else
             {
               n=0;
               m++;
               }
            }
        }
      }
      fac[q][p]=pow(-1,q + p) * determinant(b,f-1);
    }
  }
  transpose(num,fac,f);
}
//Finding transpose of matrix
void transpose(float num[25][25],float fac[25][25],float r)
{
  int i,j;
  float b[25][25],inverse[25][25],d;

  for (i=0;i<r;i++)
    {
     for (j=0;j<r;j++)
       {
         b[i][j]=fac[j][i];
        }
    }
  d=determinant(num,r);
  for (i=0;i<r;i++)
    {
     for (j=0;j<r;j++)
       {
        inverse[i][j]=b[i][j] / d;
        }
    }
   printf("\n\n\nThe inverse of matrix is : \n");

   for (i=0;i<r;i++)
    {
     for (j=0;j<r;j++)
       {
         printf("\t%f",inverse[i][j]);
        }
    printf("\n");
     }
}
