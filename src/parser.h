/*
 * parser.h
 *
 *  Created on: 29 jun. 2021
 *      Author: caroo
 */
#include "LinkedList.h"
#include <stdio.h>

#ifndef PARSER_H_
#define PARSER_H_



#endif /* PARSER_H_ */

/** \brief Parsea los datos de un archivo .csv(modo texto)
 *
 * \param LinkedList*pArray Lista en la que se agregaaran los datos parseados
 * \param FILE*pFile Archivo desde el cual se parsean los datos
 * \return int 0 si salio todo bien y sino -1
 *
 */
int parser_librosFromTxt(LinkedList*pArray,FILE*pFile);
