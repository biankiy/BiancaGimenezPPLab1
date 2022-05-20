/*
 * harcodeo.h
 *
 *  Created on: 20 may. 2022
 *      Author: bianky
 */

#ifndef HARDCODEO_H_
#define HARDCODEO_H_


#include "moto.h"
#include "servicios.h"
#include "tipos.h"
#include "color.h"
#include "fecha.h"
#include "trabajo.h"
#include "cliente.h"


int hardcodearMotos(eMoto list[],int len,int* id,int cant);
int hardcodearTipos(eTipo list[],int len,int* id,int cant);
int hardcodearTrabajos(eTrabajo list[],int len,int* id,int cant);
int hardcodearClientes(eCliente list[],int len,int* id,int cant);

#endif /* HARDCODEO_H_ */
