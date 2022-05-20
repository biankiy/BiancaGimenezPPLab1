/*
 * trabajo.c
 *
 *  Created on: 20 may. 2022
 *      Author: bianky
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trabajo.h"

int inicializarArrayTrabajo(eTrabajo list[],int len)
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

int buscarLibreJob(eTrabajo list[],int len)
{
    int ret = ERROR;

    if(list != NULL && len >0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == 1)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int mostrarUnTrabajo(eTrabajo* UnTrabajo,eServicio listServ[],int lenServ,eMoto listMoto[],int lenMoto)
{
    int ret = ERROR;
    char marcaAux[24];
    char servAux[24];

    if( UnTrabajo != NULL && listServ != NULL && lenServ >0 && listMoto != NULL && lenMoto >0 )
    {
        if(cargarDescripcionMarca(listMoto,lenMoto,UnTrabajo->idMoto,marcaAux) &&
                cargarDescServ(listServ,lenServ,UnTrabajo->idServicio,servAux) == 1)
        {
            printf("%4d  %12s  %12s     %02d/%02d/%4d\n"
                   ,UnTrabajo->id
                   ,marcaAux
                   ,servAux
                   ,UnTrabajo->fecha.dia
                   ,UnTrabajo->fecha.mes
                   ,UnTrabajo->fecha.anio);
        }
        else
        {
            printf("\nError!!!! al intentar cargar descripciones!\n");
        }
    }

    return ret;
}

int mostrarListaTrabajos(eTrabajo list[],int len,eServicio listServ[],int lenServ,eMoto listMoto[],int lenMoto)
{
    int ret = ERROR;
    if(list != NULL && len >0 && listServ != NULL && lenServ >0 && listMoto != NULL && lenMoto >0)
    {

    	printf("\n------------Lista Trabajos----------------------\n");
        printf("\n[ID]        [Moto]      [Servicio]    [Fecha]\n");
        printf("\n-----------------------------------------------\n");

        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                mostrarUnTrabajo(&list[i],listServ,lenServ,listMoto,lenMoto);
            }
        }
        printf("____________________________________________________\n\n");
        printf("\n\n");
        ret = TODOK;
    }
    return ret;
}

int altaTrabajo(eTrabajo list[],int len,int* idJob,eServicio listServ[],int lenServ,eMoto listMoto[],int lenMoto)
{
    int idMotAux, idServAux, index = ERROR,ret = ERROR;
    int diaAux, mesAux,anioAux;

    if(list != NULL && len >0 && listServ != NULL && lenServ >0 && listMoto != NULL && lenMoto >0)
    {
        index = buscarLibreJob(list,len);

        if(index != ERROR)
        {
            getInt(&idMotAux,"\nIngrese id Moto: \n","\nError.",1000,1500,3);
            mostrarListaServicios(listServ,lenServ);
            getInt(&idServAux,"\nIngrese id Servicio: \n","\nError.",20000,20003,3);
            system("cls");
            getInt(&diaAux,"\nIngrese dia [1-31]: \n","\nError.",1,31,3);
            getInt(&mesAux,"\nIngrese mes [1-12]: \n","\nError.",1,12,3);
            getInt(&anioAux,"\nIngrese año [2021-2050]: \n","\nError.",2021,2050,3);
            if(validarIdMoto(listMoto,lenMoto,idMotAux) && validarServicio(listServ,lenServ,idServAux) && valFecha(diaAux,mesAux,anioAux))
            {
                list[index].id = *idJob;
                *idJob += 1;
                list[index].idMoto = idMotAux;
                list[index].idServicio = idServAux;
                list[index].fecha.dia = diaAux;
                list[index].fecha.mes = mesAux;
                list[index].fecha.anio = anioAux;
                list[index].isEmpty = 0;
                ret = TODOK;
            }
        }
    }
    return ret;
}
