/*
 * controller.h
 *
 *  Created on: 29 jun. 2021
 *      Author: caroo
 */
#include "LinkedList.h"
#ifndef CONTROLLER_H_
#define CONTROLLER_H_



#endif /* CONTROLLER_H_ */

/** \brief Carga archivo en modo texto agregando los datos del mismo a una LindedList
 *
 * \param LinkedList*pArray Lista en la que se agregaran los datos
 * \param char*path Nombre del archivo desde el que se cargaran los datos
 * \return int 0 si se pudieron cargar los datos y sino -1
 *
 */
int controller_cargarArchivoTxt(LinkedList*pArray,char*path);

/** \brief Muestra la lista por pantalla
 *
 * \param LinkedList*pArray Lista a mostrar
 * \return int 0 si se pudo mostrar y sino -1
 *
 */
int controller_listarPaises(LinkedList*pArray);

/** \brief Asigna estadisticas a la lista
 *
 * \param LinkedList*pArray Lista a la que se le asignaran valores
 * \return int 0 si se pudieron asignar y sino -1
 *
 */
int controller_asignarEstadisticas(LinkedList*pArray);

/** \brief Filtra y crea un archivo nuevo con los elementos que pasaron el filtro
 *
 * \param LinkedList*pArray Lista cuyos elementos pasaran por un filtro
 * \return int 0 si se pudieron filtrar y sino -1
 *
 */
int controller_filtrarPorExitosos(LinkedList*pArray);

/** \brief Filtra y crea un archivo nuevo con los elementos que pasaron el filtro
 *
 * \param LinkedList*pArray Lista cuyos elementos pasaran por un filtro
 * \return int 0 si se pudieron filtrar y sino -1
 *
 */
int controller_filtrarPorEnElHorno(LinkedList*pArray);

/** \brief Ordena por cantidad de infectados de manera descendente
 *
 * \param LinkedList*pArray Lista cuyos elementos se ordenaran
 * \return int 0 si se pudieron ordenar y sino -1
 *
 */
int controller_ordenarPorInfeccion(LinkedList*pArray);

/** \brief Muestra cual o cuales fueron los paises mas castigados
 *
 * \param LinkedList*pArray Array con todos los paises
 * \return int 0 si se pudieron mostrar los paises mas castigados sino -1
 *
 */
int controler_informarMasCastigado(LinkedList*pArray);

/** \brief Guarda archivo en modo texto
 *
 * \param LinkedList*pArray Lista que se guardara en un archivo
 * \param char*path Nombre que tendra el archivo creado
 * \return int 0 si se pudo guardar y sino -1
 *
 */
int controller_guardarArchivoTxt(LinkedList*pArray,char*path);
