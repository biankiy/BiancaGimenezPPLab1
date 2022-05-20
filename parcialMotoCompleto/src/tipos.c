/*
 * tipos.c
 *
 *  Created on: 20 may. 2022
 *      Author: bianky
 */

#include "tipos.h"

int inicializarArrayTipo(eTipo list[],int len)
{
    int ret = ERROR;

    if(list != NULL && len >0)
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty = 1;
        }
        ret = TODOK;
    }
    return ret;
}


int cargarDescTipo(int idTipo, eTipo list[],int len,char* aux)
{
    int ret = ERROR;

    if( list != NULL && len >0 && aux != NULL )
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id == idTipo)
            {
                strcpy(aux,list[i].descripcion);
                break;
            }
        }
        ret = TODOK;
    }
    return ret;
}

int mostrarListaTipos(eTipo list[],int len)
{
    int ret = ERROR;
    if(list != NULL && len >0)
    {

        printf("\n----------Tipos------------\n");
        printf("\nID       Descripcion\n");
        printf("--------------------------------\n\n ");
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                printf("%4d %12s\n",list[i].id,list[i].descripcion);
                printf("----------------------------\n");
            }
        }
        printf("\n\n");
    }
    return ret;
}

int validarIdTipo(eTipo list[],int len,int idComparar)
{
    int ret = ERROR;

    if(list != NULL && len >0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id == idComparar && list[i].isEmpty == 0)
            {
                ret = TODOK;
            }
        }
    }
    return ret;
}
