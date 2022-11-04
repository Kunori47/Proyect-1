#include <stdio.h>
#include <stdlib.h>
#include "matr_e.h"

typedef struct Matrix2
{
	    int size_m;
    	int size_n;
    	int i;
    	int j;
    	int  value;

}Matrix2;

typedef struct Matrix
{
    int size_n;
    int size_m;
    struct Row *rowlist;
}Matrix;

typedef struct Row
{
    int posicion;
    struct Cell *celda;
    struct Row *next;
}Row;

typedef struct Cell
{
    int posicion;
    int value;
    struct Cell *next; 
}Cell;

int mt,cont;

Matrix *create_matrix(Matrix *matriz){

if (mt==1)
{
    printf("Introduzca el numero de filas: ");
    scanf("%d",&matriz->size_m);
    printf("Introduzca el numero de columna: ");
    scanf("%d",&matriz->size_n);    
    matriz->rowlist = NULL;

    return matriz;
}
else
{
    printf("Introduzca el numero de filas: ");
    scanf("%d",&matriz->size_m);
    printf("Introduzca el numero de columna: ");
    scanf("%d",&matriz->size_n);    
    matriz->rowlist = NULL;

    return matriz;
}

}

struct Row *create_row(int n){

    struct  Row *fila;

    fila = (struct Row *)malloc(sizeof(struct Row));
    
    fila->posicion = n;
    fila->next = NULL;

    return fila;
}

struct Cell *create_cell(int m, int value){

    struct Cell *celda;

    celda = (struct Cell *)malloc(sizeof(struct Cell));

    celda->posicion = m;
    celda->value = value;
    celda->next = NULL;

    return celda;

}

void add_itemy(Row *fila,int j){

        struct Cell *celda = create_cell(j,0);
        struct Cell *aux;
        struct Cell *now = fila->celda;
        
        while (now != NULL)
        {
            aux = now;
            now = now->next;

        }
        if (fila->celda == now)
        {
            fila->celda = celda;
        }
        else
        {
            aux->next = celda;
        }
        celda->next = now;

}


void add_itemx(Matrix *matriz,int n){

    struct Row *fila = create_row(n);
    struct Row *now = matriz->rowlist;
    struct Row *aux;
   
if (mt==1){
    while (now!= NULL)
    {
        aux = now;
        now = now->next;
    }
    if (matriz->rowlist == now)
    {
        matriz->rowlist = fila;
    }
    else
    {
       aux->next= fila;

    }
    for (int j = 0; j < matriz->size_n; j++)
    {
        add_itemy(fila,j);
    }
    
    fila->next = now;
}
else
{
while (now!= NULL)
    {
        aux = now;
        now = now->next;
    }
    if (matriz->rowlist == now)
    {
        matriz->rowlist = fila;
    }
    else
    {
       aux->next= fila;

    }
    for (int j = 0; j < matriz->size_n; j++)
    {
        add_itemy(fila,j);
    }
    
    fila->next = now;
}

}

void Sumar(struct Matrix *matriz) {
    Matrix *aux1 = matriz;
    int a;
    Matrix2 aux2;
   
    for (;aux1->rowlist != NULL; aux1->rowlist = aux1->rowlist->next)
    {
        printf("%d -->",aux1->rowlist->posicion);
        FILE *data;
        data = fopen("m2.bin", "rb");
        for (int a = 0; a <= cont; a++)
        {
            fseek(data,0,SEEK_SET);
            fread(&aux2,sizeof(Matrix2),3,data);
            printf("%d",aux2.i);
            if(aux2.i == aux1->rowlist->posicion)
                {
                    for ( ; aux1->rowlist->celda!=NULL; aux1->rowlist->celda = aux1->rowlist->celda->next){
                    if (aux2.j == aux1->rowlist->celda->posicion)
                    {
                        printf("%d -->",aux1->rowlist->celda->value + aux2.value);
                    }
                    else
                    {
                        printf("%d -->",aux1->rowlist->celda->value);
                    }
                }

                }
        }
        printf("\n");
        fclose(data);
}

}


