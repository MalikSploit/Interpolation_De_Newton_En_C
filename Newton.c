#include<stdio.h>
#include <stdlib.h>
#include <math.h>

void Newton(double x[], double y[][21])
{
  double sum,fy,xf;
  int i,j,k,t,m;
  int n = 21;
  printf("Le degré de votre polynôme est : %d", n-1);
  printf("\nEntrez la valeur de xr à laquelle y = f(x) doit être calculé xr = ");
  scanf("%lf",&xf);
  k = n;
  for(j = 1; j < n; j++)
  {
    /* BOUCLE POUR CALCULER LES DIFFERENCES DANS LE TABLEAU */
    k = k - 1;
    for(i = 0; i < k; i++)
    {
      y[i][j] = (y[i+1][j-1] - y[i][j-1])/(x[i+j]-x[i]);
    }
  }
  sum = 0;
  for(t = 1; t < n; t++)
  {
    /* BOUCLE POUR CALCULER LA VALEUR INTERPOLÉE DE y(x) */
    fy = 1;
    for(m = 0; m < t; m++)
    {
      fy = fy * (xf - x[m]);
    }
    sum = sum + (fy * y[0][t]);
  }
  sum = sum + y[0][0];
  printf("\nLa valeur interpolée de x à xr = %lf est yr = %lf\n", xf, sum);
}

//Fonction pour afficher la table de différences divisées.
void printDiffTable(double y[][21],int n)
{
  for (int i = 0; i < n; i++) 
  {
    for (int j = 0; j < n - i; j++) 
    {
      printf ("%.3lf\t", y[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  double x[21] =  {752, 855, 871, 734, 610, 582, 921, 492, 569, 462, 907, 643, 862, 524, 679, 902, 918, 828, 875, 809, 894 };
  double y[21][21];
  y[0] [0] = 85;
  y[1] [0] = 83;
  y[2] [0] = 162;
  y[3] [0] = 79;
  y[4] [0] = 81;
  y[5] [0] = 83;
  y[6] [0] = 281;
  y[7] [0] = 81;
  y[8] [0] = 81;
  y[9] [0] = 80;
  y[10][0] = 243;
  y[11][0] = 84;
  y[12][0] = 84;
  y[13][0] = 82;
  y[14][0] = 80;
  y[15][0] = 226;
  y[16][0] = 260;
  y[17][0] = 82;
  y[18][0] = 186; 
  y[19][0] = 77;
  y[20][0] = 223;
  Newton(x,y);
  printf("\n");
  printf("La table de différence divisée de Newton est la suivante : \n");
  printDiffTable(y,21);
}
