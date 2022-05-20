/*
 * cliente.c
 *
 *  Created on: 20 may. 2022
 *      Author: bianky
 */
#include "cliente.h"


int inicializarArrayClientes(eCliente list[],int len)
{
    int retorno = ERROR;

    if(list != NULL && len >0)
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty = 1;
        }
        retorno = TODOK;
    }
    return retorno;
}


int cargarNombreCliente(eCliente list[],int len,int idCliente,char* nombreAux)
{
    int retorno = ERROR;

    if( list != NULL && len >0 && nombreAux != NULL )
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id == idCliente)
            {
                strcpy(nombreAux,list[i].nombre);
                break;
            }
        }
        retorno = TODOK;
    }
    return retorno;
}
