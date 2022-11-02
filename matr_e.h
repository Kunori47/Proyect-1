typedef struct Datos
{
	int size_m;
    	int size_n;
    	int i;
    	int j;
    	int  value;

}dato;

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

void Sumar( Matrix *matriz,Matrix *matriz2) {
Matrix *aux1 = matriz;
Matrix *aux2 = matriz2;

 for (;aux1->rowlist != NULL; aux1->rowlist = aux1->rowlist->next) 
    {
        printf("%d -->",aux1->rowlist->posicion);
        for ( ; aux1->rowlist->celda!=NULL; aux1->rowlist->celda = aux1->rowlist->celda->next)
        {
            printf("%d -->",aux2->rowlist->celda->value+aux1->rowlist->celda->value);
            aux2->rowlist->celda = aux2->rowlist->celda->next;
        }
        printf("\n");
        aux2->rowlist = aux2->rowlist->next;  
    }
    
    printf("\n"); 

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

void Producto( Matrix *matriz,Matrix *matriz2){
int multiplicacion;

	for (;matriz->rowlist->celda!=NULL; matriz->rowlist->celda = matriz->rowlist->celda->next)
	{
		
		for (;matriz2->rowlist != NULL; matriz2->rowlist = matriz2->rowlist->next)
		{
			multiplicacion=0;
			for(;matriz2->rowlist->celda!=NULL; matriz2->rowlist->celda = matriz2->rowlist->celda->next)
			{
				multiplicacion=matriz->rowlist->celda->value*matriz2->rowlist->celda->value;
				matriz->rowlist->celda->value=multiplicacion;
				matriz->rowlist->celda = matriz->rowlist->celda->next;
			}
		}
	}
}

void Transponer( Matrix *matriz){
int i=0,j=0,transpuesta[1000][1000],b,a;
	
	for (;matriz->rowlist->celda!=NULL; matriz->rowlist->celda = matriz->rowlist->celda->next)
	{
		
		for (;matriz->rowlist != NULL; matriz->rowlist = matriz->rowlist->next)
		{			
			if (matriz->rowlist->celda->value != 0)
            		{
            		printf(" Pos:%d Valor:%d -->",matriz->rowlist->celda->posicion,matriz->rowlist->celda->value);
            		}
		}
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
    struct Datos m1[cont];

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

    if(mt == 1){

        FILE *data;

        data = fopen("m1.bin", "wb");

        fseek(data,0,SEEK_END);
        fprintf(data,"%d, %d, %d",m1[a].i,m1[a].j,m1[a].value);
    
        fwrite(&m1[a],sizeof(dato),3,data);

        fclose(data);

    }

    
}