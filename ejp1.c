#include <stdio.h>

int bis(int x, int m, int pos){
	int resultado;
	if (pos!=0){
		resultado = (1 << (m - pos));
		pos--;
		return bis(x,m,pos);
	}
	else
		return resultado;
}

int bic(int x, int m, int pos){
    int resultado;
    if (pos!=0){
      resultado = (x & (~(1 << (m - pos))));
      pos--;
      return bis(x,m,pos);
    }
    else
      return resultado;
}

/* Calcular x|y usando solo llamadas a las funciones bis y bic */
int bool_or(int x, int y) {
	int resultado = bis(x,y,4) ;
	return resultado;
}

/* Calcula x^y usando solo llamadas a las funciones bis y bic */
int bool_xor(int x, int y) {
	int resultado = bic(x,y,4);
	return resultado;
}

int main(){
	int x = 10, m = 0xD;
	printf("%d bis: %d \n", x,bool_or(x,m));
	printf("%d bic: %d \n", x,bool_xor(x,m));
}
