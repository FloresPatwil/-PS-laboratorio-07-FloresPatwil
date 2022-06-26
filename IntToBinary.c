#include <stdio.h>
#include <math.h>

int decabin(int n, int *R){

    *R = n%2;               //almaceno el resto en R
    return (n - *R)/2;
}

int main(){
    int B[100];     //tamaño arbitrario, por no dejar vacio el corchete
    int n;
    int R;
    printf("Ingrese un entero: ");
    scanf("%i", &n);

    int i = 0;
    while( n >= 2 ){            //el bucle finaliza cuando ya no es posible seguir dividiendo por 2
        n = decabin( n, &R );
        B[i] = R;     //armo el vector con los restos de las divisiones
        i++;
    }

    int j = 0;
    for( j; j<=i; j++ ){      //imprime todos los elementos almacenados en el vector
        printf("%i", B[j]);
    }
    return 0;
}
