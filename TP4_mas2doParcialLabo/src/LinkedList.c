#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"



static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)//RESERVA ESPACIO EN MEMORIA, INICIALIZA PFIRST Y SIZE
{
    LinkedList* this; //SI NO ENCUENTRA MEMORIA DEVUELVE NULO
    this=(LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
    	this->pFirstNode=NULL;
    	this->size =0;
    }
    else
    {
    	printf(" * No hay espacio en memoria para crear la Likedlist * ");
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	int len=-1;
	if(this != NULL)
	{
		len=this->size;
	}

	return len;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* nodoEnEseIndex=NULL;
	Node* nodoOrigen=NULL;
	Node* proxNodo=NULL;
	int len=ll_len(this);
	int i;

	if(this != NULL && nodeIndex >=0 && nodeIndex <= len)
	{
		for(i=0;i<len;i++)
		{
			if(i==0)
			{
				nodoOrigen=this->pFirstNode;
				if(i==nodeIndex)
				{
					nodoEnEseIndex=nodoOrigen;
					return nodoEnEseIndex;
				}
			}
			else
			{
				proxNodo=nodoOrigen->pNextNode;
				nodoOrigen=proxNodo;

				if(i==nodeIndex)
				{
					nodoEnEseIndex=nodoOrigen;
					return nodoEnEseIndex;
				}
			}
		}
	}
	return NULL;//SI NO SE ENCONTRÓ EL INDICE BUSCADO DEVUELVE NULO
}
//----------------------------------------------------------------------------------------------------------
/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int returnAux = -1;
	Node* nodoNuevo=NULL;
	Node* nodoOrigen;
	int len=ll_len(this);

			if(this != NULL && nodeIndex >=0 && nodeIndex <= len)//NO VALIDO EL ELEMENTO PORQUE PUEDE SER NULO SIN PROBLEMA
			{
					nodoNuevo=(Node*)malloc(sizeof(Node));
					nodoNuevo->pElement=pElement;//YA LE ASIGNO AL NUEVO NODO EL ELEMENTO QUE LLEGA POR PARÁMETRO, DADO QUE LO HACE EN CUALQUIERA  DE LOS CASOS

					if(nodoNuevo!=NULL)
					{
						if(nodeIndex == 0)
						{
							nodoNuevo->pNextNode=this->pFirstNode;//RESCATO LA DIRE DE MEMORIA DEL NODO QUE VOY A REEMPLAZAR(PARA NO PERDER LA REFERENCIA DEL QUE LE SIGUE)
							this->pFirstNode=nodoNuevo;//APUNTO EL FIRST A LA DIRECCIÓN DE MEM. DEL NODO QUE ACABO DE INSERTAR EN 0
						}								//AHORA YA ES UN TRANCITO
						else
						{
							nodoOrigen=getNode(this,(nodeIndex-1));//EL NODO DE ORIGEN ES EL QUE BUSCO MENOS UNO Y EL QUE TENGO QUE COPIAR
							nodoNuevo->pNextNode=nodoOrigen->pNextNode;//Primero igualo pNextdel nuevo, a pNext del que había para no perder ref
							nodoOrigen->pNextNode=nodoNuevo;
						//	nodoNuevo->pElement=pElement;

						}
						this->size++;
						returnAux=0;
				}
			}
			 return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)//AGREGA UN ELEMENTO AL FINAL DE LA LISTA
{
    int returnAux = -1;
    int len=ll_len(this);
    if(this != NULL)
    {

    	addNode(this,len,pElement);//SI NO HAY ELEMENTOS EN LA LISTA LO AGREGA EN 0, POR SER EL FINAL
    	returnAux=0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux=NULL;
    Node* node=NULL;
    int len=ll_len(this);

    if(this !=NULL && index>=0 && index<=len)
    {
    	node=getNode(this,index);
    	if(node!=NULL)
    	{
    		returnAux=node->pElement;
    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)//PISA EL ELEMENTO DEL ÍNDICE QUE SE LE INDIQUE CON EL NUEVO ELEMENRO
{
    int returnAux = -1;
    Node* nuevoNode=NULL;
    int len=ll_len(this);
    if(this != NULL && index >=0 && index <=len)//No valido Elemento porque puede ser nulo
    {
    	nuevoNode=getNode(this,index);
    	if(nuevoNode != NULL)
    	{
    		nuevoNode->pElement=pElement;
    		returnAux=0;
    	}
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* nodetoRemove=NULL;
    Node* nodeAux=NULL;
    int len=ll_len(this);

    if(this!= NULL && index >=0 && index <= len)
    {
    		nodetoRemove=getNode(this,index);

    		if(index==0)
    		{

    			this->pFirstNode=nodetoRemove->pNextNode;//SI FUESE EL PRIMERO TOMA LA DIRE DE MEMORIA DE FIRTS PARA NO PERDER LA REFERENCIA DEL RESTO
    		}
    		else
    		{
    			nodeAux=getNode(this,index-1);//GETEO EL NODO ANTERIOR AL QUE VOY A REMOVER PARA SALVAR LA DIRE DE MEME QUE CONTENÍA
    			nodeAux->pNextNode=nodetoRemove->pNextNode;//A LA POCISIÓN ANTERIOR LE ASIGNO LA DIRE DEL NODO AL QUE APUNTABA EL QUE VOY A REMOVER

    		}
    		this->size--;//reacomodo antes de liberar
    		free(nodetoRemove);

			returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    int len=ll_len(this);

    if(this != NULL)
    {
    	for(i=len;i>=0;i--)//BORRA TODOS LOS ELEMENTOS DE ATRÁS PARA ADELANTE PARA NO PERDER LA REFERENCIA
    	{
    		ll_remove(this,i);//EL REMOVE ADEMÁS DE BORRAR EL ELEMENTO DESENGANCHA ESE NODO
    		returnAux=0;
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
                        (1)si esta vacío
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	ll_clear(this);//ELIMINO LOS ELEMENTOS
    	free(this);//EL ESPACIO RESERVADO PARA LA LINKEDLIST
    	returnAux=0;
    	if (ll_isEmpty(this)==1)
    	{
    	   	returnAux=0;
    	}
    	else
    	{
   	    	returnAux=1;
  	    }
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)//DEVUELVE LA POCISIÓN (INDICE)EN LA QUE ESTÁ EL ELEMENTO QUE ESTOY BUSCANDO
{
    int returnAux=-1;
    Node* node;
    int i;
    int len=ll_len(this);

    if(this != NULL)//EL ELEMENTO PUEDE SER NULO
    {
    	for(i=0;i<len;i++)
    	{
    		node=getNode(this,i);
    		if(node->pElement == pElement)
    		{
    			returnAux=i;
    		}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
	int returnAux=-1;//ERROR
	int len=ll_len(this);
    if(this != NULL)
    {
    	if(len>0)
    	{
    		returnAux=0;//RETORNA 0 SI HAY ELEMENTOS EN LA LISTA
    	}
    	else
    	{
    		returnAux=1;//1 DE NO HABERLOS
    	}
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
    int returnAux = -1;
    int len=ll_len(this);

    if(this != NULL && index >=0 && index <=len)
    {
    	returnAux=addNode(this,index,pElement);
    }

    return returnAux;
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
    //Node* node;
    int len=ll_len(this);
    if(this != NULL && index>=0 && index <=len)
    {
    	returnAux=ll_get(this,index);//GUARDO EL PUNTERO AL ELEMENTO ELEMENTO PARA RETORNARLO ANTES DE BORRARLO
    	ll_remove(this,index);//BORRO EL ELEMENTO DE ESA POSICIÓN
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento

*/
int ll_contains(LinkedList* this, void* pElement)//igual que el index of pero este no devuelve el índice
{
    int returnAux=-1;
    Node* node=NULL;
    int len=ll_len(this);
    int i;

    if(this != NULL)
      {
    	returnAux=0;//Si el elemento no es igual, gira pero nunca entra al if por lo tanto devuelve 0;

    		for(i=0;i<len;i++)
    		{
    			node=getNode(this,i);
    			if(node->pElement==pElement)
    			{
    				returnAux=1;//Encontró el elemento
    			}
    		}
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
    int i;
    int j;
    int len1=ll_len(this);
    int len2=ll_len(this2);
    //Node* node2=NULL;
    void* element1;
    void* element2;

    if(this!= NULL && this2!=NULL)
    {
    	returnAux=1;//Si nunca entra al if es porque todos los elementos de 1 están en 2;

    	for(i=0;i<len1;i++)
    	{
    		element1=ll_get(this,i);//Recorre lista elemento a elemento y a cada uno lo busca con el segundo for

    		for(j=0;j<len2;i++)
    		{
    			element2=ll_get(this2,j);

    			if(element1!=element2)//ENTRA AL IF, SÓLO SI LO ENCONTRÓ Y LO INFORMA Y BREKEA
    			{
    				returnAux=0;
    				break;
    			}
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
LinkedList* ll_subList(LinkedList* this,int from,int to)//GENERA UN NUEVO LINKEDLIST PERO SÓLO CON LKOS ELEMENTOS DESDE FROM HASTA TO
{
    LinkedList* cloneArray = NULL;
    int len=ll_len(this);
    int i;
    void* element;

    if(this != NULL && from >=0 && from <=len && to >=0 && to <=len && from<to)//POR EJEMPLO SI QUIERO COPIAR SÓLO EL 4 , TENGO QUE PONER 4 Y 5
    {
        cloneArray=ll_newLinkedList();//GENERO LA LINKEDLIST RECIÉN ACÁ PARA NO CREAR UNA LISTA SI THIS LLEGASE A SER NULO

    	for(i=from;i<to;i++)
    	{
    			element=ll_get(this,i);
    			ll_add(cloneArray,element);//AGREGO LO PEDIDO AL NUEVO LINKEDLIST
    	}
    }
    else
    {
     printf("\n * Error, no se pudo crear la sublista * \n");
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
    LinkedList* cloneArray = NULL;
    int len=ll_len(this);
    int i;
    void* element;

    if(this != NULL)
    {
        cloneArray=ll_newLinkedList();//GENERO LA LINKEDLIST RECIÉN ACÁ PARA NO CREAR UNA LISTA SI THIS LLEGASE A SER NULO

    	for(i=0;i<len;i++)
    	{
    		element=ll_get(this,i);
    		ll_add(cloneArray,element);
    	}
    }
    else
    {
     printf("\n * Error, no se pudo crear una nueva lista * \n");
    }

    return cloneArray;
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
	void* element1;
	void* element2;
	int len=ll_len(this);
	int i;
	int flag;

	if(this != NULL && pFunc != NULL && (order ==0 || order ==1))
	{
		while(flag)
		{
			flag=0;
			for(i=0;i<len-1;i++)
			{
				element1=ll_get(this,i);//OBTENGO LA DIR. DE MEM DEL ELEMENTO EN ESA POSICIÓN Y EL QUE LE SIGUE
				element2=ll_get(this,i+1);
				if(((pFunc(element1,element2)>0) && order ==1) || ((pFunc(element1,element2)<0) && order ==-1))
				{//SI ELEMENTO 1 ES MAYOR A 2 Y EL ORDEN ES ASCENDENTE O SI EL 1 ES MENOR AL 2 Y EL ORDEN ES DESCENDENTE
					//ES DECIR ESTOS SON LOS UNICOS CASOS EN EL QUE ES NECESARIO INVERTIRLOS
					ll_set(this,i,element2);//2 TOMA LA POSICIÓN DE 1
					ll_set(this,i+1,element1);//1 TOMA LA POCISIÓN DE 2
					flag=1;
				}
			}
		}
		returnAux=0;
	}


    return returnAux;


}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------
/** \brief Itera los elementos de la lista para pasarcelas a la función que llega por parámetro
 *
 *  \param LinkedList* this Lista
 *  \param Fn genérica, espera recibir elemento por parámetro para realizar alguna operación
 *  \return LinkedList* Retorna (-1) en caso de que la lista sea nula, (0) Exito
 */
int ll_map(LinkedList* this, void(*fn)(void*))
{
	int auxRetorno=-1;
	void* element=NULL;
	int len=ll_len(this);
	int i;

	if(this != NULL)
	{
		for(i=0;i<len;i++)
		{
			element=ll_get(this,i);//GETEA EL PUNTERO AL ELEMENTO EN ESE INDEX
			if(element!= NULL)
			{
			 fn(element);//la paso a la fn el elemento para que calcule si se debe aplicar descuento y completar ese campo de corresponder.
			 auxRetorno=0;
			}
		}
	}
	return auxRetorno;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Itera los elementos de la lista para pasarcelas a la función que llega por parámetro y obtener de esta los elementos a contar,
 * luego retorna la cantidad obtenida.
 *
 *  \param LinkedList* this Lista
 *  \param Función que informará los elementos a contar
 *  \return LinkedList* Retorna (-1) en caso de que la lista sea nula, o devuelve el valor obtenido.
 */

int ll_count(LinkedList* this, int(*fn)(void*))//era una papa, me compliqué de más. Por lo menos lo entendí(aplausos para todos, gracias profes).
{
	int auxRetorno=-1;
	void* element=NULL;
	int len=ll_len(this);
	int i;
	int cont=0;
	if(this != NULL)
	{
		for(i=0;i<len;i++)
		{
			element=ll_get(this,i);//GETEA EL PUNTERO AL ELEMENTO EN ESE INDEX
			if(element!= NULL)
			{
			 cont=fn(element);
			 auxRetorno=auxRetorno+cont;//ACUMULA EL VALOR OBTENIDO POR LA FN
			}
		}
	}
	return auxRetorno;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------
