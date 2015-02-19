#include"biblioteca.h"



void BMH(TipoTexto T, TipoPadrao P)
{ 
	long cont;
	long m, n, i, j, k, d[MAXCHAR + 1];
	n = strlen(T);
	m = strlen(P);
	
  for (j = 0; j <= MAXCHAR; j++) d[j] = m;
  for (j = 1; j < m; j++) d[P[j-1]] = m - j;
  i = m;
  while (i <= n)    /*-- Pesquisa --*/
    { k = i;
      j = m;
      while (T[k-1] == P[j-1] && j > 0) { k--; j--; }
      if (j == 0){
		  cont++; 
		printf("Casamento na posicao: %3ld\n", k + 1);
	}
      i += d[T[i-1]];
    }
    printf("Padrao ocorreu %ld vezes.", cont);
}
void next(TipoPadrao x, int m, int *vetNext){
     int j, k;
     j=0;
     k=-1;
     vetNext[0] = -1;
     while(j<m-1){
                  while((k > -1) && (x[j] != x[k]))
                           k = vetNext[k];
                  j = j+1;
                  k = k+1;
                  if(x[j] == x[k])
                          vetNext[j] = vetNext[k];
                  else
                      vetNext[j] = k;
     }
}

void kmp(TipoPadrao x, TipoTexto y){
    int i, j, n, m, k;
    long cont = 0;
    int *vetNext;
    i = 0;
    j=0;
    m = strlen(x);
    n = strlen(y);
    vetNext = (int *)malloc(sizeof(int)*m);
    next(x, m, vetNext);
    for(k=0; k<n; k++){
    while ((i<n) && (j<m)){
          while((j > -1) && (x[j] != y[i]))
                   j = vetNext[j];
          i = i+1;
          j = j+1;
    }
    if(j == m){
         printf("\nHouve casamento na posicao %d\n", (i-m)+1);
         cont++;
         j=0;
    }
} 
printf("Padrao ocorreu %ld vezes.", cont);          
}
 
 
long hash(char vet[]){
    long num =0;
    long total = 0;
    int n = strlen(vet);
    int i = 0;
    for(i=0;i<n;i++){
        num = ((MAXCHAR*num)+vet[i])%16777213;
    }
    return num;
}

long hashtexto(char vet[],char pad[],int l){
    long num =0;
    long total = 0;
    int n = strlen(pad);
    int i = 0;
    for(i=l;i<(l+n);i++){
        num = ((MAXCHAR*num)+vet[i])%16777213;
    }
    return num;
}

int rabin_karp(char p[],char t[]){
    if (strlen(t)<strlen(p)){
        return 0;
    }
    long h,ht;
    int i = 0;
    long cont = 0;
    int n = strlen(p);
    int m = strlen(t);
    for (i=0;i<(m-n+1);i++){
        if(hash(p)==hashtexto(t,p,i)){
			printf("Houve casamento na posicao %d", i+1);
            cont++;
        }
    }
    printf("Padrao ocorreu %ld vezes.", cont);
    return cont;
}


void RK(TipoTexto T, TipoPadrao P, int d, long q){
	int i, j, p, n, m, t, k, controle = 1;
	long h;
	n = strlen(T);
	m = strlen(P);
	h = d^(m-1) % q;
	p = 0;
	t = 0;
	for(i=0; i<m; i++){
		p = (d * p + P[i]) % q;
		t = (d * t + T[i]) % q;

	}
	printf("\nEsse e o p diferente %d\n", p);
		printf("\nEsse e o t diferente %d\n", t);
	for(j=0; j<=(n-m); j++){
		
		if (p == t){
			printf("Entrou aqui\n");
			for(k=1; k<m; k++){
				if((P[k] == T[j+1]) && (controle == 1)){
					controle = 1;
				}
				else{
					controle = 0;
				}
			if(controle == 1)
				printf("Padrao ocorre %d\n", j);
			}
		}
		if(j < (n-m)){
			t = (d*(t - (T[j+1]*h)) + T[j+m+1]) % q;
			printf("\nEsse e o p %d\n", p);
		printf("\nEsse e o t%d\n", t);
		}

	}
}



void menu(char *Texto, int tamanhoTexto){
	clock_t inicio,fim;
	double tempo = 0;
     int opcao, i, z;
     char padrao[MAXTAMPADRAO];
     printf("\033[01;34m");
     printf("Digite o padrao\n");
     scanf("%[^\n]", padrao);
     printf("---------- Escolha uma opcao ----------\n\n");
     printf("1)Algoritmo Rabin-Karp\n");
     printf("2)Knuth-Morris-Pratt\n");
     printf("3)Boyer-Moore-Horspool\n");
     scanf("%d", &opcao);
     switch(opcao){
                   case 1:
						inicio=clock();
						rabin_karp(padrao, Texto);
						fim = clock();
						tempo = (double)(((double)fim-(double)inicio)/CLOCKS_PER_SEC);
						printf("\n%3.3f Segundos para executar o algoritmo \n\n",tempo);
                        break;
                   case 2:
						inicio=clock();                   
						kmp(padrao, Texto);
						fim = clock();
						tempo = (double)(((double)fim-(double)inicio)/CLOCKS_PER_SEC);
						printf("\n%3.3f Segundos para executar o algoritmo \n\n",tempo);
                        break;
                   case 3:
						inicio=clock();
						BMH(Texto, padrao);
						fim = clock();
						tempo = (double)(((double)fim-(double)inicio)/CLOCKS_PER_SEC);
						printf("\n%3.3f Segundos para executar o algoritmo \n\n",tempo);
                        break;          
                   }
}





void leArquivo(char *texto){
	int cont=0;
	int i;
	long long max = 500000000;
	char caractere;
	texto = optarg;
	char *vetorTexto;
	FILE *p;
	p=fopen (texto,"r+");
	vetorTexto = (char *) malloc (max * sizeof(char *));
	while(!feof(p)){
				caractere = getc(p); //Le cada caractere do arquivo e insere em um vetor
				printf("%c", caractere);
				vetorTexto[cont] = caractere;
				cont++;		
	}
	fclose(p);
	menu(vetorTexto, cont);
}




