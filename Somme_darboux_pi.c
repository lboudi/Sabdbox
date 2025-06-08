#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

  double delta_x,delta_y;
  int N;
  int cpt = 0;
  double Somme = 0.0;
  // N = 100;// Ceci fonctionne
  // delta_x = 1.0e-01; // Ceci fonctionne
  // delta_y = delta_x; // Ceci fonctionne
  printf("Rentrez N = ");
  scanf( "%d ",&N);
  printf("Rentrez le pas delta_x = ");
  scanf("%lf",&delta_x);
  printf("Rentrez le pas delta_x = ");
  scanf("%lf",&delta_y);
  for(int i = - N + 1 ; i < N ; i++)
    {
      for(int j = - N + 1 ; j < N ; j++)
	{
	  printf("On est a iteration %d, i = %d, j = %d, PI = %lf \n",cpt,i,j,Somme);

	  Somme = Somme + exp(-((i*delta_x)*(i*delta_x)) - ((j*delta_y)*(j*delta_y)))*delta_x*delta_y;
	  cpt += 1;
	  
	}
    }
  printf("Voici PI = %.16lf \n",Somme);
    

  return 0;
}
