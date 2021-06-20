/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: Potencia de matriz dinamica
*FECHA DE CREACION : 2 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 4 DE JUNIO 2021
*/


#pragma once
#include "Matrix.h"
#include "List.h"
template<class T>
class Operation
{
public:
	/**
	 * @brief Reserva memoria para la matriz
	 * 
	 * @param longitud 
	 * @return la dirreccion de una matriz 
	 */
	T** segmentar(int);
	T** segmentar2(int,int);

	/**
	 * @brief Inicializa la matriz en cero
	 * 
	 * @param matriz_a 
	 * @param longitud 
	 */
	void encerar(Matrix<T> matriz_a, int,int);

	/**
	 * @brief Asigna Valores a la matriz
	 * 
	 * @param matriz_a
	 * @param longitud 
	 */
	//void llenar_aleatorio(Matrix matriz_a, int,int);
	//void ingresar(Matrix, int);

	/**
	 * @brief  Multiplicacion de Matrices
	 * 
	 * @param _matrix_a 
	 * @param _matrix_b 
	 * @param _matrix_c 
	 * @param longitud
	 */
	//void calcular(Matrix, Matrix, Matrix, int);

	/**
	 * @brief Impresion de la matriz
	 * 
	 * @param _matrix_a 
	 * @param longitud 
	 */
	//void imprimir(Matrix, int);
	void imprimir2(Matrix<T>, int,int);

	/**
	 * @brief Copia los datos de una matriz
	 * 
	 * @param _matrix_a 
	 * @param _matrix_b 
	 * @param longitud
	 */
	//void copiar_matriz(Matrix, Matrix, int);

	/**
	 * @brief  Calcula la potencia de una matriz
	 * 
	 * @param _matrix_a 
	 * @param _matrix_b 
	 * @param longitud
	 */
	/*void calcular_potencia(Matrix, Matrix, int, int);
	int contar_elementos(Matrix,int,int);
	void llenar_vector(Matrix,Matrix, int,int,int);
	List<T> llenar_lista(Matrix,int);
	int maximo_comun_divisor(List<T>);*/
	

};
template<class T>
T** Operation<T>::segmentar(int dim) {
    Matrix matrix;
    int j;
    matrix.set_matrix((T**)malloc(dim * sizeof(T*)));
    for (j = 0; j < dim; j++) {
        *(matrix.get_matrix() + j) = (T*)malloc(dim * sizeof(T));
    }
    return matrix.get_matrix();
}
template<class T>
T** Operation<T>::segmentar2(int filas, int columnas)
{
    Matrix<T> matrix;
    int j;
    matrix.set_matrix((T**)malloc(columnas * sizeof(T*)));
    for (j = 0; j < filas; j++) {
        *(matrix.get_matrix() + j) = (T*)malloc(columnas * sizeof(T));
    }
    return matrix.get_matrix();
}
template<class T>
void Operation<T>::encerar(Matrix<T> matrix, int dim,int column) {
    int i, j;
    for (i = 0; i < dim; i++)
        for (j = 0; j < column; j++)
            *(*(matrix.get_matrix() + i) + j) = 0;
}
/*template<class T>
void Operation<T>::llenar_aleatorio(Matrix matriz, int filas, int columnas)
{
    std::srand(std::time(nullptr));
    int i, j;
    for (i = 0; i < filas; i++)
        for (j = 0; j < columnas; j++)

            *(*(matriz.get_matrix() + i) + j) = 1 + rand() % (100);
}
template<class T>
void Operation<T>::ingresar(Matrix matrix, int dim) {
    int i, j;
    cout << "Ingrese los datos:" << endl;
    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++) {
            cout << "[" << i + 1 << "]" << "[" << j + 1 << "] :";
            cin >> (*(*(matrix.get_matrix() + i) + j));
        }
}
template<class T>
void Operation<T>::calcular(Matrix matrix_1, Matrix matrix_2, Matrix matrix_r, int dim) {
    int i, j, k;
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            for (k = 0; k < dim; k++) {
                *(*(matrix_r.get_matrix() + i) + j) = *(*(matrix_r.get_matrix() + i) + j) + *(*(matrix_1.get_matrix() + i) + k) * *(*(matrix_2.get_matrix() + k) + j);
            }
        }
    }
}
template<class T>
void Operation<T>::imprimir(Matrix matrix, int dim) {
    int i, j;
    printf("\n");
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            printf("%d", *(*(matrix.get_matrix() + i) + j));
            printf("%*s", j + 5, "");
        }
        printf("\n");
    }
}*/
template<class T>
void Operation<T>::imprimir2(Matrix<T> matrix, int filas, int columnas)
{
    int i, j;
    printf("\n");
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            printf("%d", *(*(matrix.get_matrix() + i) + j));
            printf("%*s", j + 5, "");
        }
        printf("\n");
    }
}
/*template<class T>
void Operation<T>::copiar_matriz(Matrix m1, Matrix m2, int dim) {
    int i, j;
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            *(*(m1.get_matrix() + i) + j) = *(*(m2.get_matrix() + i) + j);
        }
    }
}
template<class T>
void Operation<T>::calcular_potencia(Matrix m1, Matrix mr, int dim, int potencia) {
    int i = 0, j = 0;
    Matrix m2;
    m2.set_matrix(segmentar(dim));
    encerar(m2, dim);
    copiar_matriz(m2, m1, dim);
    copiar_matriz(mr, m1, dim);
    if (potencia == 0) {
        encerar(mr, dim);
        for (j = 0; j < dim; j++)
            *(*(mr.get_matrix() + j) + j) = 1;
    }
    for (i = 0; i < potencia - 1; i++) {
        encerar(mr, dim);
        calcular(m2, m1, mr, dim);
        copiar_matriz(m2, mr, dim);

    }



}


template<class T>
int Operation<T>::contar_elementos(Matrix matrix, int filas, int columnas)
{
    int i, j, k, contador = 0, cont2 = 0;
    //printf("\n");
    for (k = 1; k <= 100; k++) {
        contador = 0;
        for (i = 0; i < filas; i++) {
            for (j = 0; j < columnas; j++) {

                //cout << "si entra" << endl;
                if (k == *(*(matrix.get_matrix() + i) + j)) {

                    contador = contador + 1;
                }



            }


        }
        if (contador > 0) {
            cont2 = cont2 + 1;
        }

    }
    return cont2;
}
template<class T>
void Operation<T>::llenar_vector(Matrix matrix, Matrix vector, int filas, int columnas, int dim)
{
    int i, j, k, contador = 0, cont2 = 0, fila = 0;
    //printf("\n");
    for (k = 1; k <= 100; k++) {
        contador = 0;
        for (i = 0; i < filas; i++) {
            for (j = 0; j < columnas; j++) {

                //cout << "si entra" << endl;
                if (k == *(*(matrix.get_matrix() + i) + j)) {

                    contador = contador + 1;
                }



            }


        }
        if (contador > 0) {
            *(*(vector.get_matrix() + fila) + 0) = k;
            *(*(vector.get_matrix() + fila) + 1) = contador;
            fila = fila + 1;
            cont2 = cont2 + 1;

        }

    }

}
template<class T>
List<T> Operation<T>::llenar_lista(Matrix vector, int filas)
{
    List<T> lista;
    for (int i = 0; i < filas; i++) {
        if (*(*(vector.get_matrix() + filas) + 1) > 1) {
            lista.insertar_por_la_cola(*(*(vector.get_matrix() + filas) + 0));

        }
    }
    return lista;
}
template<class T>
int Operation<T>::maximo_comun_divisor(List<T>)
{
    int mcd = 0;

    return mcd;
}*/
