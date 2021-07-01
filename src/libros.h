/*
 * datos.h
 *
 *  Created on: 29 jun. 2021
 *      Author: caroo
 */

#ifndef LIBROS_H_
#define LIBROS_H_

typedef struct{
	int id;
	char titulo;
	char autor;
	float precio;
	int editorialId;
}eLibros;

#endif /* LIBROS_H_ */

/** \brief Crea un nuevo libro en la memoria dinamica
 *
 * \return Puntero al nuevo libro
 *
 */
eLibros* libro_new();

/** \brief Crea un nuevo libro en la memoria dinamica asignando a sus campos los valores pasados
 *
 * \param id int Id que se le asignara
 * \param char*titulo titulo que se le asignara
 * \param Autor int Cant que se asignara
 * \param precio int Cant que se le asignara
 * \param editorialId int Cant que se le asignara
 * \return eLibros* Puntero al nuevo libro
 *
 */
eLibros* libro_newParams(int id,char*titulo,int Autor,int precio,int editorialId);

/** \brief Borra al libro y hace que apunte a NULL
 *
 * \param libro a borrar
 * \return void
 *
 */
void libro_delete(eLibros* this);

/** \brief Settea id al libro pasado por parametro
 *
 * \param this libro al que se le cargara el id pasado
 * \param id int Id a cargarle al libro
 * \return int 0 si se pudo settear y sino -1
 *
 */
int libro_setId(eLibros* this,int id);

/** \brief Carga en el puntero a id pasado el id del libro pasado
 *
 * \param this eLibros* libro del que se obtendra el id
 * \param id int* Puntero en el que se cargara el id
 * \return int 0 se se pudo obtener el id y sino -1
 *
 */
int libro_getId(eLibros* this,int* id);

/** \brief Settea titulo al libro pasado por parametro
 *
 * \param this libro al que se le cargara el titulo pasado
 * \param titulo char* titulo a cargarle al libro
 * \return int 0 si se pudo settear y sino -1
 *
 */
int libro_setTitulo(eLibros* this,char* titulo);

/** \brief Carga en el puntero a titulo pasado el titulo del libro pasado
 *
 * \param this eLibros* libro del que se obtendra el titulo
 * \param id int* Puntero en el que se cargara el titulo
 * \return int 0 se se pudo obtener el titulo y sino -1
 *
 */
int libro_getTitulo(eLibros* this,char* titulo);

/** \brief Settea la cantidad de Autor al libro pasado
 *
 * \param this eLibros* libro al que se le asignara la cant de Autor
 * \param Autor int Cant de Autor que se asignara al libro
 * \return int 0 si se pudo asignar y sino -1
 *
 */
int libro_setAutor(eLibros* this,int autor);

/** \brief Carga en el puntero a Autor pasado la cant de Autor del libro pasado
 *
 * \param this eLibros* libro del que se obtendra la cant de Autor
 * \param Autor int* Puntero en el que se cargara la cant de Autor
 * \return int 0 se se pudo obtener la cant de Autor y sino -1
 *
 */
int libro_getAutor(eLibros* this,int* autor);

/** \brief Settea la cantidad de precio al libro pasado
 *
 * \param this eLibros* libro al que se le asignara la cant de precio
 * \param precio int Cant de precio que se asignara al libro
 * \return int 0 si se pudo asignar y sino -1
 *
 */
int libro_setPrecio(eLibros* this,float precio);

/** \brief Carga en el puntero a precio pasado la cant de precio del libro pasado
 *
 * \param this eLibros* libro del que se obtendra la cant de precio
 * \param precio int* Puntero en el que se cargara la cant de precio
 * \return int 0 se se pudo obtener la cant de precio y sino -1
 *
 */
int libro_getPrecio(eLibros* this,float* precio);

/** \brief Settea la cantidad de editorialId al libro pasado
 *
 * \param this eLibros* libro al que se le asignara la cant de editorialId
 * \param editorialId int Cant de editorialId que se asignara al libro
 * \return int 0 si se pudo asignar y sino -1
 *
 */
int libro_setEdId(eLibros* this,int editorialId);

/** \brief Carga en el puntero a editorialId pasado la cant de editorialId del libro pasado
 *
 * \param this eLibros* libro del que se obtendra la cant de editorialId
 * \param editorialId int* Puntero en el que se cargara la cant de editorialId
 * \return int 0 se se pudo obtener la cant de editorialId y sino -1
 *
 */
int libro_getEdId(eLibros* this,int* editorialId);

/** \brief muestra un solo libro
 *
 * \param this eLibros* Puntero al libro a mostrar
 * \return void
 *
 */
void mostrarLibros(eLibros* this);
void libro_descuentos(void *libros);
int libro_sortAutor(void* libro1, void* libro2);

/** \brief Asigna valores a los campos Autor, editorialId e precio de un libro
 *
 * \param libro void* Puntero que contiene el libro a mostrar
 * \return void*
 *
 */
//void* asignarValores(void* libro);

/** \brief Determina si un libro fue o no exitoso (menos de 5k editorialId)
 *
 * \param libro void* Puntero al libro
 * \return int 1 si fue exitoso y sino 0
 *
 */
//int fueExitoso(void* libro);

/** \brief Determina si un libro esta o no al horno (cant precio triplica a la de Autor)
 *
 * \param libro void* Puntero que contiene al libro
 * \return int 1 si fue exitoso y sino 0
 *
 */
//int estaAlHorno(void* libro);

/** \brief Compara la cantidad de precio entre 2 libroes
 *
 * \param libro1 void* libro a comparar
 * \param libro2 void* libro a comparar
 * \return int 0 si la cant de precio es igual, -1 si libro1 tiene menos que libro 2 y sino 1
 *
 */
//int compararCantprecio(void* libro1,void* libro2);
