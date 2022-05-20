/*
 * moto.c
 *
 *  Created on: 20 may. 2022
 *      Author: bianky
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "moto.h"

int inicializarArrayMoto(eMoto list[],int len)
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

int buscarLibreMoto(eMoto list[],int len)
{
    int respuesta = ERROR;

    if(list != NULL && len >0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == 1)
            {
                respuesta = i;
                break;
            }
        }
    }
    return respuesta;
}

int mostrarListaMotos(eMoto list[],int len,eTipo listTipo[],int lenTipo,eColor listColor[],int lenColor,eCliente listCliente[],int lenCliente)
{
    int respuesta = ERROR;
    if(list != NULL && len >0 && listTipo != NULL && lenTipo >0 && listColor != NULL && lenColor >0 && listCliente != NULL && lenCliente >0)
    {

        printf("\n-------------------------Lista motos-----------------------------------\n");
        printf("\n[ID]       [Marca]        [Tipo]        [Color]    [Cilindrada]    [Cliente]\n");
        printf("_______________________________________________________________________________\n\n");
        for(int i=0; i<len-1; i++)
        {
            if(list[i].isEmpty == 0)
            {
                mostrarUnaMoto(&list[i],listTipo,lenTipo,listColor,lenColor,listCliente,lenCliente);
            }
        }
        printf("_______________________________________________________________________________\n\n");
        printf("\n\n");
        respuesta = TODOK;
    }
    return respuesta;
}

int mostrarUnaMoto(eMoto* unaMoto,eTipo listTipo[],int lenTipo,eColor listColor[],int lenColor,eCliente listCliente[],int lenCliente)
{
    int ret = ERROR;
    char tipoAux[24];
    char colorAux[24];
    char nombreAux[24];

    if( unaMoto != NULL && listTipo != NULL && lenTipo >0 && listColor != NULL && lenColor >0 )
    {
        if(cargarDescTipo(unaMoto->idTipo,listTipo,lenTipo,tipoAux) &&
            cargarDescColor(unaMoto->idColor,listColor,lenColor,colorAux) &&
            cargarNombreCliente(listCliente,lenCliente,unaMoto->idCliente,nombreAux)== TODOK)
        {
            printf("%4d  %12s  %12s  %12s %10d cc. %12s\n"
                   ,unaMoto->id
                   ,unaMoto->marca
                   ,tipoAux
                   ,colorAux
                   ,unaMoto->cilindrada
                   ,nombreAux);
        }
        else
        {
            printf("\nERROR al intentar cargar descripciones!\n");
        }
    }

    return ret;
}

int altaMoto(eMoto list[],int len,int* idPtr,eTipo listTipo[],int tamTipo,eColor listColor[],int tamColor)
{
    int index = ERROR, ret = ERROR;

    if(list != NULL && len >0 && idPtr != NULL && listTipo != NULL && tamTipo >0 && listColor != NULL && tamColor >0)
    {
        index = buscarLibreMoto(list,len);

        if(index != ERROR)
        {

            printf("\n------------Alta moto-------------\n");
            printf("------------------------------------\n\n");

            getString(list[index].marca,"\nIngrese marca [Max 20 caract.]: ","\nDato invalido!.Reingrese!\n",1,24,10);
            mostrarListaTipos(listTipo,tamTipo);
            getInt(&list[index].idTipo,"\nIngrese un ID valido [1000-1003] : ","\nDato invalido!.Reingrese!\n",1000,1003,10);
            mostrarListaColor(listColor,tamColor);
            getInt(&list[index].idColor,"\nIngrese un ID valido [10000-10004] : ","\nDato invalido!.Reingrese!\n",10000,10004,10);
            validarCilindrada(&list[index].cilindrada,"\nIngrese cilindrada [50,125,500,600,750] : ","\nDato invalido!.Reingrese!\n",10);

            list[index].id = *idPtr;
            *idPtr = *idPtr + 1;
            list[index].isEmpty = 0;
            ret = TODOK;
        }
    }
    return ret;
}

int modificarMoto(eMoto list[],int len,eColor listColor[],int lenColor)
{
    int idMotoAux,index,ret = ERROR;

    if(list != NULL && len >0)
    {
        do
        {
            getInt(&idMotoAux,"\nIngrese id a modificar: ","\nDato Invalido!",1000,1500,1);
            index = retornarIndicePorID(list,len,idMotoAux);

            if(index != ERROR)
            {
                switch(menuModifacar())
                {
                case 1:
                    mostrarListaColor(listColor,lenColor);
                    getInt(&list[index].idColor,"\nIngrese un ID nuevo color [10000/10004]:\n","\nDato Invalido.Reingrese:\n",10000,10004,5);
                    break;

                case 2:
                    validarCilindrada(&list[index].cilindrada,"\nIngrese nueva cilindrada [50,125,500,600,750] : ","\nDato invalido!.Reingrese!\n",10);
                    break;
                }
                ret = TODOK;
            }
        }
        while(index == ERROR);
    }
    return ret;
}

int bajaMoto(eMoto list[],int len)
{
    int index = ERROR;
    int idBaja = ERROR;
    int ret = ERROR;
    char confirma;

    if( list != NULL && len >0 )
    {
        getInt(&idBaja,"\nIngrese un ID a dar de baja: \n","\nDato Invalido.Reingrese: \n",1000,1500,10);
        index = retornarIndicePorID(list,len,idBaja);
        if(index != ERROR)
        {
            validarSioNo(&confirma,"\nConfirma baja? [s/n]:\n","\nDato Invalido.Reingrese:\n",3);

            if(confirma == 's')
            {
                list[index].isEmpty = 1;
                printf("\nBaja exitosa.\n");
                ret = TODOK;
            }
            else
            {
                printf("\nBaja cancelada por el usuario!.\n");
            }
        }
    }
    return ret;
}

int retornarIndicePorID(eMoto list[],int len,int idValidar)
{
    int ret = ERROR;

    if(list != NULL && len >0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id == idValidar && list[i].isEmpty == 0)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int validarCilindrada(int *pResultado,char *pMensaje,char *msjError,int reintentos)
{
    int ret = ERROR;
    int buffer;

    if(pResultado != NULL && pMensaje != NULL && msjError != NULL && reintentos >=0)
    {
        system("cls");
        do
        {
            printf("%s",pMensaje);
            fflush(stdin);

            if(scanf("%d",&buffer)==1)
            {
                if( buffer == 50 || buffer == 125 || buffer == 500 || buffer == 600 || buffer == 750)
                {
                    ret = TODOK;
                    *pResultado = buffer;
                    break;
                }
            }
            printf("%s",msjError);
            reintentos--;
        }
        while(reintentos >= 0);
    }
    return ret;
}

int menuModifacar()
{
    int option;

    printf("\n-----------------------------------------------\n");
    printf("\n1- Modificar Color.");
    printf("\n2- Modificar Cilindrada.");

    getInt(&option,"\nIngrese una opcion valida[1/2]: \n","\nDato Invalido.Reingrese:\n",1,2,10);

    return option;
}

int cargarDescripcionMarca(eMoto list[],int len,int idMoto,char* descrip)
{
    int respuesta = ERROR;

    if( list != NULL && len >0 && descrip != NULL )
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id == idMoto)
            {
                strcpy(descrip,list[i].marca);
                break;
            }
        }
        respuesta = TODOK;
    }
    return respuesta;
}

int validarIdMoto(eMoto list[],int len,int idValidar)
{
    int respuesta = ERROR;

    if(list != NULL && len >0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id == idValidar && list[i].isEmpty == 0)
            {
                respuesta = TODOK;
                break;
            }
        }
    }
    return respuesta;
}

int ordenarMotosPorTipoEId(eMoto list[],int len)
{
    int respuesta = ERROR;
    eMoto aux;

    if(list != NULL && len >0)
    {
        if(ordenarMotoPorTipo(list,len))
        {
            for(int i=0; i<len-1; i++)
            {
                for(int j=i+1; j<len; j++)
                {
                    if(list[i].idTipo == list[j].idTipo && list[i].id > list[j].id)
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }
            }
            respuesta = TODOK;
        }
    }
    return respuesta;
}

int ordenarMotoPorTipo(eMoto list[],int len)
{
    int respuesta = ERROR;
    eMoto aux;

    if(list != NULL && len >0)
    {
        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(list[i].idTipo > list[j].idTipo)
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
            }
        }
        respuesta = TODOK;
    }
    return respuesta;
}


