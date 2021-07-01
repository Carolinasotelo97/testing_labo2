/*
 * controller.c
 *
 *  Created on: 29 jun. 2021
 *      Author: caroo
 */


#include "controller.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include "libros.h"

int controller_cargarArchivoTxt(LinkedList*pArray,char*path)
{
    int retorno=-1;
    FILE* f;

    if(pArray!=NULL)
    {
        f=fopen(path,"r");//lo abro en modo lectura
        if(f!=NULL)
        {
            if(!parser_librosFromTxt(pArray,f))
            {
                retorno=0;
            }

            fclose(f);
        }//archivo no es NULL
    }//validacion parametros

    return retorno;
}

int controller_listarLibros(LinkedList* pArray)
{
    int retorno=-1;
    int len;
    eLibros* auxLibro;
    int auxId;
    float auxPre;
    int auxIdEd;
    char auxTitulo[50];
    char auxAutor[50];

    if(pArray!=NULL)
    {
        //id, nombre, recuperados, infectados, muertos
        system("cls");
        printf("             ***Lista de Libroes***\n\n");
        printf(" ID               NOMBRE   RECUPERADOS INFECTADOS MUERTOS\n");

        len=ll_len(pArray);

        for(int i=0;i<len;i++)
        {
            auxLibro=ll_get(pArray,i);
            if(auxLibro!=NULL)
            {
                mostrarLibro(auxLibro);
                retorno=0;
            }
        }
    }

    return retorno;
}

int controller_asignarEstadisticas(LinkedList*pArray)
{
    int retorno=-1;
    LinkedList* auxLl=NULL;//aca se guarda el retorno de ll_map

    if(pArray!=NULL)
    {
        auxLl=ll_map(pArray,asignarValores);
        if(auxLl!=NULL)
        {
            pArray=auxLl;//si auxLl es NULL no se lo asigno a la lista original

            ll_deleteLinkedList(auxLl);
            retorno=0;
        }
    }

    return retorno;
}

int controller_filtrarPorExitosos(LinkedList*pArray)
{
    int retorno=-1;
    LinkedList* listaExitosos=NULL;

    if(pArray!=NULL)
    {
        listaExitosos=ll_filter(pArray,fueExitoso);
        if(listaExitosos!=NULL)
        {
            if(!controller_guardarArchivoTxt(listaExitosos,"LibroesExitosos.csv"))
            {
            controller_listarLibroes(listaExitosos);
            printf("\n\nSe creo un archivo LibroesExitosos.csv");
            retorno=0;
            }

            ll_deleteLinkedList(listaExitosos);//la borro pq ya la guarde

        }
    }

    return retorno;
}

int controller_filtrarPorEnElHorno(LinkedList*pArray)
{
    int retorno=-1;
    LinkedList*listaEnElHorno=NULL;

    if(pArray!=NULL)
    {
        listaEnElHorno=ll_filter(pArray,estaAlHorno);
        if(listaEnElHorno!=NULL)
        {
            if(!controller_guardarArchivoTxt(listaEnElHorno,"LibroesEnElHorno.csv"))
            {
                controller_listarLibroes(listaEnElHorno);
                printf("\nSe creo el archivo LibroesEnElHorno.csv");
                retorno=0;
            }

            ll_deleteLinkedList(listaEnElHorno);//la borro pq ya la guarde

        }
    }

    return retorno;
}

int controller_ordenarPorInfeccion(LinkedList*pArray)
{
    int retorno=-1;

    if(pArray!=NULL)
    {
        if(!ll_sort(pArray,compararCantInfectados,0))
        {
            controller_listarLibroes(pArray);
            retorno=0;
        }
    }

    return retorno;
}

int controler_informarMasCastigado(LinkedList*pArray)
{
    int retorno=-1;
    int len=ll_len(pArray);
    int cantMuertos;
    eLibros* auxLibro=NULL;
    int maximoMuertos;
    char auxNombre[25];

    if(pArray!=NULL)
    {
        system("cls");
        printf("***Libro(es) mas castigado(s)***\n\n");
        printf(" NOMBRE              MUERTOS\n");

        for(int i=0;i<len;i++)
        {
            auxLibro=ll_get(pArray,i);
            if(auxLibro!=NULL)
            {
                if(!Libro_getMuertos(auxLibro,&cantMuertos))
                {
                    if(i==0||maximoMuertos<cantMuertos)
                    {
                        maximoMuertos=cantMuertos;
                    }
                }//fin if de getter de muertos
            }//if Libro!=NULL
        }//fin for

        for(int i=0;i<len;i++)
        {
            auxLibro=ll_get(pArray,i);
            if(auxLibro!=NULL)
            {
                if(!Libro_getMuertos(auxLibro,&cantMuertos))
                {
                    if(maximoMuertos==cantMuertos)
                    {
                        Libro_getNombre(auxLibro,auxNombre);//guardo el nombre dedl Libro
                        printf(" %-20s %dk\n",auxNombre,cantMuertos);
                        retorno=0;

                    }
                }//fin if de getter de muertos
            }//if Libro!=NULL
        }//fin for
    }

    return retorno;
}

int controller_guardarArchivoTxt(LinkedList*pArray,char*path)
{
    int retorno=-1;
    FILE* f;
    int len;
    int auxId;
    char auxNombre[25];
    int auxRec;
    int auxInf;
    int auxM;
    eLibros* auxLibro=NULL;

    if(pArray!=NULL&&path!=NULL)
    {
        f=fopen(path,"w");//abro el archivo en modo escritura
        if(f!=NULL)
        {
            len=ll_len(pArray);

            fprintf(f,"id,nombre,recuperados,infectados,muertos\n");//encabezado
            for(int i=0;i<len;i++)
            {
                auxLibro=ll_get(pArray,i);
                if(auxLibro!=NULL)
                {
                    if(!Libro_getId(auxLibro,&auxId)&&
                       !Libro_getInfectados(auxLibro,&auxInf)&&
                       !Libro_getMuertos(auxLibro,&auxM)&&
                       !Libro_getNombre(auxLibro,auxNombre)&&
                       !Libro_getRecuperados(auxLibro,&auxRec))//funcionaron todos los getter
                    {
                        fprintf(f,"%d,%s,%d,%d,%d\n",auxId,auxNombre,auxRec,auxInf,auxM);
                        retorno=0;
                    }
                }//Libro!=NULL
            }//fin for

            fclose(f);

        }//validacion file
    }//validacion params

    return retorno;
}
