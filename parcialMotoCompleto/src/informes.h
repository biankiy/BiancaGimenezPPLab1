/*
 * informes.h
 *
 *  Created on: 20 may. 2022
 *      Author: bianky
 */
#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "tipos.h"
#include "servicios.h"
#include "color.h"
#include "funcionesAyuda.h"
#include "trabajo.h"


int menu();
int informes();
int informarMotoPorColor(eMoto list[],int len,eColor listColor[],int lenColor,eTipo listTipo[],int lenTipo,eCliente listCliente[],int lenCliente);
int informarMotoPorTipo(eMoto list[],int len,eColor listColor[],int lenColor,eTipo listTipo[],int lenTipo,eCliente listCliente[],int lenCliente);
int informarMotoMaryorCilindrada(eMoto list[],int len,eColor listColor[],int lenColor,eTipo listTipo[],int lenTipo,eCliente listCliente[],int lenCliente);
int informarMotoSeparadaTipo(eMoto list[],int len,eColor listColor[],int lenColor,eTipo listTipo[],int lenTipo,eCliente listCliente[],int lenCliente);
int informarCantColorYTipo(eMoto list[],int len,eColor listColor[],int lenColor,eTipo listTipo[],int lenTipo);
int informarColorMasElegido(eMoto list[],int len,eColor listColor[],int lenColor);
int informarTrabajosSeleccionados(eMoto list[],int len,eTrabajo listJob[],int lenJob,eServicio listServ[],int lenServ);
int informarSumarValores(eMoto list[],int len,eTrabajo listJob[],int lenJob,eServicio listServ[],int lenServ);
int informarServiciosPorMoto(eTrabajo listJob[],int lenJob,eServicio listServ[],int lenServ,eMoto listMoto[],int lenMoto);
int informarServicioPorFecha(eServicio listServ[],int lenServ,eTrabajo listJob[],int lenJob);


#endif /* INFORMES_H_ */
