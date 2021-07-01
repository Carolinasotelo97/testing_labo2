/*
 * LinkedList.c
 *
 *  Created on: 29 jun. 2021
 *      Author: caroo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex, void* pElement);

LinkedList* ll_newLinkedList(void){
	LinkedList* this= malloc(sizeof(LinkedList));

	if(this != NULL){
		this ->pFirstNode = NULL; //limpio los campos
	}

	return this;
}

int ll_len(LinkedList* this){
	int returnAux = -1;

	if(this != NULL){
		returnAux = this ->size;
	}
	return returnAux;
}

static Node* getNode(LinkedList* this, int nodeIndex){
	Node* auxNode=NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)){
		auxNode = this ->pFirstNode;
		while(nodeIndex > 0){
			auxNode = auxNode -> pNextNode;
			nodeIndex --;
		}
	}
	return auxNode;
}

Node* test_getNode(LinkedList* this, int nodeIndex){
	return getNode(this, nodeIndex);
}

static int addNode(LinkedList* this, int nodeIndex, void* pElement){
	int returnAux = -1;
	int len = ll_len(this);
	Node* newNode = NULL;
	Node* prevNode;

	if(this != NULL && nodeIndex >= 0 && nodeIndex <= len){
		newNode= (Node*) malloc(sizeof(Node));

		if(newNode != NULL){
			newNode -> pElement = pElement;
			newNode -> pNextNode = NULL;

			if(nodeIndex == 0){
				newNode -> pNextNode = this -> pFirstNode;
				this -> pFirstNode = newNode;
			}else{
				prevNode = getNode(this, nodeIndex -1);
				newNode -> pNextNode = prevNode -> pNextNode;
				prevNode -> pNextNode = newNode;
			}
			this-> size++;
			returnAux = 0;
		}
	}
	return returnAux;
}

int test_addNode(LinkedList* this, int nodeIndex, void* pElement){
	return addNode(this, nodeIndex, pElement);
}

int ll_add(LinkedList* this, void* pElement){
	return addNode(this, ll_len(this), pElement);
}

void* ll_get(LinkedList* this, int index){
	void* returnAux = NULL;
	Node* auxNode = NULL;

	if(this!= NULL && index >=0 && index < ll_len(this)){
		auxNode = getNode(this, index);
		if(auxNode != NULL){
			returnAux = auxNode -> pElement;
		}
	}
	return returnAux;
}

ll_set(LinkedList* this, int index, void* pElement){
	int returnAux = -1;
	Node* auxNode = NULL;

	if(this != NULL && index >= 0 && index < ll_len(this)){
		auxNode = getNode(this, index);

		if(auxNode != NULL){
			auxNode -> pElement = pElement;
			returnAux = 0;
		}
	}
	return returnAux;
}

int ll_remove(LinkedList* this, int index){
	int returnAux = -1;
	Node* auxNode = NULL;
	Node* prevNode = NULL;

	if(this != NULL && index >= 0 && index<ll_len(this)){
		auxNode = getNode(this, index);

		if(auxNode != NULL){
			if(index == 0){
				this -> pFirstNode = auxNode -> pNextNode;
			}else{
				prevNode = getNode(this, index -1);
				if(prevNode != NULL){
					prevNode -> pNextNode = auxNode ->pNextNode;
				}
			}

		}
		free(auxNode);
		auxNode = NULL;
		this -> size --;
		returnAux = 0;
	}
	return returnAux;
}

int ll_clear(LinkedList* this){
	int returnAux = -1;
	int len;

	if(this != NULL){
		len = ll_len(this);
		for(int i = len -1; i>=0; i--){
			ll_remove(this, i);
		}
		returnAux = 0;
	}
	return returnAux;
}

int ll_deleteLinkedList(LinkedList* this){
	int returnAux = -1;

	if(this != NULL){
		if(!ll_clear(this)){
			free(this);
			this = NULL;
			returnAux = 0;
		}
	}
	return returnAux;
}

int ll_indexOf(LinkedList* this, void* pElement){
	int returnAux = -1;
	int len;
	void* aux = NULL;

	if(this != NULL){
		len = ll_len(this);
		for(int i=0; i<len; i++){
			aux= ll_get(this, i);
			break;
		}
	}
	return returnAux;
}

int ll_isEmpty(LinkedList* this){
	int returnAux = -1;

	if(this != NULL){
		returnAux = ll_len(this)? 0 : 1;

	}
	return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    return addNode(this,index,pElement);
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this!=NULL&&index>=0&&index<ll_len(this))
    {
        returnAux=ll_get(this,index);
        if(ll_remove(this,index)==-1)
        {
            returnAux=NULL;
        }
    }


    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        returnAux=ll_indexOf(this,pElement)==-1 ? 0 : 1;
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int len;
    void* aux;

    if(this!=NULL&&this2!=NULL)
    {
        returnAux=1;
        len=ll_len(this2);
        for(int i=0;i<len;i++)
        {
            aux=ll_get(this2,i);
            if(!ll_contains(this,aux))
            {
                returnAux=0;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* aux=NULL;
    int len=ll_len(this);

    if(this!=NULL&&from>=0&&from<len&&to>from&&to<=len)
    {
        cloneArray=ll_newLinkedList();
        if(cloneArray!=NULL)
        {
            for(int i=from;i<to;i++)
            {
                aux=ll_get(this,i);
                ll_add(cloneArray,aux);
            }
        }
    }

    return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    return ll_subList(this,0,ll_len(this));
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* aux=NULL;
    int len;
    int autor;

    if(this!=NULL&&pFunc!=NULL&&(order==0||order==1))
    {
        len=ll_len(this);
        for(int i=0;i<len-1;i++)
        {
            for(int j=i+1;j<len;j++)
            {
                autor=pFunc(ll_get(this,i),ll_get(this,j));
                if((autor=1&&order)||(autor==-1&&!order))
                {
                    aux=ll_get(this,i);
                    ll_set(this,i,ll_get(this,j));
                    ll_set(this,j,aux);
                }
            }
        }

        returnAux=0;
    }

    return returnAux;

}

/** \brief Retorna una nueva lista con los elementos que hacen que pFunc retorne 1
 *
 * \param this Lista a filtrar
 * \param pFunc Funcion que sabe como filtrar la lista
 * \return Un nuevo linkedList con los elementos que pasan el filtro
 *
 */
