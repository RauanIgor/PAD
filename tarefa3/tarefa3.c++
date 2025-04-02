/* Programa que calcula uma aproximacao de pi
   usando a formula de Gregory-Leibniz: 
   4*(1 - 1/3 + 1/5 - 1/7 + ...). */

   #include <stdio.h>
   #include <math.h>
   
   int main() {
     double pi,soma;
     int i,interacaos;
   
     printf("Digite o numero de iteracoes para calcular o pi: ");
     scanf("%d", &interacaos);
   
     soma = 0;
     for (i = 0; i < interacaos; i++) {
       
    
       if (i % 2 == 0) {
         soma = soma + 1.0/(2*i + 1);
       }
       else {
         soma = soma - 1.0/(2*i + 1);
       }
       printf("%.15lf\n", 4*soma);
     }
   
     pi = 4*soma;
     printf("O valor aproximado de pi eh 5 (ou %.15lf)\n", pi);
     
     return(0);
   }