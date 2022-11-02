#include <stdio.h>
#include <stdlib.h>
#include "matr_e.h"

int main(){

    struct Matrix *matriz = (Matrix *)malloc(sizeof(Matrix));
    struct Matrix *matriz2 = (Matrix *)malloc(sizeof(Matrix));
    int i,j,x,opt;
    
    mt=1;
    
    create_matrix(matriz);
    

    for (int i = 0; i < matriz->size_m; i++)
    {
        add_itemx(matriz,i);
        
    }

    do
    {
        printf("\t.:WELCOME:.\n");
        printf("0. Crear matriz\n");
        printf("1. Obtener un elemento de la matriz\n");
        printf("2. Asignar un elemento a la matriz\n");
        printf("3. Sumar matrices\n");
        printf("4. Escalar la matriz\n");
        printf("5. Multiplicar matrices\n");
        printf("6. Transponer la matriz\n");
        printf("7. Imprimir la matriz\n");
        printf("8. Terminar el programa\n");
        printf("Opcion: ");
        scanf("%d",&opt);

        switch (opt)
        {
        
        case 0://creacion de matrices
            mt=2;
	    	create_matrix(matriz2);
	    	for (int i = 0; i < matriz2->size_m; i++)
    	    	{
        		add_itemx(matriz2,i);
            	}
            break;
        
        case 1: //obtiene elemento
            printf("Introduzca la fila: ");
            scanf("%d",&i);
            printf("Introduzca la columna: ");
            scanf("%d",&j);
            ObtenerElemento(matriz,i,j);
            break;
            
        case 2: //coloca elemento
            printf("Cuantos elementos desea introducir en esta matriz: ");
            scanf("%d",&cont);
            for (int a = 0; a< cont; a++)
            {
                printf("Introduzca la fila: ");
                scanf("%d",&i);
                printf("Introduzca la columna: ");
                scanf("%d",&j);
                printf("Introduzca el valor: ");
                scanf("%d",&x);
                AsignarElemento(matriz,i,j,x,a);
            }
            break;
            
        case 3:    //Suma 2 matrices
        if (mt == 2)
        {
            Sumar(matriz,matriz2);
        }
        else
        {
         printf("no se ha creado segunda matriz");
        }
            break;
            
        case 4: //Escala una matriz
            printf("introduzca el valor del factorial");
            scanf("%d",&x);
            ProductoPorEscalar(matriz,x);
            break;
            
        case 5: //multiplica 2 matrices
        if (mt == 2)
        {
            Producto(matriz,matriz2);
        }
        else
        {
            printf("no se ha creado segunda matriz");
        }
        	break;
        	
        case 6: //transpone 1 matriz
        	Transponer(matriz);
        	break;
        	
        case 7: //imprime 1 matriz
        	Imprimir(matriz);
        	break;
    		
        }
        
        }
        while (opt != 8);

}
