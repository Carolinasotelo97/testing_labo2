/*
 * datos.c
 *
 *  Created on: 29 jun. 2021
 *      Author: caroo
 */
#include "libros.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "validaciones.h"


eLibros* libro_new()
{
    eLibros* nuevolibro= (eLibros*) malloc(sizeof(eLibros));

    if(nuevolibro!=NULL)//se encontro espacio en memoria
    {
        nuevolibro->id=0;
        nuevolibro->titulo=0;
        nuevolibro->autor =0;
        nuevolibro->precio=0;
        nuevolibro->editorialId =0;
        strcpy(nuevolibro->autor," ");
        strcpy(nuevolibro->titulo," ");//limpie los campos
    }

    return nuevolibro;
}

eLibros* libro_newParams(int id,char* titulo,char autor, float precio,int editorialId)
{
    eLibros* newlibro=libro_new();

    if(newlibro!=NULL)
    {
        if(libro_setId(newlibro,id)==-1||
           libro_setTitulo(newlibro,titulo)==-1||
           libro_setAutor(newlibro,autor)==-1||
           libro_setPrecio(newlibro,precio)==-1||
           libro_setEd(newlibro,editorialId))//si algun setter falla
        {
            libro_delete(newlibro);
        }
    }

    return newlibro;
}

void libro_delete(eLibros* this)
{
    if(this!=NULL)
    {
        free(this);
        this=NULL;
    }
}

int libro_setId(eLibros* this,int id)
{
    int retorno=-1;

    if(this!=NULL&&id>=0)
    {
        this->id=id;
        retorno=0;
    }

    return retorno;
}

int libro_getId(eLibros* this,int* id)
{
    int retorno=-1;

    if(this!=NULL&&id!=NULL)
    {
        *id=this->id;
        retorno=0;
    }

    return retorno;
}

int libro_setTitulo(eLibros* this,char* titulo)
{
    int retorno=-1;

    if(this!=NULL&& titulo !=NULL)
    {
        strcpy(this->titulo, titulo);
        retorno=0;
    }

    return retorno;
}

int libro_getTitulo(eLibros* this,char* titulo)
{
    int retorno=-1;

    if(this!=NULL&& titulo !=NULL)
    {
        strcpy(titulo,this->titulo);
        retorno=0;
    }

    return retorno;
}

int libro_setAutor(eLibros* this, char autor)
{
    int retorno=-1;

    if(this!=NULL&& autor != NULL)
    {
        strcpy(this->autor, autor);
        retorno=0;
    }

    return retorno;
}

int libro_getAutor(eLibros* this,char* autor)
{
    int retorno=-1;

    if(this!=NULL&&autor!=NULL)
    {
        *autor =this->autor;
        retorno=0;
    }

    return retorno;
}

int libro_setPrecio(eLibros* this, float precio)
{
    int retorno=-1;

    if(this!=NULL)
    {
        this->precio =precio;
        retorno=0;
    }

    return retorno;
}

int libro_getPrecio(eLibros* this,float* precio)
{
    int retorno=-1;

    if(this!=NULL&& precio!=NULL)
    {
        *precio =this->precio;
        retorno=0;
    }

    return retorno;
}

int libro_setEdId(eLibros* this,int editorialId)
{
    int retorno=-1;

    if(this!=NULL)
    {
        this->editorialId= editorialId;
        retorno=0;
    }

    return retorno;
}

int libro_getEdId(eLibros* this,int* editorialId)
{
    int retorno=-1;

    if(this!=NULL&& editorialId!=NULL)
    {
        *editorialId=this->editorialId;
        retorno=0;
    }

    return retorno;
}

void mostrarlibro(eLibros* this)
{
    int auxId;
    char auxTitulo[50];
    char auxAutor[50];
    float auxPre;
    int auxEdId;

    if(!libro_getId(this,&auxId)&&
       !libro_getPrecio(this,&auxPre)&&
       !libro_getAutor(this,&auxAutor)&&
       !libro_getTitulo(this,auxTitulo)&&
       !libro_getEdId(this,&auxEdId))//obtengo los valores de todos los campos
    {
        printf(" %02d --- %20s ---  %20s ---  %.4f --- %5dk\n",auxId,auxTitulo,auxAutor,auxPre,auxEdId);
    }
}

int libro_sortAutor(void* libro1, void* libro2){
	int retorno = 0;
	char auxAutor1[50];
	char auxAutor2[50];

	if(libro1 != NULL && libro2 != NULL){
		if(libro_getAutor((eLibros*)libro1, auxAutor1) == 0 && libro_getAutor((eLibros*)libro2, auxAutor2)==0){
			if(strcmp(auxAutor1, auxAutor2)> 0){
				retorno =1;
			}
			if(strcmp(auxAutor1, auxAutor2)< 0){
				retorno = -1;
			}
		}
	}
	return retorno;
}

void libro_descuentos(void *libros){
	if(libros !=NULL ){
		if(libro_getEdId((eLibros*)libros) == 1 &&
				libro_getPrecio((eLibros*) libros) >= 300){
			libro_setPrecio((eLibros*)libros,
					(libro_getPrecio((eLibros*)libros )
						-	libro_getPrecio((eLibros*) libros) *.20));
		}
		if(libro_getEdId((eLibros*)libros) == 2 && libro_getPrecio((eLibros*)libros) <= 200){
			libro_setPrecio((eLibros*)libros,
					(libro_getPrecio((eLibros*)libros)
							- libro_getPrecio((eLibros*)libros)* .10));

		}
	}
}
/*
void* asignarValores(void* libro)
{
    eLibros* country= (eLibros*) libro;
    int cantInfectados;
    int cantRecuperados;
    int cantMuertos;

    /*un valor de recuperados entre 50k y 1000k personas,
    infectados con valores entre 400k y 2000 y muertos entre 1k y 50k.

    if(country!=NULL)
    {
        cantInfectados=rand()%(1601)+400;
        cantRecuperados=rand()%(951)+50;
        cantMuertos=rand()%(50)+1;

        libro_setMuertos(country,cantMuertos);
        libro_setInfectados(country,cantInfectados);
        libro_setRecuperados(country,cantRecuperados);
    }

    return country;
}


int fueExitoso(void* libro)
{
    int retorno=0;
    eLibros* precio= (eLibros*) libro;
    int precios;

    if(precio !=NULL)
    {
        libro_getMuertos(country,&muertos);

        if(muertos<5)//menos de 5000 muertos
        {
            retorno=1;
        }
    }

    return retorno;
}


int estaAlHorno(void* libro)
{
    int retorno=0;
    eLibros* country= (eLibros*) libro;
    int infectados;
    int recuperados;

    if(country!=NULL)
    {
        libro_getInfectados(country,&infectados);
        libro_getRecuperados(country,&recuperados);

        if(infectados>=(recuperados*3))//el numero de infectados triplica al de recuperados
        {
            retorno=1;
        }
    }

    return retorno;
}


int compararCantInfectados(void* libro1,void* libro2)
{
    int retorno=0;
    eLibros* country1= (eLibros*) libro1;
    eLibros* country2= (eLibros*) libro2;
    int cantInf1;
    int cantInf2;

    if(libro1!=NULL&&libro2!=NULL)
    {
        libro_getInfectados(country1,&cantInf1);
        libro_getInfectados(country2,&cantInf2);

        if(cantInf1<cantInf2)
        {
            retorno=-1;
        }else if(cantInf1>cantInf2)
        {
            retorno=1;
        }
    }

    return retorno;
}
*/
