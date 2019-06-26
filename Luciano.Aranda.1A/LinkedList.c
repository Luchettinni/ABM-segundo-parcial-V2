#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "LinkedList.h"

#endif // LINKEDLIST_H_INCLUDED

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex);

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if ( this != NULL )
    {
        returnAux = this->size;
    }

    return returnAux;
}

static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;

    if ( this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
        pNode = this->pFirstNode;

        for (int i = 0; i < nodeIndex; i++)
        {
            pNode = pNode->pNextNode;
        }
    }

    return pNode;
}

static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    int returnAux = -1;

    Node* newNode;
    Node* auxNode;

    if ( this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        newNode = (Node*) malloc(sizeof(Node));

        if ( newNode != NULL )
        {
            newNode->pElement = pElement;
            newNode->pNextNode = NULL;

            auxNode = getNode(this, nodeIndex-1); // si no lo encuentra me devuelve NULL

            if ( auxNode == NULL )
            {
                newNode->pNextNode = this->pFirstNode;
                this->pFirstNode = newNode;
            }
            else
            {
                newNode->pNextNode = auxNode->pNextNode;
                auxNode->pNextNode = newNode;
            }
        }
        this->size++;
        returnAux = 0;
    }

    return returnAux;
}

int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int lastIndex = ll_len(this);

    if ( this != NULL )
    {
        addNode(this,lastIndex,pElement);
        returnAux = 0;
    }

    return returnAux;

    /*int returnAux = -1;
    int lastIndex = ll_len(this);

    Node* newNode;
    Node* prevNode;

    if ( this != NULL )
    {
        newNode = (Node*) malloc(sizeof(Node));

        if ( newNode != NULL )
        {
            newNode->pElement = pElement;
            newNode->pNextNode = NULL;

            prevNode = getNode(this, lastIndex-1);

            if ( prevNode == NULL )
            {
                this->pFirstNode = newNode;
            }
            else
            {
                prevNode->pNextNode = newNode;
            }
        }
        this->size++;

        returnAux = 0;
    }

    return returnAux;*/

}

void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;

    Node* pNode = NULL;

    if ( this != NULL && index >= 0 && index < ll_len(this))
    {
        pNode = getNode(this, index);

        if ( pNode != NULL )
        {
            returnAux = pNode->pElement;
        }
    }
    return returnAux;
}

int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;

    Node* auxNode = NULL;

    if( this != NULL && index >=0 && index < ll_len(this) )
    {

        auxNode = getNode(this,index); // con esto obtengo el lugar donde quiero meter el elemento

        if(auxNode != NULL)
        {
            auxNode->pElement = pElement ;
        }
        returnAux=0;
    }

    return returnAux;
}

int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;

    Node* auxNode = NULL;
    Node* pNode = NULL;

    if ( this != NULL && index >= 0 && index < ll_len(this) )
    {
        auxNode = getNode(this, index);
        pNode = getNode(this, index-1);

        if ( auxNode != NULL )
        {
            if ( index != 0 && pNode != NULL )
            {
                pNode->pNextNode = auxNode->pNextNode;
                free(auxNode);
            }
            else
            {
                this->pFirstNode = auxNode->pNextNode;
                free(auxNode);
            }
            this->size--;
            returnAux = 0;
        }
    }

    return returnAux;
}

int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    Node* auxNode = NULL;

    if ( this != NULL )
    {
        for ( int i = ll_len(this); i > 0 ; i-- )
        {
            auxNode = getNode(this, i);
            free(auxNode);
            this->size--;
        }

        returnAux = 0;
    }

    return returnAux;
}

int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if ( this != NULL )
    {
       ll_clear(this);
       free(this);
       returnAux = 0;
    }

    return returnAux;
}

int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* auxNode = NULL;

    if ( this != NULL )
    {
        for (int i = 0; i < ll_len(this); i++)
        {
            auxNode = getNode(this, i);
            if ( auxNode->pElement == pElement )
            {
                returnAux = i;
                break;
            }
        }
    }

    return returnAux;
}

int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if ( this != NULL )
    {
        returnAux = 1;

        if ( ll_len(this) > 0)
        {
            returnAux = 0;
        }
    }

    return returnAux;
}

int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux;

    returnAux = addNode(this, index, pElement);

    return returnAux;
}

void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if( this != NULL && index >= 0 && index < ll_len(this) )
    {
        returnAux = ll_get(this,index);
        ll_remove(this,index);
    }

    return returnAux;
}

int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* auxNode = NULL;

    if ( this != NULL )
    {
        returnAux = 0;
        for (int i = 0; i < ll_len(this); i++)
        {
            auxNode = getNode(this, i);
            if ( auxNode->pElement == pElement )
            {
                returnAux = 1;
                break;
            }
        }
    }

    return returnAux;
}

int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    Node* auxNode = NULL;
    Node* auxNode2 = NULL;

    if ( this != NULL && this2 != NULL )
    {
        returnAux = 1;

        for (int i = 0; i < ll_len(this); i++)
        {
            auxNode = getNode(this, i);
            auxNode2 = getNode(this2, i);

            if ( auxNode2->pElement != auxNode->pElement )
            {
                returnAux = 0;
                break;
            }
        }
    }

    return returnAux;
}

LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;


    void* toLoadElement = NULL;

    if ( this != NULL && from >= 0 && to <= ll_len(this) )
    {
        cloneArray = ll_newLinkedList();

        if ( cloneArray != NULL )
        {
            for ( int i = from; i <= to; i++ )
            {
                toLoadElement = ll_get(this, i);

                if ( toLoadElement != NULL )
                {
                    ll_add(cloneArray, toLoadElement);
                }
            }
        }
    }

    return cloneArray;
}

LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    void* toLoadNode = NULL;

    if ( this != NULL )
    {
        cloneArray = ll_newLinkedList();

        if ( cloneArray != NULL )
        {
            for ( int i = 0; i < ll_len(this); i++)
            {
                toLoadNode = ll_get(this,i);
                if( toLoadNode != NULL)
                {
                    ll_add(cloneArray, toLoadNode);
                }
            }
        }
    }

    return cloneArray;
}

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    void* elementoI = NULL;
    void* elementoJ = NULL;
    void* aux = NULL;

    if ( this != NULL && pFunc != NULL && order >= 0 && order <= 1 )
    {
        for ( int i = 0; i < ll_len(this); i++ )
        {
            for ( int j = i+1; j < ll_len(this); j++ )
            {
                elementoI = ll_get(this, i);
                elementoJ = ll_get(this, j);

                if ( order == 1 && pFunc(elementoI, elementoJ) > 0 )
                {
                    aux = elementoI;
                    ll_set(this, i, elementoJ);
                    ll_set(this, j, aux);
                }

                if ( order == 0 && pFunc(elementoI, elementoJ) < 0 )
                {
                    aux = elementoI;
                    ll_set(this, i, elementoJ);
                    ll_set(this, j, aux);
                }
            }
        }
        returnAux = 0;
    }

    return returnAux;

}
