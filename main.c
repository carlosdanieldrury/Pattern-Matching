#include"biblioteca.h"
int main(int argc, char **argv)
{
	
	int x;
	char *texto;
	while (( x = getopt( argc, argv, "a:" )) != -1) { 	/*Primitiva GetOpt*/
		switch (x){
			case 'a':
			leArquivo(texto);
		}
			break;
		}
	return 0;
}

