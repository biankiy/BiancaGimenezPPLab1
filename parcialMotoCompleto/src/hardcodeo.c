/*
 * harcodeo.c
 *
 *  Created on: 20 may. 2022
 *      Author: bianky
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hardcodeo.h"
#include "cliente.h"



//-------------------------[Moto]-------------------------//

char marca[15][24]=
{

    {"Honda"},
    {"Gilera"},
    {"Rouser"},
    {"Ducati"},
    {"Tramps"},
    {"Bultaco"},
    {"Harley"},
    {"Kawasaki"},
    {"Suzuki"},
    {"Honda"},
    {"Yumin"},
    {"Suzuki"},
    {"Rouser"},
    {"Suzuki"}

};

int idTipo[15] = {1000,1000,1002,1002,1000,1003,1000,1000,1003,1003,1003,1002,1000,1002,1000};
int idClientes[15] = {1,2,3,4,5,6,7,8,9,10,1,2,3,4,5};
int idColor[15] = {10000,10002,10004,10003,10003,10004,10002,10001,10001,10004,10002,10000,10002,10004,10000};
int cilindrada[15] = {50,125,500,600,125,50,125,500,125,750,50,125,500,600,750};

int hardcodearMotos(eMoto list[],int len,int* id,int cant)
{
    int ret = ERROR;

    if(list != NULL && len >0 && id != NULL)
    {
        for(int i=0; i<cant; i++)
        {
            list[i].id = *id;
            *id = *id + 1;
            strcpy(list[i].marca,marca[i]);
            list[i].idColor = idColor[i];
            list[i].idTipo = idTipo[i];
            list[i].cilindrada = cilindrada[i];
            list[i].idCliente = idClientes[i];
            list[i].isEmpty = 0;
        }
        ret = TODOK;
    }
    return ret;
}




int idT[4]=
			{1000,1001,1002,1003};

char descripcion[4][24] =
{
    {"Enduro"},
    {"Chopera"},
    {"Scooter"},
    {"Ciclomotor"}
};

int hardcodearTipos(eTipo list[],int len,int* id,int cant)
{
    int ret = ERROR;
    if(list != NULL && len >0 && id != NULL)
    {
        for(int i=0; i<cant; i++)
        {
            list[i].id = *(id);
            strcpy(list[i].descripcion,descripcion[i]);
            list[i].isEmpty = 0;
            *(id) = *(id)+1;
        }
        ret = TODOK;
    }
    return ret;
}


int idMoto[15] = {1000,1002,1003,1004,1005,1006,1007,1008,1009,1010,1003,1002,1000,1002,1000};
int idServicio[15] = {20001,20000,20000,20002,20002,20003,20001,20002,20000,20000,20001,20000,20003,20003,20003};
eFecha fechas[15] =
{
    {25,05,2019},
    {15,10,2018},
    {17,12,2020},
    {12,05,2018},
    {1,05,2019},
    {5,11,2020},
    {15,05,2020},
    {3,05,2020},
    {15,1,2019},
    {25,6,2020},
    {15,05,2020},
    {15,4,2020},
    {18,05,2018},
    {13,05,2019},
    {12,05,2020}
};

int hardcodearTrabajos(eTrabajo list[],int len,int* id,int cant)
{
    int ret = ERROR;

    if(list != NULL && len >0 && id != NULL)
    {
        for(int i=0; i<cant; i++)
        {
            list[i].id = *id;
            *id = *id + 1;
            list[i].idMoto = idMoto[i];
            list[i].idServicio = idServicio[i];
            list[i].fecha = fechas[i];
            list[i].isEmpty = 0;
        }
        ret = TODOK;
    }
    return ret;
}



int idCliente[10]= {1,2,3,4,5,6,7,8,9,10};
char nombre[10][24] =
{
    {"Karen"},
    {"Riku"},
    {"Victor"},
    {"Tomi"},
    {"Mora"},
    {"Micaela"},
    {"Cristina"},
    {"Alexis"},
    {"Leandro"},
    {"Patricio"}
};
char sexo[10]= {'f','m','m','m','f','f','f','m','m','m'};

int hardcodearClientes(eCliente list[],int len,int* id,int cant)
{
    int ret = ERROR;

    if(list != NULL && len >0 && id != NULL)
    {
        for(int i=0; i<cant; i++)
        {
            list[i].id = *id;
            *id = *id + 1;
            strcpy(list[i].nombre,nombre[i]);
            list[i].sexo = sexo[i];
            list[i].isEmpty = 0;
        }
        ret = TODOK;
    }
    return ret;
}
