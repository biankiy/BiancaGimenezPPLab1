/*
 * trabajo.h
 *
 *  Created on: 20 may. 2022
 *      Author: bianky
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_

#include "fecha.h"
#include "moto.h"

typedef struct
{
    int id;
    int idMoto;
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;

int inicializarArrayTrabajo(eTrabajo list[],int len);
int buscarLibreJob(eTrabajo list[],int len);
int mostrarUnTrabajo(eTrabajo* UnTrabajo,eServicio listServ[],int lenServ,eMoto listMoto[],int lenMoto);
int mostrarListaTrabajos(eTrabajo list[],int len,eServicio listServ[],int lenServ,eMoto listMoto[],int lenMoto);
int altaTrabajo(eTrabajo list[],int len,int* idJob,eServicio listServ[],int lenServ,eMoto listMoto[],int lenMoto);

#endif /* TRABAJO_H_ */
