#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<unistd.h>
#include<sys/resource.h>
#include<string.h>
#include<time.h>
#include<string.h>
#include<math.h>

#define MAXTAMTEXTO     1000
#define MAXTAMPADRAO    50
#define MAXCHAR         128
#define NUMMAXERROS     10
typedef char TipoTexto[MAXTAMTEXTO];
typedef char TipoPadrao[MAXTAMPADRAO];
TipoTexto T;
TipoPadrao P;
void leArquivo(char *texto);
void menu(char *Texto, int tamanhoTexto);
void BMH(TipoTexto T, TipoPadrao P);
void next(char *x, int m, int *vetNext);
void kmp(TipoPadrao x, TipoTexto y);
short compare(char *P, char *T, int location, long length);
long hasher(char *T, int st, long length, int base, int module);
void RabinKarp(char  *T, char *P);

