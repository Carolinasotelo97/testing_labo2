/*
 ============================================================================
 Name        : SegundoParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include <string.h>
#include "LinkedList.h"
#include "controller.h"

/** \brief Muestra al usuario un menu de opciones y le pide que elija una
 *
 * \return int La opcion elegida
 *
 */
int menu();

int main()
{
    setbuf(stdout, NULL);
    LinkedList*pandemia=ll_newLinkedList();
    char confirma='n';
    int flagMap=0;//esta flag se levanta cuando se le asigna
    char path[25];

    do
    {
        switch(menu())
        {
        case 1:
            if(ll_isEmpty(pandemia))
            {
                getString(path,sizeof(path),"\nIngrese nombre del archivo a cargar:","\nIngrese nombre del archivo sin extension .csv:");
                strcat(path,".csv");//agrego la extension del archivo
                if(!controller_cargarArchivoTxt(pandemia,path))
                {
                    printf("\nLos paises fueron cargados con exito!");
                }else
                {
                    printf("\nNo se pudieron cargar los paises");
                }
            }else//si la linkedlist no esta vacia
            {
                printf("\nLos paises ya fueron cargados");
            }
            break;
        case 2:
            if(!ll_isEmpty(pandemia))
            {
                controller_listarPaises(pandemia);
            }else
            {
                printf("\nAun no hay paises que mostrar");
            }
            break;
        case 3:
            if(!ll_isEmpty(pandemia))
            {
                if(!controller_asignarEstadisticas(pandemia))
                {
                    printf("\nEstadisticas asignadas exitosamente");
                    flagMap=1;
                }else
                {
                    printf("\nProblemas al asignar estadisticas");
                }
            }else
            {
                printf("\nNo hay paises a los que asignar estadisticas");
            }
            break;
        case 4:
            if(!ll_isEmpty(pandemia)&&flagMap)
            {
                if(controller_filtrarPorExitosos(pandemia))//no dio 0(no funciono)
                {
                    printf("\nProblemas para crear archivo...");
                }
            }else
            {
                printf("\nPrimero debe asignar estadisticas");
            }
            break;
        case 5:
            if(!ll_isEmpty(pandemia)&&flagMap)
            {
                if(controller_filtrarPorEnElHorno(pandemia))//no dio 0(no funciono)
                {
                    printf("\nProblemas para crear archivo...");
                }
            }else
            {
                printf("\nPrimero debe asignar estadisticas");
            }
            break;
        case 6:
            if(!ll_isEmpty(pandemia)&&flagMap)
            {
                controller_ordenarPorInfeccion(pandemia);
            }else
            {
                printf("\nPrimero debe asignar estadisticas");
            }
            break;
        case 7:
            if(!ll_isEmpty(pandemia)&&flagMap)
            {
                if(controler_informarMasCastigado(pandemia))//si me da 0 no entra
                {
                    printf("\nProblemas para informar paises mas castigados");
                }
            }else
            {
                printf("\nPrimero debe asignar estadisticas");
            }
            break;
        case 8:
            getCharTwoOptions(&confirma,"\nEsta seguro de que desea salir? (s/n)","Ingrese s o n:",'s','n');
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }

        printf("\n\n");
        system("pause");

    }while(confirma!='s');

    ll_deleteLinkedList(pandemia);

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("   ***MENU PANDEMIA***\n\n");
    printf("1.Cargar archivo\n");
    printf("2.Imprimir lista\n");
    printf("3.Asignar estadisticas\n");
    printf("4.Filtrar por paises exitosos\n");
    printf("5.Filtrar por paises en el horno\n");
    printf("6.Ordenar por nivel de infeccion\n");
    printf("7.Mostrar mas castigado(s)\n");
    printf("8.Salir\n");
    printf("_________________________________\n");

    getInt(&opcion,"Elija una opcion:","Elija una opcion valida:");

    return opcion;
}
