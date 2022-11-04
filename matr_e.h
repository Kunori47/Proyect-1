#ifndef matr_e
#define matr_e

struct Matrix *create_matrix(struct Matrix *);
struct Row *create_row(int);
struct Cell *create_cell(int, int );
void add_itemy(struct Row *,int);
void add_itemx(struct Matrix *,int);
void Sumar(struct Matrix *);
void ProductoPorEscalar(struct Matrix *,int);
void Producto(struct Matrix *);
void ObtenerElemento(struct Matrix *,int ,int );
void Imprimir(struct Matrix *);
void AsignarElemento(struct Matrix *matriz,int , int ,int ,int );

#endif