LinkedList* ll_filter (LinkedList* this, int (*pFunc) (void* pElement))
{
    LinkedList* nuevaLista=NULL;
    int len;
    void* pAux=NULL;

    if(this!=NULL&&pFunc!=NULL)
    {
        nuevaLista=ll_newLinkedList();
        if(nuevaLista!=NULL)
        {
            len=ll_len(this);
            for(int i=0;i<len;i++)
            {
                pAux=ll_get(this,i);
                if(pFunc(pAux))//si no da 0
                {
                    ll_add(nuevaLista,pAux);
                }
            }
        }
    }

    return nuevaLista;
}

/** \brief Itera todos los elementos de la lista y asigna valores a sus campos devolviendo una lista con los mismo
 *
 * \param Linkedlist* this Lista a cuyos elementos se le asignaran valores
 * \param *pFunc Funcion a la que se pasan todos los elemenots de la lista
 * \return LinkedList* Lista con campos asignados a los elementos
 *
 */
LinkedList* ll_map (LinkedList* this, void*(*pFunc) (void* element))
{
    LinkedList* newList=NULL;
    int len;
    void*aux=NULL;

    if(this !=NULL && pFunc !=NULL)
    {
        newList=ll_newLinkedList();
        if(newList!=NULL)
        {
            len=ll_len(this);
            for(int i=0;i<len;i++)
            {
                aux=ll_get(this,i);
                aux=pFunc(aux);

                ll_add(newList,aux);
            }
        }
    }

    return newList;
}
