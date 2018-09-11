/*
9. Escreva um programa que leia dois números em binário e calcula um número binário que
é a soma dos dois números dados. Utilize a função da questão anterior.
*/

 void somabit(int, int, int *, int *);
 int somaBytes(int, int, int *);
 int ehByte(int);
 void fatorarByte(int[], int);

 int main(){
   int a, b, c, d;
   printf("Digite binário de 8 bits: ");
   scanf("%d", &a);
   printf("Digite binário de 8 bits: ");
   scanf("%d", &b);
   printf("\t%8d\n+\n\t%8d\n=\n\t", a, b);
   d = somaBytes(a, b, &c);
   if(c != TRUE){
     printf("%8d\n", d );
   }else{
     printf("Erro ao somar os bytes.\n");
   }
   return 0;
 }

 void fatorarByte(int vetor[], int byte){
   int i;
   i = 7;
   while(i >= 0){
     vetor[i] = byte / pow(10, i);
     byte = byte - vetor[i] * pow(10, i);
     i--;
   }
 }
 int somaBytes(int byte1, int byte2, int *erro){
   int byte3, bit1, bit2, bitAdicional, bitSoma, i;
   int vByte1[8], vByte2[8];
   byte3 = 0;
   *erro = FALSE;
   if(ehByte(byte1) && ehByte(byte2)){
     fatorarByte(vByte1, byte1);
     fatorarByte(vByte2, byte2);
     i=0;
     bitAdicional = 0;
     while(i<=7){
       somabit(vByte1[i], vByte2[i], &bitAdicional, &bitSoma);
       byte3 += bitSoma * pow(10, i);
       i++;
     }
     byte3 += bitAdicional * pow(10, 8);
   }else{
     *erro = TRUE;
   }
   return byte3;
 }
 int ehByte(int byte){
   int i, bit;
   int ehValido = TRUE;
   if(byte <= pow(10, 8) && byte >= 0){
     i=7;
     while(i>=0 && ehValido){
       bit = byte / pow(10, i);
       if(bit > 1){
         ehValido = FALSE;
       }
       byte = byte - bit * pow(10, i);
       i--;
     }
   }else{
     ehValido = FALSE;
   }
   return ehValido;
 }
