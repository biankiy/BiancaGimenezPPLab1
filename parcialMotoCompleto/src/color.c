/*
 * color.c
 *
 *  Created on: 20 may. 2022
 *      Author: bianky
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "color.h"

int inicializarArrayColor(eColor list[],int len)
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

int cargarDescColor(int idColor,eColor list[],int len,char* aux)
{
    int respuesta = ERROR;

    if( list != NULL && len >0 && aux != NULL )
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id == idColor)
            {
                strcpy(aux,list[i].nombreColor);
                break;
            }
        }
        respuesta = TODOK;
    }
    return respuesta;
}

int mostrarListaColor(eColor list[],int len)
{
    int respuesta = ERROR;
    if(list != NULL && len >0)
    {

        printf("\n-------Colores------\n");
        printf("\nID       Descripcion\n");
        printf("----------------------\n\n");
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                printf("%4d %12s\n",list[i].id,list[i].nombreColor);
                printf("----------------------------\n");
            }
        }
        printf("\n\n");
    }
    return respuesta;
}

int validarIdColor(eColor list[],int len,int idComparar)
{
    int retorno = ERROR;

    if(list != NULL && len >0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id == idComparar && list[i].isEmpty == 0)
            {
                retorno = TODOK;
            }
        }
    }
    return retorno;
}

int ordenarListaColoresAux(eColor list[],int len)
{
    int ret = ERROR;
    eColor aux;

    if(list != NULL && len >0)
    {
        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(list[i].isEmpty < list[j].isEmpty)
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
            }
        }
    }
    return ret;
}
