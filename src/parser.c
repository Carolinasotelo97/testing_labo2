/*
 * parser.c
 *
 *  Created on: 29 jun. 2021
 *      Author: caroo
 */


#include "parser.h"
#include "libros.h"
#include <stdlib.h>

int parser_countriesFromTxt(LinkedList*pArray,FILE*pFile)
{
    int retorno=-1;
    int cant;
    char buffer[5][128];
    eLibros* newLibro;

    if(pArray!=NULL&&pFile!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);//leo el encabezado

        while(!feof(pFile))
        {
            cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);

            if(cant==5)//5 es la cant de campos de eLibro
            {
                newLibro=Libro_newParams(atoi(buffer[0]),buffer[1],atoi(buffer[2]),atoi(buffer[3]),atoi(buffer[4]));
                if(newLibro!=NULL)
                {
                    ll_add(pArray,newLibro);//agrego el Libro a la linkdlist
                    retorno=0;
                }
            }else
            {
                break;
            }
        }
    }

    return retorno;
}
