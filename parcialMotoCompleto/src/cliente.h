/*
 * cliente.h
 *
 *  Created on: 20 may. 2022
 *      Author: bianky
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR -1
#define TODOK 1

typedef struct
{
    int id;
    char nombre[24];
    char sexo;
    int isEmpty;

}eCliente;


int inicializarArrayClientes(eCliente list[],int len);
int cargarNombreCliente(eCliente list[],int len,int idCliente,char* nombreAux);

#endif /* CLIENTE_H_ */