void ProductoPorEscalar( Matrix *matriz,int valor){

	Matrix *aux1 = matriz;	
	
    for (;aux1->rowlist != NULL; aux1->rowlist = aux1->rowlist->next) 
    {
    	printf("%d -->",matriz->rowlist->posicion);
        for ( ; aux1->rowlist->celda!=NULL; aux1->rowlist->celda = aux1->rowlist->celda->next) 
        {
        
            aux1->rowlist->celda->value = aux1->rowlist->celda->value*valor;
            if (matriz->rowlist->celda->value != 0)
            {
            printf(" Pos:%d Valor:%d -->",aux1->rowlist->celda->posicion,aux1->rowlist->celda->value);
            } 
        }
         printf("\n");   
    }
    
    printf("\n"); 
   
}

void Producto( Matrix *matriz){
}

void Transponer( Matrix *matriz){
int aux[1000][1000],a,b,i,j;
int transp[1000][1000];
i=0;j=0;
 for (;matriz->rowlist != NULL; matriz->rowlist = matriz->rowlist->next)
    {
        
        for ( ; matriz->rowlist->celda!=NULL; matriz->rowlist->celda = matriz->rowlist->celda->next) 
        {
    aux[i][j]=matriz->rowlist->celda->value;
    j++;
  }
  b=j;
  j=0;
  i++;
  a=i;
 }
 
 for(i=0;i<b;i++)
 {
  for(j=0;j<a;j++)
  {
   transp[j][i]=aux[i][j];
  }
 }
 
 for(i=0;i<a;i++)
 {
  for(j=0;j<b;j++)
  {
  printf("%d -->",transp[i][j]); 
  }
  printf("\n");
 }
}
	
void ObtenerElemento( Matrix *matriz,int n,int m){

	Matrix *aux = matriz;
	
	for (int i = 0; i < n; i++) //se ubica en la fila 
    {
        aux->rowlist = aux->rowlist->next;
    }
	
    for (int i = 0; i < m; i++) //se ubica en la columna 
    {
        aux->rowlist->celda = aux->rowlist->celda->next;
    }
    printf("En la fila %d y columna %d , se encuentra el valor = %d \n",n,m,aux->rowlist->celda->value);
     
}

void Imprimir( Matrix *matriz){
			
    for (;matriz->rowlist != NULL; matriz->rowlist = matriz->rowlist->next) //viaja por todas las filas
    {
        printf("%d -->",matriz->rowlist->posicion);
        
        for ( ; matriz->rowlist->celda!=NULL; matriz->rowlist->celda = matriz->rowlist->celda->next) //viaja por todas las columnas
        {
        if (matriz->rowlist->celda->value != 0)
            {
            printf(" Pos:%d Valor:%d -->",matriz->rowlist->celda->posicion,matriz->rowlist->celda->value);
            }
        }
        printf("\n");    
    }
    
    printf("\n");

}

void AsignarElemento(Matrix *matriz,int n, int m,int value,int a){

    struct Row *fila = matriz->rowlist;
    struct Row *aux;
    struct Cell *aux2;
    struct Cell *celda;
    struct Cell *asig = create_cell(m,value);
    struct Matrix2 m2;

    if (mt == 1)
    {
        
        for (int i = 0; i < n; i++)
        {
            aux = fila;
            fila = fila->next;
        }
        celda = fila->celda;
	
        for (int i = 0; i < m; i++)
        {
            aux2 = celda;
            celda = celda->next;
        }
        if (matriz->rowlist->celda == celda)
        {
            matriz->rowlist->celda->value = value;
        }
        else
        {
            celda->value = value;
        }
        asig->next = celda;

    }
    
    if(mt == 2){

        FILE *data;

        data = fopen("m2.bin", "wb");

        fseek(data,0,SEEK_END);
        m2.i = n;
        m2.j = m;
        m2.value = value;
    
        fwrite(&m2,sizeof(Matrix2),3,data);

        fclose(data);

    }

    
}
