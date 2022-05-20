/*
 * color.h
 *
 *  Created on: 20 may. 2022
 *      Author: bianky
 */

#ifndef COLOR_H_
#define COLOR_H_


#define ERROR -1
#define TODOK 1

typedef struct
{
    int id;
    char nombreColor[25];
    int isEmpty;

}eColor;

int cargarDescColor(int idColor,eColor list[],int len,char* aux);
int mostrarListaColor(eColor list[],int len);
int inicializarArrayColor(eColor list[],int len);
int validarIdColor(eColor list[],int len,int idComparar);
int ordenarListaColoresAux(eColor list[],int len);


#endif /* COLOR_H_ */